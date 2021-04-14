#include "Contact.h"


void Contact::setIdUser(int newIdUser) {
	if (newIdUser >= 0)
		idContact = newIdUser;
}

void Contact::setFirstName(string newFirstName) {
	firstName = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(newFirstName);
}

void Contact::setSurname(string newSurname) {
	surname = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(newSurname);
}

void Contact::setLogin(string newLogin) {
	login = newLogin;
}

void Contact::setPassword(string newPassword) {
	password = newPassword;
}

int Contact::getIdUser() {
	return idContact;
}

string Contact::getFirstName() {
	return firstName;
}

string Contact::getSurname() {
	return surname;
}

string Contact::getLogin() {
	return login;
}

string Contact::getPassword() {
	return password;
}
