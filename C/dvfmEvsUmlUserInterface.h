/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2019/11/16 03:48:22 $
 * $Log: dvfmEvsUmlUserInterface.h,v $
 * Revision 1.2  2019/11/16 03:48:22  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/11/15 01:42:45  ewerton.silles
 * Initial revision
 * 
*/

#ifndef DVFM_EVS_UML_USER_INTERFACE_H
#define DVFM_EVS_UML_USER_INTERFACE_H "@(#)dvfmEvsUmlUserInterface.h $Revision: 1.2 $"

/* ===== beginning of file code ===== */

#include			"dvfmEvsUmlTypes.h"

typedef enum 
{
    dvfmEvsUmlSystemName,
    dvfmEvsUmlAuthors,
    dvfmEvsUmlLogin,
    dvfmEvsUmlPassword,
    dvfmEvsUmlConfirm,
    dvfmEvsUmlLanguageOption,
    dvfmEvsUmlRegister,
    dvfmEvsUmlTemporaryPassword,
    dvfmEvsUmlHelp,
    dvfmEvsUmlUseLicense,
    dvfmEvsUmlEmailRequest,
    dvfmEvsUmlFullName,
    dvfmEvsUmlConfirmationFullName,
    dvfmEvsUmlEmail,
    dvfmEvsUmlConfirmationEmail,
    dvfmEvsUmlHomePage,
    dvfmEvsUmlSizeUserInterfaceMessageNumberType
} dvfmEvsUmlUserInterfaceMessageNumberType;

/*
 * char *
 * DvfmEvsUmlGetCliUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * char * - user interface message string (O)
 * dvfmEvsUmlUserInterfaceMessageNumberType - user interface message number code Type enum (I)
 * dvfmEvsUmlLanguageType - language code Type enum (I)
 *
 * Returned code:
 * char *
 *
 * Description:
 * This function converts the user interface message number code into an user interface message for interface CLI.
 */

char *
DvfmEvsUmlGetCliUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);

/*
 * char *
 * dvfmEvsUmlGetCliNcursesInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * char * - user interface message string (O)
 * dvfmEvsUmlUserInterfaceMessageNumberType - user interface message number code Type enum (I)
 * dvfmEvsUmlLanguageType - language code Type enum (I)
 *
 * Returned code:
 * char *
 *
 * Description:
 * This function converts the user interface message number code into an user interface message for interface Ncurses.
 */

char *
DvfmEvsUmlGetNcursesUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);

/*
 * char *
 * dvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * char * - user interface message string (O)
 * dvfmEvsUmlUserInterfaceMessageNumberType - user interface message number code Type enum (I)
 * dvfmEvsUmlLanguageType - language code Type enum (I)
 *
 * Returned code:
 * char *
 *
 * Description:
 * This function converts the user interface message number code into an user interface message for interface Web.
 */

char *
DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlUserInterface.h,v $ */
