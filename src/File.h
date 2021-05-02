#ifndef FILE_h
#define FILE_h

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class File {
protected:
	const string FILENAME;
	bool isFileEmpty(fstream& textFile);

public:
	File(string FILENAME) : FILENAME(FILENAME) {};
	static void deleteFile(string filenameWithExtension);
	static void changeFilename(string oldName, string newName);
};

#endif
