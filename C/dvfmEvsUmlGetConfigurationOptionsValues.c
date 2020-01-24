/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2020/01/24 05:37:49 $
$Log: dvfmEvsUmlGetConfigurationOptionsValues.c,v $
Revision 1.2  2020/01/24 05:37:49  ewerton.silles
*** empty log message ***

Revision 1.1  2019/12/24 13:52:26  ewerton.silles
Initial revision

*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlFunctions.h"
#include	                "dvfmEvsUmlConfig.h"

#define DVFM_EVS_NUMBER_ARGUMENTS			    		2

#define DVFM_EVS_OK								    	0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID		        1

int
main(int argc,char *argv[ ]) 
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings = (dvfmEvsUmlConfigurationOptionsType *) malloc(sizeof(dvfmEvsUmlConfigurationOptionsType));
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <filename>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetConfigurationOptionsValues(argv[1], dvfmEvsUmlSettings);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }
    printf("\n\t\t\tConfiguracoes atuais:\n\n");
    printf("%s = %s\n", DVFM_EVS_UML_WEB_SERVER_URL_NAME, dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrl);
    printf("%s = %s\n", DVFM_EVS_UML_ADMINISTRATOR_USER_IDENTIFIER_NAME, dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifier);
    printf("%s = %s\n", DVFM_EVS_UML_PRIVATE_ROOT_DIRECTORY_NAME, dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectory);
    printf("%s = %s\n", DVFM_EVS_UML_DATA_DIRECTORY_NAME, dvfmEvsUmlSettings->dvfmEvsUmlDataDirectory);
    printf("%s = %s\n", DVFM_EVS_UML_COOKIES_DIRECTORY_NAME, dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectory);
    printf("%s = %s\n", DVFM_EVS_UML_USERS_DATA_FILENAME_NAME, dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename);
    printf("%s = %s\n", DVFM_EVS_UML_INVITED_USERS_DATA_FILENAME_NAME, dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename);
    printf("%s = %s\n", DVFM_EVS_UML_REQUESTING_USERS_DATA_FILENAME_NAME, dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename);
    printf("%s = %s\n", DVFM_EVS_UML_LOCKED_USERS_DATA_FILENAME_NAME, dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename);
    printf("%s = %s\n", DVFM_EVS_UML_UNLOCKING_USERS_DATA_FILENAME, dvfmEvsUmlSettings->dvfmEvsUmlUnlockingUsersDataFilename);
    printf("%s = %s\n", DVFM_EVS_UML_PASSWORD_ABEYANCES_DATA_FILENAME, dvfmEvsUmlSettings->dvfmEvsUmlPasswordAbeyancesDataFilename);
    printf("%s = %s\n\n", DVFM_EVS_UML_EMAIL_ABEYANCES_DATA_FILENAME, dvfmEvsUmlSettings->dvfmEvsUmlEmailAbeyancesDataFilename);

	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlGetConfigurationOptionsValues.c,v $ */
