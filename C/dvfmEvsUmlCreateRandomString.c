/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/30 04:31:06 $
$Log: dvfmEvsUmlCreateRandomString.c,v $
Revision 1.1  2019/11/30 04:31:06  ewerton.silles
Initial revision

*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlFunctions.h"

#define DVFM_EVS_NUMBER_ARGUMENTS			    		3

#define DVFM_EVS_OK								    	0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID		        1
#define DVFM_EVS_SECOND_ARGUMENT_INVALID	            2
#define DVFM_EVS_SECOND_ARGUMENT_INVALID_HIFEN          3

#define DVFM_EVS_EOS									'\0'

int
main(int argc,char *argv[ ]) 
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    size_t dvfmEvsUmlSizeRandomString;
	char *dvfmEvsUmlValidation;
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <valid_character> <size_random_string>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

    if(argv[2][0] == '-')
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"-\"\n");
		exit(DVFM_EVS_SECOND_ARGUMENT_INVALID_HIFEN);
	}
	
	dvfmEvsUmlSizeRandomString = (size_t) strtoul( argv[2], &dvfmEvsUmlValidation, 10);
    char dvfmEvsUmlRandomString [dvfmEvsUmlSizeRandomString + 1];
	if(*dvfmEvsUmlValidation != DVFM_EVS_EOS)
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"%c\"\n", dvfmEvsUmlValidation[0]);
		exit(DVFM_EVS_SECOND_ARGUMENT_INVALID);
	}

    dvfmEvsUmlErrorCode = DvfmEvsUmlCreateRandomString(argv[1], dvfmEvsUmlSizeRandomString, dvfmEvsUmlRandomString);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }
    printf("The random string is: \"%s\".\n", dvfmEvsUmlRandomString);
    
	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlCreateRandomString.c,v $ */
