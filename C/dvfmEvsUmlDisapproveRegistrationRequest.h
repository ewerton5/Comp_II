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

#ifndef DVFM_EVS_UML_DISAPPROVE_REGISTRATION_REQUEST_H
#define DVFM_EVS_UML_DISAPPROVE_REGISTRATION_REQUEST_H "@(#)dvfmEvsUmlDisapproveRegistrationRequest.h $Revision$"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlDisapproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *,
 *                                          char *,
 *                                          char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - user nickname string (I)
 * char * - requesting user nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Remove a requesting user from the requesting user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlDisapproveRegistrationRequest (dvfmEvsUmlConfigurationOptionsType *,
                                         char *,
                                         char *);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */
