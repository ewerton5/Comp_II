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

#include	"dvfmEvsUmlAcceptInvite.h"

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
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlTemporaryPassword)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
