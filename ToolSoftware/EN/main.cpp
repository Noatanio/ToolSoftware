#include <iostream>
#include "calculator.h"
#include "todolist.h"
#include "stopwatch.h"
#include "file.h"
using namespace std;

int main() {
    int x;

    cout << "Hello !! Welcome to ToolSoftware !" << endl << endl;
    cout << "Home" << endl;
    cout << "==========" << endl;
    cout << "1. Calculator" << endl;
    cout << "2. Todo list" << endl;
    cout << "3. Chrono" << endl;
    cout << "4. File manager" << endl << endl;
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