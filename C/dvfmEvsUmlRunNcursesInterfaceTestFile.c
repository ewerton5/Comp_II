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

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlRunNcursesInterface.h"

#define DVFM_EVS_NUMBER_ARGUMENTS			    		2

#define DVFM_EVS_OK								    	0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID		        1

int
main(int argc,char *argv[ ]) 
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings = (dvfmEvsUmlConfigurationOptionsType *) malloc(sizeof(dvfmEvsUmlConfigurationOptionsType));
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <nickname>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

    dvfmEvsUmlErrorCode = DvfmEvsUmlRunNcursesInterface(dvfmEvsUmlSettings, argv[1], dvfmEvsUmlEnglish);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }

	return DVFM_EVS_OK;
}
/* $RCSfile$ */
