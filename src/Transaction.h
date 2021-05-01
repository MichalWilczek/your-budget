#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
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
		this->idUser = idUser;
		this->idTransaction = idTransaction;
		this->value = value;
		this->name = name;
		this->issueDate = issueDate;
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
};

#endif
