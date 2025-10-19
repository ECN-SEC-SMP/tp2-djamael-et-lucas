/* Class VoitureAmphibie */

//#include <stdio.h>
#include <iostream>
#include "VoitureAmphibie.hpp"

using namespace std;

VoitureAmphibie::VoitureAmphibie(int vitesseVoiture, int vitesseBateau, int nbPlaces, int occupants)
    : Vehicule(vitesseVoiture, nbPlaces, occupants),   // on démarre en mode voiture
      Voiture(vitesseVoiture, nbPlaces, occupants),
      Bateau(vitesseBateau, nbPlaces, occupants),
      vitesseMaxVoiture_(vitesseVoiture),
      vitesseMaxBateau_(vitesseBateau),
      mode_(false)
{
    cout << "Constructeur de la classe VoitureAmphibie" << endl;
}

void VoitureAmphibie::demarrer() {
    cout << "Démarrage d'une voiture amphibie" << endl;
    // Exemple : on choisit de se comporter comme une voiture au sol
    Voiture::demarrer();
}

void VoitureAmphibie::arreter() {
    cout << "Arrêt d'une voiture amphibie" << endl;
    Voiture::arreter();
}

void VoitureAmphibie::depanner() {
    cout << "Dépannage d'une voiture amphibie" << endl;
    Voiture::depanner();
}

void VoitureAmphibie::accelerer(int increment) {
    cout << "Accélération d'une voiture amphibie de " << increment << endl;

    int vmax = mode_ ? vitesseMaxBateau_ : vitesseMaxVoiture_;
    if (vitesse_ + increment > vmax)
        throw logic_error("Le véhicule est déjà à la vitesse maximale");

    vitesse_ += increment;
}

void VoitureAmphibie::monter(int nbOcc) {
    cout << "Montée de " << nbOcc << " occupants dans une voiture amphibie" << endl;
    Voiture::monter(nbOcc);
}

void VoitureAmphibie::descendre(int nbOcc) {
    cout << "Descente de " << nbOcc << " occupants d'une voiture amphibie" << endl;
    Voiture::descendre(nbOcc);
}

void VoitureAmphibie::mettreEnPanne(double random) {
    cout << "Mise en panne d'une voiture amphibie" << endl;
    Voiture::mettreEnPanne(random);
}

string VoitureAmphibie::getEtat() const {
    // On peut choisir d'appeler la version de Voiture ou de Bateau
    // Ici, on choisit celle de Voiture
    return Vehicule::getEtat();
}


void VoitureAmphibie::afficher_caracteristiques() const {
    cout << "=== VoitureAmphibie ===" << endl;
    cout << "Vitesse max en mode voiture : " << vitesseMaxVoiture_ << endl;
    cout << "Vitesse max en mode bateau  : " << vitesseMaxBateau_ << endl;
    cout << "Nombre de places : " << nbPlaces_ << endl;
    cout << "Occupants : " << occupants_ << endl;
    cout << "Etat : " << getEtat() << endl;
}

void VoitureAmphibie::changerMode(bool bateau) {
    mode_ = bateau;
    if (mode_) {
        cout << "Passage en mode BATEAU" << endl;
        vitesseMax_ = vitesseMaxBateau_;
    } else {
        cout << "Passage en mode VOITURE" << endl;
        vitesseMax_ = vitesseMaxVoiture_;
    }
    vitesse_ = 0;
    etat_ = ARRET;
}

VoitureAmphibie::~VoitureAmphibie() {
    cout << "Destructeur de la classe VoitureAmphibie" << endl;
}
