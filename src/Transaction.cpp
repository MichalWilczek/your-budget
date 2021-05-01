#include "Transaction.h"


void Transaction::setIdUser(int newIdUser) {
	if (newIdUser >= 0)
		idUser = newIdUser;
}

void Transaction::setIdTransaction(int newIdTransaction) {
	if (newIdTransaction >= 0)
		idTransaction = newIdTransaction;
}

void Transaction::setValue(double newValue) {
    if (newValue > 0)
		// TODO: round value with two decimal digits.
		value = newValue;
}

void Transaction::setName(string newName) {
	name = newName;
}

void Transaction::setIssueDate(string newIssueDate) {
	issueDate = newIssueDate;
}

int Transaction::getIdUser() {
	return idUser;
}

int Transaction::getIdTransaction() {
	return idTransaction;
}

double Transaction::getValue() {
	return value;
}

string Transaction::getName() {
	return name;
}

string Transaction::getIssueDate() {
	return issueDate;
}

void Transaction::showTransaction() {

	string newName = name;
	for (int i=newName.length(); i < 30; i++){
		newName = newName + " ";
	}

	string newValue = Utils::convertDoubleIntoString(value);
	for (int i=newValue.length(); i < 10; i++) {
		newValue = " " + newValue;
	}

	cout << issueDate << "           " << newName << newValue << endl;
}
