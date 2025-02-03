#ifndef IA_H
#define IA_H

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"

#define NB_IA_MIN 1
#define NB_IA_MAX 6

enum Difficulte_Ia
{
    AUCUNE = 0,
    FACILE,
    MOYEN,
    DIFFICILE,
};

void jouerTourIa(Jeu& jeu, int numIa);
void debuterTourIa(Jeu& jeu, int& scoreTour);
int  choisirFaceDifficulteIA(Jeu& jeu);
void retenirDesIa(Jeu& jeu);
int  choisirFaceAleatoireIa(Jeu& jeu);
int  trouverValeurMax(Jeu& jeu);
int  verifierMinPickomino(Jeu& jeu);

#endif