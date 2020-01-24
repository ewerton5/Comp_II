/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2008/02/01 10:19:06 $
 * $Log: dvfmEvsUmlUnlockUserAccount.h,v $
 * Revision 1.1  2008/02/01 10:19:06  ewerton.silles
 * Initial revision
 *
*/

#ifndef DVFM_EVS_UML_UNLOCK_USER_ACCOUNT_H
#define DVFM_EVS_UML_UNLOCK_USER_ACCOUNT_H "@(#)dvfmEvsUmlUnlockUserAccount.h $Revision: 1.1 $"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlUnlockUserAccount (dvfmEvsUmlConfigurationOptionsType *,
 *                              char *,
 *                              char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - blocked user nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Unlocks a user account.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlUnlockUserAccount (dvfmEvsUmlConfigurationOptionsType *,
                             char *,
                             char *);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlUnlockUserAccount.h,v $ */
