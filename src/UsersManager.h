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
    int idUserLoggedIn;
    vector <User> users;

    // Other private objects.
    FileUsersXML fileUsersXML;
    User getUserNew();
    int getUserIdNew();
    bool doesLoginExist(string login);

    // Public interface.
    public:
	UsersManager(string filenameUsers) : fileUsersXML(filenameUsers) {
		users = fileUsersXML.readUsersFromFile();
		idUserLoggedIn = 0;
	};

	bool isUserLoggedIn();
    void registerUser();
    void showUsers();
    void logInUser();
    void changePasswordLoggedInUser();
	void logOutUser();

};

#endif

