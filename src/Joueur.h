#ifndef JOUEUR_H
#define JOUEUR_H

#include "Donnees.h"
#include <string>

struct Jeu;

struct Joueur
{
    std::string nom;
    int         numero;
    Pickomino   pile[NB_PICKOMINOS];
    int         sommet;
    int         score;
};

void assignerJoueur(Joueur& joueur, std::string nom, int numero);
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