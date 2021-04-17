#include "User.h"


void User::setIdUser(int newIdUser) {
	if (newIdUser >= 0)
		idUser = newIdUser;
}

void User::setFirstName(string newFirstName) {
	firstName = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(newFirstName);
}

void User::setSurname(string newSurname) {
	surname = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(newSurname);
}

void User::setLogin(string newLogin) {
	login = newLogin;
}

void User::setPassword(string newPassword) {
	password = newPassword;
}

int User::getIdUser() {
	return idUser;
}

string User::getFirstName() {
	return firstName;
}

string User::getSurname() {
	return surname;
}

string User::getLogin() {
	return login;
}

string User::getPassword() {
	return password;
}
