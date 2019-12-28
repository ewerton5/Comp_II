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

#include	"dvfmEvsUmlChangeUserPassword.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlChangeUserPassword (dvfmEvsUmlConfigurationOptionsType *,
 *                               char *,
 *                               char *,
 *                               char *,
 *                               char *,
 *                               char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - user nickname string (I)
 * char * - current password string (I)
 * char * - new password string (I)
 * char * - confirm password string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Changes a user password.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlChangeUserPassword (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                              char *dvfmEvsUmlAdminNickname,
                              char *dvfmEvsUmlUserNickname,
                              char *dvfmEvsUmlCurrentPassword,
                              char *dvfmEvsUmlNewPassword,
                              char *dvfmEvsUmlConfirmPassword)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlNewPassword)
        return dvfmEvsUmlFifthEmptyPointer;

    if (!dvfmEvsUmlConfirmPassword)
        return dvfmEvsUmlSixthEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
