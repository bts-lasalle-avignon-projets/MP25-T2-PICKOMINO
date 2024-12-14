#ifndef DONNEES_H
#define DONNEES_H

#define NB_JOUEURS_MIN 2
#define NB_JOUEURS_MAX 7

#define NB_DES   8
#define NB_FACES 6

#define NB_PICKOMINOS        16
#define VALEUR_PICKOMINO_MIN 21
#define VALEUR_PICKOMINO_MAX 36

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

#endif // DONNEES_H