#ifndef JOUEUR_H
#define JOUEUR_H

#include "Donnees.h"

#include <string>

struct Joueur
{
    std::string nom;
    int         numero;
    int         pile[NB_PICKOMINO];
    int         sommet;
};

extern Joueur joueurs[NB_JOUEURS_MAX];

void assignerJoueur(Joueur& joueur, std::string nom, int numero);
void prendrePickomino(Joueur& joueur, Pickomino (&brochette)[NB_PICKOMINO], int valeur);
void picorer(Joueur& attaquant, Joueur& cible);

#endif