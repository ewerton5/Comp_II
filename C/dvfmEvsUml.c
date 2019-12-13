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
#include                            <stdio.h>
#include                           "dvfmEvsUmlTypes.h"
#include                           "dvfmEvsUmlErrors.h"

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

#define DVFM_EVS_UML_OK                                                 0
#define DVFM_EVS_UML_INVALID_NUMBER_ARGUMENTS_SHORT                     1
#define DVFM_EVS_UML_INVALID_NUMBER_ARGUMENTS_LONG                      2
#define DVFM_EVS_UML_INVALID_POSITION_OPTION                            3
#define DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT                   4
#define DVFM_EVS_UML_INVALID_SUB_OPTIONS                                5
#define DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION                          6
#define DVFM_EVS_UML_INVALID_OPTIONS                                    7
#define DVFM_EVS_UML_INVALID_SUB_OPTIONS                                8
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
   

    char *dvfmEvsUmlSubOption [dvfmEvsUmlSizeSubOption + 1] = 
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
    char *dvfmEvsUmlValueSubOption;

    int dvfmEvsUmlMandatorySubOptionOccurs = 0;

    if(argc < DVFM_EVS_UML_MINIMUM_NUMBER_ARGUMENTS)
    {
        /* erro */
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlShortArgument, dvfmEvsUmlLanguage));
        exit(DVFM_EVS_UML_INVALID_NUMBER_ARGUMENTS_SHORT);
    }

    if(argc > DVFM_EVS_UML_MAXIMUM_NUMBER_ARGUMENTS)
    {
        /* erro */
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLongtArgument, dvfmEvsUmlLanguage));
        exit(DVFM_EVS_UML_INVALID_NUMBER_ARGUMENTS_LONG);
    }

    if(argv[1][0] != '-')
    {
        /* erro */
        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidPositionOptions, dvfmEvsUmlLanguage));
        exit(DVFM_EVS_UML_INVALID_POSITION_OPTION);
    }


    dvfmEvsUmlCurrentOption = getopt_long(argc, argv, dvfmEvsUmlShortOption, dvfmEvsUmlLongOption, NULL);

    switch (dvfmEvsUmlCurrentOption)
    {
        case 'h':
        
            /* DvfmEvsUmlShowCliHelp */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CLI_HELP_H)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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

                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }

                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }
            }

            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CLI_HELP_H)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;

        case 'o':
        
            /* DvfmEvsUmlShowConfigurationValues */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CONFIGURATION_VALUES_O)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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

                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }

                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_SHOW_CONFIGURATION_VALUES_O)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;

        case 'N':

            /* DvfmEvsUmlRunNcursesInterface */  

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_RUN_NCURSES_INTERFACE_N)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }  
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_RUN_NCURSES_INTERFACE_N)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'C':

            /* DvfmEvsUmlAddUser */ 

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_C)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }

            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_C)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'a':
        
            /* DvfmEvsUmlAddUser */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_A)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "administrator") != 0 && strcmp( dvfmEvsUmlValueSubOption, "professor") != 0 && strcmp( dvfmEvsUmlValueSubOption, "student") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_A)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'i':
        
            /* DvfmEvsUmlAddUser */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_I)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "administrator") != 0 && strcmp( dvfmEvsUmlValueSubOption, "professor") != 0 && strcmp( dvfmEvsUmlValueSubOption, "student") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ADD_USER_I)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 't':
        
            /* DvfmEvsUmlAcceptInvite */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_ACCEPT_INVITE_T)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;
                
                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_ACCEPT_INVITE_T)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'j':
        
            /* DvfmEvsUmlRejectInvite */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_REJECT_INVITE_J)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_REJECT_INVITE_J)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'n':
        
            /* DvfmEvsUmlRequestRegistration */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_REQUEST_REGISTRATION_N)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
            
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_REQUEST_REGISTRATION_N)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'q':
        
            /* DvfmEvsUmlGetPendingRegistrationRequestsPerUser */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_PER_USER_Q)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_PER_USER_Q)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'Q':
        
            /* DvfmEvsUmlGetPendingRegistrationRequests */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_Q)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_PENDING_REGISTRATION_REQUESTS_Q)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'v':
        
            /* DvfmEvsUmlApproveRegistrationRequest */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_APPROVED_REGISTRATION_REQUEST_V)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_APPROVED_REGISTRATION_REQUEST_V)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'd':
        
            /* DvfmEvsUmlDisapproveRegistrationRequest */


            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_DISAPPROVE_REGISTRATION_REQUEST_D)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_DISAPPROVE_REGISTRATION_REQUEST_D)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'U':
        
            /* DvfmEvsUmlGetUnlockingRequests */


            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_UNLOCKING_REQUESTS_U)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_UNLOCKING_REQUESTS_U)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'l':
        
            /* DvfmEvsUmlLockUserAccount */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_LOCK_USER_ACCOUNT_L)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_LOCK_USER_ACCOUNT_L)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'u':
        
            /* DvfmEvsUmlUnlockUserAccount */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_UNLOCK_USER_ACCOUNT_U)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_UNLOCK_USER_ACCOUNT_U)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'p':
        
            /* DvfmEvsUmlChangeUserPassword */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PASSWORD_P)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexNickname:
                    
                    dvfmEvsUmlNickname = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PASSWORD_P)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'r':
        
            /* DvfmEvsUmlResetUserPassword */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_RESET_USER_PASSWORD_R)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUser:
                    
                    dvfmEvsUmlMandatorySubOptionOccurs++;
                    
                    dvfmEvsUmlUser = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_RESET_USER_PASSWORD_R)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'm':
        
            /* DvfmEvsUmlChangeUserName */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_NAME_M)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_NAME_M)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'e':
        
            /* DvfmEvsUmlChangeUserEmail */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_EMAIL_E)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_EMAIL_E)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'c':
        
            /* DvfmEvsUmlConfirmEmailChange */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CONFIRM_EMAIL_CHANGE_C)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;
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

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CONFIRM_EMAIL_CHANGE_C)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'g':
        
            /* DvfmEvsUmlChangeUserProfile */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PROFILE_G)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "administrator") != 0 && strcmp( dvfmEvsUmlValueSubOption, "professor") != 0 && strcmp( dvfmEvsUmlValueSubOption, "student") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_CHANGE_USER_PROFILE_G)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 's':
        
            /* DvfmEvsUmlGetUsers */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_USERS_S)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_GET_USERS_S)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        case 'S':
        
            /* DvfmEvsUmlSearchUsers */

            if(argc - 2 < DVFM_EVS_UML_REQUIRED_SUBOPTION_SEARCH_USERS_S)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlFewSubOptions, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_INVALID_NUMBER_SUB_OPTIONS_SHORT);
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
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") != 0 && strcmp( dvfmEvsUmlValueSubOption, "english") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "portuguese") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlPortuguese;

                    if(strcmp( dvfmEvsUmlValueSubOption, "english") == 0)
                        dvfmEvsUmlLanguage = dvfmEvsUmlEnglish;

                    break;

                case dvfmEvsUmlIndexUsername:
                    
                    dvfmEvsUmlUsername = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexEmail:
                    
                    dvfmEvsUmlEmail = dvfmEvsUmlValueSubOption;

                    break;

                case dvfmEvsUmlIndexProfile:
                    
                    if(strcmp( dvfmEvsUmlValueSubOption, "administrator") != 0 && strcmp( dvfmEvsUmlValueSubOption, "professor") != 0 && strcmp( dvfmEvsUmlValueSubOption, "student") != 0 && strcmp( dvfmEvsUmlValueSubOption, "administrador-professor") != 0 && strcmp( dvfmEvsUmlValueSubOption, "administrador-student") != 0 && strcmp( dvfmEvsUmlValueSubOption, "professor-student") != 0 && strcmp( dvfmEvsUmlValueSubOption, "administrador-professor-student") != 0)
                    {
                        /* erro */
                        printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidSubOption, dvfmEvsUmlLanguage));
                        exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);
                    }
                    
                    dvfmEvsUmlProfile = dvfmEvsUmlValueSubOption;

                    break;
                
                default:

                    /* erro */
                    printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlMissingSubOptions, dvfmEvsUmlLanguage));
                    exit(DVFM_EVS_UML_INVALID_SUB_OPTIONS);

                    break;
                }

            }
        
            if(dvfmEvsUmlMandatorySubOptionOccurs < DVFM_EVS_UML_REQUIRED_SUBOPTION_SEARCH_USERS_S)
            {
                /* erro */
                printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlLackCompulsorySubOption, dvfmEvsUmlLanguage));
                exit(DVFM_EVS_UML_LACK_COMPULSORY_SUBOPTION);
            }
        
        break;
        
        default:

            /* erro */
            printf("%s\n", DvfmEvsUmlGetCliErrorMessage ( dvfmEvsUmlInvalidOptions, dvfmEvsUmlLanguage));
            exit(DVFM_EVS_UML_INVALID_OPTIONS);

        break;

    }
    printf("configuration = %s\n", dvfmEvsUmlConfiguration);
    printf("language = %u\n", dvfmEvsUmlLanguage);
    printf("user = %s\n", dvfmEvsUmlUser);
    printf("username = %s\n", dvfmEvsUmlUsername);
    printf("confirm-username = %s\n", dvfmEvsUmlConfirmUsername);
    printf("email = %s\n", dvfmEvsUmlEmail);
    printf("confirm-email = %s\n", dvfmEvsUmlConfirmEmail);
    printf("profile = %s\n", dvfmEvsUmlProfile);
    printf("friend-email = %s\n", dvfmEvsUmlFriendEmail);
    printf("nickname = %s\n", dvfmEvsUmlNickname);
    printf("key = %s\n", dvfmEvsUmlKey);

}

/* $RCSfile$ */