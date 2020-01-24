/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author$
 * $Date$
 * $Log$
*/

#include    <stdio.h>
#include    <string.h>
#include	"dvfmEvsUmlResetUserPassword.h"
#include	"dvfmEvsUmlGetUsers.h"
#include	"dvfmEvsUmlFunctions.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlResetUserPassword (dvfmEvsUmlConfigurationOptionsType *,
 *                              char *);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * char * - nickname string (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Request a temporary password.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlResetUserPassword (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                             char *dvfmEvsUmlNickname)
{
    dvfmEvsUmlUserDataType *dvfmEvsUmlUserData = (dvfmEvsUmlUserDataType *) malloc(sizeof(dvfmEvsUmlUserDataType));
    dvfmEvsUmlUserIdentifierType dvfmEvsUmlNumericIndentifier, dvfmEvsUmlNumericIndentifierFirstNumber;
    FILE *dvfmEvsUmlWrite;
    unsigned dvfmEvsUmlIndex, dvfmEvsUmlCounter;
    char dvfmEvsUmlBuffer [DVFM_EVS_UML_MAXIMUM_LENGTH_CONFIG_FILE],
         dvfmEvsUmlNumericIndentifierString [10], dvfmEvsUmlPassword [DVFM_EVS_UML_MINIMUM_SIZE_PASSWORD],
         dvfmEvsUmlEncryptedPassword [DVFM_EVS_UML_MAX_SIZE_PASSWORD];

    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;

    if (!dvfmEvsUmlNickname)
        return dvfmEvsUmlSecondEmptyPointer;

    if (DvfmEvsUmlGetUsers (dvfmEvsUmlSettings, &dvfmEvsUmlUserData))
        return dvfmEvsUmlSecondaryFunction;

    while (strcmp(dvfmEvsUmlUserData->dvfmEvsUmlNickname, dvfmEvsUmlNickname))
        dvfmEvsUmlUserData = dvfmEvsUmlUserData->dvfmEvsUmlNextUserData;
    
    if (!dvfmEvsUmlUserData)
        return dvfmEvsUmlUserNotFound;

    dvfmEvsUmlNumericIndentifier = dvfmEvsUmlUserData->dvfmEvsUmlNumericIndentifier;

    for(dvfmEvsUmlIndex = 0; dvfmEvsUmlNumericIndentifier;dvfmEvsUmlIndex++)
    {
        dvfmEvsUmlNumericIndentifierFirstNumber = dvfmEvsUmlNumericIndentifier;
        for (dvfmEvsUmlCounter = 0; dvfmEvsUmlNumericIndentifierFirstNumber > 10; dvfmEvsUmlCounter++)
            dvfmEvsUmlNumericIndentifierFirstNumber = (dvfmEvsUmlUserIdentifierType) dvfmEvsUmlNumericIndentifierFirstNumber/10;
        dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = (char) dvfmEvsUmlNumericIndentifierFirstNumber + '0';
        dvfmEvsUmlNumericIndentifier = dvfmEvsUmlNumericIndentifier - dvfmEvsUmlNumericIndentifierFirstNumber*pow(10, dvfmEvsUmlCounter);
    }
    dvfmEvsUmlNumericIndentifierString [dvfmEvsUmlIndex] = '\0';

    if (DvfmEvsUmlCreateRandomString(DVFM_EVS_UML_VALID_CHARACTERS_PASSWORD, DVFM_EVS_UML_MINIMUM_SIZE_PASSWORD, dvfmEvsUmlPassword))
        return dvfmEvsUmlSecondaryFunction;
    
    if (DvfmEvsUmlEncodePasswordWithSpecificAlgorithm(dvfmEvsUmlPassword, dvfmEvsUmlSha512, dvfmEvsUmlEncryptedPassword))
        return dvfmEvsUmlSecondaryFunction;

    if(!(dvfmEvsUmlWrite = fopen(dvfmEvsUmlSettings->dvfmEvsUmlPasswordAbeyancesDataFilename, "a")))
        return dvfmEvsUmlCantOpenFile;

    strcpy(dvfmEvsUmlBuffer, "172800:");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlNumericIndentifierString);
    strcpy(dvfmEvsUmlBuffer, ":");
    strcat(dvfmEvsUmlBuffer, dvfmEvsUmlEncryptedPassword);

    fprintf(dvfmEvsUmlWrite, "%s", dvfmEvsUmlBuffer);

    fclose(dvfmEvsUmlWrite);

    if(!(dvfmEvsUmlWrite = fopen("dvfmEvsUmlMailFile", "w")))
        return dvfmEvsUmlCantOpenFile;

    fprintf(dvfmEvsUmlWrite, "Sua senha foi resetada. A nova senha é: %s\n", dvfmEvsUmlEncryptedPassword);

    fclose(dvfmEvsUmlWrite);

    sprintf(dvfmEvsUmlBuffer, "sendmail %s < %s", dvfmEvsUmlUserData->dvfmEvsUmlEmail ,"dvfmEvsUmlMailFile");
    system(dvfmEvsUmlBuffer);

    remove("dvfmEvsUmlMailFile");
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
