/*
 *    MCA�pCDF�t�@�C���� n�b����CDF�t�@�C���p valiable Attribute�����v���O����
 *    - valiable Attribute �� 16��� ����܂��B
 *
 *    By Y. Ozaki     2005.12.14
 *
 *    �ŏI�X�V�� : 2005.12.14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cdf.h"
#include "average.h"

//**************************************************************************
//valiable_attr() : valiable attribute �����֐���main

extern CDFid crid;
extern CDFstatus status;

//�e�ϐ��̕ϐ�id
extern long ave_EmxNum;
extern long ave_EavNum;
extern long ave_BmxNum;
extern long ave_BavNum;
extern long ave_PGapNum;
extern long ave_EphNum;
extern long ave_chNum;

int valiable_attr()
{

  //===== CATDESC ==================================================
  makeAVG_TYPE();

  //===== CATDESC ==================================================
  makeCATDESC();

  //===== DEPEND_0 =================================================
  makeDEPEND_0();

  //===== DEPEND_1 =================================================
  makeDEPEND_1();

  //===== DICT_KEY =================================================
  makeDICT_KEY();

  //===== DISPLAY_TYPE =============================================
  makeDISPLAY_TYPE();

  //===== FIELDNAM =================================================
  makeFIELDNAM();

  //===== FILLVAL ==================================================
  makeFILLVAL();

  //===== FORMAT ===================================================
  makeFORMAT();

  //===== LABLAXIS =================================================
  makeLABLAXIS();

  //===== MONOTON ==================================================
  makeMONOTON();

  //===== SCALETYP =================================================
  makeSCALETYP();

  //===== UNITS ====================================================
  makeUNITS();

  //===== VALIDMAX =================================================
  makeVALIDMAX();

  //===== VALIDMIN =================================================
  makeVALIDMIN();

  //===== VAR_NOTE =================================================
  makeVAR_NOTE();

  //===== VAR_TYPE =================================================
  makeVAR_TYPE();
   
}

//**************************************************************************
//makeAVG_TYPE() : AVG_TYPE���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeAVG_TYPE()
{

  long Avg_typeNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "AVG_TYPE" , &Avg_typeNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "log" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "log" );

  input_CHARzENTRY( ave_EmxNum , Avg_typeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "log" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "log" );

  input_CHARzENTRY( ave_EavNum , Avg_typeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "log" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "log" );

  input_CHARzENTRY( ave_BmxNum , Avg_typeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "log" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "log" );

  input_CHARzENTRY( ave_BavNum , Avg_typeNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}
//**************************************************************************
//makeCATDESC() : CATDESC���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeCATDESC()
{

  long CatdescNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "CATDESC" , &CatdescNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "Electric field maximum intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Electric field maximum intensity" );

  input_CHARzENTRY( ave_EmxNum , CatdescNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "Electric field average intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Electric field average intensity" );

  input_CHARzENTRY( ave_EavNum , CatdescNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "Magnetic field maximum intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Magnetic field maximum intensity" );

  input_CHARzENTRY( ave_BmxNum , CatdescNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "Magnetic field average intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Magnetic field average intensity" );

  input_CHARzENTRY( ave_BavNum , CatdescNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "Time recorded in the original raw data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Time recorded in the original raw data" );

  input_CHARzENTRY( ave_EphNum , CatdescNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "Frequency" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Frequency" );

  input_CHARzENTRY( ave_chNum , CatdescNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "Post Gap Quality Flag" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Post Gap Quality Flag" );

  input_CHARzENTRY( ave_PGapNum , CatdescNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeDEPEND_0() : DEPEND_0���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeDEPEND_0()
{

  long DEPEND0Num;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "DEPEND_0" , &DEPEND0Num );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "Epoch" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Epoch" );

  input_CHARzENTRY( ave_EmxNum , DEPEND0Num , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "Epoch" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Epoch" );

  input_CHARzENTRY( ave_EavNum , DEPEND0Num , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "Epoch" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Epoch" );

  input_CHARzENTRY( ave_BmxNum , DEPEND0Num , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "Epoch" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Epoch" );

  input_CHARzENTRY( ave_BavNum , DEPEND0Num , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "Epoch" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Epoch" );

  input_CHARzENTRY( ave_PGapNum , DEPEND0Num , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================
}


//**************************************************************************
//makeDEPEND_1() : DEPEND_1���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeDEPEND_1()
{

  long DEPEND1Num;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "DEPEND_1" , &DEPEND1Num );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "channel" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "channel" );

  input_CHARzENTRY( ave_EmxNum , DEPEND1Num , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "channel" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "channel" );

  input_CHARzENTRY( ave_EavNum , DEPEND1Num , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "channel" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "channel" );

  input_CHARzENTRY( ave_BmxNum , DEPEND1Num , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "channel" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "channel" );

  input_CHARzENTRY( ave_BavNum , DEPEND1Num , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeDICT_KEY() : DICT_KEY���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeDICT_KEY()
{

  long DictkeyNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "DICT_KEY" , &DictkeyNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "ELECTRIC_FIELD > antenna" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "ELECTRIC_FIELD > antenna" );

  input_CHARzENTRY( ave_EmxNum , DictkeyNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "ELECTRIC_FIELD > antenna" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "ELECTRIC_FIELD > antenna" );

  input_CHARzENTRY( ave_EavNum , DictkeyNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "MAGNETIC_FIELD > antenna" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "MAGNETIC_FIELD > antenna" );

  input_CHARzENTRY( ave_BmxNum , DictkeyNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "MAGNETIC_FIELD > antenna" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "MAGNETIC_FIELD > antenna" );

  input_CHARzENTRY( ave_BavNum , DictkeyNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "time > Epoch" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "time > Epoch" );

  input_CHARzENTRY( ave_EphNum , DictkeyNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "FREQUENCY > channel" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "FREQUENCY > channel" );

  input_CHARzENTRY( ave_chNum , DictkeyNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "FLAG > post_gap" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "FLAG > post_gap" );

  input_CHARzENTRY( ave_PGapNum , DictkeyNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeDISPLAY_TYPE() : DISPLAY_TYPE���������A�K�v��z�ϐ��ɃG���g���[�����֐�
void makeDISPLAY_TYPE()
{

  long DisplaytypeNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "DISPLAY_TYPE" , &DisplaytypeNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "time_series" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "time_series" );

  input_CHARzENTRY( ave_EmxNum ,  DisplaytypeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "time_series" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "time_series" );

  input_CHARzENTRY( ave_EavNum , DisplaytypeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "time_series" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "time_series" );

  input_CHARzENTRY( ave_BmxNum , DisplaytypeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "time_series" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "time_series" );

  input_CHARzENTRY( ave_BavNum , DisplaytypeNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "time_series" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "time_series" );

  input_CHARzENTRY( ave_PGapNum , DisplaytypeNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeFIELDNAM() : FIELDNAM���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeFIELDNAM()
{

  long FieldnamNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "FIELDNAM" , &FieldnamNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "electric field maximum intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "electric field maximum intensity" );

  input_CHARzENTRY( ave_EmxNum , FieldnamNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "electric field average intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "electric field average intensity" );

  input_CHARzENTRY( ave_EavNum , FieldnamNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "magnetic field maximum intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "magnetic field maximum intensity" );

  input_CHARzENTRY( ave_BmxNum , FieldnamNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "magnetic field average intensity" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "magnetic field average intensity" );

  input_CHARzENTRY( ave_BavNum , FieldnamNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "Time since 0 AD" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Time since 0 AD" );

  input_CHARzENTRY( ave_EphNum , FieldnamNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "channel" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "channel" );

  input_CHARzENTRY( ave_chNum ,FieldnamNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "Post Gap Quality Flag" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Post Gap Quality Flag" );

  input_CHARzENTRY( ave_PGapNum ,FieldnamNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeFILLVAL() : FILLVAL���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeFILLVAL()
{

  long FillvalNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 1;            // ������镶����̕�����

  unsigned char zEntryValue[ 1 ];            // ������镶����������z��
  double EpochValue[ 1 ];
  float channelValue[ 1 ];
  int PostgapValue[ 1 ];

  //***** v���������֐����Ă�
  input_vATTR( "FILLVAL" , &FillvalNum );

  //===== Emax =====================================================
  zEntryLen = 1;
  zEntryValue[ 0 ] = ( unsigned char )255;

  input_UINT1zENTRY( ave_EmxNum , FillvalNum , zEntryLen , zEntryValue );  
  //================================================================

  //===== Eave =====================================================
  //  zEntryLen = 1;
  //  zEntryValue[ 0 ] = ( unsigned char )255;

  input_UINT1zENTRY( ave_EavNum , FillvalNum , zEntryLen , zEntryValue );  
  //================================================================

  //===== Bmax =====================================================
  //  zEntryLen = 1;
  //  zEntryValue[ 0 ] = ( unsigned char )255;

  input_UINT1zENTRY( ave_BmxNum , FillvalNum , zEntryLen , zEntryValue );  
  //================================================================

  //===== Bave =====================================================
  //  zEntryLen = 1;
  //  zEntryValue[ 0 ] = ( unsigned char )255;

  input_UINT1zENTRY( ave_BavNum , FillvalNum , zEntryLen , zEntryValue );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = 1;

  EpochValue[ 0 ] = 0.0;

  input_EPOCHzENTRY( ave_EphNum , FillvalNum , zEntryLen , EpochValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = 1;
  channelValue[ 0 ] = -1.0e15;

  input_FLOATzENTRY( ave_chNum , FillvalNum , zEntryLen , channelValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = 1;
  PostgapValue[ 0 ] = 0;

  input_UINT4zENTRY( ave_PGapNum , FillvalNum , zEntryLen , PostgapValue );
  //================================================================
}

//**************************************************************************
//makeFORMAT() : FORMAT���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeFORMAT()
{

  long FormatNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "FORMAT" , &FormatNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "%3d" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "%3d" );

  input_CHARzENTRY( ave_EmxNum , FormatNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "%3d" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "%3d" );

  input_CHARzENTRY( ave_EavNum , FormatNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "%3d" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "%3d" );

  input_CHARzENTRY( ave_BmxNum , FormatNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "%3d" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "%3d" );

  input_CHARzENTRY( ave_BavNum , FormatNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "%5.2f" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "%5.2f" );

  input_CHARzENTRY( ave_chNum , FormatNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "%3d" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "%3d" );

  input_CHARzENTRY( ave_PGapNum , FormatNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeLABLAXIS() : LABLAXIS���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeLABLAXIS()
{

  long LablaxisNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "LABLAXIS" , &LablaxisNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "E field" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "E field" );

  input_CHARzENTRY( ave_EmxNum , LablaxisNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "E field" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "E field" );

  input_CHARzENTRY( ave_EavNum , LablaxisNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "B field" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "B field" );

  input_CHARzENTRY( ave_BmxNum , LablaxisNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "B field" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "B field" );

  input_CHARzENTRY( ave_BavNum , LablaxisNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "Epoch" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Epoch" );

  input_CHARzENTRY( ave_EphNum , LablaxisNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "frequency" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "frequency" );

  input_CHARzENTRY( ave_chNum , LablaxisNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "PostGap" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "PostGap" );

  input_CHARzENTRY( ave_PGapNum , LablaxisNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================
}

//**************************************************************************
//makeMONOTON() : MONOTON���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeMONOTON()
{

  long MonotonNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "MONOTON" , &MonotonNum );

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "INCREASE" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "INCREASE" );

  input_CHARzENTRY( ave_EphNum , MonotonNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "INCREASE" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "INCREASE" );

  input_CHARzENTRY( ave_chNum , MonotonNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeSCALETYP() : SCALETYP���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeSCALETYP()
{

  long ScaletypNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "SCALETYP" , &ScaletypNum );

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "linear" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "linear" );

  input_CHARzENTRY( ave_EphNum , ScaletypNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "log" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "log" );

  input_CHARzENTRY( ave_chNum , ScaletypNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}


//**************************************************************************
//makeUNITS() : UNITS���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeUNITS()
{

  long UnitsNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "UNITS" , &UnitsNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "dB" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_EmxNum , UnitsNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "dB" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_EavNum , UnitsNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "dB" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_BmxNum , UnitsNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "dB" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_BavNum , UnitsNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "s" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "s" );

  input_CHARzENTRY( ave_EphNum , UnitsNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "Hz" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "Hz" );

  input_CHARzENTRY( ave_chNum , UnitsNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

}

//**************************************************************************
//makeVALIDMAX() : VALIDMAX���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeVALIDMAX()
{

  long ValidmaxNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  unsigned char max255[ 1 ];
  double EpochValue[ 1 ];
  float channelValue[ 1 ];
  int PostgapValue[ 1 ];


  //***** v���������֐����Ă�
  input_vATTR( "VALIDMAX" , &ValidmaxNum );

  //===== Emax =====================================================
  zEntryLen = 1L;
  max255[ 0 ] = ( char )255;

  input_UINT1zENTRY( ave_EmxNum , ValidmaxNum , zEntryLen , max255 );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = 1L;
  max255[ 0 ] = ( char )255;

  input_UINT1zENTRY( ave_EavNum , ValidmaxNum , zEntryLen , max255 );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = 1L;
  max255[ 0 ] = ( char )255;

  input_UINT1zENTRY( ave_BmxNum , ValidmaxNum , zEntryLen , max255 );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = 1L;
  max255[ 0 ] = ( char )255;

  input_UINT1zENTRY( ave_BavNum , ValidmaxNum , zEntryLen , max255 );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = 1;

  EpochValue[ 0 ] = computeEPOCH( 2015L , 12L , 31L , 23L , 59L , 59L , 999L );

  input_EPOCHzENTRY( ave_EphNum , ValidmaxNum , zEntryLen , EpochValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = 1;
  channelValue[ 0 ] = 17800.0;

  input_FLOATzENTRY( ave_chNum , ValidmaxNum , zEntryLen , channelValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = 1;
  PostgapValue[ 0 ] = 243;

  input_UINT4zENTRY( ave_PGapNum , ValidmaxNum , zEntryLen , PostgapValue );
  //================================================================

}

//**************************************************************************
//makeVALIDMIN() : VALIDMIN���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeVALIDMIN()
{

  long ValidminNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  unsigned char min0[ 1 ];
  double EpochValue[ 1 ];
  float channelValue[ 1 ];
  int PostgapValue[ 1 ];


  //***** v���������֐����Ă�
  input_vATTR( "VALIDMIN" , &ValidminNum );

  //===== Emax =====================================================
  zEntryLen = 1L;
  min0[ 0 ] = ( char )0;

  input_UINT1zENTRY( ave_EmxNum , ValidminNum , zEntryLen , min0 );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = 1L;
  min0[ 0 ] = ( char )0;

  input_UINT1zENTRY( ave_EavNum , ValidminNum , zEntryLen , min0 );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = 1L;
  min0[ 0 ] = ( char )0;

  input_UINT1zENTRY( ave_BmxNum , ValidminNum , zEntryLen , min0 );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = 1L;
  min0[ 0 ] = ( char )0;

  input_UINT1zENTRY( ave_BavNum , ValidminNum , zEntryLen , min0 );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = 1;

  EpochValue[ 0 ] = computeEPOCH( 1989L , 1L , 1L , 0L , 0L , 0L , 0L );

  input_EPOCHzENTRY( ave_EphNum , ValidminNum , zEntryLen , EpochValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = 1;
  channelValue[ 0 ] = 3.16;

  input_FLOATzENTRY( ave_chNum , ValidminNum , zEntryLen , channelValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = 1;
  PostgapValue[ 0 ] = 0;

  input_UINT4zENTRY( ave_PGapNum , ValidminNum , zEntryLen , PostgapValue );
  //================================================================
}

//**************************************************************************
//makeVAR_NOTE() : VAR_NOTE���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeVAR_NOTE()
{

  long VarnoteNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "VAR_NOTE" , &VarnoteNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "dB" );

  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );

  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_EmxNum , VarnoteNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "dB" );

  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );

  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_EavNum , VarnoteNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "dB" );

  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );

  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_BmxNum , VarnoteNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "dB" );

  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );

  strcpy( zEntryValue , "dB" );

  input_CHARzENTRY( ave_BavNum , VarnoteNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "The Quality flag of MCA data.\n 0  : normal\n 1  : MCA off\n 2  : data is noisy\n 16  : BDR on\n 32  : SMS on\n 64  : Bitrate of date is 'M'\n 128 : PWS on\n" );

  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );

  strcpy( zEntryValue , "The Quality flag of MCA data.\n 0  : normal\n 1  : MCA off\n 2  : data is noisy\n 16  : BDR on\n 32  : SMS on\n 64  : Bitrate of date is 'M'\n 128 : PWS on\n" );

  input_CHARzENTRY( ave_PGapNum , VarnoteNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================
}

//**************************************************************************
//makeVAR_TYPE() : VAR_TYPE���������A�K�v��z�ϐ��ɃG���g���[�����֐�

void makeVAR_TYPE()
{

  long VartypeNum;

  //z�G���g���[�ɕK�v�ȕϐ�
  long zEntryLen = 0;            // ������镶����̕�����
  char* zEntryValue;             // ������镶����������z��

  //***** v���������֐����Ă�
  input_vATTR( "VAR_TYPE" , &VartypeNum );

  //===== Emax =====================================================
  zEntryLen = ( long )strlen( "data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "data" );

  input_CHARzENTRY( ave_EmxNum , VartypeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Eave =====================================================
  zEntryLen = ( long )strlen( "data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "data" );

  input_CHARzENTRY( ave_EavNum , VartypeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bmax =====================================================
  zEntryLen = ( long )strlen( "data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "data" );

  input_CHARzENTRY( ave_BmxNum , VartypeNum , zEntryLen , zEntryValue );  
  free( zEntryValue );
  //================================================================

  //===== Bave =====================================================
  zEntryLen = ( long )strlen( "data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "data" );

  input_CHARzENTRY( ave_BavNum , VartypeNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== Epoch ====================================================
  zEntryLen = ( long )strlen( "support_data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "support_data" );

  input_CHARzENTRY( ave_EphNum , VartypeNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== channel ==================================================
  zEntryLen = ( long )strlen( "support_data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "support_data" );

  input_CHARzENTRY( ave_chNum , VartypeNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================

  //===== PostGap ==================================================
  zEntryLen = ( long )strlen( "data" );
  zEntryValue = ( char * )calloc( zEntryLen + 1 , sizeof( char ) );
  strcpy( zEntryValue , "data" );

  input_CHARzENTRY( ave_PGapNum , VartypeNum , zEntryLen , zEntryValue );
  free( zEntryValue );
  //================================================================
}

//***************************************************************
//input_vATTR() : v���������֐�

void input_vATTR( vAttrName , vAttrNum )
     char* vAttrName;
     long* vAttrNum;
{

  //v��������邽�߂̕ϐ�
  long v_scope = VARIABLE_SCOPE;

  //***** �������݂���CDF�t�@�C����I��
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** g���������
  status = CDFlib( CREATE_ , ATTR_ , vAttrName , v_scope , vAttrNum ,
		   NULL_ );
  
  if ( status != CDF_OK ) StatusHandler( status );

}

//***************************************************************
//input_CHARzENTRY() : CHAR�^��z�G���g���[���i�[����֐�

void input_CHARzENTRY( zEntryNum , vAttrNum , zEntryLen , zEntryValue )
     long  zEntryNum;
     long  vAttrNum;
     long  zEntryLen;               // ������镶����̕�����
     char* zEntryValue;             // ������镶����������z��
{

  char res[ 1000 ];
  
  //***** �������݂���CDF�t�@�C����I��
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �������݂���z�ϐ�,v������I�����āAz�G���g���[�Ƀf�[�^��������
  status = CDFlib(  SELECT_ , ATTR_ , vAttrNum ,
                              zENTRY_ , zEntryNum ,
                    PUT_ , zENTRY_DATA_ , CDF_CHAR , zEntryLen , zEntryValue ,
		    //                    GET_ , zENTRY_DATA_ , res ,
                    NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
  
  //  printf("%s \n",res);

}

//***************************************************************
//input_FLOATzENTRY() : FLOAT�^��z�G���g���[���i�[����֐�

void input_FLOATzENTRY( zEntryNum , vAttrNum , zEntryLen , zEntryValue )
     long  zEntryNum;
     long  vAttrNum;
     long  zEntryLen;               // ������镶����̕�����
     float* zEntryValue;             // ������镶����������z��
{

  float res[ 1 ];
  
  //***** �������݂���CDF�t�@�C����I��
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �������݂���z�ϐ�,v������I�����āAz�G���g���[�Ƀf�[�^��������
  status = CDFlib(  SELECT_ , ATTR_ , vAttrNum ,
                              zENTRY_ , zEntryNum ,
                    PUT_ , zENTRY_DATA_ , CDF_FLOAT , zEntryLen , zEntryValue ,
		    //                    GET_ , zENTRY_DATA_ , res ,
                    NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
  
  //  printf("%f \n",res[ 0 ] );

}

//***************************************************************
//input_UINT1zENTRY() : UINT1�^��z�G���g���[���i�[����֐�

void input_UINT1zENTRY( zEntryNum , vAttrNum , zEntryLen , zEntryValue )
     long  zEntryNum;
     long  vAttrNum;
     long  zEntryLen;               // ������镶����̕�����
     unsigned char* zEntryValue;             // ������镶����������z��
{

  unsigned char res[ 1 ];
  
  //***** �������݂���CDF�t�@�C����I��
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �������݂���z�ϐ�,v������I�����āAz�G���g���[�Ƀf�[�^��������
  status = CDFlib(  SELECT_ , ATTR_ , vAttrNum ,
                              zENTRY_ , zEntryNum ,
                    PUT_ , zENTRY_DATA_ , CDF_UINT1 , zEntryLen , zEntryValue ,
		    //                    GET_ , zENTRY_DATA_ , res ,
                    NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
  
  //  printf("%d \n",res[ 0 ] );

}

//***************************************************************
//input_UINT4zENTRY() : UINT4�^��z�G���g���[���i�[����֐�

void input_UINT4zENTRY( zEntryNum , vAttrNum , zEntryLen , zEntryValue )
     long  zEntryNum;
     long  vAttrNum;
     long  zEntryLen;               // ������镶����̕�����
     int*  zEntryValue;             // ������镶����������z��
{

  int res[ 1 ];
  
  //***** �������݂���CDF�t�@�C����I��
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �������݂���z�ϐ�,v������I�����āAz�G���g���[�Ƀf�[�^��������
  status = CDFlib(  SELECT_ , ATTR_ , vAttrNum ,
                              zENTRY_ , zEntryNum ,
                    PUT_ , zENTRY_DATA_ , CDF_UINT4 , zEntryLen , zEntryValue ,
		    //                    GET_ , zENTRY_DATA_ , res ,
                    NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );
  
  //  printf("%d \n",res[ 0 ] );

}

//***************************************************************
//input_EPOCHzENTRY() : EPOCH�^��z�G���g���[���i�[����֐�

void input_EPOCHzENTRY( zEntryNum , vAttrNum , zEntryLen , zEntryValue )
     long  zEntryNum;
     long  vAttrNum;
     long  zEntryLen;               // ������镶����̕�����
     double* zEntryValue;             // ������镶����������z��
{

  double res;

  long year;
  long month;
  long day;
  long hour;
  long min;
  long sec;
  long msec;
  
  
  //***** �������݂���CDF�t�@�C����I��
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** �������݂���z�ϐ�,v������I�����āAz�G���g���[�Ƀf�[�^��������
  status = CDFlib(  SELECT_ , ATTR_ , vAttrNum ,
                              zENTRY_ , zEntryNum ,
                    PUT_ , zENTRY_DATA_ , CDF_EPOCH , zEntryLen , zEntryValue ,
		    //                    GET_ , zENTRY_DATA_ , &res ,
                    NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //  EPOCHbreakdown( res , &year , &month , &day , &hour , &min , &sec , &msec );

  //  printf("%d/%d/%d %d:%d:%d.%d\n" , year , month , day , hour , min , sec , msec );

}

