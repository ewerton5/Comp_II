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
#include                           "dvfmEvsUmlTypes.h"
#include                           "dvfmEvsUmlFunctions.h"

#define DVFM_EVS_UML_MINIMUM_NUMBER_ARGUMENTS   2
#define DVFM_EVS_UML_MAXIMUM_NUMBER_ARGUMENTS   10
#define DVFM_EVS_UML_QUANTITY_OPTIONS       24

#define DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CLI_HELP_H                                 0
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CONFIGURATION_VALUES_O                     0
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_RUN_NCURSES_INTERFACE_N                         0
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_C                                      4
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_A                                      6
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_I                                      6
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_ACCEPT_INVITE_T                                 1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_REJECT_INVITE_J                                 1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_REQUEST_REGISTRATION_N                          5
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_PER_USER_Q    1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_Q             1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_APPROVED_REGISTRATION_REQUEST_V                 2
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_DISAPPROVE_REGISTRATION_REQUEST_D               2
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_UNLOCKING_REQUESTS_U                        1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_LOCK_USER_ACCOUNT_L                             1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_UNLOCK_USER_ACCOUNT_U                           1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PASSWORD_P                          1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_RESET_USER_PASSWORD_R                           1
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_NAME_M                              3
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_EMAIL_E                             3
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_CONFIRM_EMAIL_CHANGE_C                          2
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PROFILE_G                           3
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_USERS_S                                     0
#define DVFM_EVS_UML_REQUIRED_SUBOPTION_SEARCH_USERS_S                                  0

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
        dvfmEvsUmlIndexConfiguration,
        dvfmEvsUmlIndexLanguage,
        dvfmEvsUmlIndexUser,
        dvfmEvsUmlIndexUsername,
        dvfmEvsUmlIndexConfirmUsername,
        dvfmEvsUmlIndexEmail,
        dvfmEvsUmlIndexConfirmEmail,
        dvfmEvsUmlIndexProfile,
        dvfmEvsUmlIndexFriendEmail,
        dvfmEvsUmlIndexNickname,
        dvfmEvsUmlIndexKey,
        dvfmEvsUmlSizeSubOption
    };

    char *dvfmEvsUmlConfiguration = "";
    dvfmEvsUmlLanguageType dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;
    char *dvfmEvsUmlUser = "";
    char *dvfmEvsUmlUsername = "";
    char *dvfmEvsUmlConfirmUsername = "";
    char *dvfmEvsUmlEmail = "";
    char *dvfmEvsUmlConfirmEmail = "";
    char *dvfmEvsUmlProfile = "";
    char *dvfmEvsUmlFriendEmail = "";
    char *dvfmEvsUmlNickname = "";
    char *dvfmEvsUmlKey = "";
   

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

    int dvfmEvsUmlMandatorySubOptionOccurs = 0;

    if(argc < DVFM_EVS_UML_MINIMUM_NUMBER_ARGUMENTS)
    {
        /* erro */
    }

    if(argc > DVFM_EVS_UML_MAXIMUM_NUMBER_ARGUMENTS)
    {
        /* erro */
    }

    if(argv[1][0] != '-')
    {
        /* erro */
    }


    dvfmEvsUmlCurrentOption = getopt_long(argc, argv, dvfmEvsUmlShortOption, dvfmEvsUmlLongOption, NULL);

    switch (dvfmEvsUmlCurrentOption)
    {
    case 'h':
        
            /* DvfmEvsUmlShowCliHelp */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CLI_HELP_H)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:

                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }
            }

            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CLI_HELP_H)
            {
                /* erro */
            }
        
        break;

    case 'o':
        
            /* DvfmEvsUmlShowConfigurationValues */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CONFIGURATION_VALUES_O)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:

                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }

                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CONFIGURATION_VALUES_O)
            {
                /* erro */
            }
        
        break;

    case 'N':

            /* DvfmEvsUmlRunNcursesInterface */  

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_RUN_NCURSES_INTERFACE_N)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }  
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_RUN_NCURSES_INTERFACE_N)
            {
                /* erro */
            }
        
        break;
        
    case 'C':

            /* DvfmEvsUmlAddUser */ 

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_C)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUsername:

                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexProfile:

                    if(dvfmEvsUmlValueSubOption != "administrator" && dvfmEvsUmlValueSubOption != "professor" && dvfmEvsUmlValueSubOption != "student" && dvfmEvsUmlValueSubOption != "administrador-professor" && dvfmEvsUmlValueSubOption != "administrador-student" && dvfmEvsUmlValueSubOption != "professor-student" && dvfmEvsUmlValueSubOption != "administrador-professor-student")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }

            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_C)
            {
                /* erro */
            }
        
        break;
        
    case 'a':
        
            /* DvfmEvsUmlAddUser */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_A)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexProfile:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    if(dvfmEvsUmlValueSubOption != "administrator" && dvfmEvsUmlValueSubOption != "professor" && dvfmEvsUmlValueSubOption != "student")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_A)
            {
                /* erro */
            }
        
        break;
        
    case 'i':
        
            /* DvfmEvsUmlAddUser */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_I)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexProfile:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    if(dvfmEvsUmlValueSubOption != "administrator" && dvfmEvsUmlValueSubOption != "professor" && dvfmEvsUmlValueSubOption != "student")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_I)
            {
                /* erro */
            }
        
        break;
        
    case 't':
        
            /* DvfmEvsUmlAcceptInvite */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ACCEPT_INVITE_T)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;
                
                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ACCEPT_INVITE_T)
            {
                /* erro */
            }
        
        break;
        
    case 'j':
        
            /* DvfmEvsUmlRejectInvite */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_REJECT_INVITE_J)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_REJECT_INVITE_J)
            {
                /* erro */
            }
        
        break;
        
    case 'n':
        
            /* DvfmEvsUmlRequestRegistration */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_REQUEST_REGISTRATION_N)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmEmail = dvfmEvsUmlValueSubOption;

                    break;
                
                case dvfmEvsUmlIndexFriendEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlFriendEmail = dvfmEvsUmlValueSubOption;

                    break;

                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
            
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_REQUEST_REGISTRATION_N)
            {
                /* erro */
            }
        
        break;
        
    case 'q':
        
            /* DvfmEvsUmlGetPendingRegistrationRequestsPerUser */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_PER_USER_Q)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_PER_USER_Q)
            {
                /* erro */
            }
        
        break;
        
    case 'Q':
        
            /* DvfmEvsUmlGetPendingRegistrationRequests */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_Q)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_Q)
            {
                /* erro */
            }
        
        break;
        
    case 'v':
        
            /* DvfmEvsUmlApproveRegistrationRequest */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_APPROVED_REGISTRATION_REQUEST_V)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_APPROVED_REGISTRATION_REQUEST_V)
            {
                /* erro */
            }
        
        break;
        
    case 'd':
        
            /* DvfmEvsUmlDisapproveRegistrationRequest */


            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_DISAPPROVE_REGISTRATION_REQUEST_D)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_DISAPPROVE_REGISTRATION_REQUEST_D)
            {
                /* erro */
            }
        
        break;
        
    case 'U':
        
            /* DvfmEvsUmlGetUnlockingRequests */


            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_UNLOCKING_REQUESTS_U)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_UNLOCKING_REQUESTS_U)
            {
                /* erro */
            }
        
        break;
        
    case 'l':
        
            /* DvfmEvsUmlLockUserAccount */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_LOCK_USER_ACCOUNT_L)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_LOCK_USER_ACCOUNT_L)
            {
                /* erro */
            }
        
        break;
        
    case 'u':
        
            /* DvfmEvsUmlUnlockUserAccount */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_UNLOCK_USER_ACCOUNT_U)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_UNLOCK_USER_ACCOUNT_U)
            {
                /* erro */
            }
        
        break;
        
    case 'p':
        
            /* DvfmEvsUmlChangeUserPassword */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PASSWORD_P)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PASSWORD_P)
            {
                /* erro */
            }
        
        break;
        
    case 'r':
        
            /* DvfmEvsUmlResetUserPassword */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_RESET_USER_PASSWORD_R)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_RESET_USER_PASSWORD_R)
            {
                /* erro */
            }
        
        break;
        
    case 'm':
        
            /* DvfmEvsUmlChangeUserName */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_NAME_M)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmUsername:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_NAME_M)
            {
                /* erro */
            }
        
        break;
        
    case 'e':
        
            /* DvfmEvsUmlChangeUserEmail */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_EMAIL_E)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexConfirmEmail:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlConfirmEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;

                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_EMAIL_E)
            {
                /* erro */
            }
        
        break;
        
    case 'c':
        
            /* DvfmEvsUmlConfirmEmailChange */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CONFIRM_EMAIL_CHANGE_C)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);
                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexKey:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlKey = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CONFIRM_EMAIL_CHANGE_C)
            {
                /* erro */
            }
        
        break;
        
    case 'g':
        
            /* DvfmEvsUmlChangeUserProfile */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PROFILE_G)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexProfile:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    if(dvfmEvsUmlValueSubOption != "administrator" && dvfmEvsUmlValueSubOption != "professor" && dvfmEvsUmlValueSubOption != "student")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PROFILE_G)
            {
                /* erro */
            }
        
        break;
        
    case 's':
        
            /* DvfmEvsUmlGetUsers */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_USERS_S)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_USERS_S)
            {
                /* erro */
            }
        
        break;
        
    case 'S':
        
            /* DvfmEvsUmlSearchUsers */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_SEARCH_USERS_S)
            {
                /* erro */
            }

            for(dvfmEvsUmlIndexArgument = (argv[1][1] == '-') ? optind - 1 : optind; dvfmEvsUmlIndexArgument < argc; dvfmEvsUmlIndexArgument++)
            {
                dvfmEvsUmlCurrentArgument = argv[dvfmEvsUmlIndexArgument];

                dvfmEvsUmlIndexNameSubOption= getsubopt(&(dvfmEvsUmlCurrentArgument), dvfmEvsUmlSubOption, &dvfmEvsUmlValueSubOption);

                switch (dvfmEvsUmlIndexNameSubOption)
                {
                case dvfmEvsUmlIndexConfiguration:

                    dvfmEvsUmlConfiguration = dvfmEvsUmlValueSubOption;
                    
                    break;

                case dvfmEvsUmlIndexLanguage:
                    
                    if(dvfmEvsUmlValueSubOption != "portuguese" && dvfmEvsUmlValueSubOption != "english")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlLanguage = DvfmEvsUmlGetLanguageIndex(dvfmEvsUmlValueSubOption);

                    break;

                case dvfmEvsUmlIndexUsername:
                    
                    dvfmEvsUmlUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexEmail:
                    
                    dvfmEvsUmlEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexProfile:
                    
                    if(dvfmEvsUmlValueSubOption != "administrator" && dvfmEvsUmlValueSubOption != "professor" && dvfmEvsUmlValueSubOption != "student" && dvfmEvsUmlValueSubOption != "administrador-professor" && dvfmEvsUmlValueSubOption != "administrador-student" && dvfmEvsUmlValueSubOption != "professor-student" && dvfmEvsUmlValueSubOption != "administrador-professor-student")
                    {
                        /* erro */
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* menssagem de erro para opcao curta inexistente? */

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_SEARCH_USERS_S)
            {
                /* erro */
            }
        
        break;
        
    default:

            /* erro */

        break;
    }
}

/* $RCSfile$ */