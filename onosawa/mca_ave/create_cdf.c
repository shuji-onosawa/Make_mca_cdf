/*    
 *    ���ς���MCA�f�[�^��ۑ�����CDF�t�@�C�����쐬���邽�߂̊e��֐�
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdf.h"
#include "average.h"

//CDF�t�@�C����id
extern CDFid crid;
extern CDFstatus status;

extern char input[ 20 ];

extern float freq[ NUM_CHANNEL ];

extern long f_year;
extern long f_month;
extern long f_day;

//�e�ϐ��̕ϐ�id
long ave_EmxNum;
long ave_EavNum;
long ave_BmxNum;
long ave_BavNum;
long ave_PGapNum;
long ave_EphNum;
long ave_chNum;

//**************************************************************************
//createCDF() : ���ς���MCA�f�[�^��ۑ�����CDF�t�@�C�����쐬����֐�
void createCDF( ymd )
     char ymd[][ 5 ];
{
  int k;

  char *createfile;
  char *rmfile;

  char name_sec[ 3 ];

  long numDims = 0;
  static long dimSizes[1] = {0};
  long encoding = HOST_ENCODING;
  long majority = ROW_MAJOR;
  long format = SINGLE_FILE;

  createfile = ( char * )calloc( CREATE_LEN , sizeof( char ) );

  //***** ��������t�@�C�������쐬
  sprintf( createfile , "%s%s/ak_%s%d_mca_%s%s%s_v0%d" , CRNAME , ymd[ 0 ] , RESOLUTION , RESOLUTION_NUM , ymd[ 0 ] , ymd[ 1 ] , ymd[ 2 ] , VERSION); 

  rmfile = ( char * )calloc( CREATE_LEN , sizeof( char ) );
  sprintf( rmfile , "%s.cdf" , createfile );

  remove( rmfile );       /* ����CDF�����݂���Ȃ�΍폜 */

  printf("createfile =  %s\n" , createfile );

  /***** Create CDF *****/
  status = CDFlib( CREATE_ , CDF_ , createfile , numDims , dimSizes , &crid ,
		   PUT_ , CDF_ENCODING_ , encoding , 
		   CDF_MAJORITY_ , majority , 
		   CDF_FORMAT_ , format ,
		   NULL_ );
  
  if ( status != CDF_OK ) StatusHandler( status );
  free( rmfile );
  free( createfile );

  //***** global���������֐����Ă�
  global_attr( ymd );

  //***** z�ϐ������֐����Ă�
  create_zVAR();

  //***** valiable���������֐����Ă�
  valiable_attr();

}

//**************************************************************************
//create_zVAR() : �K�v��z�ϐ������֐�
void create_zVAR()
{

  //datatype�p�ϐ�
  long data_char = CDF_CHAR;
  long data_uint1 = CDF_UINT1;
  long data_uint4 = CDF_UINT4;
  long data_epoch = CDF_EPOCH;
  long data_float = CDF_FLOAT;


  //nochar�^�͕K��1 ,  char�^�̕ϐ��ɂ�1���������ۑ����Ȃ��̂�1
  long numElements = 1;

  //������1����
  long numDim1 = 1;
  long numDim0 = 0;

  //�����T�C�Y�� 1 �� 16
  long dimSize1[] = { 1 };
  long dimSize16[] = { 16 };

  //���R�[�h�ω��� channel �ȊO��VARY
  long recVary = VARY;
  long recNoVary = NOVARY;

  //�����ω��͑S�ϐ� VARY = �����ɉ����ĕω�����
  long dimVarys[] = { VARY };


  //***** �������݂���CDF�t�@�C����I�� *****
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
  
  //***** �ϐ� Emax ���쐬
  status = CDFlib( CREATE_ , zVAR_ , "Emax" , data_uint1 , numElements , numDim1 , dimSize16 , recVary , dimVarys , &ave_EmxNum ,
		   PUT_ , zVAR_SPARSERECORDS_ , PAD_SPARSERECORDS ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �ϐ� Eave ���쐬
  status = CDFlib( CREATE_ , zVAR_ , "Eave" , data_uint1 , numElements , numDim1 , dimSize16 , recVary , dimVarys , &ave_EavNum ,
		   PUT_ , zVAR_SPARSERECORDS_ , PAD_SPARSERECORDS ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �ϐ� Bmax ���쐬
  status = CDFlib( CREATE_ , zVAR_ , "Bmax" , data_uint1 , numElements , numDim1 , dimSize16 , recVary , dimVarys , &ave_BmxNum ,
		   PUT_ , zVAR_SPARSERECORDS_ , PAD_SPARSERECORDS ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �ϐ� Bave ���쐬
  status = CDFlib( CREATE_ , zVAR_ , "Bave" , data_uint1 , numElements , numDim1 , dimSize16 , recVary , dimVarys , &ave_BavNum ,
		   PUT_ , zVAR_SPARSERECORDS_ , PAD_SPARSERECORDS ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �ϐ� PostGap ���쐬
  status = CDFlib( CREATE_ , zVAR_ , "PostGap" , data_uint4 , numElements , numDim0 , dimSize1 , recVary , dimVarys , &ave_PGapNum ,
		   PUT_ , zVAR_SPARSERECORDS_ , PAD_SPARSERECORDS ,
		   NULL_ );
  
  if ( status != CDF_OK ) StatusHandler( status );
  
  //***** �ϐ� Epoch ���쐬
  status = CDFlib( CREATE_ , zVAR_ , "Epoch" , data_epoch , numElements , numDim0 , dimSize1 , recVary , dimVarys , &ave_EphNum ,
		   PUT_ , zVAR_SPARSERECORDS_ , PAD_SPARSERECORDS ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �ϐ� channel ���쐬
  status = CDFlib( CREATE_ , zVAR_ , "channel" , data_float , numElements , numDim1 , dimSize16 , recNoVary , dimVarys , &ave_chNum ,
		   PUT_ , zVAR_SPARSERECORDS_ , PAD_SPARSERECORDS ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  input_channel();
}
//**************************************************************************
//input_channel() : z�ϐ� channel �ɒl���i�[����֐�

void input_channel()
{

  int i;
  long indices[ 1 ];
  long record = 0;

  float res[ NUM_CHANNEL ];

  get_channel();

  //��CDF�̊ԈႢ�̂��߂̉��}���u
  freq[ 0 ]= 3.16;

  //***** �e�`�����l���̎��g���̒l��ϐ� channel �Ɋi�[����
  for( i = 0 ; i < 16 ; i ++ ) {
    indices[ 0 ] = ( long )i;
    status = CDFlib( SELECT_ , CDF_             , crid ,
		               zVAR_            , ave_chNum ,
		               zVAR_RECNUMBER_  , record ,
		               zVAR_DIMINDICES_ , indices ,
		     PUT_    , zVAR_DATA_       , &freq[ i ] ,
		     NULL_ );
    
    if ( status != CDF_OK ) StatusHandler( status );
  }


  //***** �e�`�����l���̎��g���̒l��ϐ� channel ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  /*
  for( i = 0 ; i < 16 ; i++ ) {
    status = CDFlib( SELECT_ , zVAR_ , ave_chNum ,
		     zVAR_RECNUMBER_ , record ,
		     zVAR_DIMINDICES_ , &indices[ i ] ,
		     GET_ , zVAR_DATA_ , &res[ i ] , 
		     NULL_ );
    
   if ( status != CDF_OK )printf("STATUS=%d\n",status);   
    if ( status != CDF_OK ) StatusHandler( status );
    printf("%d   %f\n",i,res[i]);
  }
  */
}


//**************************************************************************
//input_Epoch() : z�ϐ� Epoch �ɒl���i�[����֐�

void input_Epoch( time , record )
     double time;
     long record;
{
  //�f�[�^�`�F�b�N�p�ϐ�  
  //  double res;

  long year;
  long month;
  long day;
  long hour;
  long min;
  long sec;
  long msec;
  

  msec = ( long )( time * 1000.0 );
  msec = msec % 1000;
  time = ( long )time;
  hour = ( long )( time / TTL_HOUR );
  time = time - ( hour * TTL_HOUR );
  min = ( long )( time /TTL_MIN );
  time = time - ( min * TTL_MIN );
  sec = ( long )time;

  time = computeEPOCH( f_year , f_month , f_day , hour , min , sec , msec );
  
  //***** �����f�[�^��ϐ� Epoch �Ɋi�[����
  status = CDFlib( SELECT_ , CDF_            , crid ,
		             zVAR_           , ave_EphNum ,
		             zVAR_RECNUMBER_ , record ,
		   PUT_    , zVAR_DATA_      , &time ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �����f�[�^��ϐ� Epoch ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  /*
  status = CDFlib( SELECT_ , zVAR_           , ave_EphNum ,
		             zVAR_RECNUMBER_ , record ,
		   GET_    , zVAR_DATA_      , &res , 
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  EPOCHbreakdown( res , &year , &month , &day , &hour , &min , &sec , &msec );

    printf("%d = %d/%d/%d %d:%d:%d.%d\n" , record , year , month , day , hour , min , sec , msec );
  */
}

//**************************************************************************
//input_Emax() : z�ϐ� Emax �ɒl���i�[����֐�
void input_Emax( result , record )
     unsigned char result[];
     long record;
{

  int i;
  long recS;
  long recC;
  long recI;
  long indices[1];
  long counts[1];
  long intervals[1];
  unsigned char tmp[ NUM_CHANNEL ];

  unsigned char res[ NUM_CHANNEL ];

  recS = record;
  recC = 1;
  recI = 1;
  indices[0]=0;
  counts[0]=(long)NUM_CHANNEL;
  intervals[0]=1;
 
  for( i = 0 ; i < NUM_CHANNEL ; i ++ ) {
    tmp[ i ] = result[ i ];
  } 
  //***** �d�E�s�[�N�l�f�[�^��ϐ� Emax �Ɋi�[����
   status = CDFlib( SELECT_ , CDF_              , crid ,
		   zVAR_             , ave_EmxNum ,
		   zVAR_RECNUMBER_   , recS ,
		   zVAR_RECCOUNT_    , recC ,
		   zVAR_RECINTERVAL_ , recI ,
		   zVAR_DIMINDICES_  , indices ,
		   zVAR_DIMCOUNTS_   , counts ,
		   zVAR_DIMINTERVALS_, intervals ,
		   PUT_    , zVAR_HYPERDATA_   , &tmp , 
		   NULL_ );
  if ( status != CDF_OK ) StatusHandler( status ); 

  //***** �d�E�s�[�N�l�f�[�^��ϐ� Emax ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  /*
  for( i = 0 ; i < 16 ; i++ ) {
    indices[ 0 ] = ( long )i;
    status = CDFlib( SELECT_ , zVAR_ , ave_EmxNum ,
		     zVAR_RECNUMBER_ , record ,
		     zVAR_DIMINDICES_ , indices ,
		     GET_ , zVAR_DATA_ , &res[ i ], 
		     NULL_ );

    //printf("STATUS=%d\n",status);   
    if ( status != CDF_OK ) StatusHandler( status );
  }
  printf("\n");
  */
}

//**************************************************************************
//***** - �f�[�^�`�F�b�N�̂���
//read_Emax() : z�ϐ� Emax �ɒl���i�[����֐�
/*
void read_Emax( record )
     long record;
{

  int i;
  long indices[1];
  long counts[1];
  long intervals[1];

  unsigned char res[ NUM_CHANNEL ];

  indices[0]=0;
  counts[0]=(long)NUM_CHANNEL;
  intervals[0]=1;
 
  //***** �d�E�s�[�N�l�f�[�^��ϐ� Emax ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  
  for( i = 0 ; i < 16 ; i++ ) {
    indices[ 0 ] = ( long )i;
    status = CDFlib( SELECT_ , zVAR_ , ave_EmxNum ,
		     zVAR_RECNUMBER_ , record ,
		     zVAR_DIMINDICES_ , indices ,
		     GET_ , zVAR_DATA_ , &res[ i ], 
		     NULL_ );

    printf("STATUS=%d\n",status);   
   }
  printf("\n");
  
}
*/

//**************************************************************************
//input_Eave() : z�ϐ� Eave �ɒl���i�[����֐�

void input_Eave( result , record )
     unsigned char result[];
     long record;
{
  int i;
  long recS;
  long recC;
  long recI;
  long indices[1];
  long counts[1];
  long intervals[1];
  unsigned char tmp[ NUM_CHANNEL ];

  unsigned char res[ NUM_CHANNEL ];

  recS = record;
  recC = 1;
  recI = 1;
  indices[0]=0;
  counts[0]=(long)NUM_CHANNEL;
  intervals[0]=1;
 
  for( i = 0 ; i < NUM_CHANNEL ; i ++ ) {
    tmp[ i ] = result[ i ];
  } 

  //***** �d�E���ϒl�f�[�^��ϐ� Eave �Ɋi�[����
  status = CDFlib( SELECT_ , CDF_              , crid ,
		   zVAR_             , ave_EavNum ,
		   zVAR_RECNUMBER_   , recS ,
		   zVAR_RECCOUNT_    , recC ,
		   zVAR_RECINTERVAL_ , recI ,
		   zVAR_DIMINDICES_  , indices ,
		   zVAR_DIMCOUNTS_   , counts ,
		   zVAR_DIMINTERVALS_, intervals ,
		   PUT_    , zVAR_HYPERDATA_   , &tmp , 
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status ); 
  
  //***** �d�E���ϒl�f�[�^��ϐ� Eave ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  /*
  for( i = 0 ; i < 16 ; i++ ) {
    indices[ 0 ] = ( long )i;
    status = CDFlib( SELECT_ , zVAR_ , ave_EavNum ,
		     zVAR_RECNUMBER_ , record ,
		     zVAR_DIMINDICES_ , indices ,
		     GET_ , zVAR_DATA_ , &res[ i ], 
		     NULL_ );
    if ( status != CDF_OK )printf("STATUS=%d\n",status);   
 
    printf("%d " ,(int)res[ i ] );  
  }
  printf("\n");  
  */
}

//**************************************************************************
//input_Bmax() : z�ϐ� Bmax �ɒl���i�[����֐�

void input_Bmax( result , record )
     unsigned char result[];
     long record;
{
  int i;
  long recS;
  long recC;
  long recI;
  long indices[1];
  long counts[1];
  long intervals[1];
  unsigned char tmp[ NUM_CHANNEL ];

  //  unsigned char res[ NUM_CHANNEL ];

  recS = record;
  recC = 1;
  recI = 1;
  indices[0]=0;
  counts[0]=(long)NUM_CHANNEL;
  intervals[0]=1;
 
  for( i = 0 ; i < NUM_CHANNEL ; i ++ ) {
    tmp[ i ] = result[ i ];
  } 

  //***** ���E�s�[�N�l�f�[�^��ϐ� Bmax �Ɋi�[����
  status = CDFlib( SELECT_ , CDF_              , crid ,
		   zVAR_             , ave_BmxNum ,
		   zVAR_RECNUMBER_   , recS ,
		   zVAR_RECCOUNT_    , recC ,
		   zVAR_RECINTERVAL_ , recI ,
		   zVAR_DIMINDICES_  , indices ,
		   zVAR_DIMCOUNTS_   , counts ,
		   zVAR_DIMINTERVALS_, intervals ,
		   PUT_    , zVAR_HYPERDATA_   , &tmp , 
		   NULL_ );
  if ( status != CDF_OK ) StatusHandler( status ); 

  //***** ���E�s�[�N�l�f�[�^��ϐ� Bmax ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  /*  
  for( i = 0 ; i < 16 ; i++ ) {
    indices[ 0 ] = ( long )i;
    status = CDFlib( SELECT_ , zVAR_ , ave_BmxNum ,
		     zVAR_RECNUMBER_ , record ,
		     zVAR_DIMINDICES_ , indices ,
		     GET_ , zVAR_DATA_ , &res[ i ], 
		     NULL_ );
    
    if ( status != CDF_OK ) StatusHandler( status );
   if ( status != CDF_OK )printf("STATUS=%d\n",status);   
    printf("%d " ,res[ i ] );
  }
  printf("\n");
  */ 
}


//**************************************************************************
//input_Bave() : z�ϐ� Bave �ɒl���i�[����֐�

void input_Bave( result , record )
     unsigned char result[];
     long record;
{
  int i;
  long recS;
  long recC;
  long recI;
  long indices[1];
  long counts[1];
  long intervals[1];
  unsigned char tmp[ NUM_CHANNEL ];

  //  unsigned char res[ NUM_CHANNEL ];

  recS = record;
  recC = 1;
  recI = 1;
  indices[0]=0;
  counts[0]=(long)NUM_CHANNEL;
  intervals[0]=1;
 
  for( i = 0 ; i < NUM_CHANNEL ; i ++ ) {
    tmp[ i ] = result[ i ];
  } 

  //***** ���E���ϒl�f�[�^��ϐ� Bave �Ɋi�[����
  status = CDFlib( SELECT_ , CDF_              , crid ,
		   zVAR_             , ave_BavNum ,
		   zVAR_RECNUMBER_   , recS ,
		   zVAR_RECCOUNT_    , recC ,
		   zVAR_RECINTERVAL_ , recI ,
		   zVAR_DIMINDICES_  , indices ,
		   zVAR_DIMCOUNTS_   , counts ,
		   zVAR_DIMINTERVALS_, intervals ,
		   PUT_    , zVAR_HYPERDATA_   , &tmp , 
		   NULL_ );
  if ( status != CDF_OK ) StatusHandler( status ); 

  //***** ���E���ϒl�f�[�^��ϐ� Bave ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  /* 
  for( i = 0 ; i < 16 ; i++ ) {
    indices[ 0 ] = ( long )i;
    status = CDFlib( SELECT_ , zVAR_ , ave_BavNum ,
		     zVAR_RECNUMBER_ , record ,
		     zVAR_DIMINDICES_ , indices ,
		     GET_ , zVAR_DATA_ , &res[ i ], 
		     NULL_ );
   
    if ( status != CDF_OK ) StatusHandler( status );
    if ( status != CDF_OK )printf("STATUS=%d\n",status);    
    printf("%d " ,res[ i ] );

  }
  printf("\n");
  */ 
}

//**************************************************************************
//input_PostGap() : z�ϐ� PostGap �ɒl���i�[����֐�
//    = 1  : MCA �ϑ��� OFF
//    = 2  : �m�C�W�[�f�[�^����
//    = 16 : BDR(�f�[�^���R�[�_�[) ON
//    = 32 : SMS(���q�ϑ���) ON
//    = 64 : bitrate M

void input_PostGap( flag , record )
     int flag;
     long record;
{

    int res;

  //***** �|�X�g�M���b�v�t���O�f�[�^��ϐ� PostGap �Ɋi�[����
  status = CDFlib( SELECT_ , CDF_            , crid ,
		             zVAR_           , ave_PGapNum ,
		             zVAR_RECNUMBER_ , record ,
		   PUT_ , zVAR_DATA_ , &flag ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �|�X�g�M���b�v�t���O�f�[�^��ϐ� PostGap ������o��
  //***** - �f�[�^�`�F�b�N�̂���
  /*
  status = CDFlib( SELECT_ , zVAR_ , ave_PGapNum ,
		             zVAR_RECNUMBER_ , record ,
			     GET_ , zVAR_DATA_ , &res, 
			     NULL_ );

   if ( status != CDF_OK )printf("STATUS=%d\n",status);   
  if ( status != CDF_OK ) StatusHandler( status );

  printf("%d %d postgap = %d\n",ave_PGapNum,record, res );
  */
}
