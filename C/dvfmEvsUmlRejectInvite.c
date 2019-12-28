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

#include	"dvfmEvsUmlRejectInvite.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlRejectInvite (dvfmEvsUmlConfigurationOptionsType *,
 *                         char *,
 *                         char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - nickname string (I)
 * char * - temporary password string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Remove a invited user from the invited user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlRejectInvite (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                        char *dvfmEvsUmlNickname,
                        char *dvfmEvsUmlTemporaryPassword)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlTemporaryPassword)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
