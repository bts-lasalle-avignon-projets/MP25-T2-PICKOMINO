#ifndef DONNEES_H
#define DONNEES_H

#include <vector>

#define NB_JOUEURS_MIN 2
#define NB_JOUEURS_MAX 7

#define NB_DES 8
#define NB_FACES 6

const int FACES[NB_FACES] = {1, 2, 3, 4, 5, 6};

#define NB_PICKOMINO 16
#define VALEUR_PICKOMINO_MIN 21
#define VALEUR_PICKOMINO_MAX 36
//const  VALEURS_PICKOMINOS = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
//const  NOMBRE_DE_VERS = {1, 2, 3, 4};

struct Pickomino {
    int valeur;
    int nombreDeVers;
    enum Etat {
        VISIBLE,
        RETOURNE,
        PRIS
    };
};

const Pickomino PICKOMINOS[NB_PICKOMINO] = {
    {21, 1},
    {22, 1},
    {23, 1},
    {24, 1},
    {25, 2},
    {26, 2},
    {27, 2},
    {28, 2},
    {29, 3},
    {30, 3},
    {31, 3},
    {32, 3},
    {33, 4},
    {34, 4},
    {35, 4},
    {36, 4}
};

#endif