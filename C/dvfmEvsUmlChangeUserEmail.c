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

#include    <stdio.h>
#include    <string.h>
#include	"dvfmEvsUmlChangeUserEmail.h"
#include	"dvfmEvsUmlFunctions.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlChangeUserEmail (dvfmEvsUmlConfigurationOptionsType *,
 *                            char *,
 *                            char *,
 *                            char *,
 *                            char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - user nickname string (I)
 * char * - new email string (I)
 * char * - confirm email string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Changes a user email.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlChangeUserEmail (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                           char *dvfmEvsUmlAdminNickname,
                           char *dvfmEvsUmlUserNickname,
                           char *dvfmEvsUmlNewEmail,
                           char *dvfmEvsUmlConfirmEmail)
{
    dvfmEvsUmlUserDataType *dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlBool dvfmEvsUmlAdmin = dvfmEvsUmlFalse;
    dvfmEvsUmlUserIdentifierType dvfmEvsUmlNumericIndentifier, dvfmEvsUmlNumericIndentifierFirstNumber;
    FILE *dvfmEvsUmlRead, *dvfmEvsUmlWrite;
    unsigned dvfmEvsUmlIndex, dvfmEvsUmlCounter;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlValidationKey [DVFM_EVS_UML_SIZE_BASE_64 + 1],
         dvfmEvsUmlNumericIndentifierString [10];

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlNewEmail)
        return dvfmEvsUmlFourthEmptyPointer;

    if (!dvfmEvsUmlConfirmEmail)
        return dvfmEvsUmlFifthEmptyPointer;

    if (strcmp(dvfmEvsUmlNewEmail, dvfmEvsUmlConfirmEmail))
        return dvfmEvsUmlIncompatibleEmail;

    if (dvfmEvsUmlAdminNickname)
        if(strlen(dvfmEvsUmlAdminNickname))
            dvfmEvsUmlAdmin = dvfmEvsUmlTrue;

    if (dvfmEvsUmlAdmin)
    {
        if (DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData))
            return dvfmEvsUmlSecondaryFunction;

        while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlAdminNickname))
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
        
        if (!dvfmEvsUmlUserData)
            return dvfmEvsUmlUserNotFound;

        if (dvfmEvsUmlUserData->dvfmEvsUmlProfile != dvfmEvsUmlAdministrator)
            return dvfmEvsUmlUserIsNotAdministrator;

        while (dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData)
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData;

        while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlUserNickname))
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
        
        if (!dvfmEvsUmlUserData)
            return dvfmEvsUmlUserNotFound;
    }
    else
    {
        if (DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData))
            return dvfmEvsUmlSecondaryFunction;

        while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlUserNickname))
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
        
        if (!dvfmEvsUmlUserData)
            return dvfmEvsUmlUserNotFound;
    }

    dvfmEvsUmlNumericIndentifier = dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier;

    for(dvfmEvsUmlIndex = 0; dvfmEvsUmlNumericIndentifier;dvfmEvsUmlIndex++)
    {
        dvfmEvsUmlNumericIndentifierFirstNumber = dvfmEvsUmlNumericIndentifier;
        for (dvfmEvsUmlCounter = 0; dvfmEvsUmlNumericIndentifierFirstNumber > 10; dvfmEvsUmlCounter++)
            dvfmEvsUmlNumericIndentifierFirstNumber = (dvfmEvsUmlUserIdentifierType) dvfmEvsUmlNumericIndentifierFirstNumber/10;
        dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = (char) dvfmEvsUmlNumericIndentifierFirstNumber + '0';
        dvfmEvsUmlNumericIndentifier = dvfmEvsUmlNumericIndentifier - dvfmEvsUmlNumericIndentifierFirstNumber*pow(10, dvfmEvsUmlCounter);
    }
    dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = '\0';

    if (DvfmEvsUmlCreateRandomString(DVFM_EVS_UML_BASE_64, DVFM_EVS_UML_SIZE_BASE_64, dvfmEvsUmlValidationKey))
        return dvfmEvsUmlSecondaryFunction;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlEmailAbeyancesDataFilename, "a")))
        return dvfmEvsUmlCantOpenFile;

    strcpy(dvfmEvsUmlBuffer, "172800:");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlNumericIndentifierString);
    strcpy(dvfmEvsUmlBuffer, ":");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlNewEmail);
    strcpy(dvfmEvsUmlBuffer, ":");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlValidationKey);

    fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);

    fclose(dvfmEvsUmlWrite);

    if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
        return dvfmEvsUmlCantOpenFile;

    fprintf(dvfmEvsUmlWrite, "Seu email foi selecionado para a conta %s, clique no link abaixo para confirmar:\n\n%sdvfmEvsUmlEmailVerification.cgi?dvfmEvsUmlConfigurationFileName=dvfmEvsUmlConfigurationFileName&dvfmEvsUmlNickname=%s&dvfmEvsUmlValidationKey=%s\n",
                             dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrl, dvfmEvsUmlUserData->dvfmEvsUmlNickname,dvfmEvsUmlValidationKey);

    fclose(dvfmEvsUmlWrite);

    sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlNewEmail ,"dvfmEvsUmlMailFile");
    system(dvfmEvsUmlBuffer);

    remove("dvfmEvsUmlMailFile");
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
