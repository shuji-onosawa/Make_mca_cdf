 /*
 *    MCA�f�[�^��CDF�t�@�C��(0.25�b�Ԋu)��n�b���ς���B
 *    �����āA�����V����CDF�t�@�C���ɕۑ�����B
 *    n �b 1 ���R�[�h�ɂ���B
 *
 *    By Y. Ozaki
 *
 *    2005.11.3
 *
 *    - ���s�R�}���h ave yyyy mm dd n
 *    - Epoch �� Spacerecord �ɂ��܂���ł���(�`��̓s����)�B
 *                                                2005.12.19
 *    - �������̋��ߕ��Ԉ���Ă��̏C�����܂����B
 *                                                2006. 1. 6
 *    - �ш敝�Ŋ������l�����ʂƂ��܂��B
 *                                                2006. 1.10
 *
 *    hyper access �𓱓����č��������͂���܂����B
 *    variable attributes �̕s��𒼂��܂����B
 *    global attributes ��ST ET ��ǉ����܂����B
 *
 *                         by Masanori Aoki       2007. 1.31
 *
 *    �ŏI�X�V�� : 2007. 1.31
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "cdf.h"
#include "average.h"


CDFid opid;
CDFid crid;
CDFstatus status;

char input[ 20 ];

//�e�ϐ��̕ϐ�id
long EmaxNum;
long EaveNum;
long BmaxNum;
long BaveNum;
long E_WIDANum;
long B_WIDANum;
long PostGapNum;
long EpochNum;
long channelNum;

long f_year;
long f_month;
long f_day;

float freq[ NUM_CHANNEL ];
float bfact[ NUM_CHANNEL ];

int main( int argc , char *argv[] )
{
  clock_t start,end;
  int sec;
  int k;

  int len_ymd[ 4 ];
  char ymd[ 4 ][ 5 ];

  if( argc != MAX_ARGC ) {
    printf("Input ERROR.\n");
    exit(1);
  }

  //***** ���͂��ꂽ�N �� �� �̕�����̒����𒲂ׂ�
  /*
  for( k = 1 ; k < argc ; k++ ) {
    len_ymd[ k - 1 ] = strlen( argv[ k ] );
  } 
  if( len_ymd[ 0 ] != 4 ) {
    printf("Input ERROR of YEAR.\n");
    exit(1);
  }
  if( len_ymd[ 1 ] !=  1 && len_ymd[ 1 ] != 2 ) {
    printf("Input ERROR of MONTH.\n");
    exit(1);
  }
  if( len_ymd[ 2 ] !=  1 && len_ymd[ 2 ] != 2 ) {
    printf("Input ERROR of MONTH.\n");
    exit(1);
  }
  if( len_ymd[ 3 ] !=  1 && len_ymd[ 3 ] != 2 ) {
    printf("Input ERROR of SECONT.\n");
    exit(1);
  }
  */
  
  //***** ���͂��ꂽ�N �� �� �� ���ς̕b �� �z��ymd[] �ɕۑ�
  //year
  strcpy( ymd[ 0 ] ,argv[ 1 ] );

  //month & day & sec
  for( k = 1 ; k <= 2 ; k++ ) {
    if( strlen( argv[ k + 1 ] ) == 1 ) {
      ymd[ k ][ 0 ] = '0';
      ymd[ k ][ 1 ] = argv[ k + 1 ][ 0 ];
      ymd[ k ][ 2 ] = '\0';
    }
    else {
      strcpy( ymd[ k ] , argv[ k + 1 ] );
    }
  }

  strcpy( ymd[ 3 ] ,argv[ 4 ] );

  sec = atoi( ymd[ 3 ] );
  /*  if( sec < 1 || sec > 60 ){
    printf("!!!!! input error !!!!!\n");
    exit( 1 );
  }
  */

  start=clock();

  openCDF( ymd );
  get_VarNum();

  f_year = ( long )atoi( ymd[ 0 ] );
  f_month = ( long )atoi( ymd[ 1 ] );
  f_day = ( long )atoi( ymd[ 2 ] );

  createCDF( ymd );

  ave_data( sec );

  closeCDF();

  end =clock();

  printf(" success!! \n");
  printf("time = %f [sec]\n",(double)(end-start)/CLOCKS_PER_SEC);

}


//**************************************************************************
//openCDF() : MCA�f�[�^��CDF�t�@�C�����J���֐�
void openCDF( ymd )
     char ymd[][ 5 ];
{
  char fpname[ OPEN_LEN + 1 ];

  int k;

  //***** �I�[�v������t�@�C�������쐬

  sprintf( fpname , "%s%s/ak_h0_mca_%s%s%s_v01" , OPNAME , ymd[ 0 ] , ymd[ 0 ] , ymd[ 1 ] , ymd[ 2 ] );

  //  sprintf( fpname , "%s%s/%s%s%sMCA_H0" , OPNAME , ymd[ 0 ] , ymd[ 0 ] , ymd[ 1 ] , ymd[ 2 ] );

  //  printf("open = %s\n",fpname);

  status = CDFlib( OPEN_ , CDF_ , fpname , &opid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
}

//**************************************************************************
//closeCDF() : �ǂ�CDF�t�@�C�������֐�
void closeCDF()
{
  status = CDFclose ( opid );

  if (status != CDF_OK) StatusHandler (status);

  status = CDFclose ( crid );

  if (status != CDF_OK) StatusHandler (status);

}

//**************************************************************************
//get_VarNum() : �ǂ�CDF�t�@�C���̕ϐ�id���Q�b�g����֐�
void get_VarNum()
{
  status = CDFlib( SELECT_ , CDF_ , opid ,
		   GET_ , zVAR_NUMBER_ , "Emax"    , &EmaxNum ,
		          zVAR_NUMBER_ , "Eave"    , &EaveNum ,
		          zVAR_NUMBER_ , "Bmax"    , &BmaxNum ,
		          zVAR_NUMBER_ , "Bave"    , &BaveNum ,
		          zVAR_NUMBER_ , "E_WIDA"  , &E_WIDANum ,
		          zVAR_NUMBER_ , "B_WIDA"  , &B_WIDANum ,
		          zVAR_NUMBER_ , "PostGap" , &PostGapNum ,
		          zVAR_NUMBER_ , "Epoch"   , &EpochNum ,
		          zVAR_NUMBER_ , "channel" , &channelNum ,
		   NULL_ );

  if (status != CDF_OK) StatusHandler (status);
}

//**************************************************************************
//get_Data() : �ǂ�CDF�t�@�C���� CDF_UINT1�^�ϐ� �̒l���Q�b�g����֐�
void get_Data( num , record , varNum , data )
     int num;
     long record;
     long varNum;
     unsigned char data[];
{
  int k;
  long recS;
  long recC;
  long recI;
  long indices[1];
  long counts[1];
  long intervals[1];
  unsigned char value[num];
  recS=record;
  recC=1;
  recI=1;
  indices[0]=0;
  counts[0]=(long)num;
  intervals[0]=1;

  status = CDFlib( SELECT_ , CDF_              , opid ,
		   zVAR_             , varNum ,
		   zVAR_RECNUMBER_   , recS ,
		   zVAR_RECCOUNT_    , recC ,
		   zVAR_RECINTERVAL_ , recI ,
		   zVAR_DIMINDICES_  , indices ,
		   zVAR_DIMCOUNTS_   , counts ,
		   zVAR_DIMINTERVALS_, intervals ,
		   GET_    , zVAR_HYPERDATA_   , &value , 
		   NULL_ );
  if ( status != CDF_OK ) StatusHandler( status );
  for(k=0;k<num;k++){
    data[k]=value[k];
  }
  
  
}
//**************************************************************************
//get_EB() : �ǂ�CDF�t�@�C���� �d�E,���E �̒l���Q�b�g����֐�
void get_EB( num , record , varNum , data )
     int num;
     long record;
     long varNum;
     double data[];
{
  int k;
  long recS;
  long recC;
  long recI;
  long indices[1];
  long counts[1];
  long intervals[1];
  unsigned char value[num];

  recS=record;
  recC=1;
  recI=1;
  indices[0]=0;
  counts[0]=(long)num;
  intervals[0]=1;
  
  status = CDFlib( SELECT_ , CDF_              , opid ,
		   zVAR_             , varNum ,
		   zVAR_RECNUMBER_   , recS ,
		   zVAR_RECCOUNT_    , recC ,
		   zVAR_RECINTERVAL_ , recI ,
		   zVAR_DIMINDICES_  , indices ,
		   zVAR_DIMCOUNTS_   , counts ,
		   zVAR_DIMINTERVALS_, intervals ,
		   GET_    , zVAR_HYPERDATA_   , &value , 
		   NULL_ );
  if ( status != CDF_OK ) StatusHandler( status );
  for( k = 0 ; k < num ; k++ ) {
    data[ k ] = ( double )value[ k ];
  }
}

//**************************************************************************
//get_Epoch() : �ǂ�CDF�t�@�C����Epoch�l���Q�b�g����֐�
double get_Epoch( record )
     long record;
{
  double time;

  status = CDFlib( SELECT_ , CDF_            , opid ,
		             zVAR_           , EpochNum ,
		             zVAR_RECNUMBER_ , record ,
		   GET_    , zVAR_DATA_      , &time, 
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
  
  return time;
}

//**************************************************************************
//get_PostGap() : �ǂ�CDF�t�@�C���� PostGap �̒l���Q�b�g����֐�
int get_PostGap( record )
     long record;
{
  int flag;

  status = CDFlib( SELECT_ , CDF_            , opid ,
		             zVAR_           , PostGapNum ,
		             zVAR_RECNUMBER_ , record ,
		   GET_    , zVAR_DATA_      , &flag, 
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
  
  return flag;
}

//**************************************************************************
//get_channel() : �ǂ�CDF�t�@�C���� channel �̒l���Q�b�g����֐�
void get_channel()
{ 
  long record = 0L;
  int k;
  long recS = 0L;
  long recC = 1;
  long recI = 1;
  long indices[ 1 ];
  long counts[ 1 ];
  long intervals[ 1 ];

  //�e�`�����l���̎��g�����擾(�ϐ� channel �̒l�� GET ����)
  indices[0]=0;
  counts[0]=NUM_CHANNEL;
  intervals[0]=1;
  status = CDFlib( SELECT_ , CDF_              , opid ,
		   zVAR_             , channelNum ,
		   zVAR_RECNUMBER_   , recS ,
		   zVAR_RECCOUNT_    , recC ,
		   zVAR_RECINTERVAL_ , recI ,
		   zVAR_DIMINDICES_  , indices ,
		   zVAR_DIMCOUNTS_   , counts ,
		   zVAR_DIMINTERVALS_, intervals ,
		   GET_    , zVAR_HYPERDATA_   , &freq , 
		   NULL_ );
  if ( status != CDF_OK ) StatusHandler( status );
  printf("\n");

  for( k = 0 ; k < NUM_CHANNEL ; k++ ) {
    bfact[ k ] = sqrt( freq[ k ] * 0.6 );
  }
}

//**************************************************************************
//get_wida() : 4ch���Ƃɂ����܂��Ă���WIDA��1ch���ɕ�����֐�
void get_wida( wida , ws )
     unsigned char wida[];
     unsigned char ws[];
{
  unsigned char c;
  int i , j;

  for( j = 0 ; j < NUM_WIDA ; j ++ ){
      c = wida[ j ];
    for( i = 0 ; i < NUM_WIDA ; i ++ ){
      ws[ (4 * j) + i ] = c & 0x03;
      c >>= 2;
    }
  }
}

//**************************************************************************
//heffe() : �A���e�i�����������߂�֐�(�d�E�p)
double heffe( i )
     int i;
{

  double pi;
  double rs = 500.0E3;
  double cs = 250.0e-12;
  double cin = 100.0e-12;
  double preg = -2.2;
  double heff;
  double heffe;

  double omega , denom , real , image;
  /*
    denom : Z �̕���
    real  : Z �̎���
    image : Z �̋���
   */
  double zabs;    // Z �̑傫��
  double jwcs , jwcin;
  double pregain;

  pi = atan( 1.0 ) * 4;
  //  printf(" pi = %lf \n" , pi );

  heff = 60.0 / 2.0;
  pregain = pow( 10.0 , preg / 20.0 );

  omega = 2.0 * pi * freq[ i ];
  jwcs = omega * cs;
  jwcin = omega * cin;

  denom = pow( 1.0 / rs , 2.0 ) + pow( jwcin + jwcs , 2.0 );
  real = ( pow( 1.0 / rs , 2.0 ) + jwcin * jwcs + pow( jwcs , 2.0 ) ) / denom;
  image = ( jwcin / rs ) / denom;

  zabs = sqrt( pow( real , 2.0 ) + pow( image , 2.0 ) );
  heffe = heff * zabs * pregain;

  return( heffe );

}

//**************************************************************************
//heffb() : �A���e�i�����������߂�֐�(���E�p)
double heffb( i )
     int i;
{

  double length , a;

  //�e�`�����l���̃A���e�i�����������߂�
  if( freq[ i ] <= 164.4 ){
    a = ( log10( ( double )freq[ i ] ) - 1.0 ) * 0.8921 - 1.699;
    length = pow( 10 , a );
  }
  else if( freq[ i ] <= 800.0 ){
    length = 0.243;
  }
  else if( freq[ i ] <= 7407.0 ){
    a = ( log10( ( double )freq[ i ] ) - 3.0 ) * 1.0588 - 0.9208;
    length = pow( 10 , a );
  }
  else if( freq[ i ] <= 10000.0 ){
    length = 1.0;
  }
  else{
    a = ( 4.2504 - log10( ( double )freq[ i ] ) ) * 0.88591 - 0.22185;
    length = pow( 10 , a );
  }

  return( length );

}

//**************************************************************************
//abs_E_dB() : MCA�f�[�^�̒l�����Βl�����߂�֐�(�d�E�p)
void abs_E_dB( E , ws )
     double E[];
     unsigned char ws[];
{
  double dBV;
  int i;
  double abs;
  unsigned char cabs;

  for( i = 0 ; i < NUM_CHANNEL ; i++ ){
    if( E[ i ] == 0 ){
      E[ i ] = 0.0;
    }
    else{
      dBV = 20.0 * log10( E[ i ] ) - 25.0 * (double)ws[ i ] - 48.0 - 20.0;
      abs = pow( 10.0 , dBV / 20.0 ) / heffe( i );
      abs = abs * 1.0e3;
      //�ш敝���l��
      abs = abs / bfact[ i ];
      E[ i ] = abs * abs;
    } 
  }
}

//**************************************************************************
//abs_B_dB() : MCA�f�[�^�̒l�����Βl�����߂�֐�(���E�p)
void abs_B_dB( B , ws )
     double B[];
     unsigned char ws[];
{
  double dBV;
  int i;
  double abs;
  unsigned char cabs;

  double zzz = 120.0 * 3.141592;

  for( i = 0 ; i < NUM_CHANNEL ; i++ ){
    if( B[ i ] == 0 ){
      B[ i ] = 0;
    }
    else{
      if( i <= 9 ){
	dBV = 20.0 * log10( B[ i ] ) - 25.0 * (double)ws[ i ] - 48.0 - 25.0;
      }
      else{
	dBV = 20.0 * log10( B[ i ] ) - 25.0 * (double)ws[ i ] - 48.0 - 30.0;
      }
      abs = pow( 10.0 , dBV / 20.0 ) / heffb( i ) / zzz;
      abs = abs * 1.26 * 1.0e6;
      //�ш敝���l��
      abs = abs / bfact[ i ];
      B[ i ] = abs * abs;
    } 
  }
}

//**************************************************************************
//data_total() : n�b�Ԃ�MCA�f�[�^�̍��v�����߂�֐�
void data_total( total , data )
     double total[];
     double data[];
{
  int i;

  for( i = 0 ; i < NUM_CHANNEL ; i ++ ) {
    total[ i ] += data[ i ];
  }
}

//**************************************************************************
//data_ave() : n�b�Ԃ�MCA�f�[�^�̕��ς����߂�֐�
void data_ave( total , ave , recsp )
     double total[];
     unsigned char ave[];
     int recsp;
{
  int i;
  double rms;

  for( i = 0 ; i < NUM_CHANNEL ; i ++ ) {
    rms = total[ i ] / ( double )recsp;
    rms = sqrt( rms );
    //    rms = 20.0 * log10( rms ) + 120.0;
    //    ave[ i ] = ( unsigned char )rms;
    ave[ i ] = ( unsigned char )( ( 20.0 * log10( rms ) ) + 120.0 );

  }
}

//**************************************************************************
//ave_data() : MCA�f�[�^�𕽋ς���֐�
void ave_data( sec )
     int sec;
{

  int recsp;
  int half_recsp;
  int i , j , k;
  int q;
  long m;
  int i_max;
 
  double max[ NUM_CHANNEL ];
  double ave[ NUM_CHANNEL ];
  unsigned char wida[ NUM_WIDA ];

  int rec_vtl = 0;

  unsigned char ws[ NUM_CHANNEL ];

  double Emax_total[ NUM_CHANNEL ];
  double Eave_total[ NUM_CHANNEL ];
  double Bmax_total[ NUM_CHANNEL ];
  double Bave_total[ NUM_CHANNEL ];

  unsigned char Emax_ave[ NUM_CHANNEL ];
  unsigned char Eave_ave[ NUM_CHANNEL ];
  unsigned char Bmax_ave[ NUM_CHANNEL ];
  unsigned char Bave_ave[ NUM_CHANNEL ];

  double time;

  long hour;
  long min;
  long s;
  long msec;

  int flag;
  int MCAflag = 0;
  int VTLflag = 0;      //���R�[�h�� VIRTUAL �Ȃ��̂��܂܂�Ă�����
  int BDRflag = 0;
  int SMSflag = 0;
  int BitMflag = 0;

  int brHb = 0 , brHa = 0;    //���z�Ȃ� 1

  recsp = SECSPACE * sec;
  half_recsp = recsp / 2;
  i_max = DAYSPACE - half_recsp;

  /**************************************************************************/
  //  half_recsp = 86400;
  //  i_max = 98400;

  //input_Emax( " " , 0 );
  //input_Emax( " " , 10799 );

  for( i =  half_recsp , m = 0 ; i <= i_max ; i += recsp , m ++ ) {

//printf("%d\n",m);
    //if(m==0) input_Emax( " " , m );
    //if(m==10799) input_Emax( Emax_ave , m );
    //else input_Emax( "", m);
    //***** �ϐ��̏����� *****
    rec_vtl = 0;

    MCAflag = 0;
    VTLflag = 0;
    BDRflag = 0;
    SMSflag = 0;
    BitMflag = 0;

    for( k = 0 ; k < NUM_CHANNEL ; k++ ) {
      Emax_total[ k ] = 0;
      Eave_total[ k ] = 0;
      Bmax_total[ k ] = 0;
      Bave_total[ k ] = 0;
    }
    //*************************

    //�S�̂�Virtual�Ŗ��߂�
    //flag=0x01;
    //input_PostGap( flag , m );

    //Epoch ������ Virtual �����ׂ�  
    for( j = ( -1 ) * half_recsp ; j < half_recsp ; j++ ) {
      time = get_Epoch( ( long )( i + j ));
      
      //���R�[�h��2�ȏ�A���ŉ��z�ɂȂ��Ă��邩�𒲂ׂ�
      if( time == EPOCH_PAD ) {
	rec_vtl ++;
	brHa = 1;
      }
      else{
	brHa = 0;
      }
      if( brHb == 1 && brHa == 1 )
	VTLflag = 2;
      brHb = brHa;
    }

    //Epoch
    time = ( ( ( double )m + 1.0 ) * ( double )sec ) - ( double )sec / 2.0 ;
    input_Epoch( time , m );

    //PostGap���擾 , ����
    for( j = ( -1 ) * half_recsp ; j < half_recsp ; j++ ) {
      flag = get_PostGap( ( long )( i + j ) );

      if( MCAflag != FLAG_MCA ) MCAflag = flag & 0x01;
      if( BDRflag != FLAG_BDR ) BDRflag = flag & 0x10;
      if( SMSflag != FLAG_SMS ) SMSflag = flag & 0x20;
      if( BitMflag != FLAG_BitM ) BitMflag = flag & 0x40;
      flag = MCAflag + BDRflag + SMSflag + BitMflag;
    }
    //    printf("%d %d\n",m,flag);
    //�r�b�g���[�gM �Ȃ̂ɁA���R�[�h����ł����z�Ȃ� �m�C�W�[�t���O �𗧂Ă�
    if( BitMflag == FLAG_BitM && rec_vtl != 0 )
      VTLflag = 2;
    
    //PostGap
    flag += VTLflag;
    if((flag & 0x01) == FLAG_MCA) flag=0x01;

    //n �b�Ԃ̃��R�[�h���S�ĉ��z�Ȃ� continue
    if( rec_vtl == recsp ) {
      flag=0x01;
      input_PostGap( flag , m );

      if(m==10799){
        for( q = 0 ; q < NUM_CHANNEL ; q ++ ){
          Emax_ave[q] = 0;
          Eave_ave[q] = 0;
          Bmax_ave[q] = 0;
          Bave_ave[q] = 0;
        }

        input_Emax( Emax_ave , m );
        input_Eave( Eave_ave , m );
        input_Bmax( Bmax_ave , m );
        input_Bave( Bave_ave , m );
      }
      //      read_Emax( m );
      continue;
    } 
    else if(flag == FLAG_MCA){
      input_PostGap( flag , m );

       if(m==10799){
        for( q = 0 ; q < NUM_CHANNEL ; q ++ ){
          Emax_ave[q] = 0;
          Eave_ave[q] = 0;
          Bmax_ave[q] = 0;
          Bave_ave[q] = 0;
        }

        input_Emax( Emax_ave , m );
        input_Eave( Eave_ave , m );
        input_Bmax( Bmax_ave , m );
        input_Bave( Bave_ave , m );
      }
      continue;
    }
    else {
      input_PostGap( flag , m );
    }
    for( j = ( -1 ) * half_recsp ; j < half_recsp ; j++ ) {

      //�d�E�ɂ���
      //E_WIDA���擾
      get_Data( NUM_WIDA , ( long )( i + j ) , E_WIDANum , wida );
      get_wida( wida , ws );
	
      //E_max���擾
      get_EB( NUM_CHANNEL , ( long )( i + j ) , EmaxNum , max );
      abs_E_dB( max , ws );
      data_total( Emax_total , max );
      
      //E_ave���擾
      get_EB( NUM_CHANNEL , ( long )( i + j ) , EaveNum , ave );
      abs_E_dB( ave , ws );
      data_total( Eave_total , ave );
      
      //���E�ɂ���
      //B_WIDA���擾
      get_Data( NUM_WIDA , ( long )( i + j ) , B_WIDANum , wida );
      get_wida( wida , ws );
      
      //B_max���擾
      get_EB( NUM_CHANNEL , ( long )( i + j ) , BmaxNum , max );
      abs_B_dB( max , ws );
      data_total( Bmax_total , max );
      
      //B_ave���擾
      get_EB( NUM_CHANNEL , ( long )( i + j ) , BaveNum , ave );
      abs_B_dB( ave , ws );
      data_total( Bave_total , ave );
    }

    data_ave( Emax_total , Emax_ave , recsp );
    data_ave( Eave_total , Eave_ave , recsp );
    data_ave( Bmax_total , Bmax_ave , recsp );
    data_ave( Bave_total , Bave_ave , recsp );

    input_Emax( Emax_ave , m );
    input_Eave( Eave_ave , m );
    input_Bmax( Bmax_ave , m );
    input_Bave( Bave_ave , m );
    

    //    if( ( i % 100 < 10 ) )printf("continue...%d\n",i);

  }
}

/******************************************************************************
 * Status handler.
 *
 *    average�p�d�l�ɂȂ��Ă܂�!!
 ******************************************************************************/

void StatusHandler (status)
     CDFstatus status;
{
  char message[CDF_ERRTEXT_LEN+1];
  
  if (status < CDF_WARN) {
    printf ("An error has occurred, halting...\n");
    CDFerror (status, message);
    printf ("%s\n", message);
    exit (status);
  }
  else
    if (status < CDF_OK) {
      printf ("Warning, function may not have completed as expected...\n");
      CDFerror (status, message);
      printf ("%s\n", message);
    }
    else
      if (status > CDF_OK) {
	if( status == VIRTUAL ){
	  //	  printf("virtual\n");
	}
	else {
	  printf ("Function completed successfully, but be advised that...\n");
	  CDFerror (status, message);
	  printf ("%s\n", message);
	}
      }       
  return;
}
