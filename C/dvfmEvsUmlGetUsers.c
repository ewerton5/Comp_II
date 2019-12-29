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

#include	"dvfmEvsUmlGetUsers.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetUsers (dvfmEvsUmlConfigurationOptionsType *,
 *                     dvfmEvsUmlUserDataType **);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * dvfmEvsUmlUserDataType ** - first element in the list containing data about all users (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Return a list of all users.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetUsers (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                    dvfmEvsUmlUserDataType **dvfmEvsUmlUserData)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlSecondEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
