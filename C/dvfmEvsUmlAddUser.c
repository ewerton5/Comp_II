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

#include	<string.h>
#include	<stdio.h>
#include	"dvfmEvsUmlConfig.h"
#include	"dvfmEvsUmlConst.h"
#include	"dvfmEvsUmlAddUser.h"
#include	"dvfmEvsUmlFunctions.h"


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
DvfmEvsUmlAddUser (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
				   dvfmEvsUmlUserDataType *dvfmEvsUmlDataUser)
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

	unsigned dvfmEvsUmlTwoPointCounter, dvfmEvsUmlMultiplier, dvfmEvsUmlNumber, dvfmEvsUmlBeginPresentNickname, dvfmEvsUmlEndPresentNickname, dvfmEvsUmlLineCounter, dvfmEvsUmlInsertionLine, dvfmEvsUmlNumberProfile = 0;
    int dvfmEvsUmlIndex;

	dvfmEvsUmlBool dvfmEvsUmlLastLine = dvfmEvsUmlFalse;
	dvfmEvsUmlBool dvfmEvsUmlFirstNumber = dvfmEvsUmlTrue;
	dvfmEvsUmlBool dvfmEvsUmlFirstLine = dvfmEvsUmlTrue;
	dvfmEvsUmlBool dvfmEvsUmlFound = dvfmEvsUmlFalse;
	dvfmEvsUmlBool dvfmEvsUmlExistFirstNickname = dvfmEvsUmlFalse;

	/* variation if the information is valid */

	if(strcmp( dvfmEvsUmlDataUser->dvfmEvsUmlNickname, dvfmEvsUmlDataUser->dvfmEvsUmlConfirmNickname))
		return dvfmEvsUmlDifferentUsernameConfirmation;

	if(strcmp( dvfmEvsUmlDataUser->dvfmEvsUmlEmail, dvfmEvsUmlDataUser->dvfmEvsUmlConfirmEmail))
		return dvfmEvsUmlDifferentEmailConfirmation;

	if(strcmp( dvfmEvsUmlDataUser->dvfmEvsUmlPassword, dvfmEvsUmlDataUser->dvfmEvsUmlConfirmPassword))
		return dvfmEvsUmlDifferentPasswordConfirmation;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckStringField ( dvfmEvsUmlDataUser->dvfmEvsUmlNickname, DVFM_EVS_UML_VALID_CHARACTERS_USER_NAME, DVFM_EVS_UML_MINIMUM_SIZE_USER_NAME, DVFM_EVS_UML_MAX_SIZE_USER_NAME)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckEmail( dvfmEvsUmlDataUser->dvfmEvsUmlEmail, DVFM_EVS_UML_VALID_CHARACTERS_EMAIL, DVFM_EVS_UML_MINIMUM_SIZE_EMAIL, DVFM_EVS_UML_MAX_SIZE_EMAIL)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckStringField ( dvfmEvsUmlDataUser->dvfmEvsUmlPassword, DVFM_EVS_UML_VALID_CHARACTERS_PASSWORD, DVFM_EVS_UML_MINIMUM_SIZE_PASSWORD, DVFM_EVS_UML_MAX_SIZE_PASSWORD)))
		return dvfmEvsUmlReturnCode;

	/* redeeming username */

	dvfmEvsUmlIndex = 0;

	while (dvfmEvsUmlIndex < strlen(dvfmEvsUmlDataUser->dvfmEvsUmlNickname))
	{
		if(dvfmEvsUmlDataUser->dvfmEvsUmlNickname [dvfmEvsUmlIndex] == '-')
			dvfmEvsUmlDataUser->dvfmEvsUmlNickname [dvfmEvsUmlIndex] = ' ';
					
		dvfmEvsUmlIndex++;
	}

	/* creating nickname */

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCreateNickname ( dvfmEvsUmlDataUser->dvfmEvsUmlNickname, dvfmEvsUmlFirstNickname, dvfmEvsUmlSecondNickname)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckNickname ( dvfmEvsUmlFirstNickname, DVFM_EVS_UML_VALID_CHARACTERS_NICKNAME, DVFM_EVS_UML_MINIMUM_SIZE_NICKNAME, DVFM_EVS_UML_MAX_SIZE_NICKNAME)))
		return dvfmEvsUmlReturnCode;

	if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckNickname ( dvfmEvsUmlSecondNickname, DVFM_EVS_UML_VALID_CHARACTERS_NICKNAME, DVFM_EVS_UML_MINIMUM_SIZE_NICKNAME, DVFM_EVS_UML_MAX_SIZE_NICKNAME)))
		return dvfmEvsUmlReturnCode;

	/* redeeming profiles */

	if(strlen(dvfmEvsUmlDataUser->dvfmEvsUmlProfile))
	{
		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlProfile, "administrator")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlProfile, "professor")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlProfessor);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlProfile, "student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlStudent);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlProfile, "administrator-professor")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator + dvfmEvsUmlProfessor);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlProfile, "administrator-student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator + dvfmEvsUmlStudent);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlProfile, "professor-student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlProfessor + dvfmEvsUmlStudent);

		if(!(strcmp(dvfmEvsUmlDataUser->dvfmEvsUmlProfile, "administrator-professor-student")))
			dvfmEvsUmlNumberProfile  = (unsigned)(dvfmEvsUmlAdministrator + dvfmEvsUmlProfessor + dvfmEvsUmlStudent);
	}

	/* existence test */

	if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r")))
	{
		/* does not exist  */

		/* creating encrypted password */

		if((dvfmEvsUmlReturnCode = DvfmEvsUmlEncodePasswordWithSpecificAlgorithm( dvfmEvsUmlDataUser->dvfmEvsUmlPassword, dvfmEvsUmlSha512, dvfmEvsUmlEncryptedPassword)))
			return dvfmEvsUmlReturnCode;

		if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckPassword( dvfmEvsUmlDataUser->dvfmEvsUmlPassword, dvfmEvsUmlEncryptedPassword)))
			return dvfmEvsUmlReturnCode;

		/* writing the data in the file */

		if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "w")))
			return dvfmEvsUmlCantOpenFile;

		fprintf( dvfmEvsUmlUsersFile, "0:%s:%s:1:%s:%s", dvfmEvsUmlFirstNickname, dvfmEvsUmlEncryptedPassword, dvfmEvsUmlDataUser->dvfmEvsUmlNickname,  dvfmEvsUmlDataUser->dvfmEvsUmlEmail);

		fclose(dvfmEvsUmlUsersFile);	

	}
	else
	{
		/* exist  */

		/* varying whether the password exists */

		if(strlen(dvfmEvsUmlDataUser->dvfmEvsUmlPassword))
		{
			/* exist  */

			/* creating encrypted password */

			if((dvfmEvsUmlReturnCode = DvfmEvsUmlEncodePasswordWithSpecificAlgorithm( dvfmEvsUmlDataUser->dvfmEvsUmlPassword, dvfmEvsUmlSha512, dvfmEvsUmlEncryptedPassword)))
				return dvfmEvsUmlReturnCode;

			if((dvfmEvsUmlReturnCode = DvfmEvsUmlCheckPassword( dvfmEvsUmlDataUser->dvfmEvsUmlPassword, dvfmEvsUmlEncryptedPassword)))
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

			/* locating the new swell */

			if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r+")))
				return dvfmEvsUmlCantOpenFile;

			dvfmEvsUmlUserIdentifierPrevious = 0;
            dvfmEvsUmlLineCounter = 0;

			while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_BUFFER_SIZE_LINE_CONFIG_FILE, dvfmEvsUmlUsersFile))
			{
				/* collecting current id */

				dvfmEvsUmlIndex = strlen(dvfmEvsUmlBuffer) -1;
				dvfmEvsUmlTwoPointCounter = 0;
				dvfmEvsUmlMultiplier = 10;
				dvfmEvsUmlNumber = 0;
				dvfmEvsUmlUserIdentifierPresent = 0;

                dvfmEvsUmlLineCounter++;

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
                            else
                            {   dvfmEvsUmlUserIdentifierPresent +=  dvfmEvsUmlNumber * dvfmEvsUmlMultiplier;

                                dvfmEvsUmlMultiplier *= 10;
                            }
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
				
				if(dvfmEvsUmlUserIdentifierPresent != dvfmEvsUmlUserIdentifierPrevious + 1 && !dvfmEvsUmlFirstLine && !dvfmEvsUmlFound)
				{
					dvfmEvsUmlFound = dvfmEvsUmlTrue;

                    dvfmEvsUmlInsertionLine = dvfmEvsUmlLineCounter;

					/*===if(!dvfmEvsUmlExistFirstNickname)
					{
						snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPrevious + 1);

						fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlFirstNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlNickname,  dvfmEvsUmlDataUser->dvfmEvsUmlEmail);
					}

					else
					{
						snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPrevious + 1);

						fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlSecondNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlNickname,  dvfmEvsUmlDataUser->dvfmEvsUmlEmail);
					}===*/

				}
				else
				{
					dvfmEvsUmlUserIdentifierPrevious = dvfmEvsUmlUserIdentifierPresent;
				}

				dvfmEvsUmlFirstLine = dvfmEvsUmlFalse;
			}

            /* error test while reading file */

			if(ferror(dvfmEvsUmlUsersFile))
			{
					/* error */
					fclose (dvfmEvsUmlUsersFile);
					return dvfmEvsUmlReadError;
			}

			fclose (dvfmEvsUmlUsersFile);

            /* adding the user */

			if(!dvfmEvsUmlFound)
			{

                if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "a")))
				return dvfmEvsUmlCantOpenFile;

				if(!dvfmEvsUmlExistFirstNickname)
				{
					snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPresent + 1);

					fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlFirstNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlNickname,  dvfmEvsUmlDataUser->dvfmEvsUmlEmail);
				}

				else
				{
					snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPresent + 1);

					fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlSecondNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlNickname,  dvfmEvsUmlDataUser->dvfmEvsUmlEmail);
				}

                /* error test while reading file */

                if(ferror(dvfmEvsUmlUsersFile))
                {
                        /* error */
                        fclose (dvfmEvsUmlUsersFile);
                        return dvfmEvsUmlReadError;
                }

			    fclose (dvfmEvsUmlUsersFile);
			}
            else
            {
                if(!(dvfmEvsUmlUsersFile = fopen (dvfmEvsUmlSettings->dvfmEvsUmlUsersDataFilename, "r+")))
				return dvfmEvsUmlCantOpenFile;

                dvfmEvsUmlLineCounter = 0;

                while(fgets(dvfmEvsUmlBuffer, DVFM_EVS_UML_BUFFER_SIZE_LINE_CONFIG_FILE, dvfmEvsUmlUsersFile))
                {
                    dvfmEvsUmlLineCounter++;

                    if(dvfmEvsUmlLineCounter == dvfmEvsUmlInsertionLine - 1)
                    {
                        if(!dvfmEvsUmlExistFirstNickname)
                        {
                            snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPresent + 1);

                            fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlFirstNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlNickname,  dvfmEvsUmlDataUser->dvfmEvsUmlEmail);
                        }

                        else
                        {
                            snprintf(dvfmEvsUmlUserIdentifierString, sizeof(dvfmEvsUmlUserIdentifierPrevious + 1), "%llu", dvfmEvsUmlUserIdentifierPresent + 1);

                            fprintf( dvfmEvsUmlUsersFile, "\n%s:%s:%s:%c:%s:%s", dvfmEvsUmlUserIdentifierString, dvfmEvsUmlSecondNickname, dvfmEvsUmlEncryptedPassword, (char)(dvfmEvsUmlNumberProfile + '0'), dvfmEvsUmlDataUser->dvfmEvsUmlNickname,  dvfmEvsUmlDataUser->dvfmEvsUmlEmail);
                        }
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
            }

			/* sending email to added user */



		}
		else
		{
			/* does not exist  */
		}

	}

	return dvfmEvsUmlOk;
}

/* $RCSfile$ */