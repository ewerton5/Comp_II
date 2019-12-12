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

#include                            <stdlib.h>
#include                            <getopt.h>
#include                            <string.h>  

#define DVFM_EVS_UML_QUANTITY_OPTIONS       24

#define DVFM_EVS_UML_OK             0

int
main (int argc, char *argv[])
{
    char *dvfmEvsUmlShortOption = "hoNCaitjnqQvdUluprmecgsS";

    opterr = 0;

    struct option dvfmEvsUmlLongOption [DVFM_EVS_UML_QUANTITY_OPTIONS + 1]=
	{
		{"help", 2, NULL, 'h'},
		{"options", 2, NULL, 'o'},
        {"Ncurses", 2, NULL, 'N'},
        {"Configure", 1, NULL, 'C'},
        {"add", 1, NULL, 'a'},
        {"invite", 1, NULL, 'i'},
        {"accept", 1, NULL, 't'},
        {"reject", 1, NULL, 'j'},
        {"new", 1, NULL, 'n'},
        {"request", 1, NULL, 'q'},
        {"Request", 1, NULL, 'Q'},
        {"approve", 1, NULL, 'v'},
        {"disapprove", 1, NULL, 'd'},
        {"Unlocking", 1, NULL, 'U'},
        {"lock", 1, NULL, 'l'},
        {"unlock", 1, NULL, 'u'},
        {"password", 1, NULL, 'p'},
        {"reset", 1, NULL, 'r'},
        {"modify", 1, NULL, 'm'},
        {"edit", 1, NULL, 'e'},
        {"confirm", 1, NULL, 'c'},
        {"group", 1, NULL, 'g'},
        {"show", 2, NULL, 's'},
        {"Search", 2, NULL, 'S'},
        {NULL, 0, NULL, 0},
	};

    int dvfmEvsUmlCurrentOption;

    enum
    {
        dvfmEvsUmlConfiguration,
        dvfmEvsUmlLanguage,
        dvfmEvsUmlUser,
        dvfmEvsUmlUsername,
        dvfmEvsUmlConfirmUsername,
        dvfmEvsUmlEmail,
        dvfmEvsUmlConfirmEmail,
        dvfmEvsUmlProfile,
        dvfmEvsUmlFriendEmail,
        dvfmEvsUmlNickname,
        dvfmEvsUmlKey,
        dvfmEvsUmlSizeSubOption
    };

    char dvfmEvsUmlSubOption [dvfmEvsUmlSizeSubOption + 1] = 
    {
        "configuration",
        "language",
        "user",
        "username",
        "confirm-username",
        "email",
        "confirm-email",
        "profile",
        "friend-email",
        "nickname",
        "key",
        NULL
    };

    int dvfmEvsUmlIndexArgument, dvfmEvsUmlIndexNameSubOption;
    char *dvfmEvsUmlCurrentArgument;
    char *dvfmEvsUmlNameSubOption;
    char *dvfmEvsUmlValueSubOption;

    dvfmEvsUmlCurrentOption = getopt_long(argc, argv, dvfmEvsUmlShortOption, dvfmEvsUmlLongOption, NULL);

    switch (dvfmEvsUmlCurrentOption)
    {
    case 'h':
        
            /* DvfmEvsUmlShowCliHelp */

            /* testar se o numero de argumentos obrigatorios ta correto */
            
            for(dvfmEvsUmlIndexArgument = optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlConfiguration:
                    
                    /* variavel aque eu ainda nao criei referente a configuraçao q começa com "" vai receber o valor assim como nos outros */

                    break;

                case dvfmEvsUmlLanguage:
                    /* code */
                    break;
                
                default:
                    break;
                }
            }

        break;

    case 'o':
        
            /* DvfmEvsUmlShowConfigurationValues */
        
        break;

    case 'N':

            /* DvfmEvsUmlRunNcursesInterface */    
        
        break;
        
    case 'C':

            /* DvfmEvsUmlAddUser */    
        
        break;
        
    case 'a':
        
            /* DvfmEvsUmlAddUser */
        
        break;
        
    case 'i':
        
            /* DvfmEvsUmlAddUser */
        
        break;
        
    case 't':
        
            /* DvfmEvsUmlAcceptInvite */
        
        break;
        
    case 'j':
        
            /* DvfmEvsUmlRejectInvite */
        
        break;
        
    case 'n':
        
            /* DvfmEvsUmlRequestRegistration */
        
        break;
        
    case 'q':
        
            /* DvfmEvsUmlGetPendingRegistrationRequestsPerUser */
        
        break;
        
    case 'Q':
        
            /* DvfmEvsUmlGetPendingRegistrationRequests */
        
        break;
        
    case 'v':
        
            /* DvfmEvsUmlApproveRegistrationRequest */
        
        break;
        
    case 'd':
        
            /* DvfmEvsUmlDisapproveRegistrationRequest */
        
        break;
        
    case 'U':
        
            /* DvfmEvsUmlGetUnlockingRequests */
        
        break;
        
    case 'l':
        
            /* DvfmEvsUmlLockUserAccount */
        
        break;
        
    case 'u':
        
            /* DvfmEvsUmlUnlockUserAccount */
        
        break;
        
    case 'p':
        
            /* DvfmEvsUmlChangeUserPassword */
        
        break;
        
    case 'r':
        
            /* DvfmEvsUmlResetUserPassword */
        
        break;
        
    case 'm':
        
            /* DvfmEvsUmlChangeUserName */
        
        break;
        
    case 'e':
        
            /* DvfmEvsUmlChangeUserEmail */
        
        break;
        
    case 'c':
        
            /* DvfmEvsUmlConfirmEmailChange */
        
        break;
        
    case 'g':
        
            /* DvfmEvsUmlChangeUserProfile */
        
        break;
        
    case 's':
        
            /* DvfmEvsUmlGetUsers */
        
        break;
        
    case 'S':
        
            /* DvfmEvsUmlSearchUsers */
        
        break;
        
    default:

            /* erro */

        break;
    }
}

/* $RCSfile$ */