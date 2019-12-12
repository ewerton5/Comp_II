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
#include "dvfmEvsUmlUserInterface.h"
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

	dvfmEvsUmlReturnCode = mlCgiInitialize (&dvfmEvsUmlExecutionEnvironment);
	dvfmEvsUmlLanguageType dvfmEvsUmlLanguageSystem;

	if (dvfmEvsUmlReturnCode != ML_CGI_OK)
		exit (DVFM_EVS_UML_OK);

	if (dvfmEvsUmlExecutionEnvironment ==  commandLine)
	{
		printf ("Invalid execution environment\n");
		printf ("Ambiente de execucao invalido\n");
		exit (DVFM_EVS_UML_AMBIENTE_EXECUCAO_INVALIDO);
	}

	mlCgiBeginHttpHeader ("text/html");
	mlCgiEndHttpHeader ();

	dvfmEvsUmlReturnCode = mlCgiGetFormStringNoNewLines ("dvfmEvsUmlConfigurationFileName", dvfmEvsUmlConfigurationFileName, DVFM_EVS_UML_CONFIGURATION_FILE_NAME_LENGTH);

	if (dvfmEvsUmlReturnCode != ML_CGI_OK)
	{
		/* exibir uma pagina HTML de erro */
		printf ("<html>\nError #%u\n...</html>\n", dvfmEvsUmlReturnCode);
		mlCgiFreeResources ();
		exit (DVFM_EVS_UML_OK);
	}

	dvfmEvsUmlReturnCode = mlCgiGetFormStringNoNewLines ("dvfmEvsUmlLanguage", dvfmEvsUmlLanguage, DVFM_EVS_UML_CONFIGURATION_FILE_NAME_LENGTH);

	if (dvfmEvsUmlReturnCode != ML_CGI_OK)
	{
		/* exibir uma pagina HTML de erro */
		printf ("<html>\nError #%u\n...</html>\n", dvfmEvsUmlReturnCode);
		mlCgiFreeResources ();
		exit (DVFM_EVS_UML_OK);
	}

	dvfmEvsUmlLanguageSystem = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlLanguage);

	printf("<html>\n");
	printf("      <head>\n");
	printf("            <title>\n");
	printf("                  %s\n",  DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlSystemName, dvfmEvsUmlLanguageSystem));
	printf("                  <meta charset=\"utf-8\" %s = \"David Vinicius Ferreira Moreira e Ewerton Vieira de Silles\">\n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlAuthors, dvfmEvsUmlLanguageSystem));
	printf("            </title>\n");
	printf("            <style type=\"text/css\">\n");
	printf("                  body {\n");
	printf("                        text-align: center;\n");
	printf("                        font-family: Arial, sans-serif;\n");
	printf("                        background-color: #dddddd;\n");
	printf("                        color: rgba(0,0,0,1);\n");
	printf("                  }\n");
	printf("                  div {\n");
	printf("                        width: 500px;\n");
	printf("                        border-radius: 10pt;\n");
	printf("                        background-color: white;\n");
	printf("                        margin: 0px auto 0px auto;\n");
	printf("                        box-shadow: 0px 0px 10px rgba(0,0,0,.5);\n");
	printf("                        padding: 10px;\n");
	printf("                  }\n");
	printf("                  p {\n");
	printf("                        font-size: 8pt;\n");
	printf("                  }\n");
	printf("                  a {\n");
	printf("                        color: #606060;\n");
	printf("                        text-decoration: none;\n");
	printf("                  }\n");
	printf("                  h1 {\n");
	printf("                        font-family: 'FonteLogo', sans-serif;\n");
	printf("                        font-size: 30pt;\n");
	printf("                        color: #606060;\n");
	printf("                        text-shadow: 1px 1px 1px rgba(0,0,0,.6);\n");
	printf("                        padding: 0px;\n");
	printf("                        margin-bottom: 0px;\n");
	printf("                  }\n");
	printf("                  h2 {\n");
	printf("                        font-family: 'Titillium Web', sans-serif;\n");
	printf("                        font-size: 15pt;\n");
	printf("                        color: #888888;\n");
	printf("                        padding: 0px;\n");
	printf("                        margin-top: 0px;\n");
	printf("                  }\n");
	printf("                  a:hover {\n");
	printf("                        text-decoration: underline;\n");
	printf("                  }\n");
	printf("                  header {\n");
	printf("                        border-bottom: 1px #606060 solid;\n");
	printf("                        height: 150px;\n");
	printf("                        margin-bottom: 10px;\n");
	printf("                  }\n");
	printf("                  table {\n");
	printf("                        margin-left: auto;\n");
	printf("                        margin-right: auto;\n");
	printf("                  }\n");
	printf("                  table td {\n");
	printf("                        padding: 10px;\n");
	printf("                  }\n");
	printf("                  footer {\n");
	printf("                        clear: both;\n");
	printf("                        border-top: 1px solid #606060;\n");
	printf("                        margin-top: 10px;\n");
	printf("                        padding-top: 20px;\n");
	printf("                  }\n");
	printf("                  .button {\n");
	printf("                        display: inline-block;\n");
	printf("                        border-radius: 5pt;\n");
	printf("                        background-color: #dddddd;\n");
	printf("                        box-shadow: 0px 0px 3px rgba(0,0,0,.5);\n");
	printf("                        padding: 10px;\n");
	printf("                        margin: 2px;\n");
	printf("                        transition: background-color 1s;\n");
	printf("                        transition: color 1s;\n");
	printf("                  }\n");
	printf("                  .button:hover {\n");
	printf("                        background-color: #606060;\n");
	printf("                        color: white;\n");
	printf("                  }\n");
	printf("                  form {\n");
	printf("                        display: inline-block;\n");
	printf("                  }\n");
	printf("            </style>\n");
	printf("      </head>\n");
	printf("      <body>\n");
	printf("            <header>\n");
	printf("                  <h1>\n");
	printf("                  %s\n",  DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlSystemName, dvfmEvsUmlLanguageSystem));
	printf("                  </h1>\n");
	printf("                        <p>%s:</p>\n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlAuthors, dvfmEvsUmlLanguageSystem));
	printf("                        <p><a href=\"mailto:davidmoreira@poli.ufrj.br\">David Vinicius Ferreira Moreira</a></p>\n");
	printf("                        <p><a href=\"mailto:ewerton5@poli.ufrj.br\">Ewerton Vieira de Silles</a></p>\n");
	printf("            </header>\n");
	printf("            <div>\n");
	printf("                  <h2>\n");
	printf("                  %s\n", DvfmEvsUmlGetWebUserInterfaceMessage(dvfmEvsUmlHomePage, dvfmEvsUmlLanguageSystem));
	printf("                  </h2>\n");
	printf("                  <form action=\"dvfmEvsUmlLogin.cgi\" method=\"post\">\n");
	printf("                        <table>\n");
	printf("                              <tr>\n");
	printf("                                    <td>\n");
	printf("                                          %s:\n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlLogin, dvfmEvsUmlLanguageSystem));
	printf("                                    </td>\n");
	printf("                                    <td>\n");
	printf("                                          <input type=\"text\" name=\"dvfmEvsUmlNickname\" max=\"127\"> \n");
	printf("                                    </td>\n");
	printf("                              </tr>\n");
	printf("                              <tr>\n");
	printf("                                    <td>\n");
	printf("                                          %s:\n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlPassword, dvfmEvsUmlLanguageSystem));
	printf("                                    </td>\n");
	printf("                                    <td>\n");
	printf("                                          <input type=\"password\" name=\"dvfmEvsUmlPassword\" max=\"65\">\n");
	printf("                                    </td>\n");
	printf("                              </tr>\n");
	printf("                              <tr>\n");
	printf("                                    <td>\n");
	printf("\n");
	printf("                                    </td>\n");
	printf("                                    <td>\n");
	printf("                                          <input type=\"submit\" value=\"%s\">\n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlConfirm, dvfmEvsUmlLanguageSystem));
	printf("                                    </td>\n");
	printf("                              </tr>\n");
	printf("                              <tr>\n");
	printf("                                    <td colspan=\"2\">\n");
	printf("                        				<input type=\"hidden\" name=\"dvfmEvsUmlConfigurationFileName\" value=\"%s\">\n", dvfmEvsUmlConfigurationFileName);
	printf("                                    </td>\n");
	printf("                              </tr>\n");
	printf("                              <tr>\n");
	printf("                                    <td colspan=\"2\">\n");
	printf("				                        <input type=\"hidden\" name=\"dvfmEvsUmlLanguage\" value=\"%s\">\n", dvfmEvsUmlLanguage);
	printf("                                    </td>\n");
	printf("                              </tr>\n");
	printf("                        </table>\n");
	printf("                  </form>\n");
	printf("            </div>\n");
	printf("            <footer>\n");
	printf("                  <form action=\"dvfmEvsUmlMain.cgi\">\n");
	printf("\n");
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlConfigurationFileName\" value=\"%s\">\n", dvfmEvsUmlConfigurationFileName);
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlLanguage\" value=\"%s\">\n", dvfmEvsUmlLanguage);
	printf("                        <input class=\"button\" type=\"submit\" value=\"%s\">\n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlLanguageOption, dvfmEvsUmlLanguageSystem));
	printf("\n");
	printf("                  </form>\n");
	printf("\n");
	printf("                  <form action=\"dvfmEvsUmlShowRequestRegistrationForm.cgi\">\n");
	printf("\n");
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlConfigurationFileName\" value=\"%s\">\n", dvfmEvsUmlConfigurationFileName);
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlLanguage\" value=\"%s\">\n", dvfmEvsUmlLanguage);
	printf("                        <input class=\"button\" type=\"submit\" value=\"%s\">     \n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlRegister, dvfmEvsUmlLanguageSystem));
	printf("                  </form>\n");
	printf("\n");
	printf("                  <form action=\"dvfmEvsUmlShowRequestPasswordResetForm.cgi\">\n");
	printf("\n");
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlConfigurationFileName\" value=\"%s\">\n", dvfmEvsUmlConfigurationFileName);
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlLanguage\" value=\"%s\">\n", dvfmEvsUmlLanguage);
	printf("                        <input class=\"button\" type=\"submit\" value=\"%s\">     \n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlTemporaryPassword, dvfmEvsUmlLanguageSystem));
	printf("                  </form>\n");
	printf("\n");
	printf("                  <form action=\"dvfmEvsUmlShowWebHelp.cgi\">\n");
	printf("\n");
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlConfigurationFileName\" value=\"%s\">\n", dvfmEvsUmlConfigurationFileName);
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlLanguage\" value=\"%s\">\n", dvfmEvsUmlLanguage);
	printf("                        <input class=\"button\" type=\"submit\" value=\"%s\">     \n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlHelp, dvfmEvsUmlLanguageSystem));
	printf("                  </form>\n");
	printf("\n");
	printf("                  <form action=\"dvfmEvsUmlShowLicense.cgi\">\n");
	printf("\n");
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlConfigurationFileName\" value=\"%s\">\n", dvfmEvsUmlConfigurationFileName);
	printf("                        <input type=\"hidden\" name=\"dvfmEvsUmlLanguage\" value=\"%s\">\n", dvfmEvsUmlLanguage);
	printf("                        <input class=\"button\" type=\"submit\" value=\"%s\">     \n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlUseLicense, dvfmEvsUmlLanguageSystem));
	printf("                  </form>\n");
	printf("            </footer>\n");
	printf("      </body>\n");
	printf("</html>\n");

  	mlCgiFreeResources ();

  	return DVFM_EVS_UML_OK;
}

/* $RCSfile$ */
