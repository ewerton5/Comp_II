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

#include	<stdio.h>
#include	"dvfmEvsUmlShowCliHelp.h"

/*
 * void
 * DvfmEvsUmlShowCliHelp (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);
 *
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - the address of a local variable of type dvfmEvsUmlConfigurationOptionsType (I)
 * dvfmEvsUmlLanguageType - name of the configuration file (I)
 * 
 * Returned code:
 * 
 * void
 * 
 * Description:
 * This function shows help in the CLI environment.
 */

void
DvfmEvsUmlShowCliHelp (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
					   dvfmEvsUmlLanguageType dvfmEvsUmlLanguage)
{
	if(dvfmEvsUmlLanguage == dvfmEvsUmlPortuguese)
	{
		printf(" ==================================> Legenda <==================================\n");
		printf("|* Opcao curta e indicado por: -\n");
		printf("|* Opcao longa e indicado por: --\n");
		printf("|* Palavras antes do igual sao nomes de argumentos\n");
		printf("|* Palavras depois do igual sao valores de seu respectivo argumento\n");
		printf("|* O termo 'ou' e indicado por: |\n");
		printf("|* Valores livres e indicado por: <valor do argumento>\n");	
		printf("|* Valores  predefinidos e indicado por: ->valor do argumento<-\n");
		printf("|* Argumentos opcionais (nao obrigatorio) sao indicados por: [argumento=valor]\n");
		printf("|* Argumentos obrigatorios sao indicados por: arguemnto=valor\n");
		printf(" ===============================================================================\n");
		printf("\n");
		printf("\t\t\t -h | --help\n");
		printf("\t\t =>Descricao: monstra uma descricao de todas as opcoes e como utilisa-las em todos os idiomas disponiveis\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -h | --help [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -o | --options\n");
		printf("\t\t =>Descricao: exibe os valores de todas as opcoes de configuracao\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -o | --options [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -N | --Ncurses\n");
		printf("\t\t =>Descricao: executa o programa via interface Ncurses\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -N | --Ncurses [configuration=<arquivo-configuração>] [user=<apelido>][language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -C | --Configure\n");
		printf("\t\t =>Descricao: configura a ferramenta de adicionar permanente ou temporariamente os dados de um novo usuario ao sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -C | --Configure [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -a | --add\n");
		printf("\t\t =>Descricao: adiciona permanente ou temporariamente os dados de um novo usuario ao sistema\n");
		printf("\t\t =>Uso: -a | --add [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -i | --invite\n");
		printf("\t\t =>Descricao: solicita a adicao permanente ou temporariamente os dados de um novo usuario ao sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -i | --invite [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");	
		printf("\n");
		printf("\t\t\t -t | --accept\n");
		printf("\t\t =>Descricao: aceita um novo usuario no sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -t | --accept [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -j | --reject\n");
		printf("\t\t =>Descricao: exclui um usuario do sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -j | --reject [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -n | --new\n");
		printf("\t\t =>Descricao: inicia o processo de avaliacao\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -n | --new [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> friend-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -q | --request\n");
		printf("\t\t =>Descricao: lista todas as solicitacoes validas nao atendidas pelo usuario em questao\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -q | --request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -Q | --Request\n");
		printf("\t\t =>Descricao: lista todas as solicitacoes validas nao atendidas\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -Q | --Request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -v | --approve\n");
		printf("\t\t =>Descricao: conclui e aceita o processo de adicionar um novo usuario ao sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -v | --approve [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -d | --disapprove\n");
		printf("\t\t =>Descricao: conclui e rejeita o processo de adicionar um novo usuario ao sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -d | --disapprove [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -U | --Unlocking\n");
		printf("\t\t =>Descricao: lista todos os usuarios que solicitaram desbloqueio de conta\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -U | --Unlocking [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -l | --lock\n");
		printf("\t\t =>Descricao: bloqueia a conta do usuario em questao\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -l | --lock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -u | --unlock\n");
		printf("\t\t =>Descricao: desbloqueia uma conta\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -u | --unlock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -p | --password\n");
		printf("\t\t =>Descricao: altera a senha\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -p | --password [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -r | --reset\n");
		printf("\t\t =>Descricao: solicita uma senha temporaria para acesso ao sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -r | --reset [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -m | --modify\n");
		printf("\t\t =>Descricao: altera o nome\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -m | --modify [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] username=<nome- completo> confirm-username=<nome-completo> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -e | --edit\n");
		printf("\t\t =>Descricao: altera o endereco eletronico\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -e | --edit [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -c | --confirm\n");
		printf("\t\t =>Descricao: valida o seu novo endereço eletronico\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -c | --confirm [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] key=<chave> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -g | --group\n");
		printf("\t\t =>Descricao: troca o perfil\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -g | --group [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido>  profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -s | --show\n");
		printf("\t\t =>Descricao: obter informacoes sobre todos os usuarios cadastrados no sistema\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -s | --show [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -S | --Search\n");
		printf("\t\t =>Descricao: obter informacoes sobre todos os usuarios cadastrados no  sistema que atendam aos filtros de busca\n");
		printf("\t\t =>Uso: ./dvfmEvsUml -S | --Search [configuration=<arquivo-configuração>] [username=<nome-completo ou parte-do-nome>] [email=<endereço-eletrônico ou parte-do-endereço-eletrônico>] [profile=->administrator<- | ->professor<- | ->administrator-professor<- | ->student<- | ->administrator-student<- | ->professor-student<- | ->administrator-professor-student<- [language=->english<- | ->portuguese<-]\n");
	}
	else
	{
		printf(" ==================================> Legend <===============================\n");
		printf("|* Short option is indicated by: -\n");
		printf("|* Long option is indicated by: --\n");
		printf("|* Words before equals are argument names\n");
		printf("|* Words after the equals are values ​​of their respective argument\n");
		printf("|* The term 'or' is indicated by: |\n");
		printf("|* Free values ​​and indicated by: <argument value>\n");	
		printf("|* Default values ​​and indicated by: ->argument value<-\n");
		printf("|* Optional arguments (not required) are indicated by: [argument=value]\n");
		printf("|* Mandatory arguments are indicated by: argument=value\n");
		printf(" ===========================================================================\n");
		printf("\n");
		printf("\t\t\t -h | --help\n");
		printf("\t\t =>Description: shows a description of all options and how to use them in all available languages\n");
		printf("\t\t =>Use: ./dvfmEvsUml -h | --help [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -o | --options\n");
		printf("\t\t =>Description: displays the values ​​of all configuration options\n");
		printf("\t\t =>Use: ./dvfmEvsUml -o | --options [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -N | --Ncurses\n");
		printf("\t\t =>Description: run the program via Ncurses interface\n");
		printf("\t\t =>Use: ./dvfmEvsUml -N | --Ncurses [configuration=<arquivo-configuração>] [user=<apelido>][language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -C | --Configure\n");
		printf("\t\t =>Description: configures the tool to permanently or temporarily add new user data to the system\n");
		printf("\t\t =>Use: ./dvfmEvsUml -C | --Configure [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -a | --add\n");
		printf("\t\t =>Description: permanently or temporarily adds new user data to the system\n");
		printf("\t\t =>Use: -a | --add [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -i | --invite\n");
		printf("\t\t =>Description: requests the permanent or temporary addition of new user data to the system\n");
		printf("\t\t =>Use: ./dvfmEvsUml -i | --invite [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");	
		printf("\n");
		printf("\t\t\t -t | --accept\n");
		printf("\t\t =>Description: accept a new user in the system\n");
		printf("\t\t =>Use: ./dvfmEvsUml -t | --accept [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -j | --reject\n");
		printf("\t\t =>Description: delete a system user\n");
		printf("\t\t =>Use: ./dvfmEvsUml -j | --reject [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -n | --new\n");
		printf("\t\t =>Description: start the evaluation process\n");
		printf("\t\t =>Use: ./dvfmEvsUml -n | --new [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> friend-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -q | --request\n");
		printf("\t\t =>Description: lists all valid requests not met by the user in question\n");
		printf("\t\t =>Use: ./dvfmEvsUml -q | --request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -Q | --Request\n");
		printf("\t\t =>Description: lists all valid requests not fulfilled\n");
		printf("\t\t =>Use: ./dvfmEvsUml -Q | --Request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -v | --approve\n");
		printf("\t\t =>Description: concludes and accepts the process of adding a new user to the system\n");
		printf("\t\t =>Use: ./dvfmEvsUml -v | --approve [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -d | --disapprove\n");
		printf("\t\t =>Description: concludes and rejects the process of adding a new user to the system\n");
		printf("\t\t =>Use: ./dvfmEvsUml -d | --disapprove [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -U | --Unlocking\n");
		printf("\t\t =>Description: lists all users who have requested account unlocking\n");
		printf("\t\t =>Use: ./dvfmEvsUml -U | --Unlocking [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -l | --lock\n");
		printf("\t\t =>Description: blocks the user account in question\n");
		printf("\t\t =>Use: ./dvfmEvsUml -l | --lock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -u | --unlock\n");
		printf("\t\t =>Description: unlock an account\n");
		printf("\t\t =>Use: ./dvfmEvsUml -u | --unlock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -p | --password\n");
		printf("\t\t =>Description: change password\n");
		printf("\t\t =>Use: ./dvfmEvsUml -p | --password [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -r | --reset\n");
		printf("\t\t =>Description: request a temporary password for system access\n");
		printf("\t\t =>Use: ./dvfmEvsUml -r | --reset [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -m | --modify\n");
		printf("\t\t =>Description: change name\n");
		printf("\t\t =>Use: ./dvfmEvsUml -m | --modify [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] username=<nome- completo> confirm-username=<nome-completo> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -e | --edit\n");
		printf("\t\t =>Description: change the electronic address\n");
		printf("\t\t =>Use: ./dvfmEvsUml -e | --edit [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -c | --confirm\n");
		printf("\t\t =>Description: validate your new email address\n");
		printf("\t\t =>Use: ./dvfmEvsUml -c | --confirm [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] key=<chave> [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -g | --group\n");
		printf("\t\t =>Description: change profile\n");
		printf("\t\t =>Use: ./dvfmEvsUml -g | --group [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido>  profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -s | --show\n");
		printf("\t\t =>Description: get information about all users registered in the system\n");
		printf("\t\t =>Use: ./dvfmEvsUml -s | --show [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
		printf("\n");
		printf("\t\t\t -S | --Search\n");
		printf("\t\t =>Description: get information about all users registered in the system that meet the search filters\n");
		printf("\t\t =>Use: ./dvfmEvsUml -S | --Search [configuration=<arquivo-configuração>] [username=<nome-completo ou parte-do-nome>] [email=<endereço-eletrônico ou parte-do-endereço-eletrônico>] [profile=->administrator<- | ->professor<- | ->administrator-professor<- | ->student<- | ->administrator-student<- | ->professor-student<- | ->administrator-professor-student<- [language=->english<- | ->portuguese<-]\n");
	}
	printf("\n");

}

/* $RCSfile$ */