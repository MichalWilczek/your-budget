#include "TransactonsManager.h"

struct compareTransactionBasedOnIssueDate
{
    inline bool operator() (Transaction &transaction1, Transaction &transaction2)
    {
        string issueDate1 = transaction1.getIssueDate();
        string issueDate2 = transaction2.getIssueDate();

        DateEditor date1(issueDate1);
        DateEditor date2(issueDate2);

        return date1.getDateInteger() < date2.getDateInteger();
    }
};

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

    // Upload the transaction data.
    int idTransaction = fileTransactions.getIdTransactionLastInFile();
    int newIdTransaction = idTransaction + 1;

    cout << "Give value: ";
    string valueString = Utils::readLine();
    valueString = Utils::convertCommasToDots(valueString);
    double value = Utils::convertStringIntoDouble(valueString);

    cout << "Give name: ";
    string name = Utils::readLine();

    cout << "Issue date. Do you want to assign the current date to the transaction? Press 'y' to confirm and 'n' to decline: ";
    bool currentDate;
    bool continueLoop = true;
    char sign = Utils::readSign();
    while (continueLoop) {
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
                cout << "The sign does not correspond to any of the available options.";
                system("pause");
                break;
        }
    }
    DateEditor dateEditor(currentDate);
    string issueDate = dateEditor.getDateString();

    // Instantiate the Transaction object, push it to the vector and add it to the file.
    Transaction transaction(ID_USER_LOGGED_IN, newIdTransaction, value, name, issueDate);
    transactions.push_back(transaction);
    fileTransactions.addTransactionToFile(transaction);
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
    sort(filteredTransactions.begin(), filteredTransactions.end(), compareTransactionBasedOnIssueDate());
    for (int i=0; i<filteredTransactions.size(); i++) {
        filteredTransactions[i].showTransaction();
    }
}
