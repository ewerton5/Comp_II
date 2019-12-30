/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author$
 * $Date$
 * $Log$
*/

#include	<stdio.h>
#include	"dvfmEvsUmlShowConfigurationValues.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlShowConfigurationValues (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Displays the values of all configuration options.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlShowConfigurationValues (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                                   dvfmEvsUmlLanguageType dvfmEvsUmlLanguage)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (dvfmEvsUmlLanguage == dvfmEvsUmlPortuguese)
        printf("\n\t\t\tConfiguracoes atuais:\n\n");
    else
        printf("\n\t\t\tCurrent Configurations:\n\n");
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrlName, dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrl);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifierName, dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifier);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectoryName, dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectory);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlDataDirectoryName, dvfmEvsUmlSettings->dvfmEvsUmlDataDirectory);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectoryName, dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectory);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename);
    printf("%s = %s\n", dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename);
    printf("%s = %s\n\n", dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilenameName, dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename);
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
