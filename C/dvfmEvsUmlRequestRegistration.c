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

#include	"dvfmEvsUmlRequestRegistration.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlRequestRegistration (dvfmEvsUmlConfigurationOptionsType *,
 *                                char *,
 *                                dvfmEvsUmlUserDataType *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - email string (I)
 * dvfmEvsUmlUserDataType * - user data (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Add a user to the requesting user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlRequestRegistration (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                               char *dvfmEvsUmlEmail,
                               dvfmEvsUmlUserDataType *dvfmEvsUmlUserData)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlEmail)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
