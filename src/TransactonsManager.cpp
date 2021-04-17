#include "TransactonsManager.h"


void TransactionsManager::addTransaction(int newIdUser) {

    // Upload the transaction data.
    system("cls");
    cout << " >>> ADDING TRANSACTION <<<" << endl << endl;
    int idTransaction = fileTransactions.getIdTransactionLastInFile();

    cout << "Give value: ";
    double value = Utils::convertStringIntoDouble(Utils::readLine());

    cout << "Give name: ";
    string name = Utils::readLine();

    cout << "Give issue date: ";
    string issueDate = Utils::readLine();

    // Instantiate the Transaction object, push it to the vector and add it to the file.
    Transaction transaction(newIdUser, idTransaction, value, name, issueDate);
    transactions.push_back(transaction);
    fileTransactions.addTransactionToFile(transaction);
}
