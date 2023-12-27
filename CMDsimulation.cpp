// osProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
typedef unsigned char BYTE;
using namespace std;

//file struct to represent a file
struct File {
    string fName = "Untitled";
    bool fSize = 1;
};


//function to get the input from the user
void SplitString(string s, vector<string>& v) {

    string temp = "";
    for (int i = 0; i < s.length(); ++i) {

        if (s[i] == ' ') {
            v.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(s[i]);
        }

    }
    v.push_back(temp);

}

// function to print the vector
void PrintVector(vector<File> v) {
    cout << endl << "-The present files: " << endl;

    for (int i = 0; i < v.size(); ++i) {
        cout << i + 1;
        cout << ": '" + v[i].fName + "'" << endl;
    }
}


/* functions for commands */

// CLS
void cls() {
    system("cls");
}

// EXIT
void quit(vector<File> v) {
    ofstream wf("file.dat", ios::out | ios::binary);

    if (!wf) {
        cout << "Cannot open file!" << endl;
        ////////////////
    }

    cout << "=file openned !!!" << endl;
    for (int i = 0; i < v.size(); i++)
        wf.write((char*)&v[i], sizeof(File));
    wf.close();
    if (!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        ///////////
    }
    cout << "=data is writtin in the file !!!" << endl;

    exit(0);
}
//MKDIR
void createf(vector<File>& v, string s) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].fName == s) {
            cout << "There is a file with the name '" + s + "'" << endl;
            cout << endl;
            break;
        }
        else if (i == v.size() - 1 && v[i].fName != s) {
            File f;
            f.fName = s;
            f.fSize = 1;
            v.push_back(f);
            cout << "File has been created successfully!" << endl;
            PrintVector(v);
            break;
        }
    }
}

// DEL
void del(string s, vector<File>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].fName == s) {
            v.erase(v.begin() + i);
            cout << "The file '" + s + "' has been deleted successfully!" << endl;
            break;
        }

        if (i == v.size() - 1 && v[i].fName != s) {

            cout << "No file is found with the name '" + s + "'! " << endl;
        }
    }
}

// RENAME
//void rename(string oldStr,string newStr, vector<File>& v) {
//    bool newNameExists= false;
//    for (int i = 0;i < v.size(); i++) {
//        if (v[i].fName == newStr) {
//            cout << "There is a file with the name '" + newStr + "'" << endl;
//            newNameExists = true;
//            break;
//        }        
//    } 
//    if (!newNameExists) {
//        for (int i = 0;i < v.size(); i++) {
//            if (v[i].fName == oldStr) {
//                v[i].fName = newStr;
//                cout << "The file '" + oldStr + "' has been renamed to '" + newStr + "' " << endl << endl;
//                PrintVector(v);
//                break;
//            }
//            if (i == v.size() - 1 && v[i].fName != oldStr) {
//                cout << "No file is found with the name '" + oldStr + "'! " << endl;
//            }
//        }
//    }
//}

//RENAME2
void rename2(string oldStr, string newStr, vector<File>& v) {
    bool fileToChangeExists = false;
    bool newNameExists = false;
    int fileIndex = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].fName == oldStr) {
            fileToChangeExists = true;
            fileIndex = i;
            break;
        }
        if (i == v.size() - 1 && v[i].fName != oldStr) {
            cout << "No file is found with the name '" + oldStr + "'! " << endl;
            break;
        }
    }
    if (fileToChangeExists) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].fName == newStr) {
                cout << "There is a file with the name '" + newStr + "'" << endl;
                break;
            }
            if (i == v.size() - 1 && v[i].fName != newStr) {
                v[fileIndex].fName = newStr;
                cout << "The file '" + oldStr + "' has been renamed to '" + newStr + "' " << endl << endl;
                PrintVector(v);
                break;
            }
        }
    }
}

// HELP
void help() {
    cout << "CLS            Clears the screen." << endl;
    cout << "DEL            Deletes one or more files." << endl;
    cout << "LS             Displays a list of files in a directory." << endl;
    cout << "QUIT           the CMD.EXE program(command interpreter)." << endl;
    cout << "HELP           Provides Help information for Windows commands." << endl;
    cout << "MKDIR          Creates a new file." << endl << endl;


}
int main()
{
    // string for command
    string inputString;
    //vector to split the input string into it
    vector <string> inputVector;
    //The vector that has the files
    vector <File> filesVector;
    cout << "the beginning: " << endl;


    // input file stream
    ifstream file("file.dat", ios::binary);

    // copy the contents of the file into the vector
    File inf;
    while (file.read(reinterpret_cast<char*>(&inf), sizeof(inf)))
        filesVector.push_back(inf);
    cout << "Data is transfersd from file to vector" << endl;
    file.clear();
    cout << "binary file is cleared " << endl;
    file.close();
    PrintVector(filesVector);

    //readFile("file.dat", filesVector);
    //open file to read
    /*ifstream rf("file.dat", ios::out | ios::binary);
    if (!rf) {
        cout << "Cannot open file!" << endl;
        return 1;
    }*/

    /*std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(filesVector), {});
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return 1;
    }*/

    /*File f1,f2,f3;
    f1.fName = "file1";
    f2.fName = "file2";
    f3.fName = "file3";*/
    /*cout << "from the f1 " << endl;
    cout << f1.fName + "\n";
    cout << f1.fSize << endl;*/

    /*filesVector.push_back(f1);
    filesVector.push_back(f2);
    filesVector.push_back(f3);*/
    /*cout<<"printing from the vector"<< endl;
    cout << filesVector[0].fName << endl;*/


    while (true)
    {
        //clearing input variables
        inputString = "";
        inputVector.clear();

        //get the command from console and split into the inputVector variable
        cout << "-H:\\>";
        getline(cin, inputString);
        SplitString(inputString, inputVector);



        string command = inputVector[0];

        if (inputString.length() >= 100) {
            cout << "this command is too long!!!" << endl;
            continue;
        }
        if (command == "cls") { cls(); }
        else if (command == "ls") {
            PrintVector(filesVector);
        }
        else if (command == "help") { help(); }
        else if (command == "rename") {
            if (inputVector.size() < 3) {
                cout << "arguments missing for the command 'rename'." << endl << endl;
            }
            else {
                rename2(inputVector[1], inputVector[2], filesVector);
            }

        }
        else if (command == "del") {
            if (inputVector.size() < 2) {
                cout << "arguments missing for the command 'del'." << endl << endl;
            }
            else {
                del(inputVector[1], filesVector);
                PrintVector(filesVector);
            }
        }
        else if (command == "quit") { quit(filesVector); }
        else if (command == "mkdir") {
            if (inputVector.size() < 2) {
                cout << "Arguments missing for the command 'rename'." << endl << endl;
            }
            else {
                createf(filesVector, inputVector[1]);
            }
        }

        else { cout << "'" + inputVector[0] + "' is not recognized as an internal or external command." << endl; }


    }

    return 0;
}


