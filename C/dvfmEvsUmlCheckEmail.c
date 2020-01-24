/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2020/01/24 05:37:49 $
$Log: dvfmEvsUmlCheckEmail.c,v $
Revision 1.2  2020/01/24 05:37:49  ewerton.silles
*** empty log message ***

Revision 1.1  2019/11/30 04:31:06  ewerton.silles
Initial revision

*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlFunctions.h"

#define DVFM_EVS_NUMBER_ARGUMENTS			    		5

#define DVFM_EVS_OK								    	0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID			    1
#define DVFM_EVS_THIRD_ARGUMENT_INVALID				    2
#define DVFM_EVS_THIRD_ARGUMENT_INVALID_HIFEN		    3
#define DVFM_EVS_FOURTH_ARGUMENT_INVALID			    4
#define DVFM_EVS_FOURTH_ARGUMENT_INVALID_HIFEN		    5

#define DVFM_EVS_EOS									'\0'

int
main(int argc,char *argv[ ]) 
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    size_t dvfmEvsUmlMinimumSize;
    size_t dvfmEvsUmlMaximumSize;
	char *dvfmEvsUmlValidation;
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <email> <valid_character> <minimum_size> <maximum_size>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

    if(argv[3][0] == '-')
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"-\"\n");
		exit(DVFM_EVS_THIRD_ARGUMENT_INVALID_HIFEN);
	}
	
	dvfmEvsUmlMinimumSize = (size_t) strtoul( argv[3], &dvfmEvsUmlValidation, 10);
	if(*dvfmEvsUmlValidation != DVFM_EVS_EOS)
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"%c\"\n", dvfmEvsUmlValidation[0]);
		exit(DVFM_EVS_THIRD_ARGUMENT_INVALID);
	}

	if(argv[4][0] == '-')
	{
		printf("Error: Second argument invalid\n");
		printf("First character invalid: \"-\"\n");
		exit(DVFM_EVS_FOURTH_ARGUMENT_INVALID_HIFEN);
	}

    dvfmEvsUmlMaximumSize = (size_t) strtoul( argv[4], &dvfmEvsUmlValidation, 10);
	if(*dvfmEvsUmlValidation != DVFM_EVS_EOS)
	{
		printf("Error: Argumento dois invalido\n");
		printf("First character invalid: \"%c\"\n", dvfmEvsUmlValidation[0]);
		exit(DVFM_EVS_FOURTH_ARGUMENT_INVALID);
	}

    dvfmEvsUmlErrorCode = DvfmEvsUmlCheckEmail(argv[1], argv[2], dvfmEvsUmlMinimumSize, dvfmEvsUmlMaximumSize);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }
    printf("The email is valid.\n");
    
	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlCheckEmail.c,v $ */
