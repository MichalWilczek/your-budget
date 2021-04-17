#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include "UsersManager.h""
#include "Utils.h"
using namespace std;

class Budget {
	UsersManager usersManager;

	// Local console methods.
	char chooseOptionMainMenu();
	char chooseOptionUserMenu();

// Public interface.
public:
	Budget(string filenameUsers) : usersManager(filenameUsers) {};
	void registerUser();
	void showUsers();
	void logInUser();
	void changePasswordLoggedInUser();
	void logOutUser();
	void runConsole();
};

#endif
