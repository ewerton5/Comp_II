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

#include	<string.h>
#include	"dvfmEvsUmlGetPendingRegistrationRequestsPerUser.h"
#include	"dvfmEvsUmlGetUsers.h"
#include	"dvfmEvsUmlGetPendingRegistrationRequests.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetPendingRegistrationRequestsPerUser (dvfmEvsUmlConfigurationOptionsType *,
 *                                                  char *,
 *                                                  dvfmEvsUmlUserDataType **);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - nickname string (I)
 * dvfmEvsUmlUserDataType ** - first element in the list containing data about pending requests for the user in question (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Return a list of all valid requests not met by the user in question.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetPendingRegistrationRequestsPerUser (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                                                 char *dvfmEvsUmlNickname,
                                                 dvfmEvsUmlUserDataType **dvfmEvsUmlUserData)
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlUserDataType *dvfmEvsUmlAllUsersData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserDataType *dvfmEvsUmlFilteredUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserIdentifierType dvfmEvsUmlResponsibleUserNumericIndentifier;

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlThirdEmptyPointer;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlAllUsersData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    while (dvfmEvsUmlAllUsersData)
    {
        if (!strcmp(dvfmEvsUmlAllUsersData->dvfmEvsUmlNickname, dvfmEvsUmlNickname))
        {
            dvfmEvsUmlResponsibleUserNumericIndentifier = dvfmEvsUmlAllUsersData->dvfmEvsUmlNumericIndentifier;
            break;
        }
        dvfmEvsUmlAllUsersData = dvfmEvsUmlAllUsersData->dvfmEvsUmlNextUserData;
    }

    if (!dvfmEvsUmlAllUsersData)
        return dvfmEvsUmlUserNotFound;

    dvfmEvsUmlAllUsersData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlAllUsersData->dvfmEvsUmlPreviousUserData = NULL;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetPendingRegistrationRequests (dvfmEvsUmlSettings, &dvfmEvsUmlAllUsersData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData = NULL; 

    while (dvfmEvsUmlAllUsersData)
    {
        if(strcmp(dvfmEvsUmlAllUsersData->dvfmEvsUmlResponsibleUserNumericIndentifier, dvfmEvsUmlResponsibleUserNumericIndentifier))
        {
            dvfmEvsUmlFilteredUserData = dvfmEvsUmlAllUsersData;
            dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
            dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData->dvfmEvsUmlPreviousUserData = dvfmEvsUmlFilteredUserData;
            dvfmEvsUmlFilteredUserData = dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData;
        }
        dvfmEvsUmlAllUsersData = dvfmEvsUmlAllUsersData->dvfmEvsUmlNextUserData;
    }

    dvfmEvsUmlFilteredUserData = dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData;
    if (dvfmEvsUmlFilteredUserData)
        dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData = NULL;

    if (dvfmEvsUmlFilteredUserData)
        return dvfmEvsUmlEmptyList;

    while (dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData)
        dvfmEvsUmlFilteredUserData = dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData;
    
    *dvfmEvsUmlUserData = dvfmEvsUmlFilteredUserData;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
