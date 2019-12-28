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

#include	"dvfmEvsUmlConfirmEmailChange.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlConfirmEmailChange (dvfmEvsUmlConfigurationOptionsType *,
 *                               char *,
 *                               char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - user nickname string (I)
 * char * - validation key string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Validate an email.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlConfirmEmailChange (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                              char *dvfmEvsUmlNickname,
                              char *dvfmEvsUmlValidationKey)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlValidationKey)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
