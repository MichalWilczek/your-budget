#ifndef FILEXMLUSERS_h
#define TEXTFILEUSERS_h

#include <iostream>
#include <vector>
#include <fstream>

#include "FileXML.h"
#include "User.h"
#include "Utils.h"

using namespace std;

class FileXMLUsers :public FileXML {
	User getUser(string lineWithUserData);

public:
	FileXMLUsers(string FILENAME) : FileXML(FILENAME) {};
	void addUserToFile(User user);
	vector <User> readUsersFromFile();
	void saveUsersToFile(vector <User> users);
};

#endif
