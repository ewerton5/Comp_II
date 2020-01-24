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
#include	"dvfmEvsUmlAcceptInvite.h"
#include	"dvfmEvsUmlGetUsers.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlAcceptInvite (dvfmEvsUmlConfigurationOptionsType *,
 *                         char *,
 *                         dvfmEvsUmlUserDataType *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - temporary password string (I)
 * dvfmEvsUmlUserDataType * - user data (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Add a invited user to the user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlAcceptInvite (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                        char *dvfmEvsUmlTemporaryPassword,
                        dvfmEvsUmlUserDataType *dvfmEvsUmlUserData)
{
    dvfmEvsUmlUserDataType *dvfmEvsUmlFullUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    FILE *dvfmEvsUmlRead, *dvfmEvsUmlWrite;
    dvfmEvsUmlBool dvfmEvsUmlCompatiblePassword = dvfmEvsUmlFalse;
    unsigned dvfmEvsUmlIndex1, dvfmEvsUmlIndex2;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlAuxiliaryBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         *dvfmEvsUmlValidation, dvfmEvsUmlAuxiliary [2] = "0\0";

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlTemporaryPassword)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlUserData) 
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlUserData->dvfmEvsUmlNickname || !dvfmEvsUmlUserData->dvfmEvsUmlPassword || !dvfmEvsUmlUserData->dvfmEvsUmlConfirmPassword)
        return dvfmEvsUmlThirdEmptyPointer;

    if (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlPassword, dvfmEvsUmlUserData->dvfmEvsUmlConfirmPassword))
        return dvfmEvsUmlIncompatiblePassword;

    if (DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlFullUserData))
        return dvfmEvsUmlSecondaryFunction;

    while (strcmp(dvfmEvsUmlFullUserData->dvfmEvsUmlNickname, dvfmEvsUmlUserData->dvfmEvsUmlNickname))
        dvfmEvsUmlFullUserData = dvfmEvsUmlFullUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlFullUserData)
        return dvfmEvsUmlUserNotFound;

    if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
        return dvfmEvsUmlCantOpenFile;

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename, "rb")))
        return dvfmEvsUmlCantOpenFile;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename, "wb")))
        return dvfmEvsUmlCantOpenFile;

    while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
    {
        if (!strstr(dvfmEvsUmlBuffer, ":"))
        {
            fclose(dvfmEvsUmlRead);
            fclose(dvfmEvsUmlWrite);
            return dvfmEvsUmlReadError;
        }

        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
        dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlAuxiliaryBuffer[1];
        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, dvfmEvsUmlAuxiliary));

        if (!strstr(dvfmEvsUmlAuxiliaryBuffer, ":"))
        {
            fclose(dvfmEvsUmlRead);
            fclose(dvfmEvsUmlWrite);
            return dvfmEvsUmlReadError;
        }

        dvfmEvsUmlIndex1 = strlen(dvfmEvsUmlAuxiliaryBuffer) - strlen(strstr(dvfmEvsUmlAuxiliaryBuffer, ":"));
        dvfmEvsUmlAuxiliaryBuffer [dvfmEvsUmlIndex1] = '\0';
        if (dvfmEvsUmlFullUserData->dvfmEvsUmlNumericIndentifier != (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlAuxiliaryBuffer, &dvfmEvsUmlValidation, 10))
            fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);
        else
        {
            dvfmEvsUmlAuxiliaryBuffer [dvfmEvsUmlIndex1] = ':';

            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlAuxiliaryBuffer[1];
            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, dvfmEvsUmlAuxiliary));

            if(!(dvfmEvsUmlCompatiblePassword = strcmp(dvfmEvsUmlTemporaryPassword, dvfmEvsUmlAuxiliaryBuffer) ? dvfmEvsUmlFalse : dvfmEvsUmlTrue))
                fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);
        }

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

    if (!dvfmEvsUmlCompatiblePassword)
        return dvfmEvsUmlIncompatiblePassword;

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r")))
        return dvfmEvsUmlCantOpenFile;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "w")))
        return dvfmEvsUmlCantOpenFile;

    while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
    {
        if (!strstr(dvfmEvsUmlBuffer, ":"))
        {
            fclose(dvfmEvsUmlRead);
            fclose(dvfmEvsUmlWrite);
            return dvfmEvsUmlReadError;
        }

        dvfmEvsUmlIndex1 = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
        dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = '\0';
        if (dvfmEvsUmlFullUserData->dvfmEvsUmlNumericIndentifier == (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlBuffer, &dvfmEvsUmlValidation, 10))
        {
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }

            dvfmEvsUmlIndex2 = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex2] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }
            
            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = ':';
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex2] = ':';
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex2 + 1] = '\0';
            strcat(dvfmEvsUmlBuffer, dvfmEvsUmlUserData->dvfmEvsUmlPassword);
            strcat(dvfmEvsUmlBuffer, dvfmEvsUmlAuxiliaryBuffer);
        }
        dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = ':';
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

    fprintf(dvfmEvsUmlWrite, "Bem vindo ao Sistema de Gerenciamento de Contas, seu convite foi aceito e você já pode acessar sua conta normalmente.\n");

    fclose(dvfmEvsUmlWrite);

    sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlFullUserData->dvfmEvsUmlEmail ,"dvfmEvsUmlMailFile");
    system(dvfmEvsUmlBuffer);

    remove("dvfmEvsUmlMailFile");

    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
