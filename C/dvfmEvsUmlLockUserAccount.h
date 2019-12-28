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

#ifndef DVFM_EVS_UML_LOCK_USER_ACCOUNT_H
#define DVFM_EVS_UML_LOCK_USER_ACCOUNT_H "@(#)dvfmEvsUmlLockUserAccount.h $Revision$"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlLockUserAccount (dvfmEvsUmlConfigurationOptionsType *,
 *                            char *,
 *                            char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - user nickname string (I)
 * char * - blocked user nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Locks a user account.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlLockUserAccount (dvfmEvsUmlConfigurationOptionsType *,
                           char *,
                           char *);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */
