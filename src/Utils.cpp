#include "Utils.h"
#include <Windows.h>

string Utils::convertIntIntoString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string Utils::convertDoubleIntoString(double number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string Utils::readLine() {
    string line = "";
    getline(cin, line);
    return line;
}

string Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(string text) {
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }

    return string(text);
}

string Utils::convertCommasToDots(string text) {
    if (!text.empty())
    {
        replace(text.begin(), text.end(), ',', '.');
    }

    return string(text);
}

string Utils::readNumber(string text, int signPosition) {
    string number = "";

    while (isdigit(text[signPosition]))
    {
        number += text[signPosition];
        signPosition++;
    }
    return number;
}

int Utils::convertStringIntoInt(string number) {
    int Integer;
    istringstream iss(number);
    iss >> Integer;

    return Integer;
}

double Utils::convertStringIntoDouble(string number) {
    return stod(number);
}

char Utils::readSign() {
    string line = "";
    char sign = { 0 };

    while (true) {
        getline(cin, line);

        if (line.length() == 1) {
            sign = line[0];
            break;
        } else {
            if (line != "")
                cout << "It's not a single sign. Type in again." << endl;
        }
    }
    return sign;
}

int Utils::readInteger() {
    string line = "";
    int number = 0;

    while (true) {
        getline(cin, line);

        stringstream myStream(line);
        if (myStream >> number)
            break;
        cout << "This is not a number. Enter it once again. " << endl;
    }
    return number;
}

vector<string> Utils::splitString(string inputString, string delimitersNew) {

    vector<string> wordElements;
    stringstream stringStream(inputString);
    string line;
    while(getline(stringStream, line))
    {
        size_t prev = 0, pos;
        while ((pos = line.find_first_of(delimitersNew, prev)) != string::npos)
        {
            if (pos > prev)
                wordElements.push_back(line.substr(prev, pos-prev));
            prev = pos+1;
        }
        if (prev < line.length())
            wordElements.push_back(line.substr(prev, string::npos));
    }
    return wordElements;
}
