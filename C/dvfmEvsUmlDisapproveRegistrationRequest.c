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

#include	"dvfmEvsUmlDisapproveRegistrationRequest.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlDisapproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *,
 *                                          char *,
 *                                          char *);
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
 * Remove a requesting user from the requesting user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlDisapproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
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
