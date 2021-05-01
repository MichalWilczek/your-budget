#include "DateEditor.h"

int DateEditor::getDateInteger() {
    string dateString= year + month + day;
    int dateInteger = Utils::convertStringIntoInt(dateString);
    return dateInteger;
}

string DateEditor::getDateString() {
    string date= year + "-" + month + "-" + day;
    return date;
}

void DateEditor::setCurrentDate() {
    // Get current year, month, and day.
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int yearInteger = now->tm_year + 1900;
    int monthInteger = now->tm_mon + 1;
    int dayInteger = now->tm_mday;

    // Convert year, month, and day to the proper string format.
    year = Utils::convertIntIntoString(yearInteger);
    month = Utils::convertIntIntoString(monthInteger);
    day = Utils::convertIntIntoString(dayInteger);

    unifyDateElements();
}

void DateEditor::uploadDate(string date) {
    vector <string> dateElements = Utils::splitString(date, ",._-");

    if (dateElements.size() != 3)
        throw invalid_argument ("The date should consist of three numbers: year, month, and day.");

    year = dateElements[0];
    month = dateElements[1];
    day = dateElements[2];

    if (!isYearCorrect())
        throw invalid_argument(year);

    if (!isMonthCorrect())
        throw invalid_argument(month);

    if (!isDayCorrect())
        throw invalid_argument(day);

    unifyDateElements();
}

string DateEditor::getDateStringFirstDayOfMonth() {
    return year + "-" + month + "-" + "01";
}

/*
string DateEditor::getPreviousMonthFirstDayDate() {
    int monthInteger = Utils::convertStringIntoInt(month);

    if (monthInteger > 1) {
        int newMonthInteger = monthInteger  - 1;
        string newMonthString = Utils::convertIntIntoString(newMonthInteger);
        string newDate = year + "-" + newMonthString + "-" + day;
        DateEditor dateEditor(date);
        return dateEditor;
    }

    month = "12"
    int yearInteger

}*/

void DateEditor::uploadDateFromConsole() {

    while (true) {
        cout << "Type in the date. The required format is YYYY.MM.DD. Dots are replaceable with commas, dashes and hyphens:" << endl;
        string date = Utils::readLine();
        vector <string> dateElements = Utils::splitString(date, ",._-");

        if (dateElements.size() != 3) {
            cout << "The date should consist of three numbers: year, month, and day." << endl;
            continue;
        }

        year = dateElements[0];
        if (!isYearCorrect())
            continue;

        month = dateElements[1];
        if (!isMonthCorrect())
            continue;

        day = dateElements[2];
        if(!isDayCorrect())
            continue;

        break;
    }
    unifyDateElements();
}

bool DateEditor::isYearCorrect() {

    bool isYearCorrect = true;
    int yearInteger = Utils::convertStringIntoInt(year);

    int yearLength = year.length();
    if (yearLength > 4) {
        cout << "Year: " + year + " cannot have more than 4 digits." << endl;
        isYearCorrect = false;
    }

    if (yearInteger < 0) {
        cout << "Year: " + year + " cannot be negative." << endl;
        isYearCorrect = false;
    }

    if (!isYearCorrect)
        return isYearCorrect;

    return isYearCorrect;
}

bool DateEditor::isMonthCorrect() {

    bool isMonthCorrect = true;
    int monthInteger = Utils::convertStringIntoInt(month);

    if (month.length() > 2) {
        cout << "Month: " + month + " cannot have more than 2 digits." << endl;
        isMonthCorrect = false;
    }

    if (monthInteger < 0 || monthInteger > 12) {
        cout << "Month: " + month + " must be a number between 1 and 12." << endl;
        isMonthCorrect = false;
    }

    return isMonthCorrect;
}

bool DateEditor::isDayCorrect() {

    bool isDayCorrect = true;
    int dayInteger = Utils::convertStringIntoInt(day);

    if (day.length() > 2) {
        cout << "Day: " + day + " cannot have more than 2 digits." << endl;
        isDayCorrect = false;
    }

    int daysInMonth = getNumberOfDaysInMonth();
    if (dayInteger < 0 || dayInteger > daysInMonth) {
        cout << "Day: " + day + " should be a number between 1 and " + Utils::convertIntIntoString(daysInMonth) << " for the given month." << endl;
        isDayCorrect = false;
    }

    return isDayCorrect;
}

bool DateEditor::isLeapYear() {

    int yearInteger = Utils::convertStringIntoInt(year);

    if (yearInteger < 0)
        throw invalid_argument("Year must be a positive number.");

    if (yearInteger%4 == 0) {
        if (yearInteger%100 == 0) {
            if (yearInteger%400 == 0)
                return true;
            return false;
        }
        return true;
    }
    return false;
}

int DateEditor::getNumberOfDaysInMonth() {

    int monthInteger = Utils::convertStringIntoInt(month);

    if (monthInteger > 12 || monthInteger < 1)
        throw invalid_argument("Month: " + month + " must be between 1 and 12.");

    int days;
    switch (monthInteger) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 2:
            if (isLeapYear())
                days = 29;
            else
                days = 28;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
    }
    return days;
}

void DateEditor::unifyDateElements() {

    // Add zeros to the year if it has less than 4 digits.
    for (int i=year.length(); i<4; i++) {
        year = "0" + year;
    }

    // Add zeros to the month and the day if needed.
    if (month.length() == 1) month = "0" + month;
    if (month.length() != 2)  throw invalid_argument("Month " + month + " should consist of two two digits.");
    if (day.length() == 1) day = "0" + day;
    if (day.length() != 2)  throw invalid_argument("Day: " + day + " should consist of two two digits.");
}
