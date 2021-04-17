#include "FileUsersXML.h"


void FileUsersXML::addUserToFile(User user) {
    CMarkup xmlFile;

    // Load the XML file. If the file doesn't exist, create it and add the main headers.
    bool fileExists = xmlFile.Load(FILENAME);
    if (!fileExists) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("Users");
    }

    // Add User data to the XML file.
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("User");
    xmlFile.IntoElem();
    xmlFile.AddElem("UserId", user.getIdUser());
    xmlFile.AddElem("FirstName", user.getFirstName());
    xmlFile.AddElem("Surname", user.getSurname());
    xmlFile.AddElem("Login", user.getLogin());
    xmlFile.AddElem("Password", user.getPassword());

    xmlFile.Save(FILENAME);
}

vector <User> FileUsersXML::readUsersFromFile() {
    vector <User> users;
    CMarkup xmlFile;

    // Load the XML file. If the file doesn't exist, return an empty vector.
    bool fileExists = xmlFile.Load(FILENAME);
     if (!fileExists) {
        return users;
    }

    // Upload each 'User' element from the file and add it to the vector.
    User user;
    xmlFile.FindElem();
    xmlFile.IntoElem();
    while (xmlFile.FindElem("User")) {
        xmlFile.IntoElem();

        xmlFile.FindElem( "UserId" );
        user.setIdUser(atoi(MCD_2PCSZ(xmlFile.GetData())));

        xmlFile.FindElem( "FirstName" );
        user.setFirstName(xmlFile.GetData());

        xmlFile.FindElem( "Surname" );
        user.setSurname(xmlFile.GetData());

        xmlFile.FindElem( "Login" );
        user.setLogin(xmlFile.GetData());

        xmlFile.FindElem( "Password" );
        user.setPassword(xmlFile.GetData());

        xmlFile.OutOfElem();
        users.push_back(user);
    }

    return users;
}

void FileUsersXML::modifyUserInFile(User user) {
    CMarkup xmlFile;
    int idUser = 0;
    string password = "";

    // Load the XML file. If the file doesn't exist, exit the method.
    bool fileExists = xmlFile.Load(FILENAME);
    if (!fileExists) {
        return;
    }

    // Dig into the 'User' elements.
    xmlFile.FindElem();
    xmlFile.IntoElem();

    // Iterate over all user IDs to find the logged in one.
    while (xmlFile.FindElem("User")) {

        xmlFile.IntoElem();
        xmlFile.FindElem( "UserId" );
        idUser = atoi(MCD_2PCSZ(xmlFile.GetData()));

        // If the uploaded user id corresponds to the id of the user data, overwrite its password in the file.
        if (idUser == user.getIdUser()) {
            while (xmlFile.FindElem("Password")){
                   if (xmlFile.RemoveElem()) {
                        xmlFile.AddElem("Password", user.getPassword());
                        xmlFile.Save(FILENAME);
                        return;
                   }
            }
        }
        xmlFile.OutOfElem();
    }
}
