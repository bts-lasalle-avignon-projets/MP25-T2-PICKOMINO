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

void jouerPickominoIa();
void initialiserJeuIa(Jeu& jeu);
bool parcourirBrochetteIa(Plateau& plateau);
int  choisirFaceIa(Jeu& jeu);
int  choisirFaceAleatoireIa(Plateau& plateau);

#endif