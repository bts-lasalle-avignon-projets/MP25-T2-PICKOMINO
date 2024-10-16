#ifndef JEU_H
#define JEU_H

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"

#define SIMULATION_NB_JOUEURS 0 // Deux joueurs

struct Jeu
{
    unsigned int nbJoueurs;
    Joueur       joueurs[NB_JOUEURS_MAX];
    Plateau      plateau;
};

void jouerPickomino();
void initialiserJeu(Jeu& jeu);
void creerJoueurs(Jeu& jeu);
void assignerJoueurs(int nbJoueurs);

#endif