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
#include	"dvfmEvsUmlUnlockUserAccount.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlUnlockUserAccount (dvfmEvsUmlConfigurationOptionsType *,
 *                              char *,
 *                              char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - blocked user nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Unlocks a user account.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlUnlockUserAccount (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                             char *dvfmEvsUmlAdminNickname,
                             char *dvfmEvsUmlBlockedUserNickname)
{
    dvfmEvsUmlUserDataType *dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlBool dvfmEvsUmlAdmin = dvfmEvsUmlFalse;
    dvfmEvsUmlUserIdentifierType dvfmEvsUmlNumericIndentifier, dvfmEvsUmlNumericIndentifierFirstNumber;
    FILE *dvfmEvsUmlRead, *dvfmEvsUmlWrite;
    unsigned dvfmEvsUmlIndex, dvfmEvsUmlCounter;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlAuxiliaryBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         *dvfmEvsUmlValidation, dvfmEvsUmlNumericIndentifierString [10],
         dvfmEvsUmlNickname [DVFM_EVS_UML_MAX_SIZE_NICKNAME];

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlBlockedUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;
    
    if (!dvfmEvsUmlAdminNickname)
        if(strlen(dvfmEvsUmlAdminNickname) != 0)
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

        while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlBlockedUserNickname))
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
        
        if (!dvfmEvsUmlUserData)
            return dvfmEvsUmlUserNotFound;

        if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename, "rb")))
            return dvfmEvsUmlCantOpenFile;
 
        if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename, "wb")))
            return dvfmEvsUmlCantOpenFile;

        while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
        {
            if (!strstr(dvfmEvsUmlAuxiliaryBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                fclose(dvfmEvsUmlWrite);
                return dvfmEvsUmlReadError;
            }

            dvfmEvsUmlIndex = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = '\0';
            dvfmEvsUmlNumericIndentifier = (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlBuffer, &dvfmEvsUmlValidation, 10);
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ':';
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

        if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
            return dvfmEvsUmlCantOpenFile;

        fprintf(dvfmEvsUmlWrite, "%s\n%s",
                                "Sua conta foi desbloqueada, você já pode fazer log in normalmente.\n",
                                "Your account has been unlocked, you can already log in normally.\n");
        fclose(dvfmEvsUmlWrite);

        sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlUserData->dvfmEvsUmlEmail ,"dvfmEvsUmlMailFile");
        system(dvfmEvsUmlBuffer);

        remove("dvfmEvsUmlMailFile");
    }
    else
    {
        if (DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData))
            return dvfmEvsUmlSecondaryFunction;

        while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlBlockedUserNickname))
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
        
        if (!dvfmEvsUmlUserData)
            return dvfmEvsUmlUserNotFound;

        strcpy(dvfmEvsUmlNickname, dvfmEvsUmlUserData->dvfmEvsUmlNickname);
        dvfmEvsUmlNumericIndentifier = dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier;

        for(dvfmEvsUmlIndex = 0; dvfmEvsUmlNumericIndentifier != 0;dvfmEvsUmlIndex++)
        {
            dvfmEvsUmlNumericIndentifierFirstNumber = dvfmEvsUmlNumericIndentifier;
            for (dvfmEvsUmlCounter = 0; dvfmEvsUmlNumericIndentifierFirstNumber > 10; dvfmEvsUmlCounter++)
                dvfmEvsUmlNumericIndentifierFirstNumber = (dvfmEvsUmlUserIdentifierType) dvfmEvsUmlNumericIndentifierFirstNumber/10;
            dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = (char) dvfmEvsUmlNumericIndentifierFirstNumber + '0';
            dvfmEvsUmlNumericIndentifier = dvfmEvsUmlNumericIndentifier - dvfmEvsUmlNumericIndentifierFirstNumber*pow(10, dvfmEvsUmlCounter);
        }
        dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = '\0';

        if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUnlockingUsersDataFilename, "a")))
            return dvfmEvsUmlCantOpenFile;

        strcpy(dvfmEvsUmlBuffer, "86400:");
        strcat(dvfmEvsUmlBuffer, dvfmEvsUmlNumericIndentifierString);

        fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);

        fclose(dvfmEvsUmlWrite);

        while (dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData)
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlPreviousUserData;

        if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
            return dvfmEvsUmlCantOpenFile;

        fprintf(dvfmEvsUmlWrite, "O usuário %s solicitou desbloqueio de conta.\n", dvfmEvsUmlNickname);

        fclose(dvfmEvsUmlWrite);

        while (dvfmEvsUmlUserData)
        {
            if (dvfmEvsUmlUserData->dvfmEvsUmlProfile == dvfmEvsUmlAdministrator)
            {
                sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlUserData->dvfmEvsUmlEmail ,"dvfmEvsUmlMailFile");
                system(dvfmEvsUmlBuffer);
            }
            dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
        }
        remove("dvfmEvsUmlMailFile");
    }
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
