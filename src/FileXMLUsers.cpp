#include "FileXMLUsers.h"


void FileXMLUsers::addUserToFile(User user) {
    CMarkup xmlUsers;

    // Load the XML file. If the file doesn't exist, create it and add the main headers.
    bool fileExists = xmlUsers.Load(FILENAME);
    if (!fileExists) {
        xmlUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlUsers.AddElem("Users");
    }

    // Add User data to the XML file.
    xmlUsers.FindElem();
    xmlUsers.IntoElem();
    xmlUsers.AddElem("User");
    xmlUsers.IntoElem();
    xmlUsers.AddElem("UserId", user.getIdUser());
    xmlUsers.AddElem("FirstName", user.getFirstName());
    xmlUsers.AddElem("Surname", user.getSurname());
    xmlUsers.AddElem("Login", user.getLogin());
    xmlUsers.AddElem("Password", user.getPassword());

    xmlUsers.Save(FILENAME);
}

vector <User> FileXMLUsers::readUsersFromFile() {
    vector <User> users;
    CMarkup xmlUsers;

    // Load the XML file. If the file doesn't exist, return an empty vector.
    bool fileExists = xmlUsers.Load(FILENAME);
     if (!fileExists) {
        return users;
    }

    // Upload each 'User' element from the file and add it to the vector.
    User user;
    xmlUsers.FindElem();
    xmlUsers.IntoElem();
    while (xmlUsers.FindElem("User")) {
        xmlUsers.IntoElem();

        xmlUsers.FindElem( "UserId" );
        user.setIdUser(atoi(MCD_2PCSZ(xmlUsers.GetData())));

        xmlUsers.FindElem( "FirstName" );
        user.setFirstName(xmlUsers.GetData());

        xmlUsers.FindElem( "Surname" );
        user.setSurname(xmlUsers.GetData());

        xmlUsers.FindElem( "Login" );
        user.setLogin(xmlUsers.GetData());

        xmlUsers.FindElem( "Password" );
        user.setPassword(xmlUsers.GetData());

        xmlUsers.OutOfElem();
        users.push_back(user);
    }

    return users;
}

void FileXMLUsers::modifyUserInFile(User user) {
    CMarkup xmlUsers;
    int idUser = 0;
    string password = "";

    // Load the XML file. If the file doesn't exist, exit the method.
    bool fileExists = xmlUsers.Load(FILENAME);
    if (!fileExists) {
        return;
    }

    xmlUsers.FindElem();
    xmlUsers.IntoElem();
    while (xmlUsers.FindElem("User")) {

        xmlUsers.IntoElem();
        xmlUsers.FindElem( "UserId" );
        idUser = atoi(MCD_2PCSZ(xmlUsers.GetData()));

        // If the uploaded user id corresponds to the id of the user data, overwrite its password in the file.
        if (idUser == user.getIdUser()) {

            while (xmlUsers.FindElem("Password")){
                   if (xmlUsers.RemoveElem()) cout << "hurra!" << endl;
            }
            return;
        }
        xmlUsers.OutOfElem();
    }

    xmlUsers.Save(FILENAME);
}
