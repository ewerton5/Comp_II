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
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifier, DVFM_EVS_UML_ADMINISTRATOR_USER_IDENTIFIER);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectory, DVFM_EVS_UML_PRIVATE_ROOT_DIRECTORY);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlDataDirectory, DVFM_EVS_UML_DATA_DIRECTORY);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectory, DVFM_EVS_UML_COOKIES_DIRECTORY);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, DVFM_EVS_UML_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename, DVFM_EVS_UML_INVITED_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, DVFM_EVS_UML_REQUESTING_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename, DVFM_EVS_UML_LOCKED_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlUnlockingUsersDataFilename, DVFM_EVS_UML_UNLOCKING_USERS_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlPasswordAbeyancesDataFilename, DVFM_EVS_UML_PASSWORD_ABEYANCES_DATA_FILENAME);
	strcpy(dvfmEvsUmlSettings->dvfmEvsUmlEmailAbeyancesDataFilename, DVFM_EVS_UML_EMAIL_ABEYANCES_DATA_FILENAME);

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
						{
							fclose(dvfmEvsUmlRead);
							return dvfmEvsUmlInvalidConfigFile;
						}
						
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

					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_WEB_SERVER_URL_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlWebServerUrl, dvfmEvsUmlSettingValue);

					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_ADMINISTRATOR_USER_IDENTIFIER_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlAdministratorUserIdentifier, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_PRIVATE_ROOT_DIRECTORY_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlPrivateRootDirectory, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_DATA_DIRECTORY_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlDataDirectory, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_COOKIES_DIRECTORY_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlCookiesDirectory, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_USERS_DATA_FILENAME_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_INVITED_USERS_DATA_FILENAME_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlInvitedUsersDataFilename, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_REQUESTING_USERS_DATA_FILENAME_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlRequestingUsersDataFilename, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_LOCKED_USERS_DATA_FILENAME_NAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlLockedUsersDataFilename, dvfmEvsUmlSettingValue);
					
					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_UNLOCKING_USERS_DATA_FILENAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlUnlockingUsersDataFilename, dvfmEvsUmlSettingValue);

					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_PASSWORD_ABEYANCES_DATA_FILENAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlPasswordAbeyancesDataFilename, dvfmEvsUmlSettingValue);

					if(!strcmp(dvfmEvsUmlSettingName, DVFM_EVS_UML_EMAIL_ABEYANCES_DATA_FILENAME))
						strcpy(dvfmEvsUmlSettings->dvfmEvsUmlEmailAbeyancesDataFilename, dvfmEvsUmlSettingValue);
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

/* $RCSfile: dvfmEvsUmlFunctions.c,v $ */
