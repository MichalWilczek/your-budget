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
