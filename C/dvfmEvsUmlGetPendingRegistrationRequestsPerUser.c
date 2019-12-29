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

#include	"dvfmEvsUmlGetPendingRegistrationRequestsPerUser.h"

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
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
