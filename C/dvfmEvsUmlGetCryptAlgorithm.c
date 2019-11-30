/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/30 04:31:06 $
$Log: dvfmEvsUmlGetCryptAlgorithm.c,v $
Revision 1.1  2019/11/30 04:31:06  ewerton.silles
Initial revision

*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlFunctions.h"
#include					"dvfmEvsUmlConst.h"

#define DVFM_EVS_NUMBER_ARGUMENTS			    		2

#define DVFM_EVS_OK								    	0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID		        1

#define DVFM_EVS_EOS									'\0'

int
main(int argc,char *argv[ ]) 
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlCryptAlgorithms dvfmEvsUmlAlgorithm;
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <encrypted_password>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

    dvfmEvsUmlErrorCode = DvfmEvsUmlGetCryptAlgorithm(argv[1], &dvfmEvsUmlAlgorithm);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }
    printf("Algorithm number: %d.\n", dvfmEvsUmlAlgorithm);
    
	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlGetCryptAlgorithm.c,v $ */
