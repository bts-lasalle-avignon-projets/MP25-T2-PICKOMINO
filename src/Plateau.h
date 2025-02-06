#ifndef PLATEAU_H
#define PLATEAU_H

#include <string>

#include "Donnees.h"

struct Plateau
{
    Pickomino    brochette[NB_PICKOMINOS];
    unsigned int joueurActuel;
    int          desLances[NB_DES];
    int          desRetenus[NB_DES];
    int          nombreDesRestant;
};


// Fonctions avant partie

void initialiserBrochette(Pickomino (&brochette)[NB_PICKOMINOS]);
void initialiserPlateau(Plateau& plateau, bool initialisationBrochette = false);
void initialiserTableauDes(int (&tableauDes)[NB_DES]);

// Fonctions de partie

bool verifierPresencePickomino(const Plateau& plateau);
bool lancerPossible(const int& nombreDes);
bool estDejaChoisie(const int& nombreDes, const int& valeurARetenir, int (&desRetenus)[NB_DES]);
bool verifierValeurExistante(const int& valeurARetenir, int (&desLances)[NB_DES]);
bool verifierPresenceVers(const int& nombreDes, const int (&desRetenus)[NB_DES]);
bool verifierDesLances(int& nombreDes,
                       const int (&deslances)[NB_DES],
                       const int (&desRetenus)[NB_DES]);
void retournerPickomino(Pickomino (&brochette)[NB_PICKOMINOS], int valeur);
void lancerDes(int& nombreDes, int (&desLances)[NB_DES]);
void retenirDes(Plateau& plateau);

int  calculerScoreTour(int& nombreDes, int (&desRetenus)[NB_DES]);
int  calculerScoreFinalTour(int& nombreDes, int (&desRetenus)[NB_DES]);

#endif // PLATEAU_H