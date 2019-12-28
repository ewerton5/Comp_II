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

#include	"dvfmEvsUmlApproveRegistrationRequest.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlApproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *,
 *                                       char *,
 *                                       char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - user nickname string (I)
 * char * - requesting user nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Add a requesting user to the user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlApproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                                      char *dvfmEvsUmlUserNickname,
                                      char *dvfmEvsUmlRequestingUserNickname)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlRequestingUserNickname)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
