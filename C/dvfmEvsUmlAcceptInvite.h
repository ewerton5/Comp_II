/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2008/02/01 10:19:06 $
 * $Log: dvfmEvsUmlAcceptInvite.h,v $
 * Revision 1.1  2008/02/01 10:19:06  ewerton.silles
 * Initial revision
 *
*/

#ifndef DVFM_EVS_UML_ACCEPT_INVITE_H
#define DVFM_EVS_UML_ACCEPT_INVITE_H "@(#)dvfmEvsUmlAcceptInvite.h $Revision: 1.1 $"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlAcceptInvite (dvfmEvsUmlConfigurationOptionsType *,
 *                         char *,
 *                         dvfmEvsUmlUserDataType *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - temporary password string (I)
 * dvfmEvsUmlUserDataType * - user data (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Add a invited user to the user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlAcceptInvite (dvfmEvsUmlConfigurationOptionsType *,
                        char *,
                        dvfmEvsUmlUserDataType *);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlAcceptInvite.h,v $ */
