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

	int idTransactionLastInFile;

public:
	FileTransactionsXML(string FILENAME) : File(FILENAME) {
		idUserLastInFile = 0;
	};
	vector <Transaction> readTransactionsFromFile(int idUserLoggedIn);
	void addTransactionToFile(Transaction transaction);
	int getIdTransactionLastInFile();
	//void modifyUserInFile(User user);
};

#endif
