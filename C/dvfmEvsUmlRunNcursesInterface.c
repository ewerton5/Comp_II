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
    WINDOW * dvfmEvsUmlWindow;
    unsigned short dvfmEvsCursor = 1;
    char dvfmEvsBuffer [5][512];
    if(!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;
    
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    bkgd(COLOR_PAIR(1));

    mvprintw(2, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlSystemName, dvfmEvsUmlLanguage)))/2,
             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlSystemName, dvfmEvsUmlLanguage));

    mvprintw(4, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlAuthors, dvfmEvsUmlLanguage)))/2,
             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlAuthors, dvfmEvsUmlLanguage));
    
    mvprintw(5, 34, "David Vinicius Ferreira Moreira");
    
    mvprintw(6, 38, "Ewerton Vieira de Silles");

    dvfmEvsUmlWindow = newwin(12, 100, 7, 0);

    while(dvfmEvsCursor)
    {
        refresh();
        box(dvfmEvsUmlWindow, 0, 0);
        wrefresh(dvfmEvsUmlWindow);
        
        mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage)))/2,
                 "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage));

        if(dvfmEvsCursor == 1)
            attron(COLOR_PAIR(2));
        mvprintw(10, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage)))/2,
                 "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage));
        if(dvfmEvsCursor == 1)
            attroff(COLOR_PAIR(2));

        if(dvfmEvsCursor == 2)
            attron(COLOR_PAIR(2));
        mvprintw(11, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage)))/2,
                 "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage));
        if(dvfmEvsCursor == 2)
            attroff(COLOR_PAIR(2));
        
        if(dvfmEvsCursor == 3)
            attron(COLOR_PAIR(2));
        mvprintw(12, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage)))/2,
                 "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage));
        if(dvfmEvsCursor == 3)
            attroff(COLOR_PAIR(2));
        
        switch(mvgetch(0, 0))
        {
        case 65:
            if(dvfmEvsCursor > 1)
                dvfmEvsCursor--;
            break;
        case 66:
            if(dvfmEvsCursor < 3)
                dvfmEvsCursor++;
            break;
        case 67:
        case 10:
        case 32:
            refresh();
            box(dvfmEvsUmlWindow, 0, 0);
            wrefresh(dvfmEvsUmlWindow);

            switch (dvfmEvsCursor)
            {
            case 1:
                mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage)))/2,
                         "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage));

                mvprintw(10, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage));

                mvprintw(11, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlPassword, dvfmEvsUmlLanguage));

                mvprintw(16, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage));

                mvprintw(16, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));

                mvgetstr(10, 13, dvfmEvsBuffer [0]);
                move(11, 13);
                for (size_t i = 0; (dvfmEvsBuffer [1][i] = (char) getch()) != 10; i++)
                    mvprintw(11, i + 13, "*");
                
                dvfmEvsCursor = 2;
                while (dvfmEvsCursor)
                {
                    if(dvfmEvsCursor == 1)
                        attron(COLOR_PAIR(2));
                    mvprintw(16, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage));
                    if(dvfmEvsCursor == 1)
                        attroff(COLOR_PAIR(2));

                    if(dvfmEvsCursor == 2)
                        attron(COLOR_PAIR(2));
                    mvprintw(16, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));
                    if(dvfmEvsCursor == 2)
                        attroff(COLOR_PAIR(2));
                    
                    switch (mvgetch(0, 0))
                    {
                    case 68:
                        if(dvfmEvsCursor > 1)
                            dvfmEvsCursor--;
                        break;
                    case 67:
                        if(dvfmEvsCursor < 2)
                            dvfmEvsCursor++;
                        break;
                    case 10:
                    case 32:
                        if (dvfmEvsCursor == 1)
                            dvfmEvsCursor = 0;
                    }
                }
                dvfmEvsCursor = 1;
                break;
            case 2:
                mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage)))/2,
                         "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage));

                mvprintw(10, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlEmailRequest, dvfmEvsUmlLanguage));

                mvprintw(11, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlFullName, dvfmEvsUmlLanguage));

                mvprintw(12, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirmationFullName, dvfmEvsUmlLanguage));

                mvprintw(13, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlEmail, dvfmEvsUmlLanguage));

                mvprintw(14, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirmationEmail, dvfmEvsUmlLanguage));

                mvprintw(16, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage));

                mvprintw(16, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));

                mvgetstr(10, 40, dvfmEvsBuffer [0]);
                mvgetstr(11, 40, dvfmEvsBuffer [1]);
                mvgetstr(12, 40, dvfmEvsBuffer [2]);
                mvgetstr(13, 40, dvfmEvsBuffer [3]);
                mvgetstr(14, 40, dvfmEvsBuffer [4]);

                dvfmEvsCursor = 2;
                while (dvfmEvsCursor)
                {
                    if(dvfmEvsCursor == 1)
                        attron(COLOR_PAIR(2));
                    mvprintw(16, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage));
                    if(dvfmEvsCursor == 1)
                        attroff(COLOR_PAIR(2));

                    if(dvfmEvsCursor == 2)
                        attron(COLOR_PAIR(2));
                    mvprintw(16, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                             "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));
                    if(dvfmEvsCursor == 2)
                        attroff(COLOR_PAIR(2));
                    
                    switch (mvgetch(0, 0))
                    {
                    case 68:
                        if(dvfmEvsCursor > 1)
                            dvfmEvsCursor--;
                        break;
                    case 67:
                        if(dvfmEvsCursor < 2)
                            dvfmEvsCursor++;
                        break;
                    case 10:
                    case 32:
                        if (dvfmEvsCursor == 1)
                            dvfmEvsCursor = 0;
                    }
                }
                dvfmEvsCursor = 1;
                break;
            case 3:
                mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage)))/2,
                         "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage));

                mvprintw(10, 2, "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelpText, dvfmEvsUmlLanguage));

                attron(COLOR_PAIR(2));
                mvprintw(12, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage)))/2,
                         "%s",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage));
                attroff(COLOR_PAIR(2));

                while (mvgetch(0, 0) != 10);
            }
            break;
        case 68:
        case 127:
            dvfmEvsCursor = 0;
        }
    }


    if(dvfmEvsUmlNickname)
		if(strlen(dvfmEvsUmlNickname) != 0)
		{
            /*nickname code*/
        }
    delwin(dvfmEvsUmlWindow);
    endwin();

    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
