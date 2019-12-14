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

#ifndef DVFM_EVS_UML_RUN_NCURSES_INTERFACE_H
#define DVFM_EVS_UML_RUN_NCURSES_INTERFACE_H "@(#)dvfmEvsUmlRunNcursesInterface.h $Revision$"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlRunNcursesInterface(dvfmEvsUmlConfigurationOptionsType *,
 *                               char *,
 *                               dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - User nickname (I)
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Runs the program via Ncurses interface. The nickname argument may contain
 * a valid nickname, may be equal to NULL, or may be equal to a zero length string.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlRunNcursesInterface(dvfmEvsUmlConfigurationOptionsType *,
                              char *,
                              dvfmEvsUmlLanguageType);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */
