#ifndef FILEXMLUSERS_h
#define TEXTFILEUSERS_h

#include <iostream>
#include <vector>
#include <fstream>

#include "Markup.h"
#include "FileXML.h"
#include "User.h"
#include "Utils.h"

using namespace std;

class FileXMLUsers :public FileXML {

public:
	FileXMLUsers(string FILENAME) : FileXML(FILENAME) {};
	vector <User> readUsersFromFile();
	void addUserToFile(User user);
	void modifyUserInFile(User user);
};

#endif
