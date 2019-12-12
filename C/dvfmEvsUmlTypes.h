/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL 270 - Computacao II - Turma 2019/2
 
 * $Author: ewerton.silles $
 * $Date: 2019/11/30 04:31:06 $
 * $Log: dvfmEvsUmlTypes.h,v $
 * Revision 1.3  2019/11/30 04:31:06  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.2  2019/11/16 03:48:22  ewerton.silles
 * *** empty log message ***
 *
 * Revision 1.1  2019/11/07 17:17:27  ewerton.silles
 * Initial revision
 *
 * Revision 1.1  2019/11/07 16:49:23  ewerton.silles
 * Initial revision
 * 
*/

#ifndef DVFM_EVS_UML_TYPES_H
#define DVFM_EVS_UML_TYPES_H "@(#)dvfmEvsUmlTypes.h $Revision: 1.3 $"

/* ===== beginning of file code ===== */

typedef enum
{
	dvfmEvsUmlEnglish = 0, 
	dvfmEvsUmlPortuguese = 1, 
	dvfmEvsUmlLanguagesAmount
} dvfmEvsUmlLanguageType;

typedef unsigned long long dvfmEvsUmlUserIdentifierType;
typedef unsigned long long dvfmEvsUmlUserProfileType;

typedef enum
{
	false,
	true
} boolean;

typedef enum
{
	dvfmEvsUmlDes,
	dvfmEvsUmlMd5,
	dvfmEvsUmlSha256,
	dvfmEvsUmlSha512
} dvfmEvsUmlCryptAlgorithms;

typedef struct
{
	char dvfmEvsUmlNameSettings[];
	char dvfmEvsUmlSettings[]
}dvfmEvsUmlConfigurationOptionsType;


/* ===== end of file code ====== */

#endif
/* $RCSfile: dvfmEvsUmlTypes.h,v $ */
