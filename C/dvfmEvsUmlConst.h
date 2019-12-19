/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2019/11/30 04:31:06 $
 * $Log: dvfmEvsUmlConst.h,v $
 * Revision 1.2  2019/11/30 04:31:06  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/11/16 03:48:22  ewerton.silles
 * Initial revision
 * 
*/

#ifndef DVFM_EVS_UML_CONST_H
#define DVFM_EVS_UML_CONST_H "@(#)dvfmEvsUmlConst.h $Revision: 1.2 $"

/* ===== beginning of file code ===== */

#define DVFM_EVS_UML_MAXIMUM_LENGTH_ABSOLUTE_PATH       4096
#define DVFM_EVS_UML_MAXIMUM_LENGTH_ARCHIVE_NAME        255

#define DVFM_EVS_UML_MINIMUM_LENGTH_NICKNAME    	    3
#define DVFM_EVS_UML_MAXIMUM_LENGTH_NICKNAME    	    65

#define DVFM_EVS_UML_MAXIMUM_CHARACTERS_LINE_FILE_CONFIG    2048
#define DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE             2048 + 1
#define DVFM_EVS_UML_BUFFER_SIZE_LINE_CONFIG_FILE           2048 + 1 + 1

#define DVFM_EVS_UML_MAX_SIZE_PASSWORD                  127
#define DVFM_EVS_UML_MINIMUM_SIZE_PASSWORD              8
#define DVFM_EVS_UML_PASSWORD_BUFFER_SIZE               127 + 1
#define DVFM_EVS_UML_VALID_CHARACTERS_PASSWORD          "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .-'\"()[]{}!?@#$%&*/\\+=,;:"

#define DVFM_EVS_UML_SIZE_ENCRYPTED_PASSWORD            16
#define DVFM_EVS_UML_ENCRYPTED_PASSWORD_BUFFER_SIZE     16 + 1

#define DVFM_EVS_UML_MAX_SIZE_USER_NAME                 256
#define DVFM_EVS_UML_MINIMUM_SIZE_USER_NAME             11
#define DVFM_EVS_UML_USER_NAME_BUFFER_SIZE              256 +1
#define DVFM_EVS_UML_VALID_CHARACTERS_USER_NAME         "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .-'"

#define DVFM_EVS_UML_MAX_SIZE_EMAIL                     1024
#define DVFM_EVS_UML_MINIMUM_SIZE_EMAIL                 11
#define DVFM_EVS_UML_VALID_CHARACTERS_EMAIL             "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .-_@"

#define DVFM_EVS_UML_MAX_SIZE_NICKNAME                  65
#define DVFM_EVS_UML_MINIMUM_SIZE_NICKNAME              5
#define DVFM_EVS_UML_NICKNAME_BUFFER_SIZE               65 + 1
#define DVFM_EVS_UML_VALID_CHARACTERS_NICKNAME          "abcdefghijklmnopqrstuvwxyz."

#define DVFM_EVS_UML_MAXIMUM_NUMBER_IN_ID               30

#define DVFM_EVS_UML_MAX_SIZE_PROFILE_STRING            31
#define DVFM_EVS_UML_PROFILE_STRING_BUFFER_SIZE         31 + 1

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlConst.h,v $ */
