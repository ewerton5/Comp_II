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

#include	"dvfmEvsUmlShowConfigurationValues.h"

/*
 * dvfmEvsUmlErrorType
 * DvfmEvsUmlShowConfigurationValues (dvfmEvsUmlConfigurationOptionsType *, dvfmEvsUmlLanguageType);
 *
 * Arguments:
 * dvfmEvsUmlConfigurationOptionsType * - Configuration options (I)
 * dvfmEvsUmlLanguageType - integer that corrects a language type enum (I)
 *
 * Returned code:
 * 
 * dvfmEvsUmlErrorType - integer that correspond a error
 * 
 * Description:
 * Displays the values of all configuration options.
 */

dvfmEvsUmlErrorType
DvfmEvsUmlShowConfigurationValues (dvfmEvsUmlConfigurationOptionsType *dvfmEvsUmlSettings,
                                   dvfmEvsUmlLanguageType dvfmEvsUmlLanguage)
{
    if (!dvfmEvsUmlSettings)
        return dvfmEvsUmlFirstEmptyPointer;
    
    return dvfmEvsUmlOk;
}

/* $RCSfile$ */
