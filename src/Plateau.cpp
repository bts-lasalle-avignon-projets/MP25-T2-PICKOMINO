#include "Plateau.h"

void assignerBrochette()
{
    int       j = 1;
    int       k = 0;
    Pickomino brochette[NB_PICKOMINO];

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