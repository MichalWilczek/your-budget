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
		setIdUser(idUser);
		setFirstName(firstName);
		setSurname(surname);
		setLogin(login);
		setPassword(password);
	}

	//Container setters.
	void setIdUser(int newIdUser);
	void setFirstName(string newFirstName);
	void setSurname(string newSurname);
	void setLogin(string newLogin);
	void setPassword(string newPassword);

	// Container getters.
	int getIdUser();
	string getFirstName();
	string getSurname();
	string getLogin();
	string getPassword();
};

#endif
