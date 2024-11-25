#ifndef PLATEAU_H
#define PLATEAU_H

#include "Donnees.h"
#include <string>

struct Plateau
{
    int       desRetenus[NB_DES];
    int       joueurActuel;
    int       totalDes;
    Pickomino brochette[NB_PICKOMINOS];
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
int  transformerStringInt(std::string valeur);

#endif
