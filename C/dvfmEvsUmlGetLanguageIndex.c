/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/16 03:48:22 $
$Log: dvfmEvsUmlGetLanguageIndex.c,v $
Revision 1.2  2019/11/16 03:48:22  ewerton.silles
*** empty log message ***

Revision 1.1  2019/11/14 22:25:48  ewerton.silles
Initial revision
 
*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlFunctions.h"

#define DVFM_EVS_NUMBER_ARGUMENTS					2

#define DVFM_EVS_OK											0
#define DVFM_EVS_INVALID_NUMBER_ARGUMENTS					1

int
main(int argc,char *argv[ ]) 
{
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <language>\n", argv[0]);
		exit(DVFM_EVS_INVALID_NUMBER_ARGUMENTS);
	}
	switch (DvfmEvsUmlGetLanguageIndex (argv[1]))
	{
		case dvfmEvsUmlEnglish:
			printf("English language\n");
			break;
		case dvfmEvsUmlPortuguese:
			printf("Portuguese language\n");
			break;
		default:
			printf("English Language\n");
			break;
	}
	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlGetLanguageIndex.c,v $ */
