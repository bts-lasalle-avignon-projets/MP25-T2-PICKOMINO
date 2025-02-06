#ifndef IA_H
#define IA_H

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"

#define NB_IA_MIN 1
#define NB_IA_MAX 6

#define ATTENTE_IA 4000

enum Difficulte_Ia
{
    AUCUNE = 0,
    FACILE,
    MOYEN,
    DIFFICILE,
};

// Fonctions de partie

void debuterTourIa(Jeu& jeu, int& scoreTour);
void jouerTourIa(Jeu& jeu, int numIa);
int  choisirFaceDifficulteIA(Jeu& jeu);
void retenirDesIa(Jeu& jeu);
int  choisirFaceAleatoireIa(Jeu& jeu);
int  trouverValeurMax(Jeu& jeu);
int  verifierMinPickomino(Jeu& jeu);

#endif // DONNEES_H