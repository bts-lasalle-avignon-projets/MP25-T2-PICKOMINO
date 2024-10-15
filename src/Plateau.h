#ifndef PLATEAU_H
#define PLATEAU_H

#include "Donnees.h"

struct Plateau
{
    int       desRetenus[NB_DES];
    int       JoueurActuel;
    int       totalDes;
    Pickomino brochette[NB_PICKOMINO];
};

void assignerBrochette(Pickomino brochette[NB_PICKOMINO]);
void retournerPickomino(Pickomino (&brochette)[NB_PICKOMINO], int valeur);

#endif
