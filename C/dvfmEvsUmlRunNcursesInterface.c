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
#include	"dvfmEvsUmlUserInterface.h"

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
    unsigned short dvfmEvsCursor = 0;
    unsigned short dvfmEvsScreen = 1;
    if(!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;
    
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    bkgd(COLOR_PAIR(1));

    move(2,2);
    printw("%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlSystemName, dvfmEvsUmlLanguage));
    
    move(4,2);
    printw("%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlAuthors, dvfmEvsUmlLanguage));
    
    move(5,2);
    printw("David Vinicius Ferreira Moreira");
    
    move(6,2);
    printw("Ewerton Vieira de Silles");

    while(dvfmEvsScreen)
    {
        move(7,2);
        printw("\t\t\t\t\t\t\t\tCursor:%u\tScreen:%u", dvfmEvsCursor, dvfmEvsScreen);
        if(!dvfmEvsCursor)
            attron(COLOR_PAIR(2));
        move(8,2);
        printw("%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage));
        if(!dvfmEvsCursor)
            attroff(COLOR_PAIR(2));

        if(dvfmEvsCursor == 1)
            attron(COLOR_PAIR(2));
        move(9,2);
        printw("%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage));
        if(dvfmEvsCursor == 1)
            attroff(COLOR_PAIR(2));
        
        if(dvfmEvsCursor == 2)
            attron(COLOR_PAIR(2));
        move(10,2);
        printw("%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage));
        if(dvfmEvsCursor == 2)
            attroff(COLOR_PAIR(2));
        
        switch(getch())
        {
            case 65:
                if(dvfmEvsCursor > 0)
                    dvfmEvsCursor--;
                break;
            case 66:
                if(dvfmEvsCursor < 2)
                    dvfmEvsCursor++;
                break;
            case 67:
            case 10:
            case 32:
                dvfmEvsScreen++;
                break;
            case 68:
            case 127:
                dvfmEvsScreen--;
        }
    }


    if(dvfmEvsUmlNickname)
		if(strlen(dvfmEvsUmlNickname) != 0)
		{
            /*nickname code*/
        }

    endwin();

    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
