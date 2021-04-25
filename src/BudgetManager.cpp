#include "BudgetManager.h"


void BudgetManager::addIncome() {
    system("cls");
    cout << " >>> ADDING INCOME <<<" << endl << endl;
    incomeManager.addTransaction();
    cout << endl << "Income added." << endl << endl;
    system("pause");
}

void BudgetManager::addExpense() {
    system("cls");
    cout << " >>> ADDING EXPENSE <<<" << endl << endl;
    expensesManager.addTransaction();
    cout <<  endl << "Expense added." << endl << endl;
    system("pause");
}

void BudgetManager::showBalanceFromCurrentMonth() {
    double totalIncome = 0;
    double totalExpenses = 0;

    system("cls");
    DateEditor dateEditor;
    string currentDate = dateEditor.getDateString();
    string firstDayOfMonthDate = dateEditor.getDateStringFirstDayOfMonth();

    if (incomeManager.areTransactionsAvailable()) {
        cout << " >>> INCOME <<<" << endl << endl;
        incomeManager.showTransactions(firstDayOfMonthDate, currentDate);
        totalIncome = incomeManager.getTransactionsSummedValue();
    }

    if (expensesManager.areTransactionsAvailable()) {
        cout << endl << " >>> EXPENSES <<<" << endl << endl;
        expensesManager.showTransactions(firstDayOfMonthDate, currentDate);
        totalExpenses = expensesManager.getTransactionsSummedValue();
    }

    cout << endl << "---------------------" << endl;
    cout << "Total income = " << totalIncome << endl;
    cout << "Total expenses = " << totalIncome << endl;
    cout << "---------------------" << endl;
    cout << "Total balance = " << totalIncome - totalExpenses << endl << endl;

    system("pause");
}
