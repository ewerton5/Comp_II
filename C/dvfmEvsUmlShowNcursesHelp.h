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

#ifndef DVFM_EVS_UML_SHOW_NCURSES_HELP_H
#define DVFM_EVS_UML_SHOW_NCURSES_HELP_H "@(#)dvfmEvsUmlShowNcursesHelp.h $Revision$"

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
 * Displays the help message in the desired language in the Ncurses interface.
 */

void
DvfmEvsUmlShowNcursesHelp (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);

/* ===== end of file code ====== */

#endif
/* $RCSfile$ */
