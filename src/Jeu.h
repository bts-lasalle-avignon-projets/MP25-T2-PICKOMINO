#ifndef JEU_H
#define JEU_H

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"

#define SIMULATION

struct Jeu
{
    unsigned int nbJoueurs;
    Joueur       joueurs[NB_JOUEURS_MAX];
    Plateau      plateau;
};

void jouerPickomino();
void initialiserJeu(Jeu& jeu);
void creerJoueurs(Jeu& jeu);
void jouerTour(Jeu& jeu, int nbJoueur);

#endif