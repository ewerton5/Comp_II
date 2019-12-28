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

#include	"dvfmEvsUmlChangeUserEmail.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlChangeUserEmail (dvfmEvsUmlConfigurationOptionsType *,
 *                            char *,
 *                            char *,
 *                            char *,
 *                            char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - user nickname string (I)
 * char * - new email string (I)
 * char * - confirm email string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Changes a user email.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlChangeUserEmail (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                           char *dvfmEvsUmlAdminNickname,
                           char *dvfmEvsUmlUserNickname,
                           char *dvfmEvsUmlNewEmail,
                           char *dvfmEvsUmlConfirmEmail)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlNewEmail)
        return dvfmEvsUmlFourthEmptyPointer;

    if (!dvfmEvsUmlConfirmEmail)
        return dvfmEvsUmlFifthEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
