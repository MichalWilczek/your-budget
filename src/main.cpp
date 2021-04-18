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
    DateEditor dateEditor(false);
    cout << dateEditor.getDateString() << endl;

    //DateEditor::getCurrentDate();
   // DateEditor::uploadDateFromConsole();

    //cout << DateEditor::getNumberOfDaysInMonth(2, 2001) << endl;
    //cout << DateEditor::getNumberOfDaysInMonth(2, 2000) << endl;
      /*cout << DateEditor::getNumberOfDaysInMonth(3) << endl;
       cout << DateEditor::getNumberOfDaysInMonth(4) << endl;
        cout << DateEditor::getNumberOfDaysInMonth(5) << endl;
         cout << DateEditor::getNumberOfDaysInMonth(6) << endl;
          cout << DateEditor::getNumberOfDaysInMonth(7) << endl;
           cout << DateEditor::getNumberOfDaysInMonth(8) << endl;
            cout << DateEditor::getNumberOfDaysInMonth(9) << endl;
            cout << DateEditor::getNumberOfDaysInMonth(10) << endl;
            cout << DateEditor::getNumberOfDaysInMonth(11) << endl;
            cout << DateEditor::getNumberOfDaysInMonth(12) << endl;*/

}
