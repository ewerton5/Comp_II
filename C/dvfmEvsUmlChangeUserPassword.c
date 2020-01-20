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
#include	"dvfmEvsUmlChangeUserPassword.h"
#include	"dvfmEvsUmlFunctions.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlChangeUserPassword (dvfmEvsUmlConfigurationOptionsType *,
 *                               char *,
 *                               char *,
 *                               char *,
 *                               char *,
 *                               char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - user nickname string (I)
 * char * - current password string (I)
 * char * - new password string (I)
 * char * - confirm password string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Changes a user password.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlChangeUserPassword (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                              char *dvfmEvsUmlAdminNickname,
                              char *dvfmEvsUmlUserNickname,
                              char *dvfmEvsUmlCurrentPassword,
                              char *dvfmEvsUmlNewPassword,
                              char *dvfmEvsUmlConfirmPassword)
{
    dvfmEvsUmlUserDataType *dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlBool dvfmEvsUmlAdmin = dvfmEvsUmlFalse, dvfmEvsUmlPass = dvfmEvsUmlFalse;
    FILE *dvfmEvsUmlRead, *dvfmEvsUmlWrite;
    unsigned dvfmEvsUmlIndex1, dvfmEvsUmlIndex2;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlAuxiliaryBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         *dvfmEvsUmlValidation, dvfmEvsUmlAuxiliary [2] = "0\0",
         dvfmEvsUmlEncryptedNewPassword [DVFM_EVS_UML_MAX_SIZE_PASSWORD];


    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlNewPassword)
        return dvfmEvsUmlFifthEmptyPointer;

    if (!dvfmEvsUmlConfirmPassword)
        return dvfmEvsUmlSixthEmptyPointer;
    
    if (dvfmEvsUmlAdminNickname)
        if(strlen(dvfmEvsUmlAdminNickname))
            dvfmEvsUmlAdmin = dvfmEvsUmlTrue;

    if (dvfmEvsUmlCurrentPassword)
        if(strlen(dvfmEvsUmlCurrentPassword))
            dvfmEvsUmlPass = dvfmEvsUmlTrue;

    if (strcmp(dvfmEvsUmlNewPassword, dvfmEvsUmlConfirmPassword))
        return dvfmEvsUmlIncompatiblePassword;

    if (dvfmEvsUmlAdmin && !dvfmEvsUmlPass)
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
    else if (!dvfmEvsUmlAdmin && dvfmEvsUmlPass)
    {
        if (DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData))
            return dvfmEvsUmlSecondaryFunction;

        while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlUserNickname))
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
        
        if (!dvfmEvsUmlUserData)
            return dvfmEvsUmlUserNotFound;

        if (DvfmEvsUmlCheckPassword(dvfmEvsUmlCurrentPassword, dvfmEvsUmlUserData->dvfmEvsUmlPassword))
        {
            if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlPasswordAbeyancesDataFilename, "r")))
                return dvfmEvsUmlCantOpenFile;

            while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
            {
                if (!strstr(dvfmEvsUmlBuffer, ":"))
                {
                    fclose(dvfmEvsUmlRead);
                    return dvfmEvsUmlReadError;
                }

                strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, ":"));
                dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlBuffer[1];
                strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, dvfmEvsUmlAuxiliary));

                if (!strstr(dvfmEvsUmlBuffer, ":"))
                {
                    fclose(dvfmEvsUmlRead);
                    return dvfmEvsUmlReadError;
                }

                dvfmEvsUmlIndex1 = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
                dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = '\0';
                if (dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier == (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlBuffer, &dvfmEvsUmlValidation, 10))
                {
                    dvfmEvsUmlBuffer [dvfmEvsUmlIndex1] = ':';

                    if (!strstr(dvfmEvsUmlBuffer, ":"))
                    {
                        fclose(dvfmEvsUmlRead);
                        return dvfmEvsUmlReadError;
                    }

                    strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, ":"));
                    dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlBuffer[1];
                    strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, dvfmEvsUmlAuxiliary));

                    if (DvfmEvsUmlCheckPassword(dvfmEvsUmlCurrentPassword, dvfmEvsUmlBuffer))
                        return dvfmEvsUmlSecondaryFunction;
                }
            }

            if(ferror(dvfmEvsUmlRead))
            {
                fclose(dvfmEvsUmlRead);
                return dvfmEvsUmlReadError;
            }

            fclose(dvfmEvsUmlRead);
        }
    }
    else
        return dvfmEvsUmlIncorrectData;

    if (DvfmEvsUmlEncodePasswordWithSpecificAlgorithm(dvfmEvsUmlNewPassword, dvfmEvsUmlSha512, dvfmEvsUmlEncryptedNewPassword))
        return dvfmEvsUmlSecondaryFunction;
    
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
            strcat(dvfmEvsUmlBuffer, dvfmEvsUmlEncryptedNewPassword);
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

    if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
        return dvfmEvsUmlCantOpenFile;

    fprintf(dvfmEvsUmlWrite, "Sua senha foi alterada com sucesso.\n");

    fclose(dvfmEvsUmlWrite);

    sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlUserData->dvfmEvsUmlEmail ,"dvfmEvsUmlMailFile");
    system(dvfmEvsUmlBuffer);

    remove("dvfmEvsUmlMailFile");

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlPasswordAbeyancesDataFilename, "r")))
        return dvfmEvsUmlCantOpenFile;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlPasswordAbeyancesDataFilename, "w")))
        return dvfmEvsUmlCantOpenFile;

    while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
    {
        if (!strstr(dvfmEvsUmlBuffer, ":"))
        {
            fclose(dvfmEvsUmlRead);
            return dvfmEvsUmlReadError;
        }

        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
        dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlAuxiliaryBuffer[1];
        strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlAuxiliaryBuffer, dvfmEvsUmlAuxiliary));

        if (!strstr(dvfmEvsUmlAuxiliaryBuffer, ":"))
        {
            fclose(dvfmEvsUmlRead);
            return dvfmEvsUmlReadError;
        }

        dvfmEvsUmlIndex1 = strlen(dvfmEvsUmlAuxiliaryBuffer) - strlen(strstr(dvfmEvsUmlAuxiliaryBuffer, ":"));
        dvfmEvsUmlAuxiliaryBuffer [dvfmEvsUmlIndex1] = '\0';
        if (dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier != (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlAuxiliaryBuffer, &dvfmEvsUmlValidation, 10))
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
