#ifndef DATEEDITOR_H
#define DATEEDITOR_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "Utils.h"

using namespace std;

class DateEditor {

// Public interface.
public:
   static int getCurrentDate();
   static void uploadDateFromConsole();
   static bool isLeapYear(int year);
};

#endif
