#ifndef PLATEAU_H
#define PLATEAU_H

#include "Donnees.h"
#include <string>

struct Plateau
{
    Pickomino brochette[NB_PICKOMINOS];
    int       joueurActuel;
    int       desLances[NB_DES];
    int       desRetenus[NB_DES];
    int       nombreDes = NB_DES;
};

void retournerPickomino(Pickomino (&brochette)[NB_PICKOMINOS], int valeur);
void assignerBrochette(Pickomino (&brochette)[NB_PICKOMINOS]);
void lancerDes(int& nombreDes, int (&desLances)[NB_DES]);
void reinitialiserPlateau(int (&desLances)[NB_DES]);
int  calculerScoreTour(int& nombreDes, int (&desRetenus)[NB_DES]);
void retenirDes(int& nombreDes, int (&desLances)[NB_DES], int (&desRetenus)[NB_DES]);
bool lancerPossible(const int& nombreDes);
bool estChoisie(const int& nombreDes, const int& valeurARetenir, int (&desRetenus)[NB_DES]);
bool verifierValeurExistante(const int& valeurARetenir, int (&desLances)[NB_DES]);
int  stringToInt(std::string valeur);
bool verifierPresenceVers(const int& nombreDes, const int (&desRetenus)[NB_DES]);
int  calculerScoreFinalTour(int& nombreDes, int (&desRetenus)[NB_DES]);
bool verifierDesLances(int& nombreDes,
                       const int (&deslances)[NB_DES],
                       const int (&desRetenus)[NB_DES]);

#endif
