/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/16 03:48:22 $
$Log: dvfmEvsUmlGetWebUserInterfaceMessage.c,v $
Revision 1.2  2019/11/16 03:48:22  ewerton.silles
*** empty log message ***

Revision 1.1  2019/11/15 01:42:45  ewerton.silles
Initial revision

*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlUserInterface.h"

#define DVFM_EVS_NUMBER_ARGUMENTS						3

#define DVFM_EVS_OK										0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID				1
#define DVFM_EVS_FIRST_ARGUMENT_INVALID			    	2
#define DVFM_EVS_FIRST_ARGUMENT_INVALID_HIFEN		    3
#define DVFM_EVS_SECOND_ARGUMENT_INVALID				4
#define DVFM_EVS_SECOND_ARGUMENT_INVALID_HIFEN	    	5

#define DVFM_EVS_EOS									'\0'

int
main(int argc,char *argv[ ]) 
{
	dvfmEvsUmlUserInterfaceMessageNumberType dvfmEvsUmlUserInterfaceMessageNumber;
	dvfmEvsUmlLanguageType dvfmEvsUmlLanguage;
	char *dvfmEvsUmlValidation;

	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <user_interface_message_number> <language_number>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

	if(argv[1][0] == '-')
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"-\"\n");
		exit(DVFM_EVS_FIRST_ARGUMENT_INVALID_HIFEN);
	}
	
	dvfmEvsUmlUserInterfaceMessageNumber = (dvfmEvsUmlUserInterfaceMessageNumberType) strtoul( argv[1], &dvfmEvsUmlValidation, 10);
	if(*dvfmEvsUmlValidation != DVFM_EVS_EOS)
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"%c\"\n", dvfmEvsUmlValidation[0]);
		exit(DVFM_EVS_FIRST_ARGUMENT_INVALID);
	}

	if(argv[2][0] == '-')
	{
		printf("Error: Second argument invalid\n");
		printf("First character invalid: \"-\"\n");
		exit(DVFM_EVS_SECOND_ARGUMENT_INVALID_HIFEN);
	}

	dvfmEvsUmlLanguage = (dvfmEvsUmlLanguageType) strtoul( argv[2], &dvfmEvsUmlValidation, 10);
	if(*dvfmEvsUmlValidation != DVFM_EVS_EOS)
	{
		printf("Error: Argumento dois invalido\n");
		printf("First character invalid: \"%c\"\n", dvfmEvsUmlValidation[0]);
		printf("use: %s <erro> <language>\n", argv[0]);
		exit(DVFM_EVS_SECOND_ARGUMENT_INVALID);
	}


	printf("%s\n", DvfmEvsUmlGetWebUserInterfaceMessage (dvfmEvsUmlUserInterfaceMessageNumber, dvfmEvsUmlLanguage));

	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlGetWebUserInterfaceMessage.c,v $ */
