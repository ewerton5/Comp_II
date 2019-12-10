/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author$
$Date$
$Log$
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Libraries/mlcgi.h"
#include "dvfmEvsUmlFunctions.h"
#include "dvfmEvsUmlTypes.h"
#include "dvfmEvsUmlUserInterface.h"

#define DVFM_EVS_UML_OK					0
#define DVFM_EVS_UML_AMBIENTE_EXECUCAO_INVALIDO		1
#define DVFM_EVS_UML_CONFIGURATION_FILE_NAME_LENGTH	50
#define DVFM_EVS_UML_LANGUAGE_LENGTH			50


int
main (int argc, char **argv)
{
	unsigned dvfmEvsUmlReturnCode;
	environmentType dvfmEvsUmlExecutionEnvironment;
	char dvfmEvsUmlConfigurationFileName [DVFM_EVS_UML_CONFIGURATION_FILE_NAME_LENGTH + 1];
	char dvfmEvsUmlLanguage [DVFM_EVS_UML_LANGUAGE_LENGTH + 1];

	dvfmEvsUmlReturnCode = mlCgiInitialize (&dvfmEvsUmlExecutionEnvironment);
	dvfmEvsUmlLanguageType dvfmEvsUmlLanguageSystem;

	if (dvfmEvsUmlReturnCode != ML_CGI_OK)
		exit (DVFM_EVS_UML_OK);

	if (dvfmEvsUmlExecutionEnvironment ==  ML_CGI_FALSE)
	{
		printf ("Invalid execution environment\n");
		printf ("Ambiente de execucao invalido\n");
		exit (DVFM_EVS_UML_AMBIENTE_EXECUCAO_INVALIDO);
	}

	mlCgiBeginHttpHeader ("text/html");
	mlCgiEndHttpHeader ();

	dvfmEvsUmlReturnCode = mlCgiGetFormStringNoNewLines ("FileNameConfig", dvfmEvsUmlConfigurationFileName, DVFM_EVS_UML_CONFIGURATION_FILE_NAME_LENGTH);

	if (dvfmEvsUmlReturnCode != ML_CGI_OK)
	{
		/* exibir uma pagina HTML de erro */
		printf ("<html>\nError #%u\n...</html>\n", dvfmEvsUmlReturnCode);
		mlCgiFreeResources ();
		exit (DVFM_EVS_UML_OK);
	}

	dvfmEvsUmlReturnCode = mlCgiGetFormStringNoNewLines ("Language", dvfmEvsUmlLanguage, DVFM_EVS_UML_CONFIGURATION_FILE_NAME_LENGTH);

	if (dvfmEvsUmlReturnCode != ML_CGI_OK)
	{
		/* exibir uma pagina HTML de erro */
		printf ("<html>\nError #%u\n...</html>\n", dvfmEvsUmlReturnCode);
		mlCgiFreeResources ();
		exit (DVFM_EVS_UML_OK);
	}

	dvfmEvsUmlLanguageSystem = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlLanguage);

	/*falta botar o html certo*/
	/*eu acho q ele quer q faça ago aqui */
	/*sao 2 html?*/

	mlCgiFreeResources ();

	return DVFM_EVS_UML_OK;
}

/* $RCSfile$ */
