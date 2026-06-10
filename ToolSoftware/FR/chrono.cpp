#include "stopwatch.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// Ce fichier m'a permis d'apprendre énormément sur le temps dans un code

void chronomètre() {

    int ms, s, m, h = 0;

    cout << "Appuyez sur entrer pour démarrer le chrono... :" << endl;

    cin.ignore();
    cin.get();

    auto start = chrono::steady_clock::now();
    cout << "Appuyez sur entrer pour l'arrêter...";

    auto stop = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>( stop - start ).count();
    ms = duration % 1000;
    s = ( duration / 1000 ) % 60;
    m = ( duration / 60000 ) % 60;
    h = ( duration / 3600000 );

    cout << h << "h "
    << m << "m "
    << s << "s "
    << ms << "ms" << endl;
    
    char t;
    cout << "Encore ?(y/n)" << endl;
    cin >> t;
    if( t == 'y' ) {
        chronomètre();
    }
}
void minuteur() {
    int s;
    char t;

    cout << "Entrer le nombre de secondes : ";
    cin >> s;
    for(int i = s; i >= 0; i--) {
        cout << "\r" << i << " secondes.." << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl << "Fin !" << "continuer ?(y/n)" << endl;
    cin >> t;
    if( t == 'y' ) {
        minuteur();
    }
}
void horloge() {
    while(true) {
        auto nom = chrono::system_clock::now();
        time_t tt = chrono::system_clock::to_time_t(nom);
        tm local_tm = *localtime(&tt);
        cout << "\r                    \r";
        if(local_tm.tm_hour < 10) cout << '0';
        cout << local_tm.tm_hour << ':';
        if(local_tm.tm_min < 10) cout << '0';
        cout << local_tm.tm_min << ':';
        if(local_tm.tm_sec < 10) cout << '0';
        cout << local_tm.tm_sec << flush;
        this_thread::sleep_for(chrono::seconds(1));

        // Je pouvais aussi utiliser type_t t = time(0); et cout << ctime(&t);
    }
}

void Ochrono() {
    int x;

    cout << "Séléctionnez une option" << endl;
    cout << "1. chrono" << endl;
    cout << "2. Minuteur" << endl;
    cout << "3. Horloge" << endl;
    cin >> x;

    switch(x) {
        case 1:
        chronomètre();
        break;

        case 2:
        minuteur();
        break;

        case 3:
        horloge();
        break;
    }
}