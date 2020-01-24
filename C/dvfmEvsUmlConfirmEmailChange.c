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
#include	"dvfmEvsUmlConfirmEmailChange.h"
#include	"dvfmEvsUmlGetUsers.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlConfirmEmailChange (dvfmEvsUmlConfigurationOptionsType *,
 *                               char *,
 *                               char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - user nickname string (I)
 * char * - validation key string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Validate an email.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlConfirmEmailChange (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                              char *dvfmEvsUmlNickname,
                              char *dvfmEvsUmlValidationKey)
{
    dvfmEvsUmlUserDataType *dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlBool dvfmEvsUmlValidated = dvfmEvsUmlFalse;
    FILE *dvfmEvsUmlRead, *dvfmEvsUmlWrite;
    unsigned dvfmEvsUmlIndex1, dvfmEvsUmlIndex2;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlAuxiliaryBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlNewEmail [DVFM_EVS_UML_MAX_SIZE_EMAIL],
         *dvfmEvsUmlValidation, dvfmEvsUmlAuxiliary [2] = "0\0";

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlValidationKey)
        return dvfmEvsUmlThirdEmptyPointer;

    if (DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData))
        return dvfmEvsUmlSecondaryFunction;

    while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlNickname))
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlEmailAbeyancesDataFilename, "rb")))
        return dvfmEvsUmlCantOpenFile;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlEmailAbeyancesDataFilename, "wb")))
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
        if (dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier != (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlAuxiliaryBuffer, &dvfmEvsUmlValidation, 10))
            fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);
        else
        {
            dvfmEvsUmlAuxiliaryBuffer [dvfmEvsUmlIndex1] = ':';

            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlAuxiliaryBuffer[1];
            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, dvfmEvsUmlAuxiliary));

            dvfmEvsUmlIndex1 = strlen(dvfmEvsUmlAuxiliaryBuffer) - strlen(strstr(dvfmEvsUmlAuxiliaryBuffer, ":"));
            dvfmEvsUmlAuxiliaryBuffer [dvfmEvsUmlIndex1] = '\0';
            strcpy(dvfmEvsUmlNewEmail, dvfmEvsUmlAuxiliaryBuffer);
            dvfmEvsUmlAuxiliaryBuffer [dvfmEvsUmlIndex1] = ':';

            if (!strstr(dvfmEvsUmlAuxiliaryBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }

            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlAuxiliaryBuffer[1];
            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, dvfmEvsUmlAuxiliary));

            if(!(dvfmEvsUmlValidated = strcmp(dvfmEvsUmlValidationKey, dvfmEvsUmlAuxiliaryBuffer) ? dvfmEvsUmlFalse : dvfmEvsUmlTrue))
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

    if (!dvfmEvsUmlValidated)
        return dvfmEvsUmlIncompatibleValidationKey;

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
        if (dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier == (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlBuffer, &dvfmEvsUmlValidation, 10))
        {
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }
            
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"))] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }

            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"))] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }

            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"))] = ';';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }

            dvfmEvsUmlIndex2 = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
            
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = ':';
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ";"))] = ':';
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ";"))] = ':';
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ";"))] = ':';
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex2 + 1] = '\0';
            strcat(dvfmEvsUmlBuffer, dvfmEvsUmlNewEmail);
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
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
