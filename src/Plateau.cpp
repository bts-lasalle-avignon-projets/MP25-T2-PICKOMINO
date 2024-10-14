#include "Plateau.h"

void assignerBrochette(Pickomino brochette[NB_PICKOMINO])
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