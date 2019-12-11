/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/16 03:48:22 $
$Log: dvfmEvsUmlUserInterface.c,v $
Revision 1.2  2019/11/16 03:48:22  ewerton.silles
*** empty log message ***

Revision 1.1  2019/11/15 01:42:45  ewerton.silles
Initial revision
 
*/

#include			"dvfmEvsUmlTypes.h"
#include			"dvfmEvsUmlUserInterface.h"

					/*VARIAVEIS GLOBAIS*/

char *dvfmEvsUmlCliUserInterfaceMessages [dvfmEvsUmlLanguagesAmount][dvfmEvsUmlSizeUserInterfaceMessageNumberType]=
{
 {
	"Account Management System",
	"Authors",
	"Login",
	"Password",
	"Confirm",
	"Portuguese",
	"dvfmEvsUmlPortuguese",
	"Register",
	"Temporary password",
	"Help",
	"Use license",
	"Electronic mail for request",
	"Full name",
	"Confirmation Full Name",
	"Email",
	"Confirm Email",
	"Home page"
 },

 {
	"Sistema de Gerenciamento de Contas",
	"Autores",
	"Login",
	"Senha",
	"Confirmar",
	"Ingles",
	"dvfmEvsUmlEnglish",
	"Cadastro",
	"Senha temporaria",
	"Ajuda",
	"Licenca de uso",
	"Correio eletronico para solicitacao",
	"Nome completo",
	"Confirmaçao Nome completo",
	"Correio eletronico",
	"Confirmar correio eletronico",
	"Pagina inicial"
 }
};

char *dvfmEvsUmlNcursesUserInterfaceMessages [dvfmEvsUmlLanguagesAmount][dvfmEvsUmlSizeUserInterfaceMessageNumberType]=
{
 {
	"Account Management System",
	"Authors",
	"Login",
	"Password",
	"Confirm",
	"Portuguese",
	"dvfmEvsUmlPortuguese",
	"Register",
	"Temporary password",
	"Help",
	"Use license",
	"Electronic mail for request",
	"Full name",
	"Confirmation Full Name",
	"Email",
	"Confirm Email",
	"Home page"
 },

 {
	"Sistema de Gerenciamento de Contas",
	"Autores",
	"Login",
	"Senha",
	"Confirmar",
	"Ingles",
	"dvfmEvsUmlEnglish",
	"Cadastro",
	"Senha temporaria",
	"Ajuda",
	"Licenca de uso",
	"Correio eletronico para solicitacao",
	"Nome completo",
	"Confirmaçao Nome completo",
	"Correio eletronico",
	"Confirmar correio eletronico",
	"Pagina inicial"
 }
};

char *dvfmEvsUmlWebUserInterfaceMessages [dvfmEvsUmlLanguagesAmount][dvfmEvsUmlSizeUserInterfaceMessageNumberType]=
{
 {
	"Account Management System",
	"Authors",
	"Login",
	"Password",
	"Confirm",
	"Portuguese",
	"dvfmEvsUmlPortuguese",
	"Register",
	"Temporary password",
	"Help",
	"Use license",
	"Electronic mail for request",
	"Full name",
	"Confirmation Full Name",
	"Email",
	"Confirm Email",
	"Home page"
 },

 {
	"Sistema de Gerenciamento de Contas",
	"Autores",
	"Login",
	"Senha",
	"Confirmar",
	"Ingles",
	"dvfmEvsUmlEnglish",
	"Cadastro",
	"Senha temporaria",
	"Ajuda",
	"Licenca de uso",
	"Correio eletronico para solicitacao",
	"Nome completo",
	"Confirmaçao Nome completo",
	"Correio eletronico",
	"Confirmar correio eletronico",
	"Pagina inicial"
 }
};

/*
 * char *
 * DvfmEvsUmlGetCliUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 * dvfmEvsUmlUserInterfaceMessageNumberType - integer that corrects a user interface message number type enum (I)
 *
 * Returned code:
 * char * - User interface message
 *
 * Description:
 * This function returns the appropriate user interface message to the user interface message code and language option in the interface CLI.
 */

char *
DvfmEvsUmlGetCliUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType dvfmEvsUmlUserInterfaceMessageNumberCode, dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
{
	char *dvfmEvsUmlIndexUserInterfaceMessageNumber = "Out of range user interface message number message";

	if(dvfmEvsUmlLanguageOption >= dvfmEvsUmlLanguagesAmount)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	if(dvfmEvsUmlUserInterfaceMessageNumberCode >= dvfmEvsUmlSizeUserInterfaceMessageNumberType)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	return dvfmEvsUmlCliUserInterfaceMessages [dvfmEvsUmlLanguageOption][dvfmEvsUmlUserInterfaceMessageNumberCode];
}

/*
 * char *
 * DvfmEvsUmlGetNcursesUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 * dvfmEvsUmlUserInterfaceMessageNumberType - integer that corrects a user interface message number type enum (I)
 *
 * Returned code:
 * char * - User interface message
 *
 * Description:
 * This function returns the appropriate user interface message to the user interface message code and language option in the interface Ncurses.
 */

char *
DvfmEvsUmlGetNcursesUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType dvfmEvsUmlUserInterfaceMessageNumberCode, dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
{
	char *dvfmEvsUmlIndexUserInterfaceMessageNumber = "Out of range user interface message number message";

	if(dvfmEvsUmlLanguageOption >= dvfmEvsUmlLanguagesAmount)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	if(dvfmEvsUmlUserInterfaceMessageNumberCode >= dvfmEvsUmlSizeUserInterfaceMessageNumberType)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	return dvfmEvsUmlNcursesUserInterfaceMessages [dvfmEvsUmlLanguageOption][dvfmEvsUmlUserInterfaceMessageNumberCode];
}

/*
 * char *
 * DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 * dvfmEvsUmlUserInterfaceMessageNumberType - integer that corrects a user interface message number type enum (I)
 *
 * Returned code:
 * char * - User interface message
 *
 * Description:
 * This function returns the appropriate user interface message to the user interface message code and language option in the interface Web.
 */

char *
DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType dvfmEvsUmlUserInterfaceMessageNumberCode, dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
{
	char *dvfmEvsUmlIndexUserInterfaceMessageNumber = "Out of range user interface message number message";

	if(dvfmEvsUmlLanguageOption >= dvfmEvsUmlLanguagesAmount)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	if(dvfmEvsUmlUserInterfaceMessageNumberCode >= dvfmEvsUmlSizeUserInterfaceMessageNumberType)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	return dvfmEvsUmlWebUserInterfaceMessages [dvfmEvsUmlLanguageOption][dvfmEvsUmlUserInterfaceMessageNumberCode];
}
/* $RCSfile: dvfmEvsUmlUserInterface.c,v $ */
