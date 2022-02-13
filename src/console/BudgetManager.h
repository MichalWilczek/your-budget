#ifndef BUDGETMANAGER_h
#define BUDGETMANAGER_h

#include <iostream>
#include <vector>

#include "TransactonsManager.h"
#include "DateEditor.h"

using namespace std;

class BudgetManager {
	TransactionsManager incomeManager;
	TransactionsManager expensesManager;
	void showBalance(string startDate, string endDate);

public:
	BudgetManager(string filenameIncome, string filenameExpenses, int idUserLoggedIn):
	    incomeManager(filenameIncome, idUserLoggedIn),
	    expensesManager(filenameExpenses, idUserLoggedIn) {};

    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromChosenPeriod();
};

#endif
