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
};

void assignerJoueur(Joueur& joueur, std::string nom, int numero);
bool prendrePickominoBrochette(Jeu& jeu, int& valeurPickomino);
void prendrePickomino(Jeu& jeu, int& scoreJoueur);
bool estAuSommet(Joueur& joueur, int valeurPickomino);
bool picorer(Jeu& jeu, Joueur cible, int& valeurPickomino);

#endif