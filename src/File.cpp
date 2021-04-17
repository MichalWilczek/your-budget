#include "File.h"

bool File::isFileEmpty(fstream& file) {
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        return true;
    else
        return false;
}

void File::deleteFile(string filenameWithExtension)
{
    if (remove(filenameWithExtension.c_str()) == 0) {}
    else
        cout << "Cannot delete file: " << filenameWithExtension << endl;
}

void File::changeFilename(string oldName, string newName)
{
    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Cannot change the file name. The current name is: " << oldName << endl;
}
