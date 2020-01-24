/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2020/01/24 05:37:49 $
$Log: dvfmEvsUmlUserInterface.c,v $
Revision 1.4  2020/01/24 05:37:49  ewerton.silles
*** empty log message ***

Revision 1.3  2019/12/24 13:52:26  ewerton.silles
*** empty log message ***

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
		"Reset password",
		"Help",
		"Use license",
		"Electronic mail for request",
		"Full name",
		"Confirmation Full Name",
		"Email",
		"Confirm Email",
		"Home page",
		"Help text",
		"Use license text",
		"Add permanent user",
		"Confirm password",
		"Add",
		"Add temporary user",
		"Exit",
		"Back",
		"Incorrect nickname or password",
		"You are leaving"
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
		"Alterar senha",
		"Ajuda",
		"Licenca de uso",
		"Correio eletronico para solicitacao",
		"Nome completo",
		"Confirmar nome completo",
		"Correio eletronico",
		"Confirmar correio eletronico",
		"Pagina inicial",
		"texto de ajuda",
		"texto de licenca de uso",
		"Adicionar usuario permanente",
		"Confirmar senha",
		"Adicionar",
		"Adicionar usuario temporario",
		"Sair",
		"Voltar",
		"Apelido ou senha incorretos",
		"Voce esta saindo"
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
		"Reset password",
		"Help",
		"Use license",
		"Electronic mail for request",
		"Full name",
		"Confirmation Full Name",
		"Email",
		"Confirm Email",
		"Home page",
		"Use the directional arrows to move the cursor and press 'Enter' to select options",
		"Use license text",
		"Add permanent user",
		"Confirm password",
		"Add",
		"Add temporary user",
		"Exit",
		"Back",
		"Incorrect nickname or password",
		"You are leaving the program, press any key to continue"
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
		"Alterar senha",
		"Ajuda",
		"Licenca de uso",
		"Correio eletronico para solicitacao",
		"Nome completo",
		"Confirmar nome completo",
		"Correio eletronico",
		"Confirmar correio eletronico",
		"Pagina inicial",
		"Utilize as setas direcionais para mover o cusor e aperte 'Enter' para selecionar as opcoes",
		"texto de licenca de uso",
		"Adicionar usuario permanente",
		"Confirmar senha",
		"Adicionar",
		"Adicionar usuario temporario",
		"Sair",
		"Voltar",
		"Apelido ou senha incorretos",
		"Voce esta saindo do programa, precione qualquer tecla para continuar"
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
		"Reset password",
		"Help",
		"Use license",
		"Electronic mail for request",
		"Full name",
		"Confirmation Full Name",
		"Email",
		"Confirm Email",
		"Home page",
		"Help text",
		"Use license text",
		"Add permanent user",
		"Confirm password",
		"Add",
		"Add temporary user",
		"Exit",
		"Back",
		"Incorrect nickname or password",
		"You are leaving"
	},

 	{
		"Sistema de Gerenciamento de Contas",
		"Autores",
		"Login",
		"Senha",
		"Confirmar",
		"Ingl&ecirc;s",
		"dvfmEvsUmlEnglish",
		"Cadastro",
		"Alterar senha",
		"Ajuda",
		"Licen&ccedil;a de uso",
		"Correio eletr&ocirc;nico para solicita&ccedil;&atilde;o",
		"Nome completo",
		"Confirmar nome completo",
		"Correio eletr&ocirc;nico",
		"Confirmar correio eletr&ocirc;nico",
		"P&aacute;gina inicial",
		"texto de ajuda",
		"texto de licen&ccedil;a de uso",
		"Adicionar usu&aacute;rio permanente",
		"Confirmar senha",
		"Adicionar",
		"Adicionar usu&aacute;rio tempor&aacute;rio",
		"Sair",
		"Voltar",
		"Apelido ou senha incorretos",
		"Voc&ecirc; est&aacute; saindo"
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
DvfmEvsUmlGetCliUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType dvfmEvsUmlUserInterfaceMessageNumberCode,
									  dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
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
DvfmEvsUmlGetNcursesUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType dvfmEvsUmlUserInterfaceMessageNumberCode,
										  dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
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
DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumberType dvfmEvsUmlUserInterfaceMessageNumberCode,
									  dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
{
	char *dvfmEvsUmlIndexUserInterfaceMessageNumber = "Out of range user interface message number message";

	if(dvfmEvsUmlLanguageOption >= dvfmEvsUmlLanguagesAmount)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	if(dvfmEvsUmlUserInterfaceMessageNumberCode >= dvfmEvsUmlSizeUserInterfaceMessageNumberType)
		return dvfmEvsUmlIndexUserInterfaceMessageNumber;

	return dvfmEvsUmlWebUserInterfaceMessages [dvfmEvsUmlLanguageOption][dvfmEvsUmlUserInterfaceMessageNumberCode];
}
/* $RCSfile: dvfmEvsUmlUserInterface.c,v $ */
