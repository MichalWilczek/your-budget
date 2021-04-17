#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction {
	int idUser;
	int idTransaction;
	float value;
	string name;
	string issueDate;

public:
	Transaction(int idUser=0, int idTransaction=0, float value=0, string name="", string issueDate="2000-01-01") {
		this->idUser = idUser;
		this->idTransaction = idTransaction;
		this->value = value;
		this->name = name;
		this->issueDate = issueDate;
	}

	//Container setters.
	void setIdUser(int newIdUser);
	void setIdTransaction(int newIdTransaction);
	void setValue(float newValue);
	void setName(string newName);
	void setIssueDate(string newIssueDate);

	// Container getters.
	int getIdUser();
	int getIdTransaction();
	float getValue();
	string getName();
	string getIssueDate();
};

#endif
