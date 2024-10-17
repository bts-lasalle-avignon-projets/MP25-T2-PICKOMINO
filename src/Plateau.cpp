#include "Plateau.h"

void assignerBrochette(Pickomino (&brochette)[NB_PICKOMINOS])
{
    int j = 1;
    int k = 0;

    for(int i = VALEUR_PICKOMINO_MIN; i <= VALEUR_PICKOMINO_MAX; ++i)
    {
        brochette[i - VALEUR_PICKOMINO_MIN] = { i, j, Pickomino::VISIBLE };
        k++;
        if(k == 4)
        {
            j++;
            k = 0;
        }
    }
}

void retournerPickomino(Pickomino (&brochette)[NB_PICKOMINOS], int valeur)
{
    if(valeur >= VALEUR_PICKOMINO_MIN && valeur <= VALEUR_PICKOMINO_MAX)
        brochette[valeur - VALEUR_PICKOMINO_MIN].etat = Pickomino::RETOURNE;
}