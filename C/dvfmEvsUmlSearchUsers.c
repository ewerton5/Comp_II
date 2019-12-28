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

#include	"dvfmEvsUmlSearchUsers.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlSearchUsers (dvfmEvsUmlConfigurationOptionsType *,
 *                        char *,
 *                        char *,
 *                        dvfmEvsUmlProfileType,
 *                        dvfmEvsUmlUserDataType **);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - full name or part of the name string (I)
 * char * - full email or part of the email string (I)
 * dvfmEvsUmlProfileType - profile (I)
 * dvfmEvsUmlUserDataType ** - first element in the list containing data about all users (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Search and return a list of all users.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlSearchUsers (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                       char *dvfmEvsUmlName,
                       char *dvfmEvsUmlEmail,
                       dvfmEvsUmlProfileType dvfmEvsUmlProfile,
                       dvfmEvsUmlUserDataType **dvfmEvsUmlUserData)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlName)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlEmail)
        return dvfmEvsUmlThirdEmptyPointer;

    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlFifthEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
