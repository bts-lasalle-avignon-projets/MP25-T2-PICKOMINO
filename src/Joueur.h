#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

#include "Donnees.h"

struct Jeu;

struct Joueur
{
    std::string nom;
    int         age;
    int         numero;
    Pickomino   pile[NB_PICKOMINOS];
    int         sommet;
    int         score;
    bool        estIa;
};

// Fonctions avant partie

void assignerJoueur(Joueur& joueur, std::string nom, int numero, bool estIa, bool consentementAge);
void assignerAge(Joueur& joueur);
int trouverPlusJeune(Jeu& jeu);

// Fonctions de partie

bool prendrePickominoBrochette(Jeu& jeu, int valeurPickomino);
bool prendrePickomino(Jeu& jeu, int scoreJoueur);
bool estAuSommet(Joueur& joueur, int valeurPickomino);
bool picorer(Jeu& jeu, Joueur& cible, int valeurPickomino);
bool aDejaPickomino(Joueur& joueur, int valeurPickomino);


void rendrePickomino(Jeu& jeu);
void retournerDernierPickomino(Pickomino (&brochette)[NB_PICKOMINOS]);
void retournerPickomino(Pickomino& pickomino);
void perdreTour(Jeu& jeu);

#endif // JOUEUR_H