#include "Budget.h"


void Budget::registerUser() {
	usersManager.registerUser();
}

void Budget::showUsers() {
	usersManager.showUsers();
}

void Budget::logInUser() {
	usersManager.logInUser();
    if (usersManager.isUserLoggedIn()) {
		budgetManager = new BudgetManager(FILENAME_INCOME, FILENAME_EXPENSES, usersManager.getIdUserLoggedIn());
	}
}

void Budget::addIncome() {
    if (usersManager.isUserLoggedIn()) {
		budgetManager->addIncome();
	} else {
		cout << "Log in first to add income." << endl;
		system("pause");
	}
}

void Budget::addExpense() {
    if (usersManager.isUserLoggedIn()) {
		budgetManager->addExpense();
	} else {
		cout << "Log in first to add expense." << endl;
		system("pause");
	}
}

void Budget::showBalanceFromCurrentMonth() {
    if (usersManager.isUserLoggedIn()) {
		budgetManager->showBalanceFromCurrentMonth();
	} else {
		cout << "Log in first to show balance." << endl;
		system("pause");
	}
}

void Budget::showBalanceFromPreviousMonth() {
   if (usersManager.isUserLoggedIn()) {
		budgetManager->showBalanceFromPreviousMonth();
	} else {
		cout << "Log in first to show balance." << endl;
		system("pause");
	}
}

void Budget::showBalanceFromChosenPeriod() {
   if (usersManager.isUserLoggedIn()) {
		budgetManager->showBalanceFromChosenPeriod();
	} else {
		cout << "Log in first to show balance." << endl;
		system("pause");
	}
}

void Budget::changePasswordLoggedInUser() {
	usersManager.changePasswordLoggedInUser();
}

void Budget::logOutUser() {
	usersManager.logOutUser();
	delete budgetManager;
	budgetManager = NULL;
}

void Budget::runConsole() {
    char choice = { 0 };

    while (true) {
        if (!usersManager.isUserLoggedIn()) {
            choice = chooseOptionMainMenu();

            switch (choice) {
            case '1':
                registerUser();
                break;
            case '2':
                logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No such option available." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = chooseOptionUserMenu();

            switch (choice) {
            case '1':
                addIncome();
                break;
            case '2':
                addExpense();
                break;
            case '3':
                showBalanceFromCurrentMonth();
                break;
           case '4':
                showBalanceFromPreviousMonth();
                break;
            case '5':
                showBalanceFromChosenPeriod();
                break;
            case '8':
                changePasswordLoggedInUser();
                break;
            case '9':
                logOutUser();
                break;
            }
        }
    }
}

char Budget::chooseOptionMainMenu() {
    char choice = { 0 };

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register user" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = Utils::readSign();

    return choice;
}

char Budget::chooseOptionUserMenu() {
    char choice = { 0 };

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
   cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance from current month" << endl;
    cout << "4. Show balance from previous month" << endl;
    cout << "5. Show balance from chosen period" << endl;
    cout << "---------------------------" << endl;
    cout << "8. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = Utils::readSign();

    return choice;
}
