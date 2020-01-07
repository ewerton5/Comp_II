/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2019/12/24 13:52:26 $
 * $Log: dvfmEvsUmlTypes.h,v $
 * Revision 1.4  2019/12/24 13:52:26  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.3  2019/11/30 04:31:06  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/11/16 03:48:22  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/11/07 17:17:27  ewerton.silles
 * Initial revision
 *
*/

#ifndef DVFM_EVS_UML_TYPES_H
#define DVFM_EVS_UML_TYPES_H "@(#)dvfmEvsUmlTypes.h $Revision: 1.4 $"

/* ===== beginning of file code ===== */

#include	<time.h>
#include	"dvfmEvsUmlConst.h"

typedef enum
{
	dvfmEvsUmlEnglish = 0, 
	dvfmEvsUmlPortuguese = 1, 
	dvfmEvsUmlLanguagesAmount
} dvfmEvsUmlLanguageType;

typedef unsigned long long dvfmEvsUmlUserIdentifierType;
typedef unsigned long long dvfmEvsUmlUserProfileType;

typedef enum
{
	dvfmEvsUmlFalse,
	dvfmEvsUmlTrue,
} dvfmEvsUmlBool;

typedef enum
{
	dvfmEvsUmlDes,
	dvfmEvsUmlMd5,
	dvfmEvsUmlSha256,
	dvfmEvsUmlSha512
} dvfmEvsUmlCryptAlgorithms;

typedef struct dvfmEvsUmlConfigurationOptions
{
	char dvfmEvsUmlWebServerUrl[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlWebServerUrlName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlAdministratorUserIdentifier[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlAdministratorUserIdentifierName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlPrivateRootDirectory[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlPrivateRootDirectoryName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlDataDirectory[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlDataDirectoryName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlCookiesDirectory[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlCookiesDirectoryName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlUsersDataFilename[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlUsersDataFilenameName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlInvitedUsersDataFilename[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlInvitedUsersDataFilenameName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlRequestingUsersDataFilename[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlRequestingUsersDataFilenameName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlLockedUsersDataFilename[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlLockedUsersDataFilenameName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
} dvfmEvsUmlConfigurationOptionsType;

typedef struct dvfmEvsUmlUserData
{
	time_t dvfmEvsUmlValidationTime;
	dvfmEvsUmlUserIdentifierType dvfmEvsUmlResponsibleUserNumericIndentifier;
	dvfmEvsUmlUserIdentifierType dvfmEvsUmlNumericIndentifier;
	char dvfmEvsUmlNickname [DVFM_EVS_UML_USER_NAME_BUFFER_SIZE];
	char dvfmEvsUmlConfirmNickname [DVFM_EVS_UML_USER_NAME_BUFFER_SIZE];
	dvfmEvsUmlProfileType *dvfmEvsUmlProfile;
	char dvfmEvsUmlFullName [DVFM_EVS_UML_USER_NAME_BUFFER_SIZE];
	char dvfmEvsUmlConfirmFullName [DVFM_EVS_UML_USER_NAME_BUFFER_SIZE];
	char dvfmEvsUmlEmail [DVFM_EVS_UML_MAX_SIZE_EMAIL];
	char dvfmEvsUmlConfirmEmail [DVFM_EVS_UML_MAX_SIZE_EMAIL];
	char dvfmEvsUmlPassword [DVFM_EVS_UML_PASSWORD_BUFFER_SIZE];
	char dvfmEvsUmlConfirmPassword [DVFM_EVS_UML_PASSWORD_BUFFER_SIZE];
	struct dvfmEvsUmlUserData *dvfmEvsUmlPreviousUserData;
	struct dvfmEvsUmlUserData *dvfmEvsUmlNextUserData;
} dvfmEvsUmlUserDataType;

typedef struct dvfmEvsUmlNicknameList
{
	char dvfmEvsUmlNickname [DVFM_EVS_UML_MAX_SIZE_NICKNAME];
	struct dvfmEvsUmlNicknameList *dvfmEvsUmlNextNickname;
} dvfmEvsUmlNicknameListType;

typedef enum
{
	dvfmEvsUmlUndefined = 0,
	dvfmEvsUmlAdministrator = 1, 
	dvfmEvsUmlProfessor = 2, 
	dvfmEvsUmlStudent = 4
} dvfmEvsUmlProfileType;

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlTypes.h,v $ */
