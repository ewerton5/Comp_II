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

#ifndef DVFM_EVS_UML_CHANGE_USER_PROFILE_H
#define DVFM_EVS_UML_CHANGE_USER_PROFILE_H "@(#)dvfmEvsUmlChangeUserProfile.h $Revision$"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlChangeUserProfile (dvfmEvsUmlConfigurationOptionsType *,
 *                              char *,
 *                              char *,
 *                              dvfmEvsUmlProfileType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - administrator nickname string (I)
 * char * - user nickname string (I)
 * dvfmEvsUmlProfileType - new profile (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Change a user profile.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlChangeUserProfile (dvfmEvsUmlConfigurationOptionsType *,
                             char *,
                             char *,
                             dvfmEvsUmlProfileType);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */
