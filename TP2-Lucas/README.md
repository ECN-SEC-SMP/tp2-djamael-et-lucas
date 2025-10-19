# 🚗🚤 TP2 - Héritage multiple et exceptions en C++

## 🎯 Objectif

**CPP TP2 – héritage multiple et de la création d’exceptions**
L’objectif principal est de mettre en pratique :
- la **programmation orientée objet** avec héritage simple et multiple ;
- la **gestion d’exceptions C++** (`invalid_argument`, `logic_error`) ;

---

## 🧩 Structure du projet

TP2_LUCAS/
├── Vehicule.hpp
├── Vehicule.cpp
├── Voiture.hpp
├── Voiture.cpp
├── Bateau.hpp
├── Bateau.cpp
├── VoitureAmphibie.hpp
├── VoitureAmphibie.cpp
├── main.cpp
├── Makefile
├── log.txt
├── Compte-rendu - TP2 - CPP.pdf
└── README.md


---

## 🚙 Classes principales

### `Vehicule`
Classe de base abstraite représentant un véhicule générique.  
Elle définit les attributs communs (`vitesse`, `etat`, `nbPlaces`, etc.) et les **méthodes virtuelles** de contrôle :
- `demarrer()`, `arreter()`, `accelerer()`, `mettreEnPanne()`, etc.
- Gestion d’exceptions dans les cas incohérents (vitesse négative, véhicule plein, etc.)

### `Voiture` et `Bateau`
Sous-classes héritant virtuellement de `Vehicule`.  
Elles redéfinissent les méthodes pour afficher un message spécifique :
- `Démarrage d'une voiture`, `Arrêt d'une voiture`, etc.
- et modifient les attributs (`etat_`, `vitesse_`) après validation.

### `VoitureAmphibie`
Classe héritant **à la fois de `Voiture` et `Bateau`**.  
Elle résout le problème du **d’héritage** grâce à l’héritage virtuel.  
Elle introduit trois nouveaux attributs :
```cpp
bool mode_;               // false = voiture, true = bateau
int vitesseMaxVoiture_;
int vitesseMaxBateau_;
et une méthode spécifique :
void changerMode(bool bateau); // Permet de basculer entre les deux modes

---

## Tests

Trois fonctions de test sont définies dans le main.cpp :

Voiture_test()

Bateau_test()

VoitureAmphibie_test()

Elles permettent de :

- vérifier la levée correcte des exceptions (logic_error, invalid_argument) ;

- simuler les différentes étapes d’utilisation : démarrage, accélération, panne, dépannage, etc. ;

- et valider le passage de mode voiture ↔ bateau dans la classe VoitureAmphibie.


## Auteur

Tp - Lucas Oros
Centrale Nantes, SEC 2027