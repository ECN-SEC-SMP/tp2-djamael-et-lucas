#ifndef VOITURE_HPP
#define VOITURE_HPP

#include "Vehicule.hpp"
#include <iostream>

class Voiture : public virtual Vehicule
{
public:
    Voiture(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    void demarrer() override;
    void arreter() override;
    void mettreEnPanne(double random) override;
    ~Voiture() override = default;
};

#endif
