#include "TransactonsManager.h"


void TransactionsManager::addTransaction() {

    // Upload the transaction data.
    int idTransaction = fileTransactions.getIdTransactionLastInFile();
    int newIdTransaction = idTransaction + 1;

    cout << "Give value: ";
    double value = Utils::convertStringIntoDouble(Utils::readLine());

    cout << "Give name: ";
    string name = Utils::readLine();

    cout << "Give issue date: ";
    string issueDate = Utils::readLine();

    // Instantiate the Transaction object, push it to the vector and add it to the file.
    Transaction transaction(ID_USER_LOGGED_IN, newIdTransaction, value, name, issueDate);
    transactions.push_back(transaction);
    fileTransactions.addTransactionToFile(transaction);
}
