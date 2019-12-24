/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
Prof. Marcelo Luiz Drumond Lanza
EEL 270 - Computacao II - Turma 2019/2
 
$Author: ewerton.silles $
$Date: 2019/12/24 13:52:26 $
$Log: dvfmEvsUmlFunctions.c,v $
Revision 1.6  2019/12/24 13:52:26  ewerton.silles
*** empty log message ***

Revision 1.4  2019/11/30 04:31:06  ewerton.silles
*** empty log message ***

Revision 1.3  2019/11/16 03:48:22  ewerton.silles
*** empty log message ***

Revision 1.2  2019/11/14 16:21:38  ewerton.silles
*** empty log message ***

Revision 1.1  2019/11/08 02:11:08  ewerton.silles
Initial revision
 
*/

#define _XOPEN_SOURCE

#include	<string.h>
#include	<stdio.h>
#include	<time.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"dvfmEvsUmlFunctions.h"
#include	"dvfmEvsUmlConst.h"
#include	"dvfmEvsUmlTypes.h"
#include	"dvfmEvsUmlConfig.h"

/*
 * dvfmEvsUmlLanguageType
 * DvfmEvsUmlGetLanguageIndex( *char dvfmEvsUmlLanguage)
 *
 * Arguments:
 * char * - String referring to language(I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlEnglish - integer that corrects a language English
 * dvfmEvsUmlPortuguese - integer that corrects a language Portuguese
 *
 * Description:
 * This function returns the number corresponding to language, 0 for english, 1 for portuguese
 */

dvfmEvsUmlLanguageType
DvfmEvsUmlGetLanguageIndex(char *dvfmEvsUmlLanguage)
{
	if(!dvfmEvsUmlLanguage)
		return dvfmEvsUmlEnglish;

	if(!strcmp(dvfmEvsUmlLanguage, "dvfmEvsUmlPortuguese"))
		return dvfmEvsUmlPortuguese;

	return dvfmEvsUmlEnglish;
}

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
 * This function returns the number corresponding to error.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlGetAbsoluteFileName (char *dvfmEvsUmlDirectory, char *dvfmEvsUmlFile, char *dvfmEvsUmlConcatenatedString)
{
	if(!dvfmEvsUmlDirectory)
		return dvfmEvsUmlFirstEmptyPointer;
	
	if(!dvfmEvsUmlFile)
		return dvfmEvsUmlSecondEmptyPointer;

	if(!dvfmEvsUmlConcatenatedString)
		return dvfmEvsUmlThirdEmptyPointer;

	if(strlen(dvfmEvsUmlDirectory) > DVFM_EVS_UML_MAXIMUM_LENGTH_ABSOLUTE_PATH)
		return dvfmEvsUmlPathLong;

	if(strlen(dvfmEvsUmlFile) > DVFM_EVS_UML_MAXIMUM_LENGTH_ARCHIVE_NAME)
		return dvfmEvsUmlLongFilename;
	
	if(dvfmEvsUmlDirectory[strlen(dvfmEvsUmlDirectory) - 1] != '/')
		snprintf(dvfmEvsUmlConcatenatedString, strlen(dvfmEvsUmlDirectory) + strlen(dvfmEvsUmlFile) + 1 + 1, "%s/%s", dvfmEvsUmlDirectory, dvfmEvsUmlFile);

	else
		snprintf(dvfmEvsUmlConcatenatedString, strlen(dvfmEvsUmlDirectory) + strlen(dvfmEvsUmlFile) + 1, "%s%s", dvfmEvsUmlDirectory, dvfmEvsUmlFile);

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlCheckStringField (char *dvfmEvsUmlString, char *dvfmEvsUmlValidCharacter,  size_t dvfmEvsUmlMinimumSize, size_t dvfmEvsUmlMaximumSize)
{
	unsigned dvfmEvsUmlIndexString;
	char dvfmEvsUmlNeedle [2];
	dvfmEvsUmlNeedle [1] = '\0';
	
	if(!dvfmEvsUmlString)
                return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlValidCharacter)
                return dvfmEvsUmlSecondEmptyPointer;

	if(strlen(dvfmEvsUmlString) < dvfmEvsUmlMinimumSize)
		return dvfmEvsUmlShortString;

	if(strlen(dvfmEvsUmlString) > dvfmEvsUmlMaximumSize)
		return dvfmEvsUmlLongString;

	for(dvfmEvsUmlIndexString = 0; dvfmEvsUmlString[dvfmEvsUmlIndexString] != '\0'; dvfmEvsUmlIndexString++)
	{
		dvfmEvsUmlNeedle [0] = dvfmEvsUmlString[dvfmEvsUmlIndexString];

		if(!strstr(dvfmEvsUmlValidCharacter, dvfmEvsUmlNeedle))
			return dvfmEvsUmlInvalidCharacter;
	}

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlCheckNickname (char *dvfmEvsUmlNickname, char *dvfmEvsUmlValidCharacter, size_t dvfmEvsUmlMinimumSize, size_t dvfmEvsUmlMaximumSize)
{
	unsigned dvfmEvsUmlIndexNickname;
	char * dvfmEvsUmlFirstOccurrence;
	char dvfmEvsUmlNicknameCopy[strlen(dvfmEvsUmlNickname)];
	char dvfmEvsUmlNeedle [2];
	strcpy(dvfmEvsUmlNicknameCopy, dvfmEvsUmlNickname);
	dvfmEvsUmlNeedle [1] = '\0';

	if(!dvfmEvsUmlNickname)
			return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlValidCharacter)
			return dvfmEvsUmlSecondEmptyPointer;

	if(strlen(dvfmEvsUmlNickname) < dvfmEvsUmlMinimumSize)
			return dvfmEvsUmlShortNickname;

	if(strlen(dvfmEvsUmlNickname) > dvfmEvsUmlMaximumSize)
			return dvfmEvsUmlLongNickname; 

	if(dvfmEvsUmlNickname[0] == '.')
		return dvfmEvsUmlPointFirstPositionNickname;                              

	if(dvfmEvsUmlNickname[strlen(dvfmEvsUmlNickname) - 1] == '.')
		return dvfmEvsUmlPointLastPositionNickname;                              

	if(!(dvfmEvsUmlFirstOccurrence = strstr(dvfmEvsUmlNicknameCopy, ".")))
		return dvfmEvsUmlNoPointsNickname;
	
	dvfmEvsUmlFirstOccurrence [0] = '0';
	if((dvfmEvsUmlFirstOccurrence = strstr(dvfmEvsUmlFirstOccurrence, ".")))
		return dvfmEvsUmlTwoPointsNickname;

	for(dvfmEvsUmlIndexNickname = 0; dvfmEvsUmlNickname[dvfmEvsUmlIndexNickname] != '\0'; dvfmEvsUmlIndexNickname++)
	{
		dvfmEvsUmlNeedle [0] = dvfmEvsUmlNickname[dvfmEvsUmlIndexNickname];
		if(!strstr(dvfmEvsUmlValidCharacter, dvfmEvsUmlNeedle))
			return dvfmEvsUmlInvalidCharacter;
	}

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlCheckEmail (char *dvfmEvsUmlEmail, char *dvfmEvsUmlValidCharacter, size_t dvfmEvsUmlMinimumSize, size_t dvfmEvsUmlMaximumSize)
{
	unsigned dvfmEvsUmlIndexEmail;
	char * dvfmEvsUmlFirstOccurrence;
	char dvfmEvsUmlEmailCopy[strlen(dvfmEvsUmlEmail)];
	char dvfmEvsUmlNeedle [2];
	strcpy(dvfmEvsUmlEmailCopy, dvfmEvsUmlEmail);
	dvfmEvsUmlNeedle [1] = '\0';

	if(!dvfmEvsUmlEmail)
		return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlValidCharacter)
		return dvfmEvsUmlSecondEmptyPointer;

	if(strlen(dvfmEvsUmlEmail) < dvfmEvsUmlMinimumSize)
		return dvfmEvsUmlShortEmail;

	if(strlen(dvfmEvsUmlEmail) > dvfmEvsUmlMaximumSize)
		return dvfmEvsUmlLongEmail;

	if(dvfmEvsUmlEmail[0] == '@')
		return dvfmEvsUmlAtFirstPositionEmail;

	if(dvfmEvsUmlEmail[strlen(dvfmEvsUmlEmail) - 1] == '@')
		return dvfmEvsUmlAtLastPositionEmail;

	if(!(dvfmEvsUmlFirstOccurrence = strstr(dvfmEvsUmlEmailCopy, "@")))
		return dvfmEvsUmlNoAtsEmail;
	
	dvfmEvsUmlFirstOccurrence [0] = '0';
	if((strstr(dvfmEvsUmlFirstOccurrence, "@")))
		return dvfmEvsUmlTwoAtsEmail;

	for(dvfmEvsUmlIndexEmail = 0; dvfmEvsUmlEmail[dvfmEvsUmlIndexEmail] != '\0'; dvfmEvsUmlIndexEmail++)
	{
		dvfmEvsUmlNeedle [0] = dvfmEvsUmlEmail[dvfmEvsUmlIndexEmail];
		if(!strstr(dvfmEvsUmlValidCharacter, dvfmEvsUmlNeedle))
			return dvfmEvsUmlInvalidCharacter;
	}

        return dvfmEvsUmlOk;
}

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
DvfmEvsUmlCreateRandomString (char *dvfmEvsUmlValidCharacter, size_t dvfmEvsUmlSizeRandomString, char *dvfmEvsUmlRandomString)
{
	unsigned dvfmEvsUmlcounter;

	if(!dvfmEvsUmlValidCharacter)
		return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlRandomString)
		return dvfmEvsUmlThirdEmptyPointer;

	srand((unsigned) time(NULL));

	for(dvfmEvsUmlcounter = 0; dvfmEvsUmlcounter < dvfmEvsUmlSizeRandomString; dvfmEvsUmlcounter++)
		dvfmEvsUmlRandomString [dvfmEvsUmlcounter] =  dvfmEvsUmlValidCharacter [rand() % strlen(dvfmEvsUmlValidCharacter)];
	dvfmEvsUmlRandomString [dvfmEvsUmlcounter] = '\0';

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlCreateNickname (char *dvfmEvsUmlName, char *dvfmEvsUmlFirstNickname, char *dvfmEvsUmlSecondNickname)
{
	unsigned dvfmEvsUmlCountName = 0, dvfmEvsUmlIndexName, dvfmEvsUmlIndexOneName;
	char dvfmEvsUmlNameCopy [DVFM_EVS_UML_MAX_SIZE_USER_NAME];
	char dvfmEvsUmlNames [DVFM_EVS_UML_MAX_SIZE_NICKNAME][DVFM_EVS_UML_MAX_SIZE_NICKNAME - 2];

	if(!dvfmEvsUmlName)
		return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlFirstNickname)
		return dvfmEvsUmlSecondEmptyPointer;

	if(!dvfmEvsUmlSecondNickname)
		return dvfmEvsUmlThirdEmptyPointer;
	
	if(!(strstr(dvfmEvsUmlName, " ")))
		return dvfmEvsUmlUniqueName;

	for (dvfmEvsUmlIndexName = 0; dvfmEvsUmlName [dvfmEvsUmlIndexName] != '\0'; dvfmEvsUmlIndexName++)
		if (dvfmEvsUmlName [dvfmEvsUmlIndexName] > 'A' && dvfmEvsUmlName [dvfmEvsUmlIndexName] < 'Z')
			dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName] = dvfmEvsUmlName [dvfmEvsUmlIndexName] + 'a' - 'A';
		else
			dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName] = dvfmEvsUmlName [dvfmEvsUmlIndexName];
	
	dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName] = '\0';
		
	dvfmEvsUmlIndexName = 0;
	

	for (;  dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName?dvfmEvsUmlIndexName - 1:dvfmEvsUmlIndexName] != '\0'; dvfmEvsUmlCountName++)
	{
		for(dvfmEvsUmlIndexOneName = 0;  dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName] != ' '; dvfmEvsUmlIndexName++, dvfmEvsUmlIndexOneName++)
		{
			if (dvfmEvsUmlIndexOneName >= DVFM_EVS_UML_MAX_SIZE_NICKNAME - 2)
				return dvfmEvsUmlLongNickname;

			if ( dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName] == '.')
				return dvfmEvsUmlDotInName;

			if ( dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName] == '\0')
				break;

			dvfmEvsUmlNames [dvfmEvsUmlCountName] [dvfmEvsUmlIndexOneName] =  dvfmEvsUmlNameCopy [dvfmEvsUmlIndexName];
		}
		dvfmEvsUmlNames [dvfmEvsUmlCountName] [dvfmEvsUmlIndexOneName] = '\0';
		dvfmEvsUmlIndexName++;
	}
	dvfmEvsUmlCountName--;

	dvfmEvsUmlFirstNickname[0] = '\0';
	strcat(dvfmEvsUmlFirstNickname, dvfmEvsUmlNames[0]);
	strcat(dvfmEvsUmlFirstNickname, ".");
	strcat(dvfmEvsUmlFirstNickname, dvfmEvsUmlNames[dvfmEvsUmlCountName]);

	if (strlen(dvfmEvsUmlFirstNickname) > DVFM_EVS_UML_MAX_SIZE_NICKNAME)
		return dvfmEvsUmlLongNickname;

	if (dvfmEvsUmlCountName == 1)
		dvfmEvsUmlSecondNickname[0] = '\0';
	else
	{
		dvfmEvsUmlSecondNickname[0] = '\0';
		strcat(dvfmEvsUmlSecondNickname, dvfmEvsUmlNames[0]);
		strcat(dvfmEvsUmlSecondNickname, ".");
		if(strstr("dasdesdisdosdus", dvfmEvsUmlNames[dvfmEvsUmlCountName - 1]))
			dvfmEvsUmlCountName--;
		strcat(dvfmEvsUmlSecondNickname, dvfmEvsUmlNames[dvfmEvsUmlCountName - 1]);
	}
	if (strlen(dvfmEvsUmlSecondNickname) > DVFM_EVS_UML_MAX_SIZE_NICKNAME)
		return dvfmEvsUmlLongNickname;

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlGetCryptAlgorithm (char *dvfmEvsUmlEncryptedPassword, dvfmEvsUmlCryptAlgorithms *dvfmEvsUmlAlgorithm)
{
	char dvfmEvsUmlFirstCharacter [2] = "0\0", dvfmEvsUmlSecondCharacter [2] = "0\0";

	if(!dvfmEvsUmlEncryptedPassword)
                return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlAlgorithm)
			return dvfmEvsUmlSecondEmptyPointer;

	if(dvfmEvsUmlEncryptedPassword [0] != '$')
	{
		if(strlen(dvfmEvsUmlEncryptedPassword) > 13)
			return dvfmEvsUmlFormatEncryptedPassword;

		dvfmEvsUmlFirstCharacter [0] = dvfmEvsUmlEncryptedPassword [0];
		dvfmEvsUmlSecondCharacter [0] = dvfmEvsUmlEncryptedPassword [1];
		if(!strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./", dvfmEvsUmlFirstCharacter) ||
		   !strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./", dvfmEvsUmlSecondCharacter))
			return dvfmEvsUmlFormatEncryptedPassword;

		*dvfmEvsUmlAlgorithm = dvfmEvsUmlDes;
		return dvfmEvsUmlOk;
	}
	switch(dvfmEvsUmlEncryptedPassword [1])
	{
		case  '1':
			*dvfmEvsUmlAlgorithm = dvfmEvsUmlMd5;
			break;
		case  '5':
			*dvfmEvsUmlAlgorithm = dvfmEvsUmlSha256;
			break;
		case  '6':
			*dvfmEvsUmlAlgorithm = dvfmEvsUmlSha512;
			break;
		default:
			return dvfmEvsUmlUnknownAlgorithm;
	}	
	return dvfmEvsUmlOk;

}

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
DvfmEvsUmlEncodePasswordWithSpecificAlgorithm (char *dvfmEvsUmlFlatPassword, dvfmEvsUmlCryptAlgorithms dvfmEvsUmlAlgorithm, char *dvfmEvsUmlEncryptedPassword)
{
	char *dvfmEvsUmlBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./";
	char dvfmEvsUmlAuxiliarySalt[18] = "0\0";
	char dvfmEvsUmlSalt[23] = "$0$\0";
	dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;

	if(!dvfmEvsUmlFlatPassword)
        return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlEncryptedPassword)
        return dvfmEvsUmlThirdEmptyPointer;

	if(!(strlen(dvfmEvsUmlFlatPassword)))
		return dvfmEvsUmlVoidString;

	if(dvfmEvsUmlAlgorithm == dvfmEvsUmlDes)
	{
		if(strlen(dvfmEvsUmlFlatPassword) > 8)
			return dvfmEvsUmlLongFlatPassword;

		dvfmEvsUmlErrorCode = DvfmEvsUmlCreateRandomString(dvfmEvsUmlBase64, 2, dvfmEvsUmlSalt);

		if(dvfmEvsUmlErrorCode)
			return dvfmEvsUmlSecondaryFunction;

		strcpy(dvfmEvsUmlEncryptedPassword, crypt(dvfmEvsUmlFlatPassword, dvfmEvsUmlSalt));
	}
	else
	{
		switch(dvfmEvsUmlAlgorithm)
		{
			case dvfmEvsUmlMd5:
				dvfmEvsUmlErrorCode = DvfmEvsUmlCreateRandomString(dvfmEvsUmlBase64, 8, dvfmEvsUmlAuxiliarySalt);

				if(dvfmEvsUmlErrorCode)
					return dvfmEvsUmlSecondaryFunction;

				dvfmEvsUmlSalt[1] = '1';

				break;

			case dvfmEvsUmlSha256:
				dvfmEvsUmlErrorCode = DvfmEvsUmlCreateRandomString(dvfmEvsUmlBase64, 16, dvfmEvsUmlAuxiliarySalt);

				if(dvfmEvsUmlErrorCode)
					return dvfmEvsUmlSecondaryFunction;

				dvfmEvsUmlSalt[1] = '5';

				break;

			case dvfmEvsUmlSha512:
				dvfmEvsUmlErrorCode = DvfmEvsUmlCreateRandomString(dvfmEvsUmlBase64, 16, dvfmEvsUmlAuxiliarySalt);

				if(dvfmEvsUmlErrorCode)
					return dvfmEvsUmlSecondaryFunction;

				dvfmEvsUmlSalt[1] = '6';

				break;

			default:
				return dvfmEvsUmlAlgorithmNotFound;
		}

		strcat(dvfmEvsUmlAuxiliarySalt, "$\0");
		strcat(dvfmEvsUmlSalt, dvfmEvsUmlAuxiliarySalt);

		strcpy(dvfmEvsUmlEncryptedPassword, crypt(dvfmEvsUmlFlatPassword, dvfmEvsUmlSalt));

	}
	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlEncodePasswordWithSpecificSalt (char *dvfmEvsUmlFlatPassword, char *dvfmEvsUmlFullSalt, char *dvfmEvsUmlEncryptedPassword)
{

	if(!dvfmEvsUmlFlatPassword)
          return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlFullSalt)
		return dvfmEvsUmlSecondEmptyPointer;

	if(!dvfmEvsUmlEncryptedPassword)
		return dvfmEvsUmlThirdEmptyPointer;

	if(!(strlen(dvfmEvsUmlFlatPassword)))
		return dvfmEvsUmlVoidString;

	if (dvfmEvsUmlFullSalt[0] != '$')
	{
		if(strlen(dvfmEvsUmlFlatPassword) > 8)
			return dvfmEvsUmlLongFlatPassword;
		
		if(strlen(dvfmEvsUmlFullSalt) > 2)
			return dvfmEvsUmlInvalidSalt;
	}
	else
	{
		if (dvfmEvsUmlFullSalt[1] == '1' && strlen(dvfmEvsUmlFullSalt) > 12)
			return dvfmEvsUmlInvalidSalt;

		if ((dvfmEvsUmlFullSalt[1] == '5' || dvfmEvsUmlFullSalt[1] == '6') && (strlen(dvfmEvsUmlFullSalt) > 20))
			return dvfmEvsUmlInvalidSalt;
	}
	if(!(crypt(dvfmEvsUmlFlatPassword, dvfmEvsUmlFullSalt)))
		return dvfmEvsUmlSecondaryFunction;

	strcpy(dvfmEvsUmlEncryptedPassword, crypt(dvfmEvsUmlFlatPassword, dvfmEvsUmlFullSalt));

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlCheckPassword (char *dvfmEvsUmlFlatPassword, char *dvfmEvsUmlEncryptedPassword)
{
	unsigned dvfmEvsUmlIndexEncryptedPassword = 3;
	char dvfmEvsUmlSalt[23];
	char dvfmEvsUmlFlatPasswordEncrypted [108];
	dvfmEvsUmlErrorType dvfmEvsUmlErrorCode;

	if(!dvfmEvsUmlFlatPassword)
		return dvfmEvsUmlFirstEmptyPointer;

	if(!dvfmEvsUmlEncryptedPassword)
		return dvfmEvsUmlSecondEmptyPointer;

	if(!(strlen(dvfmEvsUmlFlatPassword)) || !(strlen(dvfmEvsUmlEncryptedPassword)))
		return dvfmEvsUmlVoidString;

	if(strlen(dvfmEvsUmlEncryptedPassword) < 3)
		return dvfmEvsUmlInvalidEncryptedPassword;
	
	dvfmEvsUmlSalt[0] = dvfmEvsUmlEncryptedPassword[0];
	dvfmEvsUmlSalt[1] = dvfmEvsUmlEncryptedPassword[1];

	if(dvfmEvsUmlEncryptedPassword [0] != '$')
	{
		if(strlen(dvfmEvsUmlEncryptedPassword) > 13)
			return dvfmEvsUmlLongEncryptedPassword;

		dvfmEvsUmlSalt[2] = '\0';
	}
	else
	{
		dvfmEvsUmlSalt[2] = dvfmEvsUmlEncryptedPassword[2];
		while(dvfmEvsUmlEncryptedPassword[dvfmEvsUmlIndexEncryptedPassword] != '$' &&
		      dvfmEvsUmlEncryptedPassword[dvfmEvsUmlIndexEncryptedPassword] != '\0')
		{
			dvfmEvsUmlSalt[dvfmEvsUmlIndexEncryptedPassword] = dvfmEvsUmlEncryptedPassword[dvfmEvsUmlIndexEncryptedPassword];

			dvfmEvsUmlIndexEncryptedPassword++;
		}
		dvfmEvsUmlSalt[dvfmEvsUmlIndexEncryptedPassword] = dvfmEvsUmlEncryptedPassword[dvfmEvsUmlIndexEncryptedPassword];
		dvfmEvsUmlSalt[dvfmEvsUmlIndexEncryptedPassword + 1] = '\0';
	}

	dvfmEvsUmlErrorCode = DvfmEvsUmlEncodePasswordWithSpecificSalt(dvfmEvsUmlFlatPassword, dvfmEvsUmlSalt, dvfmEvsUmlFlatPasswordEncrypted);

	if(dvfmEvsUmlErrorCode)
		return dvfmEvsUmlSecondaryFunction;

	if (strcmp( dvfmEvsUmlEncryptedPassword, dvfmEvsUmlFlatPasswordEncrypted))
		return dvfmEvsUmlIncompatibleFlatPassword;

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlGetConfigurationOptionsValues ( char *dvfmEvsUmlNameConfigurationFile, dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings)
{
	FILE *dvfmEvsUmlRead;
	char dvfmEvsUmlBuffer[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE + 1];
	char dvfmEvsUmlSettingValue[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	char dvfmEvsUmlSettingName[DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE - 1];
	unsigned dvfmEvsUmlIndex;
	unsigned dvfmEvsUmlIndexBuffer;

	if(!dvfmEvsUmlSettings)
		return dvfmEvsUmlSecondEmptyPointer;

	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrl, DVFM_EVS_UML_WEB_SERVER_URL);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrlName, DVFM_EVS_UML_WEB_SERVER_URL_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifier, DVFM_EVS_UML_ADMINISTRATOR_USER_IDENTIFIER);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifierName, DVFM_EVS_UML_ADMINISTRATOR_USER_IDENTIFIER_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectory, DVFM_EVS_UML_PRIVATE_ROOT_DIRECTORY);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectoryName, DVFM_EVS_UML_PRIVATE_ROOT_DIRECTORY_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlDataDirectory, DVFM_EVS_UML_DATA_DIRECTORY);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlDataDirectoryName, DVFM_EVS_UML_DATA_DIRECTORY_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectory, DVFM_EVS_UML_COOKIES_DIRECTORY);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectoryName, DVFM_EVS_UML_COOKIES_DIRECTORY_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, DVFM_EVS_UML_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilenameName, DVFM_EVS_UML_USERS_DATA_FILENAME_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename, DVFM_EVS_UML_INVITED_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilenameName, DVFM_EVS_UML_INVITED_USERS_DATA_FILENAME_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, DVFM_EVS_UML_REQUESTING_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilenameName, DVFM_EVS_UML_REQUESTING_USERS_DATA_FILENAME_NAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename, DVFM_EVS_UML_LOCKED_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilenameName, DVFM_EVS_UML_LOCKED_USERS_DATA_FILENAME_NAME);

	if(dvfmEvsUmlNameConfigurationFile)
		if(strlen(dvfmEvsUmlNameConfigurationFile) != 0)
		{
			if(!(dvfmEvsUmlRead = fopen(dvfmEvsUmlNameConfigurationFile, "r")))
				return dvfmEvsUmlCantOpenFile;
			
			while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE, dvfmEvsUmlRead))
				if(dvfmEvsUmlBuffer[0] != '#')
				{
					for (dvfmEvsUmlIndex = 0, dvfmEvsUmlIndexBuffer = 0; dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] != ' ' &&
						dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] != '='; dvfmEvsUmlIndex++, dvfmEvsUmlIndexBuffer++)
					{
						if (dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] == '\0')
							return dvfmEvsUmlInvalidConfigFile;
						
						dvfmEvsUmlSettingName[dvfmEvsUmlIndex] = dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer];
					}
					dvfmEvsUmlSettingName[dvfmEvsUmlIndex] = '\0';

					for (; dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] == ' ' ||
						dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] == '='; dvfmEvsUmlIndexBuffer++);

					for (dvfmEvsUmlIndex = 0; dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] != ' ' &&
						dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] != '\n' &&
						dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer] != '\0'; dvfmEvsUmlIndex++, dvfmEvsUmlIndexBuffer++)
						dvfmEvsUmlSettingValue[dvfmEvsUmlIndex] = dvfmEvsUmlBuffer[dvfmEvsUmlIndexBuffer];
					dvfmEvsUmlSettingValue[dvfmEvsUmlIndex] = '\0';

					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrlName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrl, dvfmEvsUmlSettingValue);

					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifierName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifier, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectoryName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectory, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlDataDirectoryName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlDataDirectory, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectoryName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectory, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilenameName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilenameName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilenameName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilenameName))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename, dvfmEvsUmlSettingValue);
				}
			if(ferror(dvfmEvsUmlRead))
			{
				fclose(dvfmEvsUmlRead);
				return dvfmEvsUmlReadError;
			}

			fclose(dvfmEvsUmlRead);
		}

	return dvfmEvsUmlOk;
}

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
DvfmEvsUmlShowCliHelp (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings, dvfmEvsUmlLanguageType dvfmEvsUmlLanguage)
{
	printf("************************************ ENGLISH ********************************\n");
	printf("\n");
	printf(" ==================================> Legend <===============================\n");
	printf("|* Short option is indicated by: -\n");
	printf("|* Long option is indicated by: --\n");
	printf("|* Words before equals are argument names\n");
	printf("|* Words after the equals are values ​​of their respective argument\n");
	printf("|* The term 'or' is indicated by: |\n");
	printf("|* Free values ​​and indicated by: <argument value>\n");	
	printf("|* Default values ​​and indicated by: ->argument value<-\n");
	printf("|* Optional arguments (not required) are indicated by: [argument=value]\n");
	printf("|* Mandatory arguments are indicated by: argument=value\n");
	printf(" ===========================================================================\n");
	printf("\n");
	printf("\t\t\t -h | --help\n");
	printf("\t\t =>Description: shows a description of all options and how to use them in all available languages\n");
	printf("\t\t =>Use: ./dvfmEvsUml -h | --help [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -o | --options\n");
	printf("\t\t =>Description: displays the values ​​of all configuration options\n");
	printf("\t\t =>Use: ./dvfmEvsUml -o | --options [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -N | --Ncurses\n");
	printf("\t\t =>Description: run the program via Ncurses interface\n");
	printf("\t\t =>Use: ./dvfmEvsUml -N | --Ncurses [configuration=<arquivo-configuração>] [user=<apelido>][language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -C | --Configure\n");
	printf("\t\t =>Description: configures the tool to permanently or temporarily add new user data to the system\n");
	printf("\t\t =>Use: ./dvfmEvsUml -C | --Configure [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -a | --add\n");
	printf("\t\t =>Description: permanently or temporarily adds new user data to the system\n");
	printf("\t\t =>Use: -a | --add [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -i | --invite\n");
	printf("\t\t =>Description: requests the permanent or temporary addition of new user data to the system\n");
	printf("\t\t =>Use: ./dvfmEvsUml -i | --invite [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");	
	printf("\n");
	printf("\t\t\t -t | --accept\n");
	printf("\t\t =>Description: accept a new user in the system\n");
	printf("\t\t =>Use: ./dvfmEvsUml -t | --accept [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -j | --reject\n");
	printf("\t\t =>Description: delete a system user\n");
	printf("\t\t =>Use: ./dvfmEvsUml -j | --reject [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -n | --new\n");
	printf("\t\t =>Description: start the evaluation process\n");
	printf("\t\t =>Use: ./dvfmEvsUml -n | --new [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> friend-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -q | --request\n");
	printf("\t\t =>Description: lists all valid requests not met by the user in question\n");
	printf("\t\t =>Use: ./dvfmEvsUml -q | --request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -Q | --Request\n");
	printf("\t\t =>Description: lists all valid requests not fulfilled\n");
	printf("\t\t =>Use: ./dvfmEvsUml -Q | --Request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -v | --approve\n");
	printf("\t\t =>Description: concludes and accepts the process of adding a new user to the system\n");
	printf("\t\t =>Use: ./dvfmEvsUml -v | --approve [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -d | --disapprove\n");
	printf("\t\t =>Description: concludes and rejects the process of adding a new user to the system\n");
	printf("\t\t =>Use: ./dvfmEvsUml -d | --disapprove [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -U | --Unlocking\n");
	printf("\t\t =>Description: lists all users who have requested account unlocking\n");
	printf("\t\t =>Use: ./dvfmEvsUml -U | --Unlocking [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -l | --lock\n");
	printf("\t\t =>Description: blocks the user account in question\n");
	printf("\t\t =>Use: ./dvfmEvsUml -l | --lock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -u | --unlock\n");
	printf("\t\t =>Description: unlock an account\n");
	printf("\t\t =>Use: ./dvfmEvsUml -u | --unlock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -p | --password\n");
	printf("\t\t =>Description: change password\n");
	printf("\t\t =>Use: ./dvfmEvsUml -p | --password [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -r | --reset\n");
	printf("\t\t =>Description: request a temporary password for system access\n");
	printf("\t\t =>Use: ./dvfmEvsUml -r | --reset [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -m | --modify\n");
	printf("\t\t =>Description: change name\n");
	printf("\t\t =>Use: ./dvfmEvsUml -m | --modify [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] username=<nome- completo> confirm-username=<nome-completo> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -e | --edit\n");
	printf("\t\t =>Description: change the electronic address\n");
	printf("\t\t =>Use: ./dvfmEvsUml -e | --edit [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -c | --confirm\n");
	printf("\t\t =>Description: validate your new email address\n");
	printf("\t\t =>Use: ./dvfmEvsUml -c | --confirm [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] key=<chave> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -g | --group\n");
	printf("\t\t =>Description: change profile\n");
	printf("\t\t =>Use: ./dvfmEvsUml -g | --group [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido>  profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -s | --show\n");
	printf("\t\t =>Description: get information about all users registered in the system\n");
	printf("\t\t =>Use: ./dvfmEvsUml -s | --show [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -S | --Search\n");
	printf("\t\t =>Description: get information about all users registered in the system that meet the search filters\n");
	printf("\t\t =>Use: ./dvfmEvsUml -S | --Search [configuration=<arquivo-configuração>] [username=<nome-completo ou parte-do-nome>] [email=<endereço-eletrônico ou parte-do-endereço-eletrônico>] [profile=->administrator<- | ->professor<- | ->administrator-professor<- | ->student<- | ->administrator-student<- | ->professor-student<- | ->administrator-professor-student<- [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("************************************ PORTUGUES ************************************\n");
	printf("\n");
	printf(" ==================================> Legenda <==================================\n");
	printf("|* Opcao curta e indicado por: -\n");
	printf("|* Opcao longa e indicado por: --\n");
	printf("|* Palavras antes do igual sao nomes de argumentos\n");
	printf("|* Palavras depois do igual sao valores de seu respectivo argumento\n");
	printf("|* O termo 'ou' e indicado por: |\n");
	printf("|* Valores livres e indicado por: <valor do argumento>\n");	
	printf("|* Valores  predefinidos e indicado por: ->valor do argumento<-\n");
	printf("|* Argumentos opcionais (nao obrigatorio) sao indicados por: [argumento=valor]\n");
	printf("|* Argumentos obrigatorios sao indicados por: arguemnto=valor\n");
	printf(" ===============================================================================\n");
	printf("\n");
	printf("\t\t\t -h | --help\n");
	printf("\t\t =>Descricao: monstra uma descricao de todas as opcoes e como utilisa-las em todos os idiomas disponiveis\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -h | --help [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -o | --options\n");
	printf("\t\t =>Descricao: exibe os valores de todas as opcoes de configuracao\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -o | --options [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -N | --Ncurses\n");
	printf("\t\t =>Descricao: executa o programa via interface Ncurses\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -N | --Ncurses [configuration=<arquivo-configuração>] [user=<apelido>][language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -C | --Configure\n");
	printf("\t\t =>Descricao: configura a ferramenta de adicionar permanente ou temporariamente os dados de um novo usuario ao sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -C | --Configure [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -a | --add\n");
	printf("\t\t =>Descricao: adiciona permanente ou temporariamente os dados de um novo usuario ao sistema\n");
	printf("\t\t =>Uso: -a | --add [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -i | --invite\n");
	printf("\t\t =>Descricao: solicita a adicao permanente ou temporariamente os dados de um novo usuario ao sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -i | --invite [configuration=<arquivo-configuração>] user=<apelido> username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");	
	printf("\n");
	printf("\t\t\t -t | --accept\n");
	printf("\t\t =>Descricao: aceita um novo usuario no sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -t | --accept [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -j | --reject\n");
	printf("\t\t =>Descricao: exclui um usuario do sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -j | --reject [configuration=<arquivo-configuração>] user=<apelido>[language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -n | --new\n");
	printf("\t\t =>Descricao: inicia o processo de avaliacao\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -n | --new [configuration=<arquivo-configuração>] username=<nome-completo> confirm-username=<nome-completo> email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> friend-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -q | --request\n");
	printf("\t\t =>Descricao: lista todas as solicitacoes validas nao atendidas pelo usuario em questao\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -q | --request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -Q | --Request\n");
	printf("\t\t =>Descricao: lista todas as solicitacoes validas nao atendidas\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -Q | --Request [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -v | --approve\n");
	printf("\t\t =>Descricao: conclui e aceita o processo de adicionar um novo usuario ao sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -v | --approve [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -d | --disapprove\n");
	printf("\t\t =>Descricao: conclui e rejeita o processo de adicionar um novo usuario ao sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -d | --disapprove [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -U | --Unlocking\n");
	printf("\t\t =>Descricao: lista todos os usuarios que solicitaram desbloqueio de conta\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -U | --Unlocking [configuration=<arquivo-configuração>] user=<apelido> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -l | --lock\n");
	printf("\t\t =>Descricao: bloqueia a conta do usuario em questao\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -l | --lock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -u | --unlock\n");
	printf("\t\t =>Descricao: desbloqueia uma conta\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -u | --unlock [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -p | --password\n");
	printf("\t\t =>Descricao: altera a senha\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -p | --password [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -r | --reset\n");
	printf("\t\t =>Descricao: solicita uma senha temporaria para acesso ao sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -r | --reset [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -m | --modify\n");
	printf("\t\t =>Descricao: altera o nome\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -m | --modify [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] username=<nome- completo> confirm-username=<nome-completo> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -e | --edit\n");
	printf("\t\t =>Descricao: altera o endereco eletronico\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -e | --edit [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] email=<endereço-eletrônico> confirm-email=<endereço-eletrônico> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -c | --confirm\n");
	printf("\t\t =>Descricao: valida o seu novo endereço eletronico\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -c | --confirm [configuration=<arquivo-configuração>] user=<apelido> [nickname=<apelido>] key=<chave> [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -g | --group\n");
	printf("\t\t =>Descricao: troca o perfil\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -g | --group [configuration=<arquivo-configuração>] user=<apelido> nickname=<apelido>  profile=->administrator<- | ->professor<- | ->student<- [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -s | --show\n");
	printf("\t\t =>Descricao: obter informacoes sobre todos os usuarios cadastrados no sistema\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -s | --show [configuration=<arquivo-configuração>] [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\t\t\t -S | --Search\n");
	printf("\t\t =>Descricao: obter informacoes sobre todos os usuarios cadastrados no  sistema que atendam aos filtros de busca\n");
	printf("\t\t =>Uso: ./dvfmEvsUml -S | --Search [configuration=<arquivo-configuração>] [username=<nome-completo ou parte-do-nome>] [email=<endereço-eletrônico ou parte-do-endereço-eletrônico>] [profile=->administrator<- | ->professor<- | ->administrator-professor<- | ->student<- | ->administrator-student<- | ->professor-student<- | ->administrator-professor-student<- [language=->english<- | ->portuguese<-]\n");
	printf("\n");
	printf("\n");
	printf("################################ END OF HELP ################################\n");
	printf("\n");

}

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlAddUser (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlUserDataType *);
 *
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - configuration options (I)
 * dvfmEvsUmlUserDataType * - struct user information (I)
 * 
 * Returned code:
 * 
 * dvfmEvsUmlOk - all right
 * 
 * Description:
 * Permanently or temporarily add new user data to the system
 */

dvfmEvsUmlErrorType
DvfmEvsUmlAddUser (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings, dvfmEvsUmlUserDataType *dvfmEvsUmlDataUser)
{

	FILE * dvfmEvsUmlUsersFile;

	dvfmEvsUmlErrorType dvfmEvsUmlReturnCode;

	char dvfmEvsUmlFirstNickname [DVFM_EVS_UML_NICKNAME_BUFFER_SIZE];
	char dvfmEvsUmlSecondNickname [DVFM_EVS_UML_NICKNAME_BUFFER_SIZE];
	char dvfmEvsUmlPresentNickname [DVFM_EVS_UML_NICKNAME_BUFFER_SIZE];
	char dvfmEvsUmlEncryptedPassword [DVFM_EVS_UML_ENCRYPTED_PASSWORD_BUFFER_SIZE];
	char dvfmEvsUmlBuffer [DVFM_EVS_UML_BUFFER_SIZE_LINE_CONFIG_FILE];
	char dvfmEvsUmlUserIdentifierString [DVFM_EVS_UML_MAXIMUM_NUMBER_IN_ID];

	dvfmEvsUmlUserIdentifierType dvfmEvsUmlUserIdentifierPresent, dvfmEvsUmlUserIdentifierPrevious;

	unsigned dvfmEvsUmlIndex, dvfmEvsUmlTwoPointCounter, dvfmEvsUmlMultiplier, dvfmEvsUmlNumber, dvfmEvsUmlBeginPresentNickname, dvfmEvsUmlEndPresentNickname, dvfmEvsUmlNumberProfile = 0;

	dvfmEvsUmlBool dvfmEvsUmlLastLine = dvfmEvsUmlFalse;
	dvfmEvsUmlBool dvfmEvsUmlFirstNumber = dvfmEvsUmlTrue;
	dvfmEvsUmlBool dvfmEvsUmlFirstLine = dvfmEvsUmlTrue;
	dvfmEvsUmlBool dvfmEvsUmlFound = dvfmEvsUmlFalse;
	dvfmEvsUmlBool dvfmEvsUmlExistFirstNickname = dvfmEvsUmlFalse;

	/* variation if the information is valid */

	if(strcmp( dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername, dvfmEvsUmlDataUser->dvfmEvsUmlStructConfirmUsername))
		return dvfmEvsUmlDifferentUsernameConfirmation;

	if(strcmp( dvfmEvsUmlDataUser->dvfmEvsUmlStructEmail, dvfmEvsUmlDataUser->dvfmEvsUmlStructConfirmEmail))
		return dvfmEvsUmlDifferentEmailConfirmation;

	if(strcmp( dvfmEvsUmlDataUser->dvfmEvsUmlStructPassword, dvfmEvsUmlDataUser->dvfmEvsUmlStructConfirmPassword))
		return dvfmEvsUmlDifferentPasswordConfirmation;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckStringField ( dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername, DVFM_EVS_UML_VALID_CHARACTERS_USER_NAME, DVFM_EVS_UML_MINIMUM_SIZE_USER_NAME, DVFM_EVS_UML_MAX_SIZE_USER_NAME)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckEmail( dvfmEvsUmlDataUser->dvfmEvsUmlStructEmail, DVFM_EVS_UML_VALID_CHARACTERS_EMAIL, DVFM_EVS_UML_MINIMUM_SIZE_EMAIL, DVFM_EVS_UML_MAX_SIZE_EMAIL)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckStringField ( dvfmEvsUmlDataUser->dvfmEvsUmlStructPassword, DVFM_EVS_UML_VALID_CHARACTERS_PASSWORD, DVFM_EVS_UML_MINIMUM_SIZE_PASSWORD, DVFM_EVS_UML_MAX_SIZE_PASSWORD)))
		return dvfmEvsUmlReturnCode;

	/* redeeming username */

	dvfmEvsUmlIndex = 0;

	while (dvfmEvsUmlIndex < strlen(dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername))
	{
		if(dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername [dvfmEvsUmlIndex] == '-')
			dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername [dvfmEvsUmlIndex] = ' ';
					
		dvfmEvsUmlIndex++;
	}

	/* creating nickname */

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCreateNickname ( dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername, dvfmEvsUmlFirstNickname, dvfmEvsUmlSecondNickname)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckNickname ( dvfmEvsUmlFirstNickname, DVFM_EVS_UML_VALID_CHARACTERS_NICKNAME, DVFM_EVS_UML_MINIMUM_SIZE_NICKNAME, DVFM_EVS_UML_MAX_SIZE_NICKNAME)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckNickname ( dvfmEvsUmlSecondNickname, DVFM_EVS_UML_VALID_CHARACTERS_NICKNAME, DVFM_EVS_UML_MINIMUM_SIZE_NICKNAME, DVFM_EVS_UML_MAX_SIZE_NICKNAME)))
		return dvfmEvsUmlReturnCode;

	/* redeeming profiles */

	if(strlen(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile))
	{
		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile, "administrator")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile, "professor")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlProfessor);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile, "student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlStudent);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile, "administrator-professor")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator + dvfmEvsUmlProfessor);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile, "administrator-student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator + dvfmEvsUmlStudent);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile, "professor-student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlProfessor + dvfmEvsUmlStudent);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlStructProfile, "administrator-professor-student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator + dvfmEvsUmlProfessor + dvfmEvsUmlStudent);
	}

	/* existence test */

	if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r")))
	{
		/* does not exist  */

		/* creating encrypted password */

		if((dvfmEvsUmlReturnCode = DvfmEvsUmlEncodePasswordWithSpecificAlgorithm( dvfmEvsUmlDataUser->dvfmEvsUmlStructPassword, dvfmEvsUmlSha512, dvfmEvsUmlEncryptedPassword)))
			return dvfmEvsUmlReturnCode;

		if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckPassword( dvfmEvsUmlDataUser->dvfmEvsUmlStructPassword, dvfmEvsUmlEncryptedPassword)))
			return dvfmEvsUmlReturnCode;

		/* writing the data in the file */

		if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "w")))
			return dvfmEvsUmlCantOpenFile;

		fprintf( dvfmEvsUmlUsersFile, "0:%s:%s:1:%s:%s", dvfmEvsUmlFirstNickname, dvfmEvsUmlEncryptedPassword, dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername,  dvfmEvsUmlDataUser->dvfmEvsUmlStructEmail);

		fclose(dvfmEvsUmlUsersFile);	

	}
	else
	{
		/* exist  */

		/* varying whether the password exists */

		if(strlen(dvfmEvsUmlDataUser->dvfmEvsUmlStructPassword))
		{
			/* exist  */

			/* creating encrypted password */

			if((dvfmEvsUmlReturnCode = DvfmEvsUmlEncodePasswordWithSpecificAlgorithm( dvfmEvsUmlDataUser->dvfmEvsUmlStructPassword, dvfmEvsUmlSha512, dvfmEvsUmlEncryptedPassword)))
				return dvfmEvsUmlReturnCode;

			if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckPassword( dvfmEvsUmlDataUser->dvfmEvsUmlStructPassword, dvfmEvsUmlEncryptedPassword)))
				return dvfmEvsUmlReturnCode;

			/* checking that there are no blank lines */

			while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_BUFFER_SIZE_LINE_CONFIG_FILE, dvfmEvsUmlUsersFile))
			{
				if (dvfmEvsUmlLastLine)
				{
					/* error */
					fclose (dvfmEvsUmlUsersFile);
					return dvfmEvsUmlCorruptedFile;
				}

				if(strlen (dvfmEvsUmlBuffer) == 1 && dvfmEvsUmlBuffer [strlen (dvfmEvsUmlBuffer) - 1] == '\n')
				{
					/* error */
					fclose (dvfmEvsUmlUsersFile);
					return dvfmEvsUmlCorruptedFile;
				}

				if (dvfmEvsUmlBuffer [strlen (dvfmEvsUmlBuffer) - 1] != '\n')
					dvfmEvsUmlLastLine = dvfmEvsUmlTrue;
			}

			/* error test while reading file */

			if(ferror(dvfmEvsUmlUsersFile))
			{
					/* error */
					fclose (dvfmEvsUmlUsersFile);
					return dvfmEvsUmlReadError;
			}

			fclose (dvfmEvsUmlUsersFile);

			/* checking if nickname already exists */

			if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r")))
				return dvfmEvsUmlCantOpenFile;

			while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_BUFFER_SIZE_LINE_CONFIG_FILE, dvfmEvsUmlUsersFile))
			{
				dvfmEvsUmlIndex = 0;
				dvfmEvsUmlTwoPointCounter = 0;

				while (dvfmEvsUmlIndex < strlen(dvfmEvsUmlBuffer))
				{
					if(dvfmEvsUmlBuffer [dvfmEvsUmlIndex] == ':')
					{

						if(dvfmEvsUmlTwoPointCounter == 0)
							dvfmEvsUmlBeginPresentNickname = dvfmEvsUmlIndex + 1;

						if(dvfmEvsUmlTwoPointCounter == 1)
							dvfmEvsUmlEndPresentNickname = dvfmEvsUmlIndex - 1;
						
						dvfmEvsUmlTwoPointCounter++;
					}
					
					dvfmEvsUmlIndex++;
				}

				strncpy(dvfmEvsUmlPresentNickname, &dvfmEvsUmlBuffer[dvfmEvsUmlBeginPresentNickname], dvfmEvsUmlEndPresentNickname - dvfmEvsUmlBeginPresentNickname + 1);

				dvfmEvsUmlPresentNickname[dvfmEvsUmlEndPresentNickname - dvfmEvsUmlBeginPresentNickname + 1] = '\0';

				if(!(strcmp( dvfmEvsUmlPresentNickname, dvfmEvsUmlFirstNickname)))
					dvfmEvsUmlExistFirstNickname = dvfmEvsUmlTrue;

				if(dvfmEvsUmlTwoPointCounter != 5)
					return dvfmEvsUmlCorruptedFile;
			}

			

			/* adding the user */

			if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r+")))
				return dvfmEvsUmlCantOpenFile;

			dvfmEvsUmlUserIdentifierPrevious = 0;

			while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_BUFFER_SIZE_LINE_CONFIG_FILE, dvfmEvsUmlUsersFile))
			{
				/* collecting current id */

				dvfmEvsUmlIndex = strlen(dvfmEvsUmlBuffer) -1;
				dvfmEvsUmlTwoPointCounter = 0;
				dvfmEvsUmlMultiplier = 10;
				dvfmEvsUmlNumber = 0;
				dvfmEvsUmlUserIdentifierPresent = 0;

				while (dvfmEvsUmlIndex >= 0)
				{
					if(dvfmEvsUmlBuffer [dvfmEvsUmlIndex] == ':')
							dvfmEvsUmlTwoPointCounter++;

					else
					{
						if(dvfmEvsUmlTwoPointCounter == 5)
						{
							dvfmEvsUmlNumber = dvfmEvsUmlBuffer [dvfmEvsUmlIndex] - '0';

							if(dvfmEvsUmlFirstNumber)
							{
								dvfmEvsUmlUserIdentifierPresent +=  dvfmEvsUmlNumber;
								dvfmEvsUmlFirstNumber = dvfmEvsUmlFalse;
							}

							dvfmEvsUmlUserIdentifierPresent +=  dvfmEvsUmlNumber * dvfmEvsUmlMultiplier;

							dvfmEvsUmlMultiplier *= 10;
						}
					}
					
					dvfmEvsUmlIndex--;
				}

				dvfmEvsUmlFirstNumber = dvfmEvsUmlTrue;

				if(dvfmEvsUmlTwoPointCounter != 5)
					return dvfmEvsUmlCorruptedFile;

				/* comparing current id with previous id */

				if(dvfmEvsUmlUserIdentifierPresent <= dvfmEvsUmlUserIdentifierPrevious && !dvfmEvsUmlFirstLine)
				{
					/* error */
					fclose (dvfmEvsUmlUsersFile);
					return dvfmEvsUmlCorruptedFile;
				}
				
				if(dvfmEvsUmlUserIdentifierPresent != dvfmEvsUmlUserIdentifierPrevious + 1)
				{
					dvfmEvsUmlFound = dvfmEvsUmlTrue;

					if(!dvfmEvsUmlExistFirstNickname)
					{
						snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPrevious + 1);

						fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlFirstNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername,  dvfmEvsUmlDataUser->dvfmEvsUmlStructEmail);
					}

					else
					{
						snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPrevious + 1);

						fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlSecondNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername,  dvfmEvsUmlDataUser->dvfmEvsUmlStructEmail);
					}

				}
				else
				{
					dvfmEvsUmlUserIdentifierPrevious = dvfmEvsUmlUserIdentifierPresent;
				}

				dvfmEvsUmlFirstLine = dvfmEvsUmlFalse;
			}

			if(!dvfmEvsUmlFound)
			{
				if(!dvfmEvsUmlExistFirstNickname)
				{
					snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPresent + 1);

					fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlFirstNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername,  dvfmEvsUmlDataUser->dvfmEvsUmlStructEmail);
				}

				else
				{
					snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPresent + 1);

					fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlSecondNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlStructUsername,  dvfmEvsUmlDataUser->dvfmEvsUmlStructEmail);
				}

			}

			/* error test while reading file */

			if(ferror(dvfmEvsUmlUsersFile))
			{
					/* error */
					fclose (dvfmEvsUmlUsersFile);
					return dvfmEvsUmlReadError;
			}

			fclose (dvfmEvsUmlUsersFile);

			/* sending email to added user */



		}
		else
		{
			/* does not exist  */
		}

	}

	return dvfmEvsUmlOk;
}

/* $RCSfile: dvfmEvsUmlFunctions.c,v $ */
