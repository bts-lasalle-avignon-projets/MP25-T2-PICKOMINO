#ifndef JOUEUR_H
#define JOUEUR_H

#include "Donnees.h"

#include <string>

struct Joueur
{
    std::string nom;
    int         numero;
    Pickomino   pile[NB_PICKOMINOS];
    int         sommet;
};

void assignerJoueur(Joueur& joueur, std::string nom, int numero);
bool prendrePickomino(Jeu& jeu, int numJoueur, int valeur);
bool picorer(Joueur& joueur, int& valeur);

#endif