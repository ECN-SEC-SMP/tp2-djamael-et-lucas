#include "VoitureAmphibie.hpp"

VoitureAmphibie::VoitureAmphibie(int vitesseVoiture, int vitesseBateau, int nbPlaces, int occupants)
    : Vehicule(vitesseVoiture, nbPlaces, occupants),
      Voiture(vitesseVoiture, nbPlaces, occupants),
      Bateau(vitesseBateau, nbPlaces, occupants),
      vitesseMaxVoiture_(vitesseVoiture),
      vitesseMaxBateau_(vitesseBateau)
{
    std::cout << "Création d'une voiture amphibie !\n";
}

void VoitureAmphibie::afficherInfos() const
{
    std::cout << "=== Infos Voiture Amphibie ===\n";
    std::cout << "Occupants : " << occupants_ << "/" << nbPlaces_ << "\n";
    std::cout << "État : " <<getEtat() << "\n";
    std::cout << "Mode voiture → vitesse max : " << vitesseMaxVoiture_ << "\n";
    std::cout << "Mode bateau  → vitesse max : " << vitesseMaxBateau_ << "\n";
}

// ===== Redéfinition des méthodes virtuelles pour lever l'ambiguïté =====

void VoitureAmphibie::demarrer()
{
    Vehicule::demarrer(); // version unique
    std::cout << "Démarrage de la voiture amphibie !" << std::endl;
}

void VoitureAmphibie::arreter()
{
    Vehicule::arreter();
    std::cout << "Arrêt de la voiture amphibie !" << std::endl;
}

void VoitureAmphibie::accelerer(int increment)
{
    Vehicule::accelerer(increment);
    std::cout << "Voiture amphibie accélère de " << increment << std::endl;
}

void VoitureAmphibie::monter(int nbOcc)
{
    Vehicule::monter(nbOcc);
    std::cout << nbOcc << " personnes montent dans la voiture amphibie" << std::endl;
}

void VoitureAmphibie::descendre(int nbOcc)
{
    Vehicule::descendre(nbOcc);
    std::cout << nbOcc << " personnes descendent de la voiture amphibie" << std::endl;
}

void VoitureAmphibie::mettreEnPanne(double random)
{
    Vehicule::mettreEnPanne(random);
    std::cout << "Voiture amphibie en panne : " << getEtat() << std::endl;
}

void VoitureAmphibie::depanner()
{
    Vehicule::depanner();
    std::cout << "Voiture amphibie dépannée" << std::endl;
}

std::string VoitureAmphibie::getEtat() const
{
    return Vehicule::getEtat();
}