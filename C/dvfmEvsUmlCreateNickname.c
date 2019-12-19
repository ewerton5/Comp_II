/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/30 04:31:06 $
$Log: dvfmEvsUmlCreateNickname.c,v $
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
    char dvfmEvsUmlFirstNickname [DVFM_EVS_UML_MAX_SIZE_NICKNAME + 1];
	char dvfmEvsUmlSecondNickname [DVFM_EVS_UML_MAX_SIZE_NICKNAME + 1];
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <full_name>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}

    dvfmEvsUmlErrorCode = DvfmEvsUmlCreateNickname(argv[1], dvfmEvsUmlFirstNickname, dvfmEvsUmlSecondNickname);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }
    printf("First nickname: \"%s\", Second nickname: \"%s\".\n", dvfmEvsUmlFirstNickname, dvfmEvsUmlSecondNickname);
    
	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlCreateNickname.c,v $ */
