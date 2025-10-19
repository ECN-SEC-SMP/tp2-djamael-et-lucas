//  Voiture.h
//  TP_HM_Exc
//

#pragma once

#include <stdexcept>
#include <iostream>
#include "Vehicule.hpp"

using namespace std;

class Voiture : public virtual Vehicule
{
protected:
    
public:

    Voiture(int vitesseMax=0, int nbPlaces=1, int occupants=0);
    
    void demarrer() override;
    
    void arreter() override;
    
    void depanner() override;

    void accelerer(int increment) override;

    void monter(int nbOcc) override;

    void descendre(int nbOcc) override;

    void mettreEnPanne(double random) override;

    string getEtat() const override;
    
    ~Voiture();

};

