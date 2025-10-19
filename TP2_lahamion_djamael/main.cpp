#include "Vehicule.hpp"
#include "Voiture.hpp"
#include "VoitureAmphibie.hpp"
#include "Bateau.hpp"
#include <iostream>
using namespace std;

int main()
{
    srand(time(nullptr)); // initialise le générateur
    double randomValue = static_cast<double>(rand()) / RAND_MAX; // entre 0.0 et 1.0
    cout << "Valeur aléatoire pour la panne: " << randomValue << endl;
    try
    {
        Vehicule v(120, 4, 2);
        cout << v << endl;

        v.demarrer();
        v.accelerer(50);
        cout << v << endl;

        // Provoquer une erreur : dépasser la vitesse max
        v.accelerer(100);
    }
    catch (const invalid_argument& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }

    try
    {
        Vehicule v2(90, 2, 2);
        cout<<v2<<endl;
        cout<<"Descente de tous les passagers"<<endl;
        v2.descendre(2);
        cout<<v2<<endl;
        cout<<"Monté de 4 passagers"<<endl;
        v2.monter(4); // provoque une exception
        cout<<v2<<endl;
    }
    catch (const invalid_argument& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }

    try
    {
        Vehicule v3(100, 4, 1);
        cout<<v3<<endl;
        v3.mettreEnPanne(0.7);
        cout<<v3<<endl;
        v3.demarrer(); // impossible en panne
    }
    catch (const invalid_argument& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }

    try
    {
        Voiture lavoiture(100, 4, 1);
        Bateau lebateau(100, 2, 1);
        lavoiture.demarrer();
        lebateau.demarrer();

        cout<<"Voiture"<<endl<<lavoiture<<endl;
        cout<<"Bateau"<<endl<<lebateau<<endl;

        lavoiture.mettreEnPanne(0.7);
        cout<<"Voiture"<<endl<<lavoiture<<endl;
        cout<<"Bateau"<<endl<<lebateau<<endl;
        lavoiture.demarrer(); // impossible en panne
    }
    catch (const invalid_argument& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }
    
    try
    {
        VoitureAmphibie VA(120, 200, 2, 1);
        VA.afficherInfos();
        VA.descendre(1);
        VA.afficherInfos();
        VA.demarrer();
        Bateau* ModeBateau = dynamic_cast<Bateau*>(&VA);
        Voiture* ModeVoiture = dynamic_cast<Voiture*>(&VA);
        cout<<*ModeBateau<<endl;
        cout<<*ModeVoiture<<endl;

    }
    catch (const invalid_argument& e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}
