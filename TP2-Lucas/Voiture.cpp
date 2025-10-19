/* Class voiture */

//#include <stdio.h>
#include <iostream>
#include "Vehicule.hpp"
#include "Voiture.hpp"

using namespace std;

Voiture::Voiture(int vitesseMax, int nbPlaces, int occupants) : Vehicule(vitesseMax, nbPlaces, occupants)
{
    // Constructeur de la classe Voiture
}

void Voiture::demarrer(){
    Vehicule::demarrer(); // Appel de la méthode de la classe de base
    etat_=MARCHE;
    vitesse_=10;
}

void Voiture::arreter(){   
    Vehicule::arreter(); // Appel de la méthode de la classe de base
    etat_=ARRET;
    vitesse_=0;
}

void Voiture::depanner(){  
    Vehicule::depanner(); // Appel de la méthode de la classe de base
    etat_=ARRET;
    vitesse_=0;
}

void Voiture::accelerer(int increment){
    Vehicule::accelerer(increment); // Appel de la méthode de la classe de base
    vitesse_+=increment;
}

void Voiture::monter(int nbOcc){ 
    Vehicule::monter(nbOcc); // Appel de la méthode de la classe de base
    occupants_+=nbOcc;
}

void Voiture::descendre(int nbOcc){
    Vehicule::descendre(nbOcc); // Appel de la méthode de la classe de base
    occupants_-=nbOcc;
}

void Voiture::mettreEnPanne(double random){
    Vehicule::mettreEnPanne(random); // Appel de la méthode de la classe de base    
    if (random<0.5) etat_=PANNE_LEGERE;
    else if (random>=0.5) etat_=PANNE_SEVERE;
}

string Voiture::getEtat() const{
    return Vehicule::getEtat(); // Appel de la méthode de la classe de base
}

Voiture::~Voiture() {
    cout << "Destructeur de la classe Voiture" << endl;
}