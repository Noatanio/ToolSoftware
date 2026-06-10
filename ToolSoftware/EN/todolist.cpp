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

    cout << "Todo list" << endl;
    cout << "==========" << endl;
    cout << "1. Change task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete a task" << endl;
    cout << "4. Exit" << endl;
    cin >> x;

    if( x == 1 ) {
        cout << "Select the number of the task to change : ";
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
        cout << "Here are the tasks : " << endl;
        lecture();
        affichage();      
        cin.get();
        Otodolist();
    }
    if( x == 3 ) {
        cout << "Select the task to delete : ";
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
        cout << "Data has been deleted !" << endl;
        Otodolist();
    }
    if( x == 4 ) {
        return;
    }
}
