#include "FileXML.h"

bool FileXML::isFileEmpty(fstream& textFile) {
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

void FileXML::deleteFile(string filenameWithExtension)
{
    if (remove(filenameWithExtension.c_str()) == 0) {}
    else
        cout << "Cannot delete file: " << filenameWithExtension << endl;
}

void FileXML::changeFilename(string oldName, string newName)
{
    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Cannot change file name. The name current name is: " << oldName << endl;
}
