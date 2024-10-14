#ifndef PLATEAU_H
#define PLATEAU_H

#include "Donnees.h"

void assignerBrochette();

enum Face
{
    UN = 1,
    DEUX,
    TROIS,
    QUATRE,
    CINQ,
    VER = 6
};

struct Pickomino
{
    int valeur;
    int nombreDeVers;
    enum Etat
    {
        VISIBLE,
        RETOURNE,
        PRIS
    } etat;
};

struct Plateau
{
    int       desRetenus[8];
    int       JoueurActuel;
    int       totalDes;
    Pickomino brochette[NB_PICKOMINO];
};

#endif