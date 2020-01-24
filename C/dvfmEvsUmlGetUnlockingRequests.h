/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2008/02/01 10:19:06 $
 * $Log: dvfmEvsUmlGetUnlockingRequests.h,v $
 * Revision 1.1  2008/02/01 10:19:06  ewerton.silles
 * Initial revision
 *
*/

#ifndef DVFM_EVS_UML_GET_UNLOCKING_REQUESTS_H
#define DVFM_EVS_UML_GET_UNLOCKING_REQUESTS_H "@(#)dvfmEvsUmlGetUnlockingRequests.h $Revision: 1.1 $"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetUnlockingRequests (dvfmEvsUmlConfigurationOptionsType *,
 *                                 char *,
 *                                 dvfmEvsUmlNicknameListType **);
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
DvfmEvsUmlGetUnlockingRequests (dvfmEvsUmlConfigurationOptionsType *,
                                char *,
                                dvfmEvsUmlNicknameListType **);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlGetUnlockingRequests.h,v $ */
