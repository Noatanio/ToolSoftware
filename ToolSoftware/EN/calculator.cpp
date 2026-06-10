#include "calculator.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

static string x;

void operate() {

    double a, b;
    char c, m;

    cout << "Enter the operation you want to solve " << endl;
    cout << "( one operator only with space beetween caracters ) :" << endl;
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

    cout << "continue ? (y/n) :" << endl;
    cin >> m;
    if( m == 'y' ) {
        operate();
    }else{
        // Return to main
    }
}

void Ocalculator() {
    cout << "Welcome in the calculator !" << endl;
    operate();
}
