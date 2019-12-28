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

#ifndef DVFM_EVS_UML_SHOW_CONFIGURATION_VALUES_H
#define DVFM_EVS_UML_SHOW_CONFIGURATION_VALUES_H "@(#)dvfmEvsUmlShowConfigurationValues.h $Revision$"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlShowConfigurationValues (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Displays the values of all configuration options.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlShowConfigurationValues (dvfmEvsUmlConfigurationOptionsType *,
                                   dvfmEvsUmlLanguageType);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */
