#include <iostream>
#include "calculator.h"
#include "todolist.h"
#include "stopwatch.h"
#include "file.h"
using namespace std;

int main() {
    int x;

    cout << "Bonjour !! Bienvenue dans ToolSoftware !" << endl << endl;
    cout << "Menu" << endl;
    cout << "==========" << endl;
    cout << "1. Calculatrice" << endl;
    cout << "2. Liste de taches" << endl;
    cout << "3. Chrono" << endl;
    cout << "4. Gestionnaire de fichiers" << endl << endl;
    cin >> x;
    cout << endl;

    if( x == 1 ) {
        Ocalculator();
    }
    if( x == 2 ) {
        Otodolist();
    }
    if( x == 3 ) {
        Ochrono();
    }
    if( x == 4 ) {
        Ofile();
    }

    return 0;
}