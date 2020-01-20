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
#include	<string.h>
#include	<math.h>
#include	"dvfmEvsUmlRequestRegistration.h"
#include	"dvfmEvsUmlFunctions.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlRequestRegistration (dvfmEvsUmlConfigurationOptionsType *,
 *                                char *,
 *                                dvfmEvsUmlUserDataType *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - email string (I)
 * dvfmEvsUmlUserDataType * - user data (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Add a user to the requesting user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlRequestRegistration (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                               char *dvfmEvsUmlEmail,
                               dvfmEvsUmlUserDataType *dvfmEvsUmlUserData)
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlUserDataType *dvfmEvsUmlAllUsersData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    FILE *dvfmEvsUmlWrite;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE];
    unsigned dvfmEvsUmlIndex, dvfmEvsUmlCounter;
    dvfmEvsUmlUserIdentifierType dvfmEvsUmlNumericIndentifier, dvfmEvsUmlNumericIndentifierFirstNumber;
	char *dvfmEvsUmlValidation, dvfmEvsUmlNumericIndentifierString [10], dvfmEvsUmlResponsibleUserNumericIndentifierString [10],
          dvfmEvsUmlAuxiliary [2] = "0\0", dvfmEvsUmlFirstNickname [DVFM_EVS_UML_MAX_SIZE_NICKNAME],
          dvfmEvsUmlSecondNickname [DVFM_EVS_UML_MAX_SIZE_NICKNAME];

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlEmail)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlUserData->dvfmEvsUmlEmail ||
        !dvfmEvsUmlUserData->dvfmEvsUmlConfirmEmail ||
        !dvfmEvsUmlUserData->dvfmEvsUmlFullName ||
        !dvfmEvsUmlUserData->dvfmEvsUmlConfirmFullName)
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlThirdEmptyPointer;

    dvfmEvsUmlErrorCode = DvfmEvsUmlCheckEmail(dvfmEvsUmlEmail, DVFM_EVS_UML_VALID_CHARACTERS_EMAIL, DVFM_EVS_UML_MINIMUM_SIZE_EMAIL, DVFM_EVS_UML_MAX_SIZE_EMAIL);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    dvfmEvsUmlErrorCode = DvfmEvsUmlCheckEmail(dvfmEvsUmlUserData->dvfmEvsUmlEmail, DVFM_EVS_UML_VALID_CHARACTERS_EMAIL, DVFM_EVS_UML_MINIMUM_SIZE_EMAIL, DVFM_EVS_UML_MAX_SIZE_EMAIL);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    dvfmEvsUmlErrorCode = DvfmEvsUmlCheckEmail(dvfmEvsUmlUserData->dvfmEvsUmlConfirmEmail, DVFM_EVS_UML_VALID_CHARACTERS_EMAIL, DVFM_EVS_UML_MINIMUM_SIZE_EMAIL, DVFM_EVS_UML_MAX_SIZE_EMAIL);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    if(strcmp(dvfmEvsUmlUserData->dvfmEvsUmlEmail, dvfmEvsUmlUserData->dvfmEvsUmlConfirmEmail))
        return dvfmEvsUmlIncompatibleEmail;

    if(strcmp(dvfmEvsUmlUserData->dvfmEvsUmlFullName, dvfmEvsUmlUserData->dvfmEvsUmlConfirmFullName))
        return dvfmEvsUmlIncompatibleFullName;

    dvfmEvsUmlErrorCode = DvfmEvsUmlCreateNickname(dvfmEvsUmlUserData->dvfmEvsUmlFullName, dvfmEvsUmlFirstNickname, dvfmEvsUmlSecondNickname);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlAllUsersData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    while (dvfmEvsUmlAllUsersData->dvfmEvsUmlNextUserData)
    {
        if (!strcmp(dvfmEvsUmlAllUsersData->dvfmEvsUmlNickname, dvfmEvsUmlFirstNickname))
            strcpy(dvfmEvsUmlFirstNickname, dvfmEvsUmlSecondNickname);
        dvfmEvsUmlAllUsersData = dvfmEvsUmlAllUsersData->dvfmEvsUmlNextUserData;
    }

    if (!strcmp(dvfmEvsUmlAllUsersData->dvfmEvsUmlNickname, dvfmEvsUmlFirstNickname))
        strcpy(dvfmEvsUmlFirstNickname, dvfmEvsUmlSecondNickname);

    dvfmEvsUmlNumericIndentifier = dvfmEvsUmlAllUsersData->dvfmEvsUmlNumericIndentifier + 1;
    for(dvfmEvsUmlIndex = 0; dvfmEvsUmlNumericIndentifier; dvfmEvsUmlIndex++)
    {
        dvfmEvsUmlNumericIndentifierFirstNumber = dvfmEvsUmlNumericIndentifier;
        for (dvfmEvsUmlCounter = 0; dvfmEvsUmlNumericIndentifierFirstNumber > 10; dvfmEvsUmlCounter++)
            dvfmEvsUmlNumericIndentifierFirstNumber = (dvfmEvsUmlUserIdentifierType) dvfmEvsUmlNumericIndentifierFirstNumber/10;
        dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = (char) dvfmEvsUmlNumericIndentifierFirstNumber + '0';
        dvfmEvsUmlNumericIndentifier = dvfmEvsUmlNumericIndentifier - dvfmEvsUmlNumericIndentifierFirstNumber*pow(10, dvfmEvsUmlCounter);
    }
    dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = '\0';

    while (dvfmEvsUmlAllUsersData && strcmp(dvfmEvsUmlAllUsersData->dvfmEvsUmlEmail, dvfmEvsUmlEmail))
        dvfmEvsUmlAllUsersData = dvfmEvsUmlAllUsersData->dvfmEvsUmlPreviousUserData;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;

    dvfmEvsUmlNumericIndentifier = dvfmEvsUmlAllUsersData->dvfmEvsUmlNumericIndentifier;
    for(dvfmEvsUmlIndex = 0; dvfmEvsUmlNumericIndentifier;dvfmEvsUmlIndex++)
    {
        dvfmEvsUmlNumericIndentifierFirstNumber = dvfmEvsUmlNumericIndentifier;
        for (dvfmEvsUmlCounter = 0; dvfmEvsUmlNumericIndentifierFirstNumber > 10; dvfmEvsUmlCounter++)
            dvfmEvsUmlNumericIndentifierFirstNumber = (dvfmEvsUmlUserIdentifierType) dvfmEvsUmlNumericIndentifierFirstNumber/10;
        dvfmEvsUmlResponsibleUserNumericIndentifierString [dvfmEvsUmlIndex] = (char) dvfmEvsUmlNumericIndentifierFirstNumber + '0';
        dvfmEvsUmlNumericIndentifier = dvfmEvsUmlNumericIndentifier - dvfmEvsUmlNumericIndentifierFirstNumber*pow(10, dvfmEvsUmlCounter);
    }
    dvfmEvsUmlResponsibleUserNumericIndentifierString [dvfmEvsUmlIndex] = '\0';

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "a")))
        return dvfmEvsUmlCantOpenFile;

    strcpy(dvfmEvsUmlBuffer, dvfmEvsUmlNumericIndentifierString);
    strcat(dvfmEvsUmlBuffer, ":");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlFirstNickname);
    strcat(dvfmEvsUmlBuffer, "::4:");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlUserData->dvfmEvsUmlFullName);
    strcat(dvfmEvsUmlBuffer, ":");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlUserData->dvfmEvsUmlEmail);
    strcat(dvfmEvsUmlBuffer, "\n");

    fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);

    fclose(dvfmEvsUmlWrite);

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, "ab")))
        return dvfmEvsUmlCantOpenFile;

    strcpy(dvfmEvsUmlBuffer, "604800:");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlResponsibleUserNumericIndentifierString);
    strcat(dvfmEvsUmlBuffer, ":");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlNumericIndentifierString);
    strcat(dvfmEvsUmlBuffer, ":");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlUserData->dvfmEvsUmlPassword);
    strcat(dvfmEvsUmlBuffer, "\n");

    fprintf(dvfmEvsUmlWrite, "%c", dvfmEvsUmlBuffer);

    fclose(dvfmEvsUmlWrite);
    
    if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
        return dvfmEvsUmlCantOpenFile;

    fprintf(dvfmEvsUmlWrite, "%s\n%s",
                             "Your request has been registered in the system.\n",
                             "If you did not make these changes contact us.\n");
    fclose(dvfmEvsUmlWrite);

    sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlEmail ,"dvfmEvsUmlMailFile");
    system(dvfmEvsUmlBuffer);

    remove("dvfmEvsUmlMailFile");
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
