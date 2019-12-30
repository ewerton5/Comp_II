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
#include	"dvfmEvsUmlGetUsers.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetUsers (dvfmEvsUmlConfigurationOptionsType *,
 *                     dvfmEvsUmlUserDataType **);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * dvfmEvsUmlUserDataType ** - first element in the list containing data about all users (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Return a list of all users.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetUsers (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
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

    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r")))
        return dvfmEvsUmlCantOpenFile;
    
    dvfmEvsUmlCurrentUserData->dvfmEvsUmlNextUserData = NULL;

    while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
    {
        for(dvfmEvsUmlDateIndex = 0; dvfmEvsUmlDateIndex < 6; dvfmEvsUmlDateIndex++)
        {
            if (strstr(dvfmEvsUmlBuffer, ":"))
            {
                dvfmEvsUmlIndex = strlen(dvfmEvsUmlBuffer) - strlen(strstr(dvfmEvsUmlBuffer, ":"));
                dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = '\0';
                strcpy(dvfmEvsUmlDate, dvfmEvsUmlBuffer);
                dvfmEvsUmlBuffer [dvfmEvsUmlIndex] = ':';
                strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, ":"));
                dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlBuffer[1];
                strcpy(dvfmEvsUmlBuffer, strstr(dvfmEvsUmlBuffer, dvfmEvsUmlAuxiliary));
            }

            switch (dvfmEvsUmlDateIndex)
            {
            case 0:
                dvfmEvsUmlCurrentUserData->dvfmEvsUmlNumericIndentifier = (unsigned) strtoul(dvfmEvsUmlDate, &dvfmEvsUmlValidation, 10);
                if(*dvfmEvsUmlValidation != '\0')
                    return dvfmEvsUmlInvalidCharacter;
                break;
            case 1:
                strcpy(dvfmEvsUmlCurrentUserData->dvfmEvsUmlUsername, dvfmEvsUmlDate);
                break;
            case 2:
                strcpy(dvfmEvsUmlCurrentUserData->dvfmEvsUmlPassword, dvfmEvsUmlDate);
                break;
            case 3:
                dvfmEvsUmlCurrentUserData->dvfmEvsUmlProfile = (dvfmEvsUmlProfileType) strtoul(dvfmEvsUmlDate, &dvfmEvsUmlValidation, 10);
                if(*dvfmEvsUmlValidation != '\0')
                    return dvfmEvsUmlInvalidCharacter;
                break;
            case 4:
                strcpy(dvfmEvsUmlCurrentUserData->dvfmEvsUmlFullName, dvfmEvsUmlDate);
                break;
            case 5:
                strcpy(dvfmEvsUmlCurrentUserData->dvfmEvsUmlEmail, dvfmEvsUmlDate);
                break;
            }
        }
        dvfmEvsUmlCurrentUserData->dvfmEvsUmlPreviousUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));;
        dvfmEvsUmlCurrentUserData->dvfmEvsUmlPreviousUserData->dvfmEvsUmlNextUserData = dvfmEvsUmlCurrentUserData;
        dvfmEvsUmlCurrentUserData = dvfmEvsUmlCurrentUserData->dvfmEvsUmlPreviousUserData;
    }

    if(ferror(dvfmEvsUmlRead))
    {
        fclose(dvfmEvsUmlRead);
        return dvfmEvsUmlReadError;
    }

    fclose(dvfmEvsUmlRead);
    
    *dvfmEvsUmlUserData = dvfmEvsUmlCurrentUserData->dvfmEvsUmlNextUserData;

    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
