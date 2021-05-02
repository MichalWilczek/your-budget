#ifndef FILEUSERSXML_h
#define FILEUSERSXML_h

#include <iostream>
#include <vector>
#include <fstream>

#include "Markup.h"
#include "File.h"
#include "User.h"

using namespace std;

class FileUsersXML :public File {

public:
	FileUsersXML(string FILENAME) : File(FILENAME) {};
	vector <User> readUsersFromFile();
	void addUserToFile(User user);
	void modifyUserInFile(User user);
};

#endif
