/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/30 04:31:06 $
$Log: dvfmEvsUmlErrors.c,v $
Revision 1.3  2019/11/30 04:31:06  ewerton.silles
*** empty log message ***

Revision 1.2  2019/11/16 03:48:22  ewerton.silles
*** empty log message ***

Revision 1.1  2019/11/14 22:25:01  ewerton.silles
Initial revision
 
*/

#include			"dvfmEvsUmlTypes.h"
#include			"dvfmEvsUmlErrors.h"

					/*VARIAVEIS GLOBAIS*/

char *dvfmEvsUmlCliErrorMessages [dvfmEvsUmlLanguagesAmount][dvfmEvsUmlSizeErrorType]=
{
	{
		"Ok",
		"The first argument passed is empty",
		"The second argument passed is empty",
		"The third argument passed is empty",
		"The path is too long",
		"The filename is too long",
		"Minimum size as bigger than maximum size",
		"The term received is too short",
		"The term received is too long",
		"Received term has invalid characters",
		"Nickname too short",
		"Nickname too long",
		"Nickname starting with point",
		"Nickname ending with point",
		"Nickname without point",
		"Nickname with more than one point",
		"Nickname has invalid characters",
		"Email too short",
		"Email too long",
		"Email starting with at",
		"Email ending with at",
		"Email without at",
		"Email with more than one at",
		"Email has invalid characters",
		"A Unique name was passed",
		"The name have a dot",
		"Encrypted password corrupted",
		"Unable to recognize the algorithm",
		"Password too long",
		"Problems in an internal function",
		"Unregistered Encryption Algorithm",
		"Void string",
		"Invalid encrypted password",
		"The encrypted password is too long",
		"Incompatible password",
		"Invalid salt",
		"Can't Open file",
		"Error reading the file",
		"The argument is too short",
		"The argument is too Long",
		"Invalid option position",
		"Few sub options",
		"Invalid sub option",
		"Missing any required argument",
		"Short or long invalid option"
	},

	{
		"Sucesso",
		"O primeiro argumento passado esta vazio",
		"O segundo argumento passado esta vazio",
		"O terceiro argumento passado esta vazio",
		"O caminho e muito longo",
		"O nome do arquivo e muito longo",
		"O tamanho minimo e maior que o tamanho maximo",
		"O termo recebido e muito curto",
		"O termo recebido e muito longo",
		"O termo recebido possui caracteres invalidos",
		"Apelido muito curto",
		"Apelido muito longo",
		"Apelido comecando com ponto",
		"Apelido terminando com ponto",
		"Apelido com mais que um ponto",
		"Apelido com caracteres invalidos",
		"Correio eletronico muito curto",
		"Correio eletronico muito longo",
		"Correio eletronico comecando com arroba",
		"Correio eletronico terminando com arroba",
		"Correio eletronico com mais que um arroba",
		"Correio eletronico com caracteres invalidos",
		"Foi passado um unico nome",
		"Nome teminando com ponto",
		"Senha cifrada corrompida",
		"Nao foi capaz de reconhecer o algoritimo",
		"Senha muito longa",
		"Problemas em uma funcao interna",
		"Algoritimo de criptografia nao registrado",
		"Palavra vazia",
		"Senha criptografada invalida",
		"A senha criptografada e muito longa",
		"Senha incompativel"
		"Tempero invalido",
		"O arqivo nao pode ser aberto"
		"Erro na leitura do arquivo",
		"O argumento e muito curto",
		"O argumento e muito longo",
		"Posicao da opcao invalida",
		"Poucas sub opcoes",
		"Sub opcao invalida",
		"Faltou algum argumento obrigatrio",
		"Opcao curta ou longa invalida"
	}
};

char *dvfmEvsUmlNcursesErrorMessages [dvfmEvsUmlLanguagesAmount][dvfmEvsUmlSizeErrorType]=
{
	{
		"Ok",
		"The first argument passed is empty",
		"The second argument passed is empty",
		"The third argument passed is empty",
		"The path is too long",
		"The filename is too long",
		"Minimum size as bigger than maximum size",
		"The term received is too short",
		"The term received is too long",
		"Received term has invalid characters",
		"Nickname too short",
		"Nickname too long",
		"Nickname starting with point",
		"Nickname ending with point",
		"Nickname without point",
		"Nickname with more than one point",
		"Nickname has invalid characters",
		"Email too short",
		"Email too long",
		"Email starting with at",
		"Email ending with at",
		"Email without at",
		"Email with more than one at",
		"Email has invalid characters",
		"A Unique name was passed",
		"The name have a dot",
		"Encrypted password corrupted",
		"Unable to recognize the algorithm",
		"Password too long",
		"Problems in an internal function",
		"Unregistered Encryption Algorithm",
		"Void string",
		"Invalid encrypted password",
		"The encrypted password is too long",
		"Incompatible password",
		"Invalid salt",
		"Can't Open file",
		"Error reading the file",
		"The argument is too short",
		"The argument is too Long",
		"Invalid option position",
		"Few sub options",
		"Invalid sub option",
		"Missing any required argument",
		"Short or long invalid option"
	},

	{
		"Sucesso",
		"O primeiro argumento passado esta vazio",
		"O segundo argumento passado esta vazio",
		"O terceiro argumento passado esta vazio",
		"O caminho e muito longo",
		"O nome do arquivo e muito longo",
		"O tamanho minimo e maior que o tamanho maximo",
		"O termo recebido e muito curto",
		"O termo recebido e muito longo",
		"O termo recebido possui caracteres invalidos",
		"Apelido muito curto",
		"Apelido muito longo",
		"Apelido comecando com ponto",
		"Apelido terminando com ponto",
		"Apelido com mais que um ponto",
		"Apelido com caracteres invalidos",
		"Correio eletronico muito curto",
		"Correio eletronico muito longo",
		"Correio eletronico comecando com arroba",
		"Correio eletronico terminando com arroba",
		"Correio eletronico com mais que um arroba",
		"Correio eletronico com caracteres invalidos",
		"Foi passado um unico nome",
		"Nome teminando com ponto",
		"Senha cifrada corrompida",
		"Nao foi capaz de reconhecer o algoritimo",
		"Senha muito longa",
		"Problemas em uma funcao interna",
		"Algoritimo de criptografia nao registrado",
		"Palavra vazia",
		"Senha criptografada invalida",
		"A senha criptografada e muito longa",
		"Senha incompativel"
		"Tempero invalido",
		"O arqivo nao pode ser aberto"
		"Erro na leitura do arquivo",
		"O argumento e muito curto",
		"O argumento e muito longo",
		"Posicao da opcao invalida",
		"Poucas sub opcoes",
		"Sub opcao invalida",
		"Faltou algum argumento obrigatrio",
		"Opcao curta ou longa invalida"
	}
};

char *dvfmEvsUmlWebErrorMessages [dvfmEvsUmlLanguagesAmount][dvfmEvsUmlSizeErrorType]=
{
	{
		"Ok",
		"The first argument passed is empty",
		"The second argument passed is empty",
		"The third argument passed is empty",
		"The path is too long",
		"The filename is too long",
		"Minimum size as bigger than maximum size",
		"The term received is too short",
		"The term received is too long",
		"Received term has invalid characters",
		"Nickname too short",
		"Nickname too long",
		"Nickname starting with point",
		"Nickname ending with point",
		"Nickname without point",
		"Nickname with more than one point",
		"Nickname has invalid characters",
		"Email too short",
		"Email too long",
		"Email starting with at",
		"Email ending with at",
		"Email without at",
		"Email with more than one at",
		"Email has invalid characters",
		"A Unique name was passed",
		"The name have a dot",
		"Encrypted password corrupted",
		"Unable to recognize the algorithm",
		"Password too long",
		"Problems in an internal function",
		"Unregistered Encryption Algorithm",
		"Void string",
		"Invalid encrypted password",
		"The encrypted password is too long",
		"Incompatible password",
		"Invalid salt",
		"Can't Open file",
		"Error reading the file",
		"The argument is too short",
		"The argument is too Long",
		"Invalid option position",
		"Few sub options",
		"Invalid sub option",
		"Missing any required argument",
		"Short or long invalid option"
	},

	{
		"Sucesso",
		"O primeiro argumento passado esta vazio",
		"O segundo argumento passado esta vazio",
		"O terceiro argumento passado esta vazio",
		"O caminho e muito longo",
		"O nome do arquivo e muito longo",
		"O tamanho minimo e maior que o tamanho maximo",
		"O termo recebido e muito curto",
		"O termo recebido e muito longo",
		"O termo recebido possui caracteres invalidos",
		"Apelido muito curto",
		"Apelido muito longo",
		"Apelido comecando com ponto",
		"Apelido terminando com ponto",
		"Apelido com mais que um ponto",
		"Apelido com caracteres invalidos",
		"Correio eletronico muito curto",
		"Correio eletronico muito longo",
		"Correio eletronico comecando com arroba",
		"Correio eletronico terminando com arroba",
		"Correio eletronico com mais que um arroba",
		"Correio eletronico com caracteres invalidos",
		"Foi passado um unico nome",
		"Nome teminando com ponto",
		"Senha cifrada corrompida",
		"Nao foi capaz de reconhecer o algoritimo",
		"Senha muito longa",
		"Problemas em uma funcao interna",
		"Algoritimo de criptografia nao registrado",
		"Palavra vazia",
		"Senha criptografada invalida",
		"A senha criptografada e muito longa",
		"Senha incompativel"
		"Tempero invalido",
		"O arqivo nao pode ser aberto"
		"Erro na leitura do arquivo",
		"O argumento e muito curto",
		"O argumento e muito longo",
		"Posicao da opcao invalida",
		"Poucas sub opcoes",
		"Sub opcao invalida",
		"Faltou algum argumento obrigatrio",
		"Opcao curta ou longa invalida"
	}
};

/*
 * char *
 * DvfmEvsUmlGetCliErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 * dvfmEvsUmlErrorType - integer that corrects a error type enum (I)
 *
 * Returned code:
 * char * - error message
 *
 * Description:
 * This function returns the appropriate error message to the error code and language option in the interface CLI.
 */

char *
DvfmEvsUmlGetCliErrorMessage (dvfmEvsUmlErrorType dvfmEvsUmlErrorCode, dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
{
	char *dvfmEvsUmlIndexError = "Out of range error message";

	if(dvfmEvsUmlLanguageOption >= dvfmEvsUmlLanguagesAmount)
		return dvfmEvsUmlIndexError;

	if(dvfmEvsUmlErrorCode >= dvfmEvsUmlSizeErrorType)
		return dvfmEvsUmlIndexError;

	return dvfmEvsUmlCliErrorMessages [dvfmEvsUmlLanguageOption][dvfmEvsUmlErrorCode];
}

/*
 * char *
 * DvfmEvsUmlGetNcursesErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 * dvfmEvsUmlErrorType - integer that corrects a error type enum (I)
 *
 * Returned code:
 * char * - error message
 *
 * Description:
 * This function returns the appropriate error message to the error code and language option in the interface Ncurses.
 */

char *
DvfmEvsUmlGetNcursesErrorMessage (dvfmEvsUmlErrorType dvfmEvsUmlErrorCode, dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
{
	char *dvfmEvsUmlIndexError = "Out of range error message";

	if(dvfmEvsUmlLanguageOption >= dvfmEvsUmlLanguagesAmount)
		return dvfmEvsUmlIndexError;

	if(dvfmEvsUmlErrorCode >= dvfmEvsUmlSizeErrorType)
		return dvfmEvsUmlIndexError;

	return dvfmEvsUmlNcursesErrorMessages [dvfmEvsUmlLanguageOption][dvfmEvsUmlErrorCode];
}

/*
 * char *
 * DvfmEvsUmlGetWebErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 * dvfmEvsUmlErrorType - integer that corrects a error type enum (I)
 *
 * Returned code:
 * char * - error message
 *
 * Description:
 * This function returns the appropriate error message to the error code and language option in the interface Web.
 */

char *
DvfmEvsUmlGetWebErrorMessage (dvfmEvsUmlErrorType dvfmEvsUmlErrorCode, dvfmEvsUmlLanguageType dvfmEvsUmlLanguageOption)
{
	char *dvfmEvsUmlIndexError = "Out of range error message";

	if(dvfmEvsUmlLanguageOption >= dvfmEvsUmlLanguagesAmount)
		return dvfmEvsUmlIndexError;

	if(dvfmEvsUmlErrorCode >= dvfmEvsUmlSizeErrorType)
		return dvfmEvsUmlIndexError;

	return dvfmEvsUmlWebErrorMessages [dvfmEvsUmlLanguageOption][dvfmEvsUmlErrorCode];
}
/* $RCSfile: dvfmEvsUmlErrors.c,v $ */
