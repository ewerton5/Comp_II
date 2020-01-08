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
#include	"dvfmEvsUmlApproveRegistrationRequest.h"
#include	"dvfmEvsUmlGetUsers.h"
#include	"dvfmEvsUmlGetPendingRegistrationRequests.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlApproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *,
 *                                       char *,
 *                                       char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - user nickname string (I)
 * char * - requesting user nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Add a requesting user to the user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlApproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                                      char *dvfmEvsUmlUserNickname,
                                      char *dvfmEvsUmlRequestingUserNickname)
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlUserDataType *dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserIdentifierType dvfmEvsUmlResponsibleUserNumericIndentifier, dvfmEvsUmlNumericIndentifier;
    FILE *dvfmEvsUmlRead, *dvfmEvsUmlWrite;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlAuxiliaryBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE];
    unsigned dvfmEvsUmlIndex;
    char *dvfmEvsUmlValidation, dvfmEvsUmlEmail [DVFM_EVS_UML_MAX_SIZE_EMAIL], dvfmEvsUmlAuxiliary [2] = "0\0";

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlRequestingUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    while (dvfmEvsUmlUserData && strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlUserNickname))
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;
    
    dvfmEvsUmlResponsibleUserNumericIndentifier = dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier;

    dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData = NULL;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    while (dvfmEvsUmlUserData && strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlRequestingUserNickname))
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;
    
    dvfmEvsUmlNumericIndentifier = dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier;
    strcpy(dvfmEvsUmlEmail, dvfmEvsUmlUserData->dvfmEvsUmlEmail);

    dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData = NULL;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetPendingRegistrationRequests (dvfmEvsUmlSettings, &dvfmEvsUmlUserData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    while (dvfmEvsUmlUserData && dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier != dvfmEvsUmlNumericIndentifier)
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;

    if (dvfmEvsUmlUserData->dvfmEvsUmlResponsibleUserNumericIndentifier != dvfmEvsUmlResponsibleUserNumericIndentifier)
        return dvfmEvsUmlUserISNotResponsible;

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r")))
        return dvfmEvsUmlCantOpenFile;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "w")))
        return dvfmEvsUmlCantOpenFile;

    while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
    {
        if (!strstr(dvfmEvsUmlBuffer, ":"))
            return dvfmEvsUmlReadError;

        dvfmEvsUmlIndex = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
        dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = '\0';
        if (dvfmEvsUmlNumericIndentifier == (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlBuffer, &dvfmEvsUmlValidation, 10))
        {
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
                return dvfmEvsUmlReadError;

            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"))] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
                return dvfmEvsUmlReadError;
            
            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"))] = '\0';
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ':';
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ";"))] = ':';
            strcat(dvfmEvsUmlBuffer, dvfmEvsUmlUserData->dvfmEvsUmlPassword);
            strcat(dvfmEvsUmlBuffer, dvfmEvsUmlAuxiliaryBuffer);
        }
        dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ':';
        fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);
    }
    fprintf(dvfmEvsUmlWrite, "%c", EOF);

    if(ferror(dvfmEvsUmlRead))
    {
        fclose(dvfmEvsUmlRead);
        fclose(dvfmEvsUmlWrite);
        return dvfmEvsUmlReadError;
    }

    fclose(dvfmEvsUmlRead);
    fclose(dvfmEvsUmlWrite);

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, "rb")))
        return dvfmEvsUmlCantOpenFile;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, "wb")))
        return dvfmEvsUmlCantOpenFile;

    while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
    {
        if (!strstr(dvfmEvsUmlBuffer, ":"))
            return dvfmEvsUmlReadError;

        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
        dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlAuxiliaryBuffer[1];
        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, dvfmEvsUmlAuxiliary));

        if (!strstr(dvfmEvsUmlAuxiliaryBuffer, ":"))
            return dvfmEvsUmlReadError;

        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, ":"));
        dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlAuxiliaryBuffer[1];
        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, dvfmEvsUmlAuxiliary));

        if (!strstr(dvfmEvsUmlAuxiliaryBuffer, ":"))
            return dvfmEvsUmlReadError;

        dvfmEvsUmlAuxiliaryBuffer [strlen(dvfmEvsUmlAuxiliaryBuffer) - strlen(strstr(dvfmEvsUmlAuxiliaryBuffer, ":"))] = '\0';
        dvfmEvsUmlNumericIndentifier = (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlBuffer, &dvfmEvsUmlValidation, 10);
        if (dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier != dvfmEvsUmlNumericIndentifier)
            fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);
    }
    fprintf(dvfmEvsUmlWrite, "%c", EOF);

    if(ferror(dvfmEvsUmlRead))
    {
        fclose(dvfmEvsUmlRead);
        fclose(dvfmEvsUmlWrite);
        return dvfmEvsUmlReadError;
    }

    fclose(dvfmEvsUmlRead);
    fclose(dvfmEvsUmlWrite);

    if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
        return dvfmEvsUmlCantOpenFile;

    fprintf(dvfmEvsUmlWrite, "%s\n%s",
                             "Welcome to the Account Management System.\n",
                             "Bem vindo ao Sistema de Gerenciamento de Contas.\n");
    fclose(dvfmEvsUmlWrite);

    sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlEmail ,"dvfmEvsUmlMailFile");
    system(dvfmEvsUmlBuffer);

    remove("dvfmEvsUmlMailFile");
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
