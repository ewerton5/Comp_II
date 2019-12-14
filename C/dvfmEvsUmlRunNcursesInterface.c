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
#include	<string.h>
#include	"dvfmEvsUmlRunNcursesInterface.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlRunNcursesInterface(dvfmEvsUmlConfigurationOptionsType *,
 *                               char *,
 *                               dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - User nickname (I)
 * dvfmEvsUmlLanguageType - Language (I)
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
DvfmEvsUmlRunNcursesInterface(dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                              char *dvfmEvsUmlNickname,
                              dvfmEvsUmlLanguageType dvfmEvsUmlLanguage)
{
    if(!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;
    
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    bkgd(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    move(2,1);
    printw("Titulo");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(2));  
    move(3,1);
    printw("Texto");
    attroff(COLOR_PAIR(2));
    refresh();
    getch();

    if(dvfmEvsUmlNickname)
		if(strlen(dvfmEvsUmlNickname) != 0)
		{
            /*nickname code*/
        }

    endwin();

    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
