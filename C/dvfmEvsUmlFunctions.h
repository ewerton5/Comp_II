/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2019/11/30 04:31:06 $
 * $Log: dvfmEvsUmlFunctions.h,v $
 * Revision 1.4  2019/11/30 04:31:06  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.3  2019/11/16 03:48:22  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/11/08 02:11:08  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/11/07 17:23:33  ewerton.silles
 * Initial revision
 * 
*/

#ifndef DVFM_EVS_UML_FUNCTIONS_H
#define DVFM_EVS_UML_FUNCTIONS_H "@(#)dvfmEvsUmlFunctions.h $Revision: 1.4 $"

/* ===== beginning of file code ===== */

#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlErrors.h"

/*
 * dvfmEvsUmlLanguageType
 * DvfmEvsUmlGetLanguageIndex(char*);
 *
 * Arguments:
 * char * - language string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlLanguageType - integer that correspond a language
 * 
 * Description:
 * This function returns the number corresponding to language, 0 for english and 1 for portuguese
 */

dvfmEvsUmlLanguageType
DvfmEvsUmlGetLanguageIndex(char*);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetAbsoluteFileName(char*);
 *
 * Arguments:
 * char * - path string (I)
 * char * - filename string (I)
 * char * - concatenated string (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * This function concatenate two strings and return it.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetAbsoluteFileName (char *, char *, char *);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlCheckStringField (char *, char *,  size_t, size_t);
 *
 * Arguments:
 * char * - string to validate (I)
 * char * - valid characters (I)
 * size_t - minimum length (I)
 * size_t - maximum lenght (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - valid string
 * 
 * Description:
 * This function returns whether or not the string is valid.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlCheckStringField (char *, char *,  size_t, size_t);

/*
 *dvfmEvsUmlUmlErrorType
 *DvfmEvsUmlCheckNickname (char *, char *, size_t, size_t);
 *
 * Arguments:
 * char * - nick name to validate (I)
 * char * - valid characters (I)
 * size_t - minimum length (I)
 * size_t - maximum lenght (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - valid nick name.
 * 
 * Description:
 * This function returns whether or not the nick name is valid.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlCheckNickname (char *, char *, size_t, size_t);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlCheckEmail (char *, char *, size_t, size_t);
 *
 * Arguments:
 * char * - Email to validate (I)
 * char * - valid characters (I)
 * size_t - minimum length (I)
 * size_t - maximum lenght (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - valid Email.
 * 
 * Description:
 * This function returns whether or not the Email is valid.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlCheckEmail (char *, char *, size_t, size_t);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlCreateRandomString (char *, size_t, char *);
 *
 * Arguments:
 * char * - valid characters (I)
 * size_t - random string length (I)
 * char * - random string (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - trouble free function.
 * 
 * Description:
 * This function returns a random string.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlCreateRandomString (char *, size_t, char *);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlCreateNickname (char *, char *, char *);
 *
 * Arguments:
 * char * - full name (I)
 * char * - first nickname option (O)
 * char * - second nickname option(O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - trouble free function.
 * 
 * Description:
 * This function returns two nickname options.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlCreateNickname (char *, char *, char *);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetCryptAlgorithm (char *, mldlUmlCryptAlgorithms *);
 *
 * Arguments:
 * char * - encrypted password (I)
 * mldlUmlCryptAlgorithms * - algorithm used in encryption (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - trouble free function.
 * 
 * Description:
 * This function returns the algorithm used in encryption.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetCryptAlgorithm (char *, dvfmEvsUmlCryptAlgorithms *);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlEncodePasswordWithSpecificAlgorithm (char *, mldlUmlCryptAlgorithms, char *);
 *
 *
 * Arguments:
 * char * - flat password (I)
 * mldlUmlCryptAlgorithms * - algorithm used in encryption (I)
 * char * - encrypted password (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - trouble free function.
 * 
 * Description:
 * This function returns the encrypted password based on the planda password and encryption algorithm.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlEncodePasswordWithSpecificAlgorithm (char *, dvfmEvsUmlCryptAlgorithms, char *);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlEncodePasswordWithSpecificSalt (char *, char *, char *);
 *
 *
 * Arguments:
 * char * - flat password (I)
 * char * - full salt (I)
 * char * - encrypted password (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - trouble free function.
 * 
 * Description:
 * This function returns the encrypted password based on the planda password and full salt.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlEncodePasswordWithSpecificSalt (char *, char *, char *);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlCheckPassword (char *, char *);
 *
 *
 *
 * Arguments:
 * char * - flat password (I)
 * char * - encrypted password (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - if the flat password is compatible with the encrypted one.
 * 
 * Description:
 * This function evaluates whether the flat password is compatible with the encrypted password.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlCheckPassword (char *, char *);

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlGetConfigurationOptionsValues (char *, dvfmEvsUmlConfigurationOptionsType *);
 *
 *
 * Arguments:
 * char * - name of the configuration file (I)
 * dvfmEvsUmlConfigurationOptionsType * - the address of a local variable of type dvfmEvsUmlConfigurationOptionsType (O)
 *
 * Returned code:
 * 
 * dvfmEvsUmlOk - if the flat password is compatible with the encrypted one.
 * 
 * Description:
 * Fills the structure with the configuration information.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetConfigurationOptionsValues ( char *, dvfmEvsUmlConfigurationOptionsType *);

/*
 * void
 * DvfmEvsUmlShowCliHelp (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);
 *
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - the address of a local variable of type dvfmEvsUmlConfigurationOptionsType (I)
 * dvfmEvsUmlLanguageType - name of the configuration file (I)
 * 
 * Returned code:
 * 
 * void
 * 
 * Description:
 * This function shows help in the CLI environment.
 */

void
DvfmEvsUmlShowCliHelp (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);

/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlFunctions.h,v $ */
