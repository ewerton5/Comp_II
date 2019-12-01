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
#include "Bibliotecas/mlcgi.h"
#include "dvfmEvsUmlFunctions.h"

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

	dvfmEvsUmlReturnCode = mlCgiInitialize (&dvfmEvsUmlExecutionEnvironment)
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

	switch(dvfmEvsUmlPortuguese)
	{
		case dvfmEvsUmlPortuguese:
			/*html portuguese*/
			printf("<html>\n");
			printf("      <head>\n");
			printf("            <title>\n");
			printf("                  %s\n", dvfmEvsUmlWebUserInterfaceMessages [dvfmEvsUmlLanguageSystem][dvfmEvsUmlSystemName]);
			printf("                  <meta autores = \"David Vinicius Ferreira Moreira e Ewerton Vieira de Silles\">\n");
			printf("            </title>\n");
			printf("      </head>\n");
			printf("      <body bgcolor = \"cyan\">\n");
			printf("\n");
			printf("            <div align = \"center\">\n");
			printf("                  <font size=\"15\">\n");
			printf("                  %s\n", dvfmEvsUmlWebUserInterfaceMessages [dvfmEvsUmlLanguageSystem][dvfmEvsUmlSystemName]);
			printf("                  </font>\n");
			printf("                  <br><br>\n");
			printf("                  <font size=\"-10\">\n");
			printf("                        %s: <br>\n", dvfmEvsUmlWebUserInterfaceMessages [dvfmEvsUmlLanguageSystem][dvfmEvsUmlAuthors]);
			printf("                        <a href=\"mailto:davidmoreira@poli.ufrj.br\">David Vinicius Ferreira Moreira</a> <br>\n");
			printf("                        <a href=\"mailto:ewerton5@poli.ufrj.br\">Ewerton Vieira de Silles</a>\n");
			printf("                  </font>\n");
			printf("                  <br>\n");
			printf("                  <br>\n");
			printf("                  <br>\n");
			printf("            </div>\n");
			printf("\n");
			printf("            <div align = \"center\">\n");
			printf("                  <form action=\"dvfmEvsUmlRequestRegistration.cgi\" method=\"post\">\n");
			printf("                        <table border=\"0\">\n");
			printf("                              <tr>\n");
			printf("                                    <td>\n");
			printf("                                          %s:\n");
			printf("                                    </td>\n");
			printf("                                    <td>\n");
			printf("                                          <input type=\"text\" name=\"dvfmEvsUmlAdimim\" max=\"1024\"> \n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                              <tr>\n");
			printf("                                    <td>\n");
			printf("                                          %s:\n");
			printf("                                    </td>\n");
			printf("                                    <td>\n");
			printf("                                          <input type=\"text\" name=\"dvfmEvsUmlUserName\" max=\"256\">\n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                              <tr>\n");
			printf("                                    <td>\n");
			printf("                                          %s:\n");
			printf("                                    </td>\n");
			printf("                                    <td>\n");
			printf("                                          <input type=\"text\" name=\"dvfmEvsUmlUserNameConfirmation\" max=\"256\">\n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                              <tr>\n");
			printf("                                    <td>\n");
			printf("                                          %s:\n");
			printf("                                    </td>\n");
			printf("                                    <td>\n");
			printf("                                          <input type=\"text\" name=\"dvfmEvsUmlEmail\" max=\"1024\">\n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                              <tr>\n");
			printf("                                    <td>\n");
			printf("                                          %s:\n");
			printf("                                    </td>\n");
			printf("                                    <td>\n");
			printf("                                          <input type=\"text\" name=\"dvfmEvsUmlEmailConfirmation\" max=\"1024\">\n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                              <tr>\n");
			printf("                                    <td>\n");
			printf("\n");
			printf("                                    </td>\n");
			printf("                                    <td>\n");
			printf("                                          <input type=\"submit\" value=\"Registar -se\">\n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                              <tr>\n");
			printf("                                    <td colspan=\"2\">\n");
			printf("                                          <input type=\"hidden\" name=\"dvfmEvsUmlConfigurationFileName\">\n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                              <tr>\n");
			printf("                                    <td colspan=\"2\">\n");
			printf("                                          <input type=\"hidden\" name=\"dvfmEvsUmlLanguage\">\n");
			printf("                                    </td>\n");
			printf("                              </tr>\n");
			printf("                        </table>\n");
			printf("                  </form>\n");
			printf("            </div>\n");
			printf("\n");
			printf("            <div align = \"center\">\n");
			printf("                  <br>\n");
			printf("                  <br>\n");
			printf("                  <br>\n");
			printf("                  <br>\n");
			printf("                  <pre>\n");
			printf("                        <a href=\"dvfmEvsUmlMain.cgi?dvfmEvsUmlConfigurationFileName=dvfmEvs-uml.cfg&dvfmEvsUmlLanguage=dvfmEvsUmlEnglish\">%s</a>\n");
			printf("                  </pre>\n");
			printf("            </div>\n");
			printf("      </body>\n");
			printf("</html>\n");
		break;

		case dvfmEvsUmlEnglish:
			/*html english*/
		break;

		default:
			/*html english*/
	}

  mlCgiFreeResources ();

  return DVFM_EVS_UML_OK;
}

/* $RCSfile$ */
