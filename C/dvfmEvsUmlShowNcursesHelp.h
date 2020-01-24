/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2008/02/01 10:19:06 $
 * $Log: dvfmEvsUmlShowNcursesHelp.h,v $
 * Revision 1.1  2008/02/01 10:19:06  ewerton.silles
 * Initial revision
 *
*/

#ifndef DVFM_EVS_UML_SHOW_NCURSES_HELP_H
#define DVFM_EVS_UML_SHOW_NCURSES_HELP_H "@(#)dvfmEvsUmlShowNcursesHelp.h $Revision: 1.1 $"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"

/*
 * void
 * DvfmEvsUmlShowNcursesHelp (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 *
 * Returned code:
 * 
 * void - no return
 * 
 * Description:
 * This function shows help in the Ncurse environment.
 */

void
DvfmEvsUmlShowNcursesHelp (dvfmEvsUmlConfigurationOptionsType *,
                           dvfmEvsUmlLanguageType);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlShowNcursesHelp.h,v $ */
