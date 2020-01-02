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
#include	"dvfmEvsUmlSearchUsers.h"
#include	"dvfmEvsUmlGetUsers.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlSearchUsers (dvfmEvsUmlConfigurationOptionsType *,
 *                        char *,
 *                        char *,
 *                        dvfmEvsUmlProfileType,
 *                        dvfmEvsUmlUserDataType **);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - full name or part of the name string (I)
 * char * - full email or part of the email string (I)
 * dvfmEvsUmlProfileType - profile (I)
 * dvfmEvsUmlUserDataType ** - first element in the list containing data about all users (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Search and return a list of all users.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlSearchUsers (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                       char *dvfmEvsUmlName,
                       char *dvfmEvsUmlEmail,
                       dvfmEvsUmlProfileType dvfmEvsUmlProfile,
                       dvfmEvsUmlUserDataType **dvfmEvsUmlUserData)
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlUserDataType *dvfmEvsUmlFullUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserDataType *dvfmEvsUmlFilteredUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlBool dvfmEvsUmlInFilter;

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlFifthEmptyPointer;

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlFullUserData);
    if (dvfmEvsUmlErrorCode)
        return dvfmEvsUmlSecondaryFunction;

    dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData = NULL;

    while (dvfmEvsUmlFullUserData)
    {
        dvfmEvsUmlInFilter = dvfmEvsUmlTrue;
        
        if (dvfmEvsUmlName)
            if (!strstr(dvfmEvsUmlFullUserData->dvfmEvsUmlFullName, dvfmEvsUmlName))
                dvfmEvsUmlInFilter = dvfmEvsUmlFalse;
        if (dvfmEvsUmlEmail)
            if (!strstr(dvfmEvsUmlFullUserData->dvfmEvsUmlEmail, dvfmEvsUmlEmail))
                dvfmEvsUmlInFilter = dvfmEvsUmlFalse;
        if (dvfmEvsUmlProfile && (dvfmEvsUmlFullUserData->dvfmEvsUmlProfile != dvfmEvsUmlProfile))
                dvfmEvsUmlInFilter = dvfmEvsUmlFalse;
        if(dvfmEvsUmlInFilter)
        {
            dvfmEvsUmlFilteredUserData = dvfmEvsUmlFullUserData;
            dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));;
            dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData->dvfmEvsUmlPreviousUserData = dvfmEvsUmlFilteredUserData;
            dvfmEvsUmlFilteredUserData = dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData;
        }
        dvfmEvsUmlFullUserData = dvfmEvsUmlFullUserData->dvfmEvsUmlNextUserData;
    }

    dvfmEvsUmlFilteredUserData = dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData;
    dvfmEvsUmlFilteredUserData->dvfmEvsUmlNextUserData = NULL;

    while (dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData)
        dvfmEvsUmlFilteredUserData = dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData;

    if (dvfmEvsUmlFilteredUserData->dvfmEvsUmlPreviousUserData)
        return dvfmEvsUmlEmptyList;
    
    *dvfmEvsUmlUserData = dvfmEvsUmlFilteredUserData;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
