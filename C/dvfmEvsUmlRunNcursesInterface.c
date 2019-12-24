/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2019/12/24 13:52:26 $
 * $Log: dvfmEvsUmlRunNcursesInterface.c,v $
 * Revision 1.1  2019/12/24 13:52:26  ewerton.silles
 * Initial revision
 *
*/

#include	<curses.h>
#include	<string.h>
#include	"dvfmEvsUmlRunNcursesInterface.h"
#include	"dvfmEvsUmlUserInterface.h"
#include	"dvfmEvsUmlFunctions.h"

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
    WINDOW *dvfmEvsUmlWindow;
    unsigned short dvfmEvsUmlCursor = 1, dvfmEvsUmlIndex;
    dvfmEvsUmlBool dvfmEvsUmlLogged = dvfmEvsUmlFalse, dvfmEvsUmlWithNickname = dvfmEvsUmlFalse,
                   dvfmEvsUmlIncorrectUser = dvfmEvsUmlFalse, dvfmEvsUmlBackScreen = dvfmEvsUmlFalse;
    char dvfmEvsUmlBuffer [5][DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE];
    char dvfmEvsUmlAuxiliary [2] = "0\0";
    FILE *dvfmEvsUmlRead;

    if(!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;
    
    if(dvfmEvsUmlNickname)
        if(strlen(dvfmEvsUmlNickname) != 0)
            dvfmEvsUmlWithNickname = dvfmEvsUmlTrue;

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    bkgd(COLOR_PAIR(1));

    mvprintw(2, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlSystemName, dvfmEvsUmlLanguage)))/2,
             "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlSystemName, dvfmEvsUmlLanguage));

    mvprintw(4, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlAuthors, dvfmEvsUmlLanguage)))/2,
             "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlAuthors, dvfmEvsUmlLanguage));
    
    mvprintw(5, 34, "David Vinicius Ferreira Moreira");
    
    mvprintw(6, 38, "Ewerton Vieira de Silles");

    dvfmEvsUmlWindow = newwin(15, 100, 7, 0);

    while(dvfmEvsUmlCursor)
    {
        refresh();
        box(dvfmEvsUmlWindow, 0, 0);
        wrefresh(dvfmEvsUmlWindow);
        
        mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage)))/2,
                 "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguage));

        if(dvfmEvsUmlCursor == 1)
            attron(COLOR_PAIR(2));
        mvprintw(10, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage)))/2,
                 "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage));
        if(dvfmEvsUmlCursor == 1)
            attroff(COLOR_PAIR(2));

        if(dvfmEvsUmlCursor == 2)
            attron(COLOR_PAIR(2));
        mvprintw(11, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage)))/2,
                 "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage));
        if(dvfmEvsUmlCursor == 2)
            attroff(COLOR_PAIR(2));
        
        if(dvfmEvsUmlCursor == 3)
            attron(COLOR_PAIR(2));
        mvprintw(12, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage)))/2,
                 "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage));
        if(dvfmEvsUmlCursor == 3)
            attroff(COLOR_PAIR(2));

        if(dvfmEvsUmlCursor == 4)
            attron(COLOR_PAIR(2));
        mvprintw(13, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExit, dvfmEvsUmlLanguage)))/2,
                 "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExit, dvfmEvsUmlLanguage));
        if(dvfmEvsUmlCursor == 4)
            attroff(COLOR_PAIR(2));
        
        
        switch(dvfmEvsUmlWithNickname?10:mvgetch(0, 0))
        {
        case 65:
            if(dvfmEvsUmlCursor > 1)
                dvfmEvsUmlCursor--;
            else
                dvfmEvsUmlCursor = 4;
            break;
        case 66:
            if(dvfmEvsUmlCursor < 4)
                dvfmEvsUmlCursor++;
            else
                dvfmEvsUmlCursor = 1;
            break;
        case 10:
            refresh();
            box(dvfmEvsUmlWindow, 0, 0);
            wrefresh(dvfmEvsUmlWindow);

            switch (dvfmEvsUmlCursor)
            {
            case 1:
                while (!dvfmEvsUmlLogged && !dvfmEvsUmlBackScreen)
                {
                    refresh();
                    box(dvfmEvsUmlWindow, 0, 0);
                    wrefresh(dvfmEvsUmlWindow);

                    mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage)))/2,
                            "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage));

                    mvprintw(10, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlLogin, dvfmEvsUmlLanguage));

                    mvprintw(11, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlPassword, dvfmEvsUmlLanguage));

                    if(!dvfmEvsUmlWithNickname)
                        mvprintw(18, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage)))/2,
                                "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage));

                    if(!dvfmEvsUmlWithNickname)
                        mvprintw(18, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                                "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));
                    else
                        mvprintw(18, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                                "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));

                    if(dvfmEvsUmlIncorrectUser)
                    {
                        attron(COLOR_PAIR(3));
                        mvprintw(16, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlIncorrectPassword, dvfmEvsUmlLanguage)))/2,
                                    "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlIncorrectPassword, dvfmEvsUmlLanguage));
                        attroff(COLOR_PAIR(3));
                    }

                    if(!dvfmEvsUmlWithNickname)
                        mvgetstr(10, 13, dvfmEvsUmlBuffer [0]);
                    else
                    {
                        strcpy(dvfmEvsUmlBuffer [0], dvfmEvsUmlNickname);
                        mvprintw(10, 13, "%s", dvfmEvsUmlBuffer [0]);
                    }

                    move(11, 13);
                    for (dvfmEvsUmlIndex = 0; (dvfmEvsUmlBuffer [1][dvfmEvsUmlIndex] = (char) getch()) != 10; dvfmEvsUmlIndex++)
                        mvprintw(11, dvfmEvsUmlIndex + 13, "*");
                    dvfmEvsUmlBuffer [1][dvfmEvsUmlIndex] = '\0';

                    if(dvfmEvsUmlWithNickname)
                    {
                        attron(COLOR_PAIR(2));
                        mvprintw(18, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                                "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));
                        attroff(COLOR_PAIR(2));
                    }

                    if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r")))
                    {
                        refresh();
                        box(dvfmEvsUmlWindow, 0, 0);
                        wrefresh(dvfmEvsUmlWindow);
                        mvprintw(13, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExiting, dvfmEvsUmlLanguage)))/2,
                                            "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExiting, dvfmEvsUmlLanguage));
                        mvgetch(0, 0);

                        delwin(dvfmEvsUmlWindow);
                        endwin();
                        return dvfmEvsUmlCantOpenFile;
                    }
                    
                    while(fgets(dvfmEvsUmlBuffer [2], DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
                    {
                        strcpy(dvfmEvsUmlBuffer [2], strstr(dvfmEvsUmlBuffer [2], ":"));
                        dvfmEvsUmlAuxiliary [0] = dvfmEvsUmlBuffer [2][1];
                        strcpy(dvfmEvsUmlBuffer [2], strstr(dvfmEvsUmlBuffer [2], dvfmEvsUmlAuxiliary));

                        strcpy(dvfmEvsUmlBuffer [3], strstr(dvfmEvsUmlBuffer [2], "$"));

                        for (dvfmEvsUmlIndex = 0; dvfmEvsUmlBuffer [2][dvfmEvsUmlIndex] != '\0'; dvfmEvsUmlIndex++)
                            if(dvfmEvsUmlBuffer [2][dvfmEvsUmlIndex] == ':')
                            {
                                dvfmEvsUmlBuffer [2][dvfmEvsUmlIndex] = '\0';
                                break;
                            }
                        
                        for (dvfmEvsUmlIndex = 0; dvfmEvsUmlBuffer [3][dvfmEvsUmlIndex] != '\0'; dvfmEvsUmlIndex++)
                            if(dvfmEvsUmlBuffer [3][dvfmEvsUmlIndex] == ':')
                            {
                                dvfmEvsUmlBuffer [3][dvfmEvsUmlIndex] = '\0';
                                break;
                            }

                        if(!strcmp(dvfmEvsUmlBuffer [0], dvfmEvsUmlBuffer [2]))
                            if(!DvfmEvsUmlCheckPassword(dvfmEvsUmlBuffer [1], dvfmEvsUmlBuffer [3]))
                                dvfmEvsUmlLogged = dvfmEvsUmlTrue;
                    }

                    if(ferror(dvfmEvsUmlRead))
                    {
                        fclose(dvfmEvsUmlRead);

                        refresh();
                        box(dvfmEvsUmlWindow, 0, 0);
                        wrefresh(dvfmEvsUmlWindow);
                        mvprintw(13, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExiting, dvfmEvsUmlLanguage)))/2,
                                            "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExiting, dvfmEvsUmlLanguage));
                        mvgetch(0, 0);

                        delwin(dvfmEvsUmlWindow);
                        endwin();
                        
                        return dvfmEvsUmlReadError;
                    }

                    fclose(dvfmEvsUmlRead);
                    
                    if(!dvfmEvsUmlWithNickname)
                    {
                        dvfmEvsUmlCursor = 2;

                        while (dvfmEvsUmlCursor)
                        {
                            if(dvfmEvsUmlCursor == 1)
                                attron(COLOR_PAIR(2));
                            mvprintw(18, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage)))/2,
                                    "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage));
                            if(dvfmEvsUmlCursor == 1)
                                attroff(COLOR_PAIR(2));

                            if(dvfmEvsUmlCursor == 2)
                                attron(COLOR_PAIR(2));
                            mvprintw(18, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                                    "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));
                            if(dvfmEvsUmlCursor == 2)
                                attroff(COLOR_PAIR(2));
                        
                            switch (mvgetch(0, 0))
                            {
                            case 68:
                                if(dvfmEvsUmlCursor > 1)
                                    dvfmEvsUmlCursor--;
                                break;
                            case 67:
                                if(dvfmEvsUmlCursor < 2)
                                    dvfmEvsUmlCursor++;
                                break;
                            case 10:
                                if (dvfmEvsUmlCursor == 1)
                                {
                                    dvfmEvsUmlBackScreen = dvfmEvsUmlTrue;
                                    dvfmEvsUmlLogged = dvfmEvsUmlFalse;
                                }
                                else if (!dvfmEvsUmlLogged)
                                    dvfmEvsUmlIncorrectUser = dvfmEvsUmlTrue;
                                dvfmEvsUmlCursor = 0;
                            }
                        }
                    }
                    else 
                        while ((dvfmEvsUmlBuffer[2][0] = mvgetch(0, 0)) != 10)
                            if(dvfmEvsUmlBuffer[2][0] == 27)
                            {
                                dvfmEvsUmlCursor = 0;
                                break;
                            }
                        if (!dvfmEvsUmlLogged)
                            dvfmEvsUmlIncorrectUser = dvfmEvsUmlTrue;
                }

                /*next screen*/
                if(dvfmEvsUmlLogged)
                {
                    refresh();
                    box(dvfmEvsUmlWindow, 0, 0);
                    wrefresh(dvfmEvsUmlWindow);

                    mvprintw(8, (int) 47, "Logged");
                    mvprintw(8, (int) (100 - strlen(dvfmEvsUmlBuffer [0]))/2,
                            "%s", dvfmEvsUmlBuffer [0]);

                    attron(COLOR_PAIR(2));
                    mvprintw(12, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExit, dvfmEvsUmlLanguage)))/2,
                            "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExit, dvfmEvsUmlLanguage));
                    attroff(COLOR_PAIR(2));

                    while (mvgetch(0, 0) != 10);

                    dvfmEvsUmlBackScreen = dvfmEvsUmlTrue;
                }
                
                if(dvfmEvsUmlBackScreen)
                {
                    dvfmEvsUmlBackScreen = dvfmEvsUmlFalse;
                    dvfmEvsUmlIncorrectUser = dvfmEvsUmlFalse;
                    dvfmEvsUmlCursor = 1;
                }
                break;
            case 2:
                mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage)))/2,
                         "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlRegister, dvfmEvsUmlLanguage));

                mvprintw(10, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlEmailRequest, dvfmEvsUmlLanguage));

                mvprintw(11, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlFullName, dvfmEvsUmlLanguage));

                mvprintw(12, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirmationFullName, dvfmEvsUmlLanguage));

                mvprintw(13, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlEmail, dvfmEvsUmlLanguage));

                mvprintw(14, 2, "%s:",DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirmationEmail, dvfmEvsUmlLanguage));

                mvprintw(16, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage)))/2,
                             "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage));

                mvprintw(16, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                             "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));

                mvgetstr(10, 40, dvfmEvsUmlBuffer [0]);
                mvgetstr(11, 40, dvfmEvsUmlBuffer [1]);
                mvgetstr(12, 40, dvfmEvsUmlBuffer [2]);
                mvgetstr(13, 40, dvfmEvsUmlBuffer [3]);
                mvgetstr(14, 40, dvfmEvsUmlBuffer [4]);

                dvfmEvsUmlCursor = 2;
                while (dvfmEvsUmlCursor)
                {
                    if(dvfmEvsUmlCursor == 1)
                        attron(COLOR_PAIR(2));
                    mvprintw(16, (int) (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage)))/2,
                             "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage));
                    if(dvfmEvsUmlCursor == 1)
                        attroff(COLOR_PAIR(2));

                    if(dvfmEvsUmlCursor == 2)
                        attron(COLOR_PAIR(2));
                    mvprintw(16, (int) 50 + (50 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage)))/2,
                             "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlConfirm, dvfmEvsUmlLanguage));
                    if(dvfmEvsUmlCursor == 2)
                        attroff(COLOR_PAIR(2));
                    
                    switch (mvgetch(0, 0))
                    {
                    case 68:
                        if(dvfmEvsUmlCursor > 1)
                            dvfmEvsUmlCursor--;
                        break;
                    case 67:
                        if(dvfmEvsUmlCursor < 2)
                            dvfmEvsUmlCursor++;
                        break;
                    case 10:
                        if (dvfmEvsUmlCursor == 1)
                            dvfmEvsUmlCursor = 0;
                    }
                }
                dvfmEvsUmlCursor = 1;
                break;
            case 3:
                mvprintw(8, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage)))/2,
                         "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelp, dvfmEvsUmlLanguage));

                mvprintw(10, 2, "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlHelpText, dvfmEvsUmlLanguage));

                attron(COLOR_PAIR(2));
                mvprintw(12, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage)))/2,
                         "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlBack, dvfmEvsUmlLanguage));
                attroff(COLOR_PAIR(2));

                while (mvgetch(0, 0) != 10);

                break;
            case 4:
                dvfmEvsUmlCursor = 0;
            }
        }
    }

    refresh();
    box(dvfmEvsUmlWindow, 0, 0);
    wrefresh(dvfmEvsUmlWindow);
    mvprintw(13, (int) (100 - strlen(DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExiting, dvfmEvsUmlLanguage)))/2,
                         "%s", DvfmEvsUmlGetNcursesUserInterfaceMessage(dvfmEvsUmlExiting, dvfmEvsUmlLanguage));
    mvgetch(0, 0);

    delwin(dvfmEvsUmlWindow);
    endwin();

    return dvfmEvsUmlOk;
}

/* $RCSfile: dvfmEvsUmlRunNcursesInterface.c,v $ */
