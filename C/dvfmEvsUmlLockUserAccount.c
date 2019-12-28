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
                           char *dvfmEvsUmlUserNickname,
                           char *dvfmEvsUmlBlockedUserNickname)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlBlockedUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
