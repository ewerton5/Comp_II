/*
  Universidade Federal do Rio de Janeiro
  Escola Politecnica
  Departamento de Eletronica e de Computacao
  Prof. Marcelo Luiz Drumond Lanza
  EEL 270 - Computacao II - Turma 2019/2
 
  $Author: ewerton.silles $
  $Date: 2008/02/01 10:19:06 $
  $Log: dvfmEvsUmlAddUser.h,v $
  Revision 1.1  2008/02/01 10:19:06  ewerton.silles
  Initial revision
 
*/

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

#ifndef DVFM_EVS_UML_ADD_USER
#define DVFM_EVS_UML_ADD_USER "@(#)dvfmEvsUmlAddUser.h $Revision: 1.1 $"

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
/* $RCSfile: dvfmEvsUmlAddUser.h,v $ */