#ifndef USER_H
#define USER_H

#include <iostream>
#include "Utils.h"

using namespace std;

class User {
	int idUser;
	string firstName;
	string surname;
	string login;
	string password;

public:
	Contact(int idUser=0, string firstName="", string surname="", string login="", string password="") {
		this->idUser = idUser;
		this->firstName = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(firstName);
		this->surname = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(surname);
		this->login = login;
		this->password = password;
	}

	void setIdUser(int newIdUser);
	void setFirstName(string newFirstName);
	void setSurname(string newSurname);
	void setLogin(string newLogin);
	void setPassword(string newPassword);

	int getIdUser();
	string getFirstName();
	string getSurname();
	string getLogin();
	string getPassword();
};

#endif
