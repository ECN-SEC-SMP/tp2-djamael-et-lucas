#ifndef VOITURE_AMPHIBIE_HPP
#define VOITURE_AMPHIBIE_HPP

#include "Voiture.hpp"
#include "Bateau.hpp"
#include <iostream>

class VoitureAmphibie :  public Voiture, public Bateau
{
    int vitesseMaxVoiture_;
    int vitesseMaxBateau_;

public:
    VoitureAmphibie(int vitesseVoiture = 120, int vitesseBateau = 50, int nbPlaces = 2, int occupants = 1);
    ~VoitureAmphibie() override = default;
    
    // Redéfinir explicitement les fonctions virtuelles
    void demarrer() override;
    void arreter() override;
    void accelerer(int increment) override;
    void monter(int nbOcc) override;
    void descendre(int nbOcc) override;
    void mettreEnPanne(double random) override;
    void depanner() override;
    string getEtat() const override;

    void afficherInfos() const;
};

#endif
