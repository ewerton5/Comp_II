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

#include	"dvfmEvsUmlResetUserPassword.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlResetUserPassword (dvfmEvsUmlConfigurationOptionsType *,
 *                              char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Request a temporary password.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlResetUserPassword (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                             char *dvfmEvsUmlNickname)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
