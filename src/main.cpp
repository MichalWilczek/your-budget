#include <iostream>

/*
#include "Markup.h"
#include "Budget.h"

using namespace std;


int main() {

    Budget budget("users.xml", "income.xml", "expenses.xml");
    budget.runConsole();
    return 0;
}
*/


#include "DateEditor.h"

using namespace std;


int main() {
    //DateEditor::getCurrentDate();
    DateEditor::uploadDateFromConsole();

    cout << DateEditor::isLeapYear(1901) << endl;
    cout << DateEditor::isLeapYear(1900) << endl;
    cout << DateEditor::isLeapYear(2000) << endl;
    cout << DateEditor::isLeapYear(2004) << endl;
    cout << DateEditor::isLeapYear(2100) << endl;
    cout << DateEditor::isLeapYear(2010) << endl;
}
