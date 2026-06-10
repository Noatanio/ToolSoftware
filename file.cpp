#include "file.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

void create() {
    string y;

    cout << "Vous allez créer un fichier dans ce dossier." << endl;
    cout << "Entrer le nom du fichier que vous souhaitez créer :" << endl;
    getline(cin, y);

    ofstream file(y);
    file.close();

    cout << "Fichier créée !" << endl;
}

void suppr() {
    string z;

    cout << "Entrer le nom du fichier que vous voulez supprimer :" << endl;
    getline(cin , z);

    if( filesystem::exists(z) ) {
        filesystem::remove(z);
        cout << z << " a été supprimé" << endl;
    }else{
        cout << "Impossible de trouver ce fichier" << endl;
    }
}

void list() {
    string a;

    cout << "Entrer le nom du dossier que vous voulez lister :" << endl;
    getline(cin, a);
    if( filesystem::exists(a) ) {
        cout << filesystem::current_path().string() << endl << endl;
        for( auto&  element : filesystem::directory_iterator(a) ) {
            if( filesystem::is_regular_file(element) ) {
                cout << "Fichier - " << element.path().filename().string() << "   " << element.file_size() / ( 1024.0 )<< "KB" << endl;               
            }else{
                cout << "Dossier - " << element.path().string() << endl;
                               
            }
        }
    }else{
        cout << "Impossible de trouver le dossier" << endl;
    }
}

void choix() {
    string x;

    while(true) {
        getline(cin, x);
        if( x == "/help" ) {
            cout << "Vous pouvez utiliser ces commandes /help, /create, /delete or /list" << endl << endl;       
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
    cout << "Bienvenue dans le terminal gestionnaire de fichiers !" << endl;
    cout << "Utilisez /help pour lister les commandes disponibles !" << endl << endl;
    choix();
}