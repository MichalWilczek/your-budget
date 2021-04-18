#ifndef DATEEDITOR_H
#define DATEEDITOR_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "Utils.h"

using namespace std;

class DateEditor {

    string year;
    string month;
    string day;

    void setCurrentDate();
    void uploadDateFromConsole();
    bool isYearCorrect();
    bool isMonthCorrect();
    bool isDayCorrect();
    bool isLeapYear();
    int getNumberOfDaysInMonth();

// Public interface.
public:
    DateEditor(bool currentDate=true) {
        if (currentDate)
            setCurrentDate();
        else
            uploadDateFromConsole();
    }
    int getDateInteger();
    string getDateString();
};

#endif
