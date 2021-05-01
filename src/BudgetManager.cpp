#include "BudgetManager.h"

void BudgetManager::showBalance(string startDate, string endDate) {

    double totalIncome = 0;
    double totalExpenses = 0;
    system("cls");

    if (incomeManager.areTransactionsAvailable()) {
        cout << " >>> INCOME <<<" << endl << endl;
        incomeManager.showTransactions(startDate, endDate);
        totalIncome = incomeManager.getTransactionsSummedValue(startDate, endDate);
    }

    if (expensesManager.areTransactionsAvailable()) {
        cout << endl << " >>> EXPENSES <<<" << endl << endl;
        expensesManager.showTransactions(startDate, endDate);
        totalExpenses = expensesManager.getTransactionsSummedValue(startDate, endDate);
    }

    cout << endl << "---------------------" << endl;
    cout << "Total income = " << totalIncome << endl;
    cout << "Total expenses = " << totalExpenses << endl;
    cout << "---------------------" << endl;
    cout << "Total balance = " << totalIncome - totalExpenses << endl << endl;
    system("pause");
}

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
    DateEditor dateEditor;
    string currentDate = dateEditor.getDateString();
    string firstDayOfMonthDate = dateEditor.getDateStringFirstDayOfMonth();

    showBalance(firstDayOfMonthDate, currentDate);
}

void BudgetManager::showBalanceFromPreviousMonth() {
    DateEditor dateEditorCurrentDate;
    string firstDayOfPreviousMonthDate = dateEditorCurrentDate.getDateStringFirstDayOfPreviousMonth();

    DateEditor lastMonthDate(firstDayOfPreviousMonthDate);
    string lastDayOfPreviousMonthDate = lastMonthDate.getDateStringLastDayOfMonth();

    showBalance(firstDayOfPreviousMonthDate, lastDayOfPreviousMonthDate);
}

void BudgetManager::showBalanceFromChosenPeriod() {
    system("cls");

    cout << ">>> START DATE <<<" << endl;
    DateEditor dateEditorStartDate(false);
    string startDate = dateEditorStartDate.getDateString();

    cout << endl << ">>> END DATE <<<" << endl;
    DateEditor dateEditorEndDate(false);
    string endDate = dateEditorEndDate.getDateString();

    showBalance(startDate, endDate);
}
