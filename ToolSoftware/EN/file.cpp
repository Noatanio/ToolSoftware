#include "file.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

void create() {
    string y;

    cout << "You will create a file in this directory." << endl;
    cout << "Enter the name of the file you want to create :" << endl;
    getline(cin, y);

    ofstream file(y);
    file.close();

    cout << "File created !" << endl;
}

void suppr() {
    string z;

    cout << "Enter the file you want to delete :" << endl;
    getline(cin , z);

    if( filesystem::exists(z) ) {
        filesystem::remove(z);
        cout << z << " has left the game" << endl;
    }else{
        cout << "Cannot find this file" << endl;
    }
}

void list() {
    string a;

    cout << "Enter the directory you want to list :" << endl;
    getline(cin, a);
    if( filesystem::exists(a) ) {
        cout << filesystem::current_path().string() << endl << endl;
        for( auto&  element : filesystem::directory_iterator(a) ) {
            if( filesystem::is_regular_file(element) ) {
                cout << "File - " << element.path().filename().string() << "   " << element.file_size() / ( 1024.0 )<< "KB" << endl;               
            }else{
                cout << "Directory - " << element.path().string() << endl;
                               
            }
        }
    }else{
        cout << "Cannot find this directory" << endl;
    }
}

void choix() {
    string x;

    while(true) {
        getline(cin, x);
        if( x == "/help" ) {
            cout << "You can use these commands /help, /create, /delete or /list" << endl << endl;       
        }else if( x == "/create" ) {
            create();
        }else if( x == "/delete" ) {
            suppr();
        }else if( x == "/list" ) {
            list();
        }
    }
}

void Ofile() {
    cout << "Welcome to file manager terminal !" << endl;
    cout << "Use /help to list all commands !" << endl << endl;
    choix();
}