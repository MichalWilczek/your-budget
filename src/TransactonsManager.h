#ifndef TRANSACTIONSMANAGER_h
#define TRANSACTIONSMANAGER_h

#include <iostream>
#include <vector>
#include <algorithm>

#include "Transaction.h"
#include "FileTransactionsXML.h"
#include "DateEditor.h"

using namespace std;

class TransactionsManager {
	const int ID_USER_LOGGED_IN;
	vector <Transaction> transactions;
	FileTransactionsXML fileTransactions;

public:
	TransactionsManager(string filenameTransactions, int idUserLoggedIn):
	    fileTransactions(filenameTransactions), ID_USER_LOGGED_IN(idUserLoggedIn) {
		transactions = fileTransactions.readTransactionsFromFile(ID_USER_LOGGED_IN);
	};
	bool areTransactionsAvailable();
	double getTransactionsSummedValue();
	void addTransaction();
	void showTransactions(string startingIssueDate, string endIssueDate);
};

#endif
