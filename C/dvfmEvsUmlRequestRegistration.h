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

#ifndef DVFM_EVS_UML_REQUEST_REGISTRATION_H
#define DVFM_EVS_UML_REQUEST_REGISTRATION_H "@(#)dvfmEvsUmlRequestRegistration.h $Revision$"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlRequestRegistration (dvfmEvsUmlConfigurationOptionsType *,
 *                                char *,
 *                                dvfmEvsUmlUserDataType *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - email string (I)
 * dvfmEvsUmlUserDataType * - user data (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Add a user to the requesting user list.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlRequestRegistration (dvfmEvsUmlConfigurationOptionsType *,
                               char *,
                               dvfmEvsUmlUserDataType *);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */
