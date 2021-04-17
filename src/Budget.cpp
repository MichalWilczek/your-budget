#include "Budget.h"


void Budget::registerUser() {
	usersManager.registerUser();
}

void Budget::showUsers() {
	usersManager.showUsers();
}

void Budget::logInUser() {
	usersManager.logInUser();
	/*if (usersManager.isUserLoggedIn()) {
		addressesManager = new ContactsManager(TEXTFILE_CONTACTS, usersManager.getIdUserLoggedIn());
	}*/
}

void Budget::changePasswordLoggedInUser() {
	usersManager.changePasswordLoggedInUser();
}

void Budget::logOutUser() {
	usersManager.logOutUser();
	/*delete addressesManager;
	addressesManager = NULL;*/
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
            /*case '1':
                addContact();
                break;
            case '2':
                searchContactByFirstName();
                break;
            case '3':
                searchContactBySurname();
                break;
            case '4':
                showContactsOfLoggedInUser();
                break;
            case '5':
                deleteContact();
                break;
            case '6':
                editContact();
                break;*/
            case '7':
                changePasswordLoggedInUser();
                break;
            case '8':
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
   /* cout << "1. Add contact" << endl;
    cout << "2. Search contact by first name" << endl;
    cout << "3. Search contact by surname" << endl;
    cout << "4. Show contacts" << endl;
    cout << "5. Delete contact" << endl;
    cout << "6. Edit contact" << endl;
    cout << "---------------------------" << endl;*/
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = Utils::readSign();

    return choice;
}
