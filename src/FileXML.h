#ifndef FILEXML_h
#define FILEXML_h

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"

using namespace std;

class FileXML {
protected:
	const string FILENAME;
	bool isFileEmpty(fstream& textFile);

public:
	FileXML(string FILENAME) : FILENAME(FILENAME) {};
	static void deleteFile(string filenameWithExtension);
	static void changeFilename(string oldName, string newName);
};

#endif
