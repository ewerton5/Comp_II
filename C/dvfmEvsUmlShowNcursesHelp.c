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

#include	<curses.h>
#include	"dvfmEvsUmlShowNcursesHelp.h"
#include	"dvfmEvsUmlUserInterface.h"

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
DvfmEvsUmlShowNcursesHelp (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                           dvfmEvsUmlLanguageType dvfmEvsUmlLanguage)
{
    printw("%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelpText, dvfmEvsUmlLanguage));
}

/* $RCSfile$ */
