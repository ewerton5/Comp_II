/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author$
$Date$
$Log$
*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlFunctions.h"
#include					"dvfmEvsUmlConst.h"

#define DVFM_EVS_NUMBER_ARGUMENTS			    		2

#define DVFM_EVS_OK								    	0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID		        1

int
main(int argc,char *argv[ ]) 
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings = malloc(sizeof(dvfmEvsUmlConfigurationOptionsType));
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
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrlName, dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrl);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifierName, dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifier);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectoryName, dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectory);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlDataDirectoryName, dvfmEvsUmlSettings->dvfmEvsUmlDataDirectory);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectoryName, dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectory);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename);
    
	return DVFM_EVS_OK;
}
/* $RCSfile$ */
