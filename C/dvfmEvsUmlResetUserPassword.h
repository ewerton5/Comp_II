/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2008/02/01 10:19:06 $
 * $Log: dvfmEvsUmlResetUserPassword.h,v $
 * Revision 1.1  2008/02/01 10:19:06  ewerton.silles
 * Initial revision
 *
*/

#ifndef DVFM_EVS_UML_RESET_USER_PASSWORD_H
#define DVFM_EVS_UML_RESET_USER_PASSWORD_H "@(#)dvfmEvsUmlResetUserPassword.h $Revision: 1.1 $"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlResetUserPassword (dvfmEvsUmlConfigurationOptionsType *,
 *                              char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Request a temporary password.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlResetUserPassword (dvfmEvsUmlConfigurationOptionsType *,
                             char *);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlResetUserPassword.h,v $ */
