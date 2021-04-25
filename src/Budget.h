#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include "UsersManager.h"
#include "BudgetManager.h"
#include "Utils.h"
using namespace std;

class Budget {
	UsersManager usersManager;
	BudgetManager *budgetManager;

	const string FILENAME_INCOME;
	const string FILENAME_EXPENSES;

	// Local console methods.
	char chooseOptionMainMenu();
	char chooseOptionUserMenu();

// Public interface.
public:
	Budget(string filenameUsers, string filenameIncome, string filenameExpenses) :
		usersManager(filenameUsers), FILENAME_INCOME(filenameIncome), FILENAME_EXPENSES(filenameExpenses) {
		budgetManager = NULL;
	};
	~Budget() {
		delete budgetManager;
		budgetManager = NULL;
	}
	void registerUser();
	void showUsers();
	void logInUser();
	void addIncome();
	void addExpense();
	void showBalanceFromCurrentMonth();
	void changePasswordLoggedInUser();
	void logOutUser();
	void runConsole();
};

#endif
