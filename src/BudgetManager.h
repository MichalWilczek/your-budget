#ifndef BUDGETMANAGER_h
#define BUDGETMANAGER_h

#include <iostream>
#include <vector>

#include "TransactonsManager.h"

using namespace std;

class BudgetManager {
	TransactionsManager incomeManager;
	TransactionsManager expensesManager;

	/*
	void showContact(Contact contact);
	Contact setNewContact(int idUserLoggedIn);
	int getIdContactFromClient();
	static void showAmountOfFoundContacts(int amountContacts);
	char chooseOptionEditionMenu();
    */

public:
	BudgetManager(string filenameIncome, string filenameExpenses, int idUserLoggedIn):
	    incomeManager(filenameIncome, idUserLoggedIn),
	    expensesManager(filenameExpenses, idUserLoggedIn) {};

    void addIncome();
    void addExpense();

	/*void editContact();
	void showContactsOfLoggedInUser();
	void searchContactByFirstName();
	void searchContactBySurname();
	*/
};

#endif
