#ifndef TRANSACTIONSMANAGER_h
#define TRANSACTIONSMANAGER_h

#include <iostream>
#include <vector>

#include "Transaction.h"
#include "FileTransactionsXML.h"

using namespace std;

class TransactionsManager {
	const int ID_USER_LOGGED_IN;
	vector <Transaction> transactions;
	FileTransactionsXML fileTransactions;

	/*
	void showContact(Contact contact);
	Contact setNewContact(int idUserLoggedIn);
	int getIdContactFromClient();
	static void showAmountOfFoundContacts(int amountContacts);
	char chooseOptionEditionMenu();
    */

public:
	TransactionsManager(string filenameTransactions, int idUserLoggedIn):
	    fileTransactions(filenameTransactions), ID_USER_LOGGED_IN(idUserLoggedIn) {
		transactions = fileTransactions.readTransactionsFromFile(ID_USER_LOGGED_IN);
	};
	void addTransaction();

	/*void editContact();
	void showContactsOfLoggedInUser();
	void searchContactByFirstName();
	void searchContactBySurname();
	*/
};

#endif
