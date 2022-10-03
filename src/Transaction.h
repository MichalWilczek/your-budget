#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <cmath>
#include "Utils.h"

using namespace std;


class Transaction {
	int idUser;
	int idTransaction;
	double value;
	string name;
	string issueDate;

public:
	Transaction(int idUser=0, int idTransaction=0, double value=0, string name="", string issueDate="2000-01-01") {
		setIdUser(idUser);
		setIdTransaction(idTransaction);
		setValue(value);
		setName(name);
		setIssueDate(issueDate);
	}

	// Container setters.
	void setIdUser(int newIdUser);
	void setIdTransaction(int newIdTransaction);
	void setValue(double newValue);
	void setName(string newName);
	void setIssueDate(string newIssueDate);

	// Container getters.
	int getIdUser();
	int getIdTransaction();
	double getValue();
	string getName();
	string getIssueDate();

	// Other container methods.
	void showTransaction();

	// Sorting operators.
	bool operator< (const Transaction &other) const {
        return issueDate < other.issueDate;
	}
};

#endif
