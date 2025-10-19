#include "Bateau.hpp"

Bateau::Bateau(int vitesseMax, int nbPlaces, int occupants)
    : Vehicule(vitesseMax, nbPlaces, occupants)
{
    std::cout << "Création d'un bateau (" << nbPlaces << " places)\n";
}

void Bateau::demarrer()
{
    Vehicule::demarrer();
    std::cout << "> Le bateau démarre.\n";
}

void Bateau::arreter()
{
    std::cout << "> Le bateau s'arrête.\n";
    Vehicule::arreter();
}

void Bateau::mettreEnPanne(double random)
{
    Vehicule::mettreEnPanne(random);
    std::cout << "> Le bateau tombe en panne (" << getEtat() << ").\n";
}
