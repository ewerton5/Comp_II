/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2019/11/30 04:31:06 $
 * $Log: dvfmEvsUmlErrors.h,v $
 * Revision 1.3  2019/11/30 04:31:06  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/11/16 03:48:22  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/11/14 22:25:01  ewerton.silles
 * Initial revision
 * 
*/

#ifndef DVFM_EVS_UML_ERRORS_H
#define DVFM_EVS_UML_ERRORS_H "@(#)dvfmEvsUmlErrors.h $Revision: 1.3 $"

/* ===== beginning of file code ===== */

#include			"dvfmEvsUmlTypes.h"

typedef enum 
{
	dvfmEvsUmlOk,
	dvfmEvsUmlFirstEmptyPointer,
	dvfmEvsUmlSecondEmptyPointer,
	dvfmEvsUmlThirdEmptyPointer,
	dvfmEvsUmlPathLong,
	dvfmEvsUmlLongFilename,
	dvfmEvsUmlMinimumMaximumInverted,
	dvfmEvsUmlShortString,
	dvfmEvsUmlLongString,
	dvfmEvsUmlInvalidCharacter,
	dvfmEvsUmlShortNickname,
	dvfmEvsUmlLongNickname,
	dvfmEvsUmlPointFirstPositionNickname,
	dvfmEvsUmlPointLastPositionNickname,
	dvfmEvsUmlNoPointsNickname,
	dvfmEvsUmlTwoPointsNickname,
	dvfmEvsUmlInvalidCharacterNickname,
	dvfmEvsUmlShortEmail,
	dvfmEvsUmlLongEmail,
	dvfmEvsUmlAtFirstPositionEmail,
	dvfmEvsUmlAtLastPositionEmail,
	dvfmEvsUmlNoAtsEmail,
	dvfmEvsUmlTwoAtsEmail,
	dvfmEvsUmlInvalidCharacterEmail,
	dvfmEvsUmlUniqueName,
	dvfmEvsUmlDotInName,
	dvfmEvsUmlFormatEncryptedPassword,
	dvfmEvsUmlUnknownAlgorithm,
	dvfmEvsUmlLongFlatPassword,
	dvfmEvsUmlSecondaryFunction,
	dvfmEvsUmlAlgorithmNotFound,
	dvfmEvsUmlVoidString,
	dvfmEvsUmlInvalidEncryptedPassword,
	dvfmEvsUmlLongEncryptedPassword,
	dvfmEvsUmlIncompatibleFlatPassword,
	dvfmEvsUmlInvalidSalt,
	dvfmEvsUmlCantOpenFile,
	dvfmEvsUmlReadError,
	dvfmEvsUmlShortArgument,
	dvfmEvsUmlLongtArgument,
	dvfmEvsUmlInvalidPositionOptions,
	dvfmEvsUmlFewSubOptions,
	dvfmEvsUmlInvalidSubOption,
	dvfmEvsUmlLackCompulsorySubOption,
	dvfmEvsUmlInvalidOptions,
	dvfmEvsUmlSizeErrorType, 
} dvfmEvsUmlErrorType;

/*
 * char *
 * DvfmEvsUmlGetCliErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * char * - language string (O)
 * dvfmEvsUmlErrorType - error code Type enum (I)
 * dvfmEvsUmlLanguageType - language code Type enum (I)
 *
 * Returned code:
 * char *
 *
 * Description:
 * This function converts the error code into an error message for interface CLI.
 */

char *
DvfmEvsUmlGetCliErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);

/*
 * char *
 * DvfmEvsUmlGetNcursesErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * char * - language string (O)
 * dvfmEvsUmlErrorType - error code Type enum (I)
 * dvfmEvsUmlLanguageType - language code Type enum (I)
 *
 * Returned code:
 * char *
 *
 * Description:
 * This function converts the error code into an error message for interface Ncurses.
 */

char *
DvfmEvsUmlGetNcursesErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);

/*
 * char *
 * DvfmEvsUmlGetWebErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * char * - language string (O)
 * dvfmEvsUmlErrorType - error code Type enum (I)
 * dvfmEvsUmlLanguageType - language code Type enum (I)
 *
 * Returned code:
 * char *
 *
 * Description:
 * This function converts the error code into an error message for interface Web.
 */

char *
DvfmEvsUmlGetWebErrorMessage (dvfmEvsUmlErrorType, dvfmEvsUmlLanguageType);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlErrors.h,v $ */
