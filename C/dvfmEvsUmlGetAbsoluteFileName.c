/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/11/30 04:31:06 $
$Log: dvfmEvsUmlGetAbsoluteFileName.c,v $
Revision 1.2  2019/11/30 04:31:06  ewerton.silles
*** empty log message ***

Revision 1.1  2019/11/16 03:48:22  ewerton.silles
Initial revision

*/

#include					<stdio.h>
#include					<stdlib.h>
#include					"dvfmEvsUmlFunctions.h"
#include					"dvfmEvsUmlConst.h"

#define DVFM_EVS_NUMBER_ARGUMENTS					3

#define DVFM_EVS_OK											0
#define DVFM_EVS_NUMBER_ARGUMENTS_INVALID				1

#define DVFM_EVS_UML_MAXIMUM_LENGTH_CONCATENATED_STRING     DVFM_EVS_UML_MAXIMUM_LENGTH_ABSOLUTE_PATH + DVFM_EVS_UML_MAXIMUM_LENGTH_ARCHIVE_NAME

int
main(int argc,char *argv[ ]) 
{
    dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;
    char dvfmEvsUmlConcatenatedString [DVFM_EVS_UML_MAXIMUM_LENGTH_CONCATENATED_STRING];
	if (argc != DVFM_EVS_NUMBER_ARGUMENTS) 
	{
		printf("use: %s <path> <filename>\n", argv[0]);
		exit(DVFM_EVS_NUMBER_ARGUMENTS_INVALID);
	}
    dvfmEvsUmlErrorCode = DvfmEvsUmlGetAbsoluteFileName(argv[1], argv[2], dvfmEvsUmlConcatenatedString);
	if (dvfmEvsUmlErrorCode)
    {
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage(dvfmEvsUmlErrorCode, dvfmEvsUmlEnglish));
        exit(DVFM_EVS_OK);
    }
    printf("%s\n", dvfmEvsUmlConcatenatedString);
	return DVFM_EVS_OK;
}
/* $RCSfile: dvfmEvsUmlGetAbsoluteFileName.c,v $ */
