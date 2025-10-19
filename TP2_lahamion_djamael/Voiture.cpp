#include "Voiture.hpp"

Voiture::Voiture(int vitesseMax, int nbPlaces, int occupants)
    : Vehicule(vitesseMax, nbPlaces, occupants)
{
    std::cout << "Création d'une voiture (" << nbPlaces << " places)\n";
}

void Voiture::demarrer()
{
    Vehicule::demarrer();
    std::cout << "> La voiture démarre.\n";
}

void Voiture::arreter()
{
    std::cout << "> La voiture s'arrête.\n";
    Vehicule::arreter();
}

void Voiture::mettreEnPanne(double random)
{
    Vehicule::mettreEnPanne(random);
    std::cout << "> La voiture tombe en panne (" << getEtat() << ").\n";
}
