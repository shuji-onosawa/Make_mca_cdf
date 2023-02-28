/*
 *    average �p �w�b�_�[�t�@�C��
 *    - ave_bndwdth �t�H���_�[ �ɑΉ����Ă��܂��B
 *
 *    By Y. Ozaki
 *
 *    2006. 1.10
 *
 *    �ŏI�X�V�� : 2006. 1.10
 */

//***** �֐��錾 *****

//****** MCAave.c �Ő錾����Ă���֐�
// Status handler.
void StatusHandler();

//CDF�t�@�C�����I�[�v������
void openCDF( char ymd[][ 5 ] );

//CDF�t�@�C�����N���[�Y����
void closeCDF();

//�ǂ�CDF�t�@�C���̕ϐ�id���Q�b�g����
void get_VarNum();

//�ǂ�CDF�t�@�C���� CDF_UINT1�^�ϐ� �̒l���Q�b�g����֐�
void get_Data( int num , long record , long varNum , unsigned char data[] );

//�ǂ�CDF�t�@�C���� �d�E,���E �ϐ��̒l���Q�b�g����֐�
void get_EB( int num , long record , long varNum , double data[] );

//�ǂ�CDF�t�@�C����Epoch�l���Q�b�g����֐�
double get_Epoch( long record );

//�ǂ�CDF�t�@�C���� PostGap �̒l���Q�b�g����֐�
int get_PostGap( long record );

//�ǂ�CDF�t�@�C���� channel �̒l���Q�b�g����֐�
void get_channel();

//4ch���Ƃɂ����܂��Ă���WIDA��1ch���ɕ�����
void get_wida( unsigned char wida[] , unsigned char ws[] );

//�A���e�i�����������߂�(�d�E�p)
double heffe( int i );

//�A���e�i�����������߂�(���E)
double heffb( int i );

//MCA�f�[�^�̒l�����Βl�����߂�(�d�E�p)
void abs_E_dB( double E[] , unsigned char ws[] );

//MCA�f�[�^�̒l�����Βl�����߂�(���E�p)
void abs_B_dB( double B[] , unsigned char ws[] );

//n�b�Ԃ�MCA�f�[�^�̍��v�����߂�
void data_total( double total[] , double data[] );

//n�b�Ԃ�MCA�f�[�^�̕��ς����߂�
void data_ave( double total[] , unsigned char ave[] , int recsp );

//MCA�f�[�^�𕽋ς���
void ave_data( float sec );

//****** create_cdf.c �Ő錾����Ă���֐�
//���ς����f�[�^��ۑ�����CDF�t�@�C�����쐬����
void createCDF( char ymd[][ 5 ] );

//�K�v��z�ϐ������֐�
void create_zVAR();

//z�ϐ� Epoch �ɒl���i�[����֐�
void input_Epoch( double time , long record );

//z�ϐ� channel �ɒl���i�[����֐�
void input_channel();

//z�ϐ� Emax �ɒl���i�[����֐�
void input_Emax( unsigned char result[] , long record );

//z�ϐ� Eave �ɒl���i�[����֐�
void input_Eave( unsigned char result[] , long record );

//z�ϐ� Bmax �ɒl���i�[����֐�
void input_Bmax( unsigned char result[] , long record );

//z�ϐ� Bave �ɒl���i�[����֐�
void input_Bave( unsigned char result[] , long record );

//input_PostGap() : z�ϐ� PostGap �ɒl���i�[����֐�
void input_PostGap( int flag , long record );
  
//z�ϐ� Emax �ɒl����� �֐�
//void read_Emax( long record );
/*******************************************************************/
//gattr_ave.c �Ő錾���ꂽ�֐�

//gloal attribute �����֐���main
int global_attr( char ymd[][ 5 ] );

//g����������āA����g�G���g���[�ɒl���i�[����֐�
void input_gATTR( char* gAttrName , char* gEntryValue , long gEntryLen , long data_char);

//���݂̔N������m��
void get_date( char ymd[][ 5 ] );

/*******************************************************************/
//vattr_ave.c �Ő錾���ꂽ�֐�

//valiable attribute �����֐���main
int valiable_attr();

//valiable attribute �����֐�
void input_vATTR( char* vAttrName , long* vAttrNum );

//�evaliable attribute���K�v��z�ϐ���,�G���g���[�����֐�
void makeAVG_TYPE();
void makeCATDESC();
void makeDEPEND_0();
void makeDEPEND_1();
void makeDICT_KEY();
void makeDISPLAY_TYPE();
void makeFIELDNAM();
void makeFILLVAL();
void makeFORMAT();
void makeLABLAXIS();
void makeMONOTON();
void makeSCALETYP();
void makeUNITS();
void makeVALIDMAX();
void makeVALIDMIN();
void makeVAR_NOTE();
void makeVAR_TYPE();

//CDF_CHAR�^��z�G���g���[��PUT����֐�
void input_CHARzENTRY( long varNum , long vAttrNum , long zEntryLen , char* zEntryValue );

//CDF_FLOAT�^��z�G���g���[��PUT����֐�
void input_FLOATzENTRY( long varNum , long vAttrNum , long zEntryLen , float* zEntryValue );

//CDF_UINT1�^��z�G���g���[��PUT����֐�
void input_UINT1zENTRY( long varNum , long vAttrNum , long zEntryLen , unsigned char* zEntryValue );

//CDF_UINT4�^��z�G���g���[��PUT����֐�
void input_UINT4zENTRY( long varNum , long vAttrNum , long zEntryLen , int* zEntryValue );

//CDF_EPOCH�^��z�G���g���[��PUT����֐�
void input_EPOCHzENTRY( long varNum , long vAttrNum , long zEntryLen , double* zEntryValue );




//***** 定数宣言 *****
#define OPNAME "./onosawa/data/CDF-H0/"

#define CRNAME "./onosawa/data/CDF-H1_test1/"

#define RESOLUTION       "h"
#define RESOLUTION_LARGE "H"
#define RESOLUTION_NUM    1 
#define VERSION           2

/* open cdf file name length */
// ex : /remote/raid1/usr/y-ozaki/CDFdata/1989/ak_h0_mca_19890311_v01
#define OPEN_LEN    63

/* create cdf file name length */
// ex : /remote/raid1/usr/y-ozaki/CDFdata/ave/1989/ak_h8_mca_19890311_v01.cdf
#define CREATE_LEN    72

//�ŏ��ɃR�}���h���͂����ׂ��萔�̐�
#define MAX_ARGC 5

//1�� = 0.25 �Ԋu�� 345600 ��
#define DAYSPACE    345600

//1�b = 0.25 �Ԋu�� 4 ��
#define SECSPACE    4

//�`�����l����
#define NUM_CHANNEL 16

//WIDA �̃`�����l����
#define NUM_WIDA    4

//status = 1001 ��record�ɓ����Ă�l��virtual
#define VIRTUAL     1001

//Epoch �� PAD�l �� double�^�� 0 �ł��B
#define EPOCH_PAD   0

//PostGap�t���O �̗�����
#define FLAG_MCA    1
#define FLAG_VTL    2
#define FLAG_BDR    16
#define FLAG_SMS    32
#define FLAG_BitM   64

#define         TTL_HOUR        3600
#define         TTL_MIN         60

