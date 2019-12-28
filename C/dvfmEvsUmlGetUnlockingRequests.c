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

#include	"dvfmEvsUmlGetUnlockingRequests.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetUnlockingRequests (dvfmEvsUmlConfigurationOptionsType *,
 *                                 char *,
 *                                 dvfmEvsUmlNicknameListType *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - nickname string (I)
 * dvfmEvsUmlNicknameListType ** - first element in the list containing nickname of users requesting account unlocking (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Return a list containing the data of all users requesting account unlocking.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetUnlockingRequests (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                                char *dvfmEvsUmlNickname,
                                dvfmEvsUmlNicknameListType **dvfmEvsUmlNicknameList)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (!dvfmEvsUmlNicknameList)
        return dvfmEvsUmlThirdEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
