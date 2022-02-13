#include "TransactonsManager.h"

bool TransactionsManager::areTransactionsAvailable() {
    if (transactions.size() > 0)
        return true;
    return false;
}

double TransactionsManager::getTransactionsSummedValue(string startIssueDate, string endIssueDate) {

    // Set dates in the proper integer format.
    DateEditor dateEditorStartIssueDate(startIssueDate);
    DateEditor dateEditorEndIssueDate(endIssueDate);
    int startIssueDateInteger = dateEditorStartIssueDate.getDateInteger();
    int endIssueDateInteger = dateEditorEndIssueDate.getDateInteger();

    // Sum the specified transactions,
    double sum=0;
    for (int i=0; i<transactions.size(); i++) {
        string issueDate = transactions[i].getIssueDate();

        DateEditor dateEditorIssueDate(issueDate);
        int issueDateInteger = dateEditorIssueDate.getDateInteger();

        if (startIssueDateInteger <= issueDateInteger && endIssueDateInteger >= issueDateInteger)
            sum += transactions[i].getValue();
    }
    return sum;
}

void TransactionsManager::addTransaction() {

    double value = 0;

    // Upload the transaction data.
    int idTransaction = fileTransactions.getIdTransactionLastInFile();
    int newIdTransaction = idTransaction + 1;

    try {
        cout << "Give value: ";
        string valueString = Utils::readLine();
        valueString = Utils::convertCommasToDots(valueString);
        value = Utils::convertStringIntoDouble(valueString);
    } catch (invalid_argument) {
        cout << "Input cannot be converted into a number." << endl << endl;
        return;
    }

    cout << "Give name: ";
    string name = Utils::readLine();

    bool currentDate;
    bool continueLoop = true;
    char sign;
    while (continueLoop) {
        cout << "Issue date. Do you want to assign the current date to the transaction? Press 'y' to confirm and 'n' to decline: ";
        sign = Utils::readSign();
        switch (sign) {
            case 'y':
                currentDate = true;
                continueLoop = false;
                break;
            case 'n':
                currentDate = false;
                continueLoop = false;
                break;
            default:
                cout << "The sign does not correspond to any of the available options." << endl << endl;
                break;
        }
    }
    DateEditor dateEditor(currentDate);
    string issueDate = dateEditor.getDateString();

    // Instantiate the Transaction object, push it to the vector and add it to the file.
    Transaction transaction(ID_USER_LOGGED_IN, newIdTransaction, value, name, issueDate);
    transactions.push_back(transaction);
    fileTransactions.addTransactionToFile(transaction);
    cout << endl << "Transaction saved." << endl << endl;
}

void TransactionsManager::showTransactions(string startIssueDate, string endIssueDate) {

    // Set dates in the proper integer format.
    DateEditor dateEditorStartIssueDate(startIssueDate);
    DateEditor dateEditorEndIssueDate(endIssueDate);
    int startIssueDateInteger = dateEditorStartIssueDate.getDateInteger();
    int endIssueDateInteger = dateEditorEndIssueDate.getDateInteger();

    // Filter out transactions that do not correspond to the issue date criteria.
    vector <Transaction> filteredTransactions;
    for (int i=0; i<transactions.size(); i++) {
        string issueDate = transactions[i].getIssueDate();

        DateEditor dateEditorIssueDate(issueDate);
        int issueDateInteger = dateEditorIssueDate.getDateInteger();

        if (startIssueDateInteger <= issueDateInteger && endIssueDateInteger >= issueDateInteger)
            filteredTransactions.push_back(transactions[i]);
    }

    // Sort the filtered transactions with respect to their issue dates.
    sort(filteredTransactions.begin(), filteredTransactions.end());
    for (int i=0; i<filteredTransactions.size(); i++) {
        filteredTransactions[i].showTransaction();
    }
}
