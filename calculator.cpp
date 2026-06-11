#include "calculator.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

static string x;

void operate() {

    double a, b;
    char c, m;

    cout << "Entrer l'opération que vous voulez résoudre " << endl;
    cout << "( un seul opérateur seulement avec des espaces entre les nombres ) :" << endl;
    cin.ignore();
    getline(cin, x);
    stringstream ss(x);
    ss >> a >> c >> b;

    switch(c) {

    case '+':
        cout << "= " << a + b << endl;
        break;

    case '-':
        cout << "= " << a - b << endl;
        break;

    case '*':
        cout << "= " << a * b << endl;
        break;

    case '/':
        cout << "= " << a / b << endl;
        break;
    }

    cout << "continuer ? (y/n) :" << endl;
    cin >> m;
    if( m == 'y' ) {
        operate();
    }
}

void Ocalculator() {
    cout << "Bienvenue dans la calcuatrice !" << endl;
    operate();
}
