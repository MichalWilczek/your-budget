#include "UsersManager.h"

User UsersManager::getUserNew() {
    string firstName, surname, login, password;

    User user;
    user.setIdUser(getUserIdNew());

    cout << "Set first name: ";
    cin >> firstName;
    user.setFirstName(firstName);

    cout << "Set surname: ";
    cin >> surname;
    user.setSurname(surname);

    do {
        cout << "Set login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Set password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UsersManager::getUserIdNew() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getIdUser() + 1;
}

bool UsersManager::doesLoginExist(string login) {
    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "User with such login already exists in the database." << endl;
            return true;
        }
    }
    return false;
}

bool UsersManager::isUserLoggedIn() {
    if (idUserLoggedIn > 0) return true;
    else return false;
}

int UsersManager::getIdUserLoggedIn() {
    if (isUserLoggedIn()) return idUserLoggedIn;
    else throw invalid_argument("No user is logged in.");
}

void UsersManager::registerUser() {
    User uzytkownik = getUserNew();

    users.push_back(uzytkownik);
    fileUsersXML.addUserToFile(uzytkownik);

    cout << endl << "Account created." << endl << endl;
    system("pause");
}

void UsersManager::showUsers() {
    for (unsigned int i = 0; i < users.size(); i++) {
        cout << users[i].getIdUser() << endl;
        cout << users[i].getFirstName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UsersManager::logInUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Set login: ";
    login = Utils::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getLogin() == login)
        {
            for (int trials = 3; trials > 0; trials--)
            {
                cout << "Set password. Remaining trials: " << trials << ": ";
                password = Utils::readLine();

                if (itr->getPassword() == password)
                {
                    cout << endl << "Login successful." << endl << endl;
                    system("pause");
                    idUserLoggedIn = itr->getIdUser();
                    return;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "The user witch such login does not exist in the database." << endl << endl;
    system("pause");
    return;
}

void UsersManager::changePasswordLoggedInUser()
{
    string newPassword = "";
    cout << "Set new password: ";
    newPassword = Utils::readLine();

    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].getIdUser() == idUserLoggedIn) {
            users[i].setPassword(newPassword);
            fileUsersXML.modifyUserInFile(users[i]);
            cout << "Password changed." << endl << endl;
            system("pause");
        }
    }
}

void UsersManager::logOutUser() {
    idUserLoggedIn = 0;
}
