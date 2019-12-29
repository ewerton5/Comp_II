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

#include	"dvfmEvsUmlChangeUserProfile.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlChangeUserProfile (dvfmEvsUmlConfigurationOptionsType *,
 *                              char *,
 *                              char *,
 *                              dvfmEvsUmlProfileType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - user nickname string (I)
 * dvfmEvsUmlProfileType - new profile (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Change a user profile.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlChangeUserProfile (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                             char *dvfmEvsUmlAdminNickname,
                             char *dvfmEvsUmlUserNickname,
                             dvfmEvsUmlProfileType dvfmEvsUmlNewProfile)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlAdminNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
