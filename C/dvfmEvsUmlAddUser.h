/*
  Universidade Federal do Rio de Janeiro
  Escola Politecnica
  Departamento de Eletronica e de Computacao
  Prof. Marcelo Luiz Drumond Lanza
  EEL 270 - Computacao II - Turma 2019/2
 
  $Author$
  $Date$
  $Log$ 
*/

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

#ifndef DVFM_EVS_UML_ADD_USER
#define DVFM_EVS_UML_ADD_USER "@(#)dvfmEvsUmlAddUser.h $Revision$"

/* ===== beginning of file code ===== */

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlAddUser (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlUserDataType *);
 *
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - configuration options (I)
 * dvfmEvsUmlUserDataType * - struct user information (I)
 * 
 * Returned code:
 * 
 * dvfmEvsUmlOk - all right
 * 
 * Description:
 * Permanently or temporarily add new user data to the system
 */

dvfmEvsUmlErrorType
DvfmEvsUmlAddUser (dvfmEvsUmlConfigurationOptionsType *,
                   dvfmEvsUmlUserDataType *);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */