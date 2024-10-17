#ifndef PLATEAU_H
#define PLATEAU_H

#include "Donnees.h"

struct Plateau
{
    int       desRetenus[NB_DES];
    int       joueurActuel;
    int       totalDes;
    Pickomino brochette[NB_PICKOMINOS];
};

void retournerPickomino(Pickomino (&brochette)[NB_PICKOMINOS], int valeur);
void assignerBrochette(Pickomino (&brochette)[NB_PICKOMINOS]);

#endif
