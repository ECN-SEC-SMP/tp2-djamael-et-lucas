/* Class Bateau */

//#include <stdio.h>
#include <iostream>
#include "Vehicule.hpp"
#include "Bateau.hpp"

using namespace std;

Bateau::Bateau(int vitesseMax, int nbPlaces, int occupants) : Vehicule(vitesseMax, nbPlaces, occupants)
{
    // Constructeur de la classe Bateau
}

void Bateau::demarrer(){
    Vehicule::demarrer(); // Appel de la méthode de la classe de base
    cout << "Démarrage d'un bateau" << endl;
    etat_=MARCHE;
    vitesse_=10;
}

void Bateau::arreter(){
    Vehicule::arreter(); // Appel de la méthode de la classe de base
    cout << "Arrêt d'un bateau" << endl;
    Vehicule::arreter(); // Appel de la méthode de la classe de base
    etat_=ARRET;
    vitesse_=0;
}

void Bateau::depanner(){
    Vehicule::depanner(); // Appel de la méthode de la classe de base
    etat_=ARRET;
    vitesse_=0;
}

void Bateau::accelerer(int increment){
    Vehicule::accelerer(increment); // Appel de la méthode de la classe de base
    vitesse_+=increment;
}

void Bateau::monter(int nbOcc){
    Vehicule::monter(nbOcc); // Appel de la méthode de la classe de base
    occupants_+=nbOcc;
}

void Bateau::descendre(int nbOcc){
    Vehicule::descendre(nbOcc); // Appel de la méthode de la classe de base
    occupants_-=nbOcc;
}

void Bateau::mettreEnPanne(double random){
    Vehicule::mettreEnPanne(random); // Appel de la méthode de la classe de base
    if (random<0.5) etat_=PANNE_LEGERE;
    else if (random>=0.5) etat_=PANNE_SEVERE;
}

string Bateau::getEtat() const{
    return Vehicule::getEtat(); // Appel de la méthode de la classe de base
}

//destructeur
Bateau::~Bateau(){
    cout << "Destructeur de la classe Bateau" << endl;
}