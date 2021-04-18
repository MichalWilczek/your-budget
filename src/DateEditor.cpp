#include "DateEditor.h"

int DateEditor::getCurrentDate() {
    // Get current year, month, and day.
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int yearInteger = now->tm_year + 1900;
    int monthInteger = now->tm_mon + 1;
    int dayInteger = now->tm_mday;

    // Convert year, month, and day to the proper string format.
    string year = Utils::convertIntIntoString(yearInteger);
    string month = Utils::convertIntIntoString(monthInteger);
    string day = Utils::convertIntIntoString(dayInteger);
    if (month.length() == 1) month = "0" + month;
    if (month.length() != 2)  throw invalid_argument("Month should consist of two two digits.");

    // Add date string elements all together and reconvert the sum into integer.
    string dateString= year + month + day;
    int dateInteger = Utils::convertStringIntoInt(dateString);
    return dateInteger;
}

void DateEditor::uploadDateFromConsole() {

/*
    //string date = "06,05-2021.05-14"
    bool continueLoop = false;

    do {
        cout << "Type in the date. The required format is YYYY.MM.DD. Dots are replacable with commas, dashes and hyphens:" << endl;
        string date = Utils::readLine();
        vector <string> dateElements = Utils::splitString(date, ",._-");

        if (dateElements.size() != 3) {
            cout << "The date should consist of three numbers: year, month, and day." << endl;
            continueLoop = true;
            continue;
        }

        string year = dateElements[0];
        string month = dateElements[1];
        string day = dateElements[2];

        if (year.length() > 4) {
            cout << "Year cannot have more than 4 digits." << endl;
            continue;
        }

    } while (continueLoop)*/
}

bool DateEditor::isLeapYear(int year) {

    if (year < 0)
        throw invalid_argument("Year must be a positive number.");

    if (year%4 == 0) {
        if (year%100 == 0) {
            if (year%400 == 0)
                return true;

                return false;
        }

        return true;
    }

    return false;
}


















