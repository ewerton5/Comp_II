 # Universidade Federal do Rio de Janeiro
 # Escola Politecnica
 # Departamento de Eletronica e de Computacao
 # Prof. Marcelo Luiz Drumond Lanza
 # EEL 270 - Computacao II - Turma 2019/2
 
 # $Author: ewerton.silles $
 # $Date: 2019/12/24 13:52:26 $
 # $Log: GNUmakefile,v $
 # Revision 1.5  2019/12/24 13:52:26  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.4  2019/11/30 04:31:59  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.3  2019/11/16 03:48:22  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.2  2019/11/15 01:42:45  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.1  2019/11/08 02:11:08  ewerton.silles
 # Initial revision
 # 

OS = $(shell uname -s)

#  Tools
CC = gcc
LD = gcc

ifeq ($(cc), GCC)
CC = gcc
endif

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

AR = ar
AFLAGS = -r

LCRYPT = -lcrypt
LMLCGI = -L./../Libraries/CentOS -lmlcgi
LNCURSES = -lncurses

#  Options
CFLAGS = -Wall -std=c11
LFLAGS = -Wall -std=c11

#  object files
#===> secundary functions
DVFM_EVS_GETLANGUAGEINDEXOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlGetLanguageIndex.o
DVFM_EVS_GETABSOLUTEFILENAMEOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlGetAbsoluteFileName.o
DVFM_EVS_CHECKSTRINGFIELDOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlCheckStringField.o
DVFM_EVS_CHECKNICKNAMEOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlCheckNickname.o
DVFM_EVS_CHECKEMAILOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlCheckEmail.o
DVFM_EVS_CREATERANDOMSTRINGOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlCreateRandomString.o
DVFM_EVS_CREATENICKNAMEOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlCreateNickname.o
DVFM_EVS_GETCRYPTALGORITHMOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlGetCryptAlgorithm.o
DVFM_EVS_ENCODEPASSWORDWITHSPECIFICALGORITHMOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlEncodePasswordWithSpecificAlgorithm.o
DVFM_EVS_ENCODEPASSWORDWITHSPECIFICSALTOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlEncodePasswordWithSpecificSalt.o
DVFM_EVS_CHECKPASSWORDOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlCheckPassword.o
DVFM_EVS_GETCONFIGURATIONOPTIONSVALUESOBJS = dvfmEvsUmlFunctions.o dvfmEvsUmlErrors.o dvfmEvsUmlGetConfigurationOptionsValues.o

#===> error message functions
DVFM_EVS_GETCLIERRORMESSAGEOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlGetCliErrorMessage.o
DVFM_EVS_GETNCURSESERRORMESSAGEOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlGetNcursesErrorMessage.o
DVFM_EVS_GETWEBERRORMESSAGEOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlGetWebErrorMessage.o

#===> interface message functions
DVFM_EVS_GETCLIUSERINTERFACEMESSAGEOBJS = dvfmEvsUmlUserInterface.o dvfmEvsUmlGetCliUserInterfaceMessage.o
DVFM_EVS_GETNCURSESUSERINTERFACEMESSAGEOBJS = dvfmEvsUmlUserInterface.o dvfmEvsUmlGetNcursesUserInterfaceMessage.o
DVFM_EVS_GETWEBUSERINTERFACEMESSAGEOBJS = dvfmEvsUmlUserInterface.o dvfmEvsUmlGetWebUserInterfaceMessage.o

#===> CGIs
DVFM_EVS_CGIMAINOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlCgiMain.o dvfmEvsUmlUserInterface.o dvfmEvsUmlFunctions.o
DVFM_EVS_CGISHOWREQUESTREGISTRATIONFORMOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlCgiShowRequestRegistrationForm.o dvfmEvsUmlUserInterface.o dvfmEvsUmlFunctions.o
DVFM_EVS_CGISHOWREQUESTPASSWORDRESETFORMOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlCgiShowRequestPasswordResetForm.o dvfmEvsUmlUserInterface.o dvfmEvsUmlFunctions.o
DVFM_EVS_CGISHOWWEBHELPOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlCgiShowWebHelp.o dvfmEvsUmlUserInterface.o dvfmEvsUmlFunctions.o
DVFM_EVS_CGISHOWLICENSEOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlCgiShowLicense.o dvfmEvsUmlUserInterface.o dvfmEvsUmlFunctions.o
DVFM_EVS_CGISHOWADDUSERFORMOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlCgiShowAddUserForm.o dvfmEvsUmlUserInterface.o dvfmEvsUmlFunctions.o

#===> primary file
DVFM_EVS_DVFMEVSUMLOBJS = dvfmEvsUml.o\
						  dvfmEvsUmlFunctions.o\
						  dvfmEvsUmlErrors.o\
						  dvfmEvsUmlUserInterface.o\
						  dvfmEvsUmlShowCliHelp.o\
						  dvfmEvsUmlShowConfigurationValues.o\
						  dvfmEvsUmlRunNcursesInterface.o\
						  dvfmEvsUmlAddUser.o\
						  dvfmEvsUmlAcceptInvite.o\
						  dvfmEvsUmlRejectInvite.o\
						  dvfmEvsUmlRequestRegistration.o\
						  dvfmEvsUmlGetPendingRegistrationRequestsPerUser.o\
						  dvfmEvsUmlGetPendingRegistrationRequests.o\
						  dvfmEvsUmlApproveRegistrationRequest.o\
						  dvfmEvsUmlDisapproveRegistrationRequest.o\
						  dvfmEvsUmlGetUnlockingRequests.o\
						  dvfmEvsUmlLockUserAccount.o\
						  dvfmEvsUmlUnlockUserAccount.o\
						  dvfmEvsUmlChangeUserPassword.o

#===> Ncurses (Remover depois)
DVFM_EVS_UML_RUNNCURSESINTERFACEOBJS = dvfmEvsUmlErrors.o dvfmEvsUmlRunNcursesInterface.o dvfmEvsUmlUserInterface.o dvfmEvsUmlShowNcursesHelp.o\
									   dvfmEvsUmlFunctions.o dvfmEvsUmlRunNcursesInterfaceTestFile.o 

#===> Index html
DVFM_EVS_INDEXHTMLFILE = ../HTML/index_en-us.html ../HTML/index_pt-br.html

#===> Install
DVFM_EVS_INSTALLOBJS =  $(DVFM_EVS_CGIMAINOBJS)\
						$(DVFM_EVS_CGISHOWREQUESTREGISTRATIONFORMOBJS)\
						$(DVFM_EVS_CGISHOWREQUESTPASSWORDRESETFORMOBJS)\
						$(DVFM_EVS_CGISHOWWEBHELPOBJS)\
						$(DVFM_EVS_CGISHOWLICENSEOBJS)\
						$(DVFM_EVS_CGISHOWADDUSERFORMOBJS)

#===> Path
DVFM_EVS_CGIS_DIRECTORY = ~/public/html/EEL270/2019-2/DVFM_EVS/CGIs

DVFM_EVS_BINARIES_DIRECTORY = ~/private/EEL270/2019-2/DVFM_EVS/Binaries

DVFM_EVS_DVFM_EVS_DIRECTORY = ~/public/html/EEL270/2019-2/DVFM_EVS

DVFM_EVS_MAKE_DIRECTORY = 	$(DVFM_EVS_BINARIES_DIRECTORY)\
							~/private/EEL270/2019-2/DVFM_EVS/Data/Cookies\
							$(DVFM_EVS_CGIS_DIRECTORY)

# shortcut
#===> secundary functions
DVFM_EVS_SECUNDARYFUNCTIONS = dvfmEvsUmlGetLanguageIndex\
							  dvfmEvsUmlGetAbsoluteFileName\
							  dvfmEvsUmlCheckStringField\
							  dvfmEvsUmlCheckNickname\
							  dvfmEvsUmlCheckEmail\
							  dvfmEvsUmlCreateRandomString\
							  dvfmEvsUmlCreateNickname\
							  dvfmEvsUmlGetCryptAlgorithm\
							  dvfmEvsUmlEncodePasswordWithSpecificAlgorithm\
							  dvfmEvsUmlEncodePasswordWithSpecificSalt\
							  dvfmEvsUmlCheckPassword\
							  dvfmEvsUmlGetConfigurationOptionsValues

#===> error message functions
DVFM_EVS_ERRORSFUNCTIONS = dvfmEvsUmlGetCliErrorMessage\
							dvfmEvsUmlGetNcursesErrorMessage\
							dvfmEvsUmlGetWebErrorMessage

#===> interface message functions
DVFM_EVS_INTERFACEFUNCTIONS = dvfmEvsUmlGetCliUserInterfaceMessage\
							dvfmEvsUmlGetNcursesUserInterfaceMessage\
							dvfmEvsUmlGetWebUserInterfaceMessage

#===> CGIs
DVFM_EVS_CGIS = dvfmEvsUmlMain.cgi\
				dvfmEvsUmlShowRequestRegistrationForm.cgi\
				dvfmEvsUmlShowRequestPasswordResetForm.cgi\
				dvfmEvsUmlShowWebHelp.cgi\
				dvfmEvsUmlShowLicense.cgi\
				dvfmEvsUmlShowAddUserForm.cgi

#===> primary files
DVFM_EVS_PRIMARYFILES = dvfmEvsUml

#===> Ncurses
DVFM_EVS_NCURSES = dvfmEvsUmlRunNcursesInterface

#===>index html
DVFM_EVS_INDEXHTM = indexHtml

#===> Install
DVFM_EVS_CLEAN_ALL = clean-all

DVFM_EVS_INSTALL =  $(DVFM_EVS_CGIS)\
					$(DVFM_EVS_NCURSES)\
					$(DVFM_EVS_PRIMARYFILES)\
					$(DVFM_EVS_INDEXHTM)

#===> All
DVFM_EVS_ALL = $(DVFM_EVS_SECUNDARYFUNCTIONS)\
			   $(DVFM_EVS_ERRORSFUNCTIONS)\
			   $(DVFM_EVS_INTERFACEFUNCTIONS)\
			   $(DVFM_EVS_CGIS)\
			   $(DVFM_EVS_PRIMARYFILES)\
			   $(DVFM_EVS_NCURSES)\
			   $(DVFM_EVS_INDEXHTM)

# implicit rule
.c.o:
	$(CC) $(CFLAGS) -c $<

# commands
all: $(DVFM_EVS_ALL)

secundaryFunctions: $(DVFM_EVS_SECUNDARYFUNCTIONS)

errorsFunctions: $(DVFM_EVS_ERRORSFUNCTIONS)

interfaceFunctions: $(DVFM_EVS_INTERFACEFUNCTIONS)

interfaceFunctions: $(DVFM_EVS_CGIS)

#===> secundary functions
dvfmEvsUmlGetLanguageIndex: $(DVFM_EVS_GETLANGUAGEINDEXOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETLANGUAGEINDEXOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetAbsoluteFileName: $(DVFM_EVS_GETABSOLUTEFILENAMEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETABSOLUTEFILENAMEOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlCheckStringField: $(DVFM_EVS_CHECKSTRINGFIELDOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CHECKSTRINGFIELDOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlCheckNickname: $(DVFM_EVS_CHECKNICKNAMEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CHECKNICKNAMEOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlCheckEmail: $(DVFM_EVS_CHECKEMAILOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CHECKEMAILOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlCreateRandomString: $(DVFM_EVS_CREATERANDOMSTRINGOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CREATERANDOMSTRINGOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlCreateNickname: $(DVFM_EVS_CREATENICKNAMEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CREATENICKNAMEOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetCryptAlgorithm: $(DVFM_EVS_GETCRYPTALGORITHMOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETCRYPTALGORITHMOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlEncodePasswordWithSpecificAlgorithm: $(DVFM_EVS_ENCODEPASSWORDWITHSPECIFICALGORITHMOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_ENCODEPASSWORDWITHSPECIFICALGORITHMOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlEncodePasswordWithSpecificSalt: $(DVFM_EVS_ENCODEPASSWORDWITHSPECIFICSALTOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_ENCODEPASSWORDWITHSPECIFICSALTOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlCheckPassword: $(DVFM_EVS_CHECKPASSWORDOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CHECKPASSWORDOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetConfigurationOptionsValues: $(DVFM_EVS_GETCONFIGURATIONOPTIONSVALUESOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETCONFIGURATIONOPTIONSVALUESOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)

#===> primary functions

dvfmEvsUmlGetCliErrorMessage: $(DVFM_EVS_GETCLIERRORMESSAGEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETCLIERRORMESSAGEOBJS)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetNcursesErrorMessage: $(DVFM_EVS_GETNCURSESERRORMESSAGEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETNCURSESERRORMESSAGEOBJS)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetWebErrorMessage: $(DVFM_EVS_GETWEBERRORMESSAGEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETWEBERRORMESSAGEOBJS)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetCliUserInterfaceMessage: $(DVFM_EVS_GETCLIUSERINTERFACEMESSAGEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETCLIUSERINTERFACEMESSAGEOBJS)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetNcursesUserInterfaceMessage: $(DVFM_EVS_GETNCURSESUSERINTERFACEMESSAGEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETNCURSESUSERINTERFACEMESSAGEOBJS)
	cp $@ $@-$(OS)-$(CC)

dvfmEvsUmlGetWebUserInterfaceMessage: $(DVFM_EVS_GETWEBUSERINTERFACEMESSAGEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_GETWEBUSERINTERFACEMESSAGEOBJS)
	cp $@ $@-$(OS)-$(CC)

#===> CGIs

dvfmEvsUmlMain.cgi: $(DVFM_EVS_CGIMAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CGIMAINOBJS) $(LCRYPT) $(LMLCGI)
	cp $@ $(DVFM_EVS_CGIS_DIRECTORY)

dvfmEvsUmlShowRequestRegistrationForm.cgi: $(DVFM_EVS_CGISHOWREQUESTREGISTRATIONFORMOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CGISHOWREQUESTREGISTRATIONFORMOBJS) $(LCRYPT) $(LMLCGI)
	cp $@ $(DVFM_EVS_CGIS_DIRECTORY)

dvfmEvsUmlShowRequestPasswordResetForm.cgi: $(DVFM_EVS_CGISHOWREQUESTPASSWORDRESETFORMOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CGISHOWREQUESTPASSWORDRESETFORMOBJS) $(LCRYPT) $(LMLCGI)
	cp $@ $(DVFM_EVS_CGIS_DIRECTORY)

dvfmEvsUmlShowWebHelp.cgi: $(DVFM_EVS_CGISHOWWEBHELPOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CGISHOWWEBHELPOBJS) $(LCRYPT) $(LMLCGI)
	cp $@ $(DVFM_EVS_CGIS_DIRECTORY)

dvfmEvsUmlShowLicense.cgi: $(DVFM_EVS_CGISHOWLICENSEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CGISHOWLICENSEOBJS) $(LCRYPT) $(LMLCGI)
	cp $@ $(DVFM_EVS_CGIS_DIRECTORY)

dvfmEvsUmlShowAddUserForm.cgi: $(DVFM_EVS_CGISHOWADDUSERFORMOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_CGISHOWADDUSERFORMOBJS) $(LCRYPT) $(LMLCGI)
	cp $@ $(DVFM_EVS_CGIS_DIRECTORY)

#===> primary files

dvfmEvsUml: $(DVFM_EVS_DVFMEVSUMLOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_DVFMEVSUMLOBJS) $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)
	cp $@ $(DVFM_EVS_BINARIES_DIRECTORY)


#===> Ncurses (Remover depois)

dvfmEvsUmlRunNcursesInterface: $(DVFM_EVS_UML_RUNNCURSESINTERFACEOBJS)
	$(LD) $(LFLAGS) -o $@ $(DVFM_EVS_UML_RUNNCURSESINTERFACEOBJS) $(LNCURSES)  $(LCRYPT)
	cp $@ $@-$(OS)-$(CC)
	cp $@ $(DVFM_EVS_BINARIES_DIRECTORY)

#===> Install

install: $(DVFM_EVS_INSTALLOBJS)
	mkdir -p $(DVFM_EVS_MAKE_DIRECTORY)
	make $(DVFM_EVS_CLEAN_ALL)
	make $(DVFM_EVS_INSTALL)

indexHtml: $(DVFM_EVS_INDEXHTMLFILE)
	cd ../HTML && cp index_*.html $(DVFM_EVS_DVFM_EVS_DIRECTORY)
	cd $(DVFM_EVS_DVFM_EVS_DIRECTORY) && ln -s index-en.html index.html

clean:
	rm -f *.o $(DVFM_EVS_ALL)

clean-all:
	rm -f *.o $(DVFM_EVS_ALL) *-FreeBSD-* *-Linux-*

clean-freebsd:
	rm -f *.o $(DVFM_EVS_ALL) *-FreeBSD-*

clean-linux:
	rm -f *.o $(DVFM_EVS_ALL) *-Linux-*

# $RCSfile: GNUmakefile,v $ 
