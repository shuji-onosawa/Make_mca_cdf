/*
 *    MCA�pCDF�t�@�C���� n�b����CDF�t�@�C�� ��global Attribute�����v���O����
 *    - global Attribute �� 20�� ����܂��B
 *
 *    By Y. Ozaki     2005.11.04
 *
 *    �ŏI�X�V�� : 2005.11.04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cdf.h"
#include "average.h"
//**************************************************************************
//global_attr() : gloal attribute �����֐���main

extern CDFid crid;
extern CDFstatus status;

int global_attr( ymd )
     char ymd[][ 5 ];
{

  char gAttrName[ 30 ];

  char date[ 3 ][ 5 ];
  int i;

  //g�G���g���[�ɕK�v�ȕϐ�
  long data_char = CDF_CHAR;     // �f�[�^�^
  long gEntryLen = 0;            // ������镶����̕�����
  char gEntryValue[ 150 ] = "";  // ������镶����������z��
  char* Rule;                    // Rules_of_use �p������镶����������z��
                                 // - ����������������

  //===== Acknowledgement =========================================

  //***** g��������gAttrName[]�ɑ��
  strcpy( gAttrName , "Acknowledgement" );

  //***** g�G���g���[��gEntryValue[]�ɑ��
  strcpy( gEntryValue , "AKEBONO VLF-MCA data were provided by Akebono VLF team through the data archive system at Kanazawa University in Japan." );

  //***** ������镶����̕������𒲂ׂ�
  gEntryLen = ( long )strlen( gEntryValue );

  if( gEntryLen > 150 ) printf("over string!!\n");

  //***** g����������āA����g�G���g���[�ɒl���i�[����֐����Ă�
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );

  //================================================================

  //===== ADID_ref ==========================================
  strcpy( gAttrName , "ADID_ref" );
  strcpy( gEntryValue , "NSSD0241 " );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Data_type ================================================

  //***** g��������gAttrName[]�ɑ��
  strcpy( gAttrName , "Data_type" );

  //***** g�G���g���[��gEntryValue[]�ɑ��
  sprintf( gEntryValue , "%s%d > High Resolution data" , RESOLUTION_LARGE , RESOLUTION_NUM );

  //***** ������镶����̕������𒲂ׂ�
  gEntryLen = ( long )strlen( gEntryValue );

  if( gEntryLen > 150 ) printf("over string!!\n");

  //***** g����������āA����g�G���g���[�ɒl���i�[����֐����Ă�
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );

  //================================================================

  //===== Data_version =============================================
  strcpy( gAttrName , "Data_version" );

  //***** CDF�t�@�C���쐬��(�����̓��t)�𒲂ׂ�

  sprintf( gEntryValue , "%d" , VERSION ); 

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Descriptor ===============================================
  strcpy( gAttrName , "Descriptor" );
  strcpy( gEntryValue , "MCA > multi channel analyzer" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Discipline ===============================================
  strcpy( gAttrName , "Discipline" );
  strcpy( gEntryValue , "Space Physics > Magnetospheric Science" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 100 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Generated_by =============================================
  strcpy( gAttrName , "Generated_by" );
  strcpy( gEntryValue , "KANAZAWA University" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Generation_date ==========================================
  strcpy( gAttrName , "Generation_date" );

  //***** CDF�t�@�C���쐬��(�����̓��t)�𒲂ׂ�
  get_date( date );

  strcpy( gEntryValue , date[ 0 ]);
  for( i = 1 ; i < 3 ; i ++ ) {
    strcat( gEntryValue , date[ i ] );
  }

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Instrument_type ==========================================
  strcpy( gAttrName , "Instrument_type" );
  strcpy( gEntryValue , "Radio and Plasma Waves(space)" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Logical_file_id ==========================================
  strcpy( gAttrName , "Logical_file_id" );

  sprintf( gEntryValue , "AK_%s%d_MCA_%s%s%s_V0%d" , RESOLUTION_LARGE , RESOLUTION_NUM , ymd[ 0 ] , ymd[ 1 ] , ymd[ 2 ] , VERSION);

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Logical_source ===========================================
  strcpy( gAttrName , "Logical_source" );

  sprintf( gEntryValue , "AK_%s%d_MCA" , RESOLUTION_LARGE , RESOLUTION_NUM );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Logical_source_description ===============================
  strcpy( gAttrName , "Logical_source_description" );
  strcpy( gEntryValue , "Akebono Radio and Plasma Waves High Resolution data" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Mission_group ============================================
  strcpy( gAttrName , "Mission_group" );
  strcpy( gEntryValue , "Akebono" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== MODS =====================================================
  strcpy( gAttrName , "MODS" );
  strcpy( gEntryValue , " " );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== PI_affiliation ===========================================
  strcpy( gAttrName , "PI_affiliation" );
  strcpy( gEntryValue , "KANAZAWA University" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== PI_name ==================================================
  strcpy( gAttrName , "PI_name" );
  strcpy( gEntryValue , "I. Nagano" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Project ==================================================
  strcpy( gAttrName , "Project" );
  strcpy( gEntryValue , " " );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== Rules_of_use =============================================
  strcpy( gAttrName , "Rules_of_use" );

  Rule = ( char * )calloc( 1000 , sizeof( char ) );

  strcpy( Rule , " In order to confirm the reliability of the data, you are requested to contact the VLF PI, Prof. Isamu Nagano before using the VLF-MCA data in oral/poster presentations. In the publishment, you should contact to the VLF PI and contact person before the submission for the confirmation of the principle of authorship/aknowledgement. You are also requested to send reprints to AKEBONO Project Office and the VLF PI:\n" );
  strcat( Rule , "\nAKEBONO Project Office:\n  Prof. Toshifumi Mukai (Project Scientist),\n  Institute of Space and Astronautical Science,\n  3-1-1 Yoshinodai, Sagamihara, Kanagawa 229-8510, Japan\n  E-mail: mukai@stp.isas.jaxa.jp\n  FAX: +81-42-759-8456\n");
  strcat( Rule , "\nVLF PI:\n  Prof. Isamu Nagano,\n  Kanazawa University,\n  Kakuma, Kanazawa 920-1192, Japan\n  E-mail: nagano@is.t.kanazawa-u.ac.jp\n  FAX: +81-76-234-4859\n");
  strcat( Rule , "\nFor further information, please contact with:\n  Dr. Yoshiya Kasahara\n  Kanazawa University,\n  Kakuma, Kanazawa 920-1192, Japan\n  E-mail: kasahara@is.t.kanazawa-u.ac.jp\n  FAX: +81-76-234-4952\n");

  gEntryLen = ( long )strlen( Rule );
  if( gEntryLen > 1000 ) printf("over string!!\n");
  input_gATTR( gAttrName , Rule , gEntryLen , data_char );

  free( Rule );
  //================================================================

  //===== source_name ==============================================
  strcpy( gAttrName , "source_name" );
  strcpy( gEntryValue , "Akebono > Akebono satellite" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== TEXT =====================================================
  strcpy( gAttrName , "TEXT" );

  Rule = ( char * )calloc( 250 , sizeof( char ) );

  sprintf( Rule , "Kimura, I., K. Hashimoto, I. Nagano, T. Okada, M. Yamamoto, T. Yoshino, H. Matsumoto, M. Ejiri, and K. Hayashi,\nVLF observations by the Akebono (EXOS-D) satellite,\nJ. Geomagn. Geoelectr., 42(4), pp.459-478, 1990\n" );

  gEntryLen = ( long )strlen( Rule );
  if( gEntryLen > 250 ) printf("over string!!\n");
  input_gATTR( gAttrName , Rule , gEntryLen , data_char );

  free( Rule );
  //================================================================

  //===== Time_resolution ==========================================
  strcpy( gAttrName , "Time_resolution" );

  sprintf( gEntryValue , "%ss" , ymd[ 3 ] );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== TITLE ====================================================
  strcpy( gAttrName , "TITLE" );
  strcpy( gEntryValue , "Akebono MCA High resolution data" );

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== ST  ==========================================
  strcpy( gAttrName , "Start_time" );

  sprintf( gEntryValue , "%s_%s/%s_0:0:0:0" , ymd[ 0 ] , ymd[ 1 ] , ymd[ 2 ]);

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //================================================================

  //===== ET  ==========================================
  strcpy( gAttrName , "End_time" );

  sprintf( gEntryValue , "%s_%s/%s_23:59:59:999" , ymd[ 0 ] , ymd[ 1 ] , ymd[ 2 ]);

  gEntryLen = ( long )strlen( gEntryValue );
  if( gEntryLen > 150 ) printf("over string!!\n");
  input_gATTR( gAttrName , gEntryValue , gEntryLen , data_char );
  //===============================================================
}


//***************************************************************
//input_gATTR() : g����������āA����g�G���g���[�ɒl���i�[����֐�

void input_gATTR( gAttrName , gEntryValue , gEntryLen , dataType )
     char* gAttrName;
     char* gEntryValue;
     long  gEntryLen;
     long dataType;
{
  CDFstatus status;

  //g��������邽�߂̕ϐ�
  long g_scope = GLOBAL_SCOPE;
  long gAttrNum;

  long gEntryNum = 0L;

  char res[ 1000 ];

  //***** �������݂���CDF�t�@�C����I��
  status = CDFlib( SELECT_ , CDF_ , crid ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** g���������
  status = CDFlib( CREATE_ , ATTR_ , gAttrName , g_scope , &gAttrNum ,
		   NULL_ );
  
  if ( status != CDF_OK ) StatusHandler( status );


  //***** �f�t�H���g��g�����G���g���[��I�����Ag�G���g���[�ԍ����l������
  status = CDFlib( SELECT_ , gENTRY_ , gEntryNum ,
		   NULL_ );

  if ( status != CDF_OK ) StatusHandler( status );

  //***** g������I�����āAg�G���g���[�Ƀf�[�^��������
  //- GET�͕K�v�Ȃ��̂ŁA�ŏI�I�ɏ���!!
  status = CDFlib(  SELECT_ , ATTR_ , gAttrNum ,
		              gENTRY_ , gEntryNum ,
		    PUT_ , gENTRY_DATA_ , dataType , gEntryLen , gEntryValue ,
		    //		    GET_ , gENTRY_DATA_ , res ,
		    NULL_ );

   if ( status != CDF_OK ) StatusHandler( status );

   //   printf("\n%s \n",res);

}

//***************************************************************
//get_date() : ���݂̔N������m��
void get_date( date )
     char date[][ 5 ];
{
  struct tm *lt;
  time_t now;
  int year , month , day;
  
  time( &now );
  lt = localtime(&now);
  year = lt -> tm_year + 1900;
  month = lt -> tm_mon + 1;
  day = lt -> tm_mday;

  //***** year �� int�^ ���� char�^ �ɕϊ�����
  sprintf( date[ 0 ] , "%4d" , year );

  //***** month �� int�^ ���� char�^ �ɕϊ�����
  date[ 1 ][ 0 ] = ( int )( month / 10 ) + '0';
  date[ 1 ][ 1 ] = ( int )( month % 10 ) + '0';
  date[ 1 ][ 2 ] = '\0';

  //***** day �� int�^ ���� char�^ �ɕϊ�����
  date[ 2 ][ 0 ] = ( int )( day / 10 ) + '0';
  date[ 2 ][ 1 ] = ( int )( day % 10 ) + '0';
  date[ 2 ][ 2 ] = '\0';

}
