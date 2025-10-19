#include "Vehicule.hpp"
#include <iostream>
#include <stdexcept>

Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
{
    if (vitesseMax < 0)
        throw std::invalid_argument("Vitesse maximale négative !");
    if (nbPlaces <= 0)
        throw std::invalid_argument("Nombre de places invalide !");
    if (occupants < 0 || occupants > nbPlaces)
        throw std::invalid_argument("Nombre d'occupants incohérent !");

    vitesse_ = 0;
    vitesseMax_ = vitesseMax;
    nbPlaces_ = nbPlaces;
    occupants_ = occupants;
    etat_ = ARRET;
}

void Vehicule::demarrer()
{
    if (etat_ == MARCHE)
        throw std::invalid_argument("Le véhicule est déjà en marche !");
    if (etat_ == PANNE_LEGERE || etat_ == PANNE_SEVERE)
        throw std::invalid_argument("Le véhicule est en panne et ne peut pas démarrer !");
    etat_ = MARCHE;
}

void Vehicule::arreter()
{
    vitesse_ = 0;
    etat_ = ARRET;
}

void Vehicule::depanner()
{
    if (etat_ == PANNE_LEGERE || etat_ == PANNE_SEVERE)
        etat_ = ARRET;
}

void Vehicule::accelerer(int increment)
{
    if (etat_ != MARCHE)
        throw std::invalid_argument("Le véhicule doit être en marche pour accélérer !");
    if (vitesse_ + increment > vitesseMax_)
        throw std::invalid_argument("Vitesse maximale atteinte !");
    vitesse_ += increment;
}

void Vehicule::monter(int nbOcc)
{
    if (nbOcc <= 0)
        throw std::invalid_argument("Nombre d'occupants à monter invalide !");
    if (occupants_ + nbOcc > nbPlaces_)
        throw std::invalid_argument("Trop de passagers !");
    occupants_ += nbOcc;
}

void Vehicule::descendre(int nbOcc)
{
    if (nbOcc <= 0 || nbOcc > occupants_)
        throw std::invalid_argument("Pas autant de passagers à descendre !");
    occupants_ -= nbOcc;
}

void Vehicule::mettreEnPanne(double random)
{
    etat_ = (random < 0.5) ? PANNE_LEGERE : PANNE_SEVERE;
    vitesse_ = 0;
}

std::string Vehicule::getEtat() const
{
    switch (etat_)
    {
        case ARRET: return "Arrêt";
        case MARCHE: return "Marche";
        case PANNE_LEGERE: return "Panne légère";
        case PANNE_SEVERE: return "Panne sévère";
        default: return "Inconnu";
    }
}
Vehicule::~Vehicule()
{
    // destructeur vide
}


std::ostream& operator<<(std::ostream& os, const Vehicule& v)
{
    os << "- Vitesse : " << v.vitesse_ << "/" << v.vitesseMax_
       << "\n- Places : " << v.nbPlaces_
       << "\n- Occupants : " << v.occupants_
       << "\n- État : " << v.getEtat() << "\n";
    return os;
}
