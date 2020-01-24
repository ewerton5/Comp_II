/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2008/02/01 10:19:06 $
 * $Log: dvfmEvsUmlGetPendingRegistrationRequestsPerUser.h,v $
 * Revision 1.1  2008/02/01 10:19:06  ewerton.silles
 * Initial revision
 *
*/

#ifndef DVFM_EVS_UML_GET_PENDING_REGISTRATION_REQUESTS_PER_USER_H
#define DVFM_EVS_UML_GET_PENDING_REGISTRATION_REQUESTS_PER_USER_H "@(#)dvfmEvsUmlGetPendingRegistrationRequestsPerUser.h $Revision: 1.1 $"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetPendingRegistrationRequestsPerUser (dvfmEvsUmlConfigurationOptionsType *,
 *                                                  char *,
 *                                                  dvfmEvsUmlUserDataType **);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - nickname string (I)
 * dvfmEvsUmlUserDataType ** - first element in the list containing data about pending requests for the user in question (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Return a list of all valid requests not met by the user in question.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetPendingRegistrationRequestsPerUser (dvfmEvsUmlConfigurationOptionsType *,
                                                 char *,
                                                 dvfmEvsUmlUserDataType **);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlGetPendingRegistrationRequestsPerUser.h,v $ */
