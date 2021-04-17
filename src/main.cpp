#include <iostream>
#include "Markup.h"
#include "Budget.h"

using namespace std;


int main() {

    Budget budget("users.xml");
    budget.runConsole();
    return 0;
}

