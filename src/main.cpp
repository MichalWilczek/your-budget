#include <iostream>
#include "Markup.h"
#include "UsersManager.h"

using namespace std;


int main() {

    UsersManager usersManager("users.xml");

    //usersManager.registerUser();
    usersManager.showUsers();
    usersManager.logInUser();
    usersManager.changePasswordLoggedInUser();

    return 0;
}

