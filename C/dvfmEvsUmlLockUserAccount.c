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
#include	"dvfmEvsUmlLockUserAccount.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlLockUserAccount (dvfmEvsUmlConfigurationOptionsType *,
 *                            char *,
 *                            char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - user nickname string (I)
 * char * - blocked user nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Locks a user account.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlLockUserAccount (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                           char *dvfmEvsUmlAdminNickname,
                           char *dvfmEvsUmlBlockedUserNickname)
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlUserDataType *dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserIdentifierType dvfmEvsUmlNumericIndentifier;
    FILE *dvfmEvsUmlRead, *dvfmEvsUmlWrite;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlAuxiliaryBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE];
    unsigned dvfmEvsUmlIndex;
    char *dvfmEvsUmlValidation;

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlAdminNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlBlockedUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlAdminNickname))
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;

    if (dvfmEvsUmlUserData->dvfmEvsUmlProfile != dvfmEvsUmlAdministrator)
        return dvfmEvsUmlUserIsNotAdministrator;

    while (dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData)
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData;

    while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlBlockedUserNickname))
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;
    
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

        dvfmEvsUmlIndex = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
        dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = '\0';
        if (dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier == (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlBuffer, &dvfmEvsUmlValidation, 10))
        {
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ';';

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
            
            strcpy(dvfmEvsUmlAuxiliaryBuffer, strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ";"))] = ':';
            dvfmEvsUmlBuffer [strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":")) + 1] = '\0';
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ':';
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

    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
