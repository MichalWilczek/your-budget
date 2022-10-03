#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <iterator>
#include <vector>

using namespace std;

class Utils {

public:
	static string convertIntIntoString(int number);
	static string convertDoubleIntoString(double number);
	static int convertStringIntoInt(string number);
    static double convertStringIntoDouble(string number);
	static string convertCommasToDots(string text);
	static string convertFirstLetterIntoCapitalOtherIntoLowercase(string text);
	static string readLine();
    static string readNumber(string text, int signPosition);
	static char readSign();
	static int readInteger();
	static vector <string> splitString(string s, string delimiters);
};

#endif
