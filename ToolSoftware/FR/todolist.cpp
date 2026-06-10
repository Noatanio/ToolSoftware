#include "todolist.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

static string a, b, c, d, e;
int x, t;

void lecture() {

    ifstream file("list.txt");
    getline(file, a);
    getline(file, b);
    getline(file, c);
    getline(file, d);
    getline(file, e);
    file.close();

}
void écriture() {
    ofstream file("list.txt");
    file << a << endl;
    file << b << endl;
    file << c << endl;
    file << d << endl;
    file << e << endl;
    file.close();
}
void affichage() {
    ifstream file;
    cout << "1. " << a << endl;
    cout << "2. " << b << endl;
    cout << "3. " << c << endl;
    cout << "4. " << d << endl;
    cout << "5. " << e << endl;
}

void Otodolist() {

    cout << "Liste de taches" << endl;
    cout << "==========" << endl;
    cout << "1. Changer une tache" << endl;
    cout << "2. Voir les taches" << endl;
    cout << "3. Supprimer une tache" << endl;
    cout << "4. Sortir" << endl;
    cin >> x;

    if( x == 1 ) {
        cout << "Séléctionnez le numéro de la tache à changer : ";
        cin >> t;

        if( t == 1 ) {
        lecture();
        cin.ignore();
        getline(cin, a);
        affichage(); 
        écriture();    
        }
        if( t == 2 ) {
        lecture();
        cin.ignore();
        getline(cin, b);
        affichage();
        écriture();
        }
        if( t == 3 ) {
        lecture();
        cin.ignore();
        getline(cin, c);
        affichage();
        écriture();
        }
        if( t == 4 ) {
        lecture();
        cin.ignore();
        getline(cin, d);
        affichage();
        écriture();
        }
        if( t == 5 ) {
        lecture();
        cin.ignore();
        getline(cin, e);
        affichage();
        écriture();
        }
        Otodolist();
    }
    if( x == 2 ) {
        cout << "Voici les taches : " << endl;
        lecture();
        affichage();      
        cin.get();
        Otodolist();
    }
    if( x == 3 ) {
        cout << "S&l&ctionnez la tache à supprimer : ";
        cin >> t;
        if( t == 1 ) {
            lecture();
            a = "";
            écriture();
        }
        if( t == 2 ) {
            lecture();
            b = "";
            écriture();
        }
        if( t == 3 ) {
            lecture();
            c = "";
            écriture();
        }
        if( t == 4 ) {
            lecture();
            d = "";
            écriture();
        }
        if( t == 5 ) {
            lecture();
            e = "";
            écriture();
        }
        cout << "La tache a été supprimé !" << endl;
        Otodolist();
    }
    if( x == 4 ) {
        return;
    }
}
