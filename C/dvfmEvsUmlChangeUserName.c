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

#include	"dvfmEvsUmlChangeUserName.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlChangeUserName (dvfmEvsUmlConfigurationOptionsType *,
 *                           char *,
 *                           char *,
 *                           char *,
 *                           char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - user nickname string (I)
 * char * - new name string (I)
 * char * - confirm name string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Changes a user name.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlChangeUserName (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                          char *dvfmEvsUmlAdminNickname,
                          char *dvfmEvsUmlUserNickname,
                          char *dvfmEvsUmlNewName,
                          char *dvfmEvsUmlConfirmName)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlNewName)
        return dvfmEvsUmlFourthEmptyPointer;

    if (!dvfmEvsUmlConfirmName)
        return dvfmEvsUmlFifthEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
