//  VoitureAmphibie.h
//  TP_HM_Exc
//

#pragma once

#include <stdexcept>
#include <iostream>
#include "Voiture.hpp"
#include "Bateau.hpp"

using namespace std;

class VoitureAmphibie : public Voiture, public Bateau
{
protected:
    bool mode_; // false = mode voiture, true = mode bateau
    int vitesseMaxVoiture_;
    int vitesseMaxBateau_;
    
public:

    VoitureAmphibie(int vitesseVoiture, int vitesseBateau, int nbPlaces, int occupants);

    void demarrer() override;

    void arreter() override;
    
    void depanner() override;

    void accelerer(int increment) override;

    void monter(int nbOcc) override;

    void descendre(int nbOcc) override;

    void mettreEnPanne(double random) override;

    string getEtat() const override;

    void afficher_caracteristiques() const;

    void changerMode(bool bateau); // true = mode bateau, false = mode voiture
    
    ~VoitureAmphibie();
};

