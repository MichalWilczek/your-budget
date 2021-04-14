#include "UsersManager.h"

User UsersManager::getUserNew() {
    User user;

    user.setIdUser(getUserIdNew());

    string firstName;
    cout << "Set first name: ";
    cin >> firstName;
    user.setFirstName(firstName);

    string surname;
    cout << "Set surname: ";
    cin >> surname;
    user.setSurname(surname);

    string login;
    do {
        cout << "Set login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
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

void UsersManager::registerUser() {
    User uzytkownik = getUserNew();

    users.push_back(uzytkownik);
    fileXML.addUserToFile(uzytkownik);

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
    cout << "The user witch such login does not exist in the databse." << endl << endl;
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
            fileXML.modifyUserInFile(users[i]);
            cout << "Password changed." << endl << endl;
            system("pause");
        }
    }
}

void UsersManager::logOutUser() {
    idUserLoggedIn = 0;
}

/*
void UsersManager::registerUser() {
    User uzytkownik = getUserNew();

    users.push_back(uzytkownik);
    fileXML.addUserToFile(uzytkownik);

    cout << endl << "Account created." << endl << endl;
    system("pause");
}

int UsersManager::getIdUserLoggedIn() {
    if (idUserLoggedIn > 0)
        return idUserLoggedIn;
    else
        throw invalid_argument("Received value is lower than 1.");
}

User UsersManager::getUserNew() {
    User user;

    user.setIdContact(getUserIdNew());

    string login;
    do {
        cout << "Set login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Set password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

bool UsersManager::isUserLoggedIn() {
    if (idUserLoggedIn > 0) return true;
    else return false;
}

int UsersManager::getUserIdNew() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getIdContact() + 1;
}

bool UsersManager::doesLoginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "User with such login already exists in the database." << endl;
            return true;
        }
    }
    return false;
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
                    idUserLoggedIn = itr->getIdContact();
                    return;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "The user witch such login does not exist in the databse." << endl << endl;
    system("pause");
    return;
}

void UsersManager::changePasswordLoggedInUser()
{
    string newPassword = "";
    cout << "Set new password: ";
    newPassword = Utils::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getIdContact() == idUserLoggedIn)
        {
            itr->setPassword(newPassword);
            cout << "Password changed." << endl << endl;
            system("pause");
        }
    }
    fileXML.saveUsersToFile(users);
}

void UsersManager::logOutUser() {
    idUserLoggedIn = 0;
}
*/
