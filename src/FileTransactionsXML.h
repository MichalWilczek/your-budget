#ifndef FILETRANSACTIONSXML_h
#define FILETRANSACTIONSXML_h

#include <iostream>
#include <vector>
#include <fstream>

#include "Markup.h"
#include "File.h"
#include "Transaction.h"
#include "Utils.h"

using namespace std;

class FileTransactionsXML :public File {

public:
	FileTransactionsXML(string FILENAME) : File(FILENAME) {};
	vector <Transaction> readTransactionsFromFile(int idUserLoggedIn);
	void addTransactionToFile(Transaction transaction);
	//void modifyUserInFile(User user);
};

#endif
