#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "FileUsersXML.h"
#include "Utils.h"

using namespace std;

class UsersManager {

    // Initial parameters set in the constructor.
    vector <User> users;
    int idUserLoggedIn;

    // Other private objects.
    FileUsersXML fileXML;
    User getUserNew();
    int getUserIdNew();
    bool doesLoginExist(string login);

    public:
	UsersManager(string filenameUsers) : fileXML(filenameUsers) {
		users = fileXML.readUsersFromFile();
		idUserLoggedIn = 0;
	};

    void registerUser();
    void showUsers();
    void logInUser();
    void changePasswordLoggedInUser();
	void logOutUser();
    /*

	int idUserLoggedIn;
	vector <User> users;
	FileXMLUsers fileXML;

	User getUserNew();
	int getUserIdNew();
	bool doesLoginExist(string login);

public:
	UsersManager(string filenameUsers) : fileXML(filenameUsers) {
		users = fileXML.readUsersFromFile();
		idUserLoggedIn = 0;
	};
	bool isUserLoggedIn();
	int getIdUserLoggedIn();
	void showUsers();
	void registerUser();
	void logInUser();
	void changePasswordLoggedInUser();
	void logOutUser();
	*/
};

#endif

