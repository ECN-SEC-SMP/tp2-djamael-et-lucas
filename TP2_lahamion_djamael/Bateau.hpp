#ifndef BATEAU_HPP
#define BATEAU_HPP

#include "Vehicule.hpp"
#include <iostream>

class Bateau : public virtual Vehicule
{
public:
    Bateau(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    void demarrer() override;
    void arreter() override;
    void mettreEnPanne(double random) override;
    ~Bateau() override = default;
};

#endif
