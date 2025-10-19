/*
 * LUCAS OROS 
 * TP2 - SEC - 14/10/2025
 * CPP - TP2 - main.cpp
 *
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>  
#include <ctime>    
#include "Vehicule.hpp"
#include "Voiture.hpp"
#include "Bateau.hpp"
#include "VoitureAmphibie.hpp"

using namespace std;

void Voiture_test(void){
    Voiture v(180,5,1);
    cout << "Voiture: " << v;

    v.monter(2);
    v.demarrer();
    v.accelerer(60);
    double random = (double)rand() / RAND_MAX;
    v.mettreEnPanne(random);
    cout << v;
    v.descendre(1);
    v.depanner();
    v.demarrer();
    cout << v;
}

void bateau_test(void){
    Bateau b(80,20,5);
    cout << "Bateau: " << b;

    b.monter(3);
    b.demarrer();
    b.accelerer(30);
    double random = (double)rand() / RAND_MAX;
    b.mettreEnPanne(random);
    cout << b;
    b.descendre(2);
    b.depanner();
    b.demarrer();
    cout << b;
}

void voitureAmphibie_test(void){
    VoitureAmphibie va(150, 50, 4 ,1);
    va.afficher_caracteristiques();

    cout << "\n-- Mode voiture --" << endl;
    va.monter(2);
    va.demarrer();
    va.accelerer(100);
    cout << va;
    double random = (double)rand() / RAND_MAX;
    va.mettreEnPanne(random);
    va.afficher_caracteristiques();
    va.descendre(1);
    va.depanner();

    cout << "\n-- Changement en mode bateau --" << endl;
    va.changerMode(true);
    va.demarrer();
    va.accelerer(30);
    va.afficher_caracteristiques();
    
}


int main()
{
    cout << "TP2: CPP" << endl;
    srand(time(nullptr));  // initialise la graine avec le temps actuel (secondes)

    Voiture_test();
    cout << "------------------------" << endl;
    bateau_test();
    cout << "------------------------" << endl;
    voitureAmphibie_test();
    cout << "------------------------" << endl;

    return 0;
}



