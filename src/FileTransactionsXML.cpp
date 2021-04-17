#include "FileTransactionsXML.h"


void FileTransactionsXML::addTransactionToFile(Transaction transaction) {
    CMarkup xmlFile;

    // Load the XML file. If the file doesn't exist, create it and add the main headers.
    bool fileExists = xmlFile.Load(FILENAME);
    if (!fileExists) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("Transactions");
    }

    // Add Transaction data to the XML file.
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("Transaction");
    xmlFile.IntoElem();
    xmlFile.AddElem("IdUser", transaction.getIdUser());
    xmlFile.AddElem("IdTransaction", transaction.getIdTransaction());
    xmlFile.AddElem("Value", transaction.getValue());
    xmlFile.AddElem("Name", transaction.getName());
    xmlFile.AddElem("IssueDate", transaction.getIssueDate());

    xmlFile.Save(FILENAME);
}

vector <Transaction> FileTransactionsXML::readTransactionsFromFile(int idUserLoggedIn) {
    vector <Transaction> transactions;
    CMarkup xmlFile;

    // Load the XML file. If the file doesn't exist, return an empty vector.
    bool fileExists = xmlFile.Load(FILENAME);
     if (!fileExists) {
        return transactions;
    }

    // Upload each 'Transaction' element from the file and add it to the vector.
    Transaction transaction;
    xmlFile.FindElem();
    xmlFile.IntoElem();
    while (xmlFile.FindElem("Transaction")) {
        xmlFile.IntoElem();

        // Read transactions that only belong to the logged in user.
        xmlFile.FindElem( "IdUser" );
        int idUser = atoi(MCD_2PCSZ(xmlFile.GetData()));
        if (idUser == idUserLoggedIn) {
            transaction.setIdUser(idUser);

            xmlFile.FindElem("IdTransaction");
            transaction.setIdTransaction(atoi(MCD_2PCSZ(xmlFile.GetData())));

           xmlFile.FindElem("Value");
           transaction.setValue(atof(MCD_2PCSZ(xmlFile.GetData())));

            xmlFile.FindElem("Name");
            transaction.setName(xmlFile.GetData());

            xmlFile.FindElem("IssueDate");
            transaction.setIssueDate(xmlFile.GetData());
        }
        xmlFile.OutOfElem();
        transactions.push_back(transaction);
    }

    return transactions;
}
