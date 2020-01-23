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
#include	"dvfmEvsUmlGetPendingRegistrationRequests.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetPendingRegistrationRequests (dvfmEvsUmlConfigurationOptionsType *,
 *                                           dvfmEvsUmlUserDataType **);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * dvfmEvsUmlUserDataType ** - first element in the list containing data about pending requests for the user in question (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Return a list of all valid requests not met.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetPendingRegistrationRequests (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                                          dvfmEvsUmlUserDataType **dvfmEvsUmlUserData)
{
    unsigned short dvfmEvsUmlIndex, dvfmEvsUmlDateIndex;
    FILE *dvfmEvsUmlRead;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE];
    char dvfmEvsUmlDate [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE];
    char dvfmEvsUmlAuxiliary [2] = "0\0";
    dvfmEvsUmlUserDataType *dvfmEvsUmlCurrentUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
	char *dvfmEvsUmlValidation;

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlSecondEmptyPointer;

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, "rb")))
        return dvfmEvsUmlCantOpenFile;

    dvfmEvsUmlCurrentUserData->dvfmEvsUmlPreviousUserData = NULL;

    while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
    {
        for(dvfmEvsUmlDateIndex = 0; dvfmEvsUmlDateIndex < 5; dvfmEvsUmlDateIndex++)
        {
            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                return dvfmEvsUmlReadError;
            }

            dvfmEvsUmlIndex = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = '\0';
            strcpy(dvfmEvsUmlDate, dvfmEvsUmlBuffer);
            dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ':';

            if (!strstr(dvfmEvsUmlBuffer, ":"))
            {
                fclose(dvfmEvsUmlRead);
                return dvfmEvsUmlReadError;
            }

            strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, ":"));
            dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlBuffer[1];
            strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, dvfmEvsUmlAuxiliary));

            switch (dvfmEvsUmlDateIndex)
            {
            case 0:
                dvfmEvsUmlCurrentUserData->dvfmEvsUmlValidationTime = (time_t) strtoul(dvfmEvsUmlDate, &dvfmEvsUmlValidation, 10);
                if(*dvfmEvsUmlValidation != '\0')
                {
                    fclose(dvfmEvsUmlRead);
                    return dvfmEvsUmlInvalidCharacter;
                }
                break;
            case 1:
                dvfmEvsUmlCurrentUserData->dvfmEvsUmlResponsibleUserNumericIndentifier = (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlDate, &dvfmEvsUmlValidation, 10);
                if(*dvfmEvsUmlValidation != '\0')
                {
                    fclose(dvfmEvsUmlRead);
                    return dvfmEvsUmlInvalidCharacter;
                }
                break;
            case 2:
                dvfmEvsUmlCurrentUserData->dvfmEvsUmlNumericIndentifier = (dvfmEvsUmlUserIdentifierType) strtoul(dvfmEvsUmlDate, &dvfmEvsUmlValidation, 10);
                if(*dvfmEvsUmlValidation != '\0')
                {
                    fclose(dvfmEvsUmlRead);
                    return dvfmEvsUmlInvalidCharacter;
                }
                break;
            case 3:
                strcpy(dvfmEvsUmlCurrentUserData->dvfmEvsUmlPassword, dvfmEvsUmlDate);
                break;
            }
        }

        if (dvfmEvsUmlCurrentUserData->dvfmEvsUmlValidationTime > 0)
        {
            dvfmEvsUmlCurrentUserData->dvfmEvsUmlNextUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
            dvfmEvsUmlCurrentUserData->dvfmEvsUmlNextUserData->dvfmEvsUmlPreviousUserData = dvfmEvsUmlCurrentUserData;
            dvfmEvsUmlCurrentUserData = dvfmEvsUmlCurrentUserData->dvfmEvsUmlNextUserData;
        }
    }

    if(ferror(dvfmEvsUmlRead))
    {
        fclose(dvfmEvsUmlRead);
        return dvfmEvsUmlReadError;
    }

    fclose(dvfmEvsUmlRead);

    dvfmEvsUmlCurrentUserData = dvfmEvsUmlCurrentUserData->dvfmEvsUmlPreviousUserData;
    if (dvfmEvsUmlCurrentUserData)
        dvfmEvsUmlCurrentUserData->dvfmEvsUmlNextUserData = NULL;

    if (dvfmEvsUmlCurrentUserData)
        return dvfmEvsUmlEmptyList;

    while (dvfmEvsUmlCurrentUserData->dvfmEvsUmlPreviousUserData)
        dvfmEvsUmlCurrentUserData = dvfmEvsUmlCurrentUserData->dvfmEvsUmlPreviousUserData;

    *dvfmEvsUmlUserData = dvfmEvsUmlCurrentUserData;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
