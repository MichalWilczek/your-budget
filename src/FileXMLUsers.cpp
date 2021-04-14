#include "FileXMLUsers.h"


void FileXMLUsers::addUserToFile(User user) {

}

vector <User> FileXMLUsers::readUsersFromFile() {

    vector <User> users;

    User user;
    string lineWitUserData = "";

    fstream textFile;
    textFile.open(FILENAME.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, lineWitUserData)) {
            user = getUser(lineWitUserData);
            users.push_back(user);
        }
    }
    textFile.close();
    return users;
}

User FileXMLUsers::getUser(string lineWitUserData) {
    User user;
    string userDataElement = "";
    int numberUserDataElement = 1;

    for (int signPosition = 0; signPosition < lineWitUserData.length(); signPosition++) {
        if (lineWitUserData[signPosition] != '|') {
            userDataElement += lineWitUserData[signPosition];
        } else {
            switch (numberUserDataElement) {
            case 1:
                user.setIdUser(atoi(userDataElement.c_str()));
                break;
            case 2:
                user.setLogin(userDataElement);
                break;
            case 3:
                user.setPassword(userDataElement);
                break;
            }
            userDataElement = "";
            numberUserDataElement++;
        }
    }
    return user;
}

void FileXMLUsers::saveUsersToFile(vector <User> users) {
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(FILENAME.c_str(), ios::out);

    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {

            if (itr == itrEnd) {
                textFile << lineWithUserData;
            } else {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {
        cout << "The file: " << FILENAME << " cannot be opened." << endl;
    }
    textFile.close();
}
