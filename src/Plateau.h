#ifndef PLATEAU_H
#define PLATEAU_H

#include "Donnees.h"
#include <string>

struct Plateau
{
    Pickomino    brochette[NB_PICKOMINOS];
    unsigned int joueurActuel;
    int          desLances[NB_DES];
    int          desRetenus[NB_DES];
    int          nombreDesRestant;
};

void retournerPickomino(Pickomino (&brochette)[NB_PICKOMINOS], int valeur);
void initialiserBrochette(Pickomino (&brochette)[NB_PICKOMINOS]);
bool verifierPresencePickomino(const Plateau& plateau);
void lancerDes(int& nombreDes, int (&desLances)[NB_DES]);
void initialiserTableauDes(int (&tableauDes)[NB_DES]);
int  calculerScoreTour(int& nombreDes, int (&desRetenus)[NB_DES]);
void retenirDes(Plateau& plateau);
bool lancerPossible(const int& nombreDes);
bool estDejaChoisie(const int& nombreDes, const int& valeurARetenir, int (&desRetenus)[NB_DES]);
bool verifierValeurExistante(const int& valeurARetenir, int (&desLances)[NB_DES]);
bool verifierPresenceVers(const int& nombreDes, const int (&desRetenus)[NB_DES]);
int  calculerScoreFinalTour(int& nombreDes, int (&desRetenus)[NB_DES]);
bool verifierDesLances(int& nombreDes,
                       const int (&deslances)[NB_DES],
                       const int (&desRetenus)[NB_DES]);

#endif