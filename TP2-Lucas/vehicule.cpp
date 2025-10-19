/* Class vehicule */

//#include <stdio.h>
#include <iostream>
#include "Vehicule.hpp"
#include <math.h>  
#include <fstream> 
#include <map>
#include <sstream>
#include <set>

using namespace std;

Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
{
    if (vitesseMax<0) throw invalid_argument("vitesseMax ne peut pas être négative");
    if (nbPlaces<=0) throw invalid_argument("nbPlaces doit être strictement positive");
    if (occupants<0) throw invalid_argument("occupants ne peut pas être négatif");
    if (occupants>nbPlaces) throw invalid_argument("occupants ne peut pas être supérieur à nbPlaces");
    
    this->vitesseMax_=vitesseMax;
    this->nbPlaces_=nbPlaces;
    this->occupants_=occupants;
    this->vitesse_=0;
    this->etat_=ARRET;
}

void Vehicule::demarrer()
{
    if (etat_==PANNE_SEVERE) throw logic_error("Le véhicule est en panne sévère, il ne peut pas démarrer");
    if (etat_==PANNE_LEGERE) throw logic_error("Le véhicule est en panne légère, il ne peut pas démarrer");
    if (etat_==MARCHE) throw logic_error("Le véhicule est déjà en marche");
    if (occupants_==0) throw logic_error("Le véhicule ne peut pas démarrer sans occupants");
}

void Vehicule::arreter(){
    if (etat_==ARRET) throw logic_error("Le véhicule est déjà à l'arrêt");
}

void Vehicule::depanner(){
    if (etat_==ARRET) throw logic_error("Le véhicule n'est pas en panne");
    if (etat_==MARCHE) throw logic_error("Le véhicule n'est pas en panne");
}

void Vehicule::accelerer(int increment){
    if (etat_==ARRET) throw logic_error("Le véhicule est à l'arrêt, il ne peut pas accélérer");
    if (etat_==PANNE_SEVERE) throw logic_error("Le véhicule est en panne sévère, il ne peut pas accélérer");
    if (etat_==PANNE_LEGERE) throw logic_error("Le véhicule est en panne légère, il ne peut pas accélérer");
    //if (vitesse_<0) throw invalid_argument("L'incrément doit être positif");
    if (vitesse_+increment>=vitesseMax_) throw logic_error("Le véhicule est déjà à la vitesse maximale");
}

void Vehicule::monter(int nbOcc){
    if (nbOcc<0) throw invalid_argument("Le nombre d'occupants doit être positif");
    if (occupants_+nbOcc>nbPlaces_) throw logic_error("Le véhicule ne peut pas accueillir autant d'occupants");
}

void Vehicule::descendre(int nbOcc){
    if (nbOcc<0) throw invalid_argument("Le nombre d'occupants doit être positif");
    if (nbOcc>occupants_) throw logic_error("Le véhicule ne peut pas avoir un nombre négatif d'occupants");
}

void Vehicule::mettreEnPanne(double random){
    if (random<0 || random>1) throw invalid_argument("Le paramètre random doit être compris entre 0 et 1");
}

string Vehicule::getEtat() const
{
    if (etat_==ARRET) return "ARRET";
    else if (etat_==MARCHE) return "MARCHE";
    else if (etat_==PANNE_LEGERE) return "PANNE_LEGERE";
    else if (etat_==PANNE_SEVERE) return "PANNE_SEVERE";
    else return "ETAT_INCONNU";
}
    

// opérateur d'affichage
ostream& operator<<(ostream& s,Vehicule const& v)
{
    s << "Vitesse : " << v.vitesse_ << " / Vitesse max : " << v.vitesseMax_ << " / Nombre de places : " << v.nbPlaces_ << " / Occupants : " << v.occupants_ << " / Etat : " << v.getEtat() << endl;
    return s;
}

// destructeur
Vehicule::~Vehicule() {
    // Code de nettoyage si nécessaire
}