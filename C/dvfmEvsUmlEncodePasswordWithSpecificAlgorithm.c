/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/30 04:31:06 $
$Log: dvfmEvsUmlEncodePasswordWithSpecificAlgorithm.c,v $
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
    dvfmEvsUmlCryptAlgorithms dvfmEvsUmlAlgorithm;
	char dvfmEvsUmlEncryptedPassword [108];
	char *dvfmEvsUmlValidation;

	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <flat password> <algorithm used in encryption>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

    if(argv[2][0] == '-')
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"-\"\n");
		exit(DVFM_EVS_SECOND_ARGUMENT_INVALID_HIFEN);
	}
	
	dvfmEvsUmlAlgorithm = (dvfmEvsUmlCryptAlgorithms) strtoul( argv[2], &dvfmEvsUmlValidation, 10);
	if(*dvfmEvsUmlValidation != DVFM_EVS_EOS)
	{
		printf("Error: First argument invalid\n");
		printf("First character invalid: \"%c\"\n", dvfmEvsUmlValidation[0]);
		exit(DVFM_EVS_SECOND_ARGUMENT_INVALID);
	}

    dvfmEvsUmlErrorCode = DvfmEvsUmlEncodePasswordWithSpecificAlgorithm(argv[1], dvfmEvsUmlAlgorithm, dvfmEvsUmlEncryptedPassword);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }
    printf("Encrypted password: \"%s\".\n", dvfmEvsUmlEncryptedPassword);
    
	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlEncodePasswordWithSpecificAlgorithm.c,v $ */
