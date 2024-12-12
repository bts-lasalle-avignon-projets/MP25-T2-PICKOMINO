#include "Plateau.h"
#include "Ihm.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

void initialiserBrochette(Pickomino (&brochette)[NB_PICKOMINOS])
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

bool verifierPresencePickomino(const Plateau& plateau)
{
    for(int i = 0; i < NB_PICKOMINOS; i++)
    {
        if(plateau.brochette[i].etat == Pickomino::VISIBLE)
            return true;
    }
    return false;
}

void lancerDes(int& nombreDes, int (&desLances)[NB_DES])
{
    initialiserTableauDes(desLances);
    if(nombreDes > 0)
    {
        int j = 0;
        srand(time(NULL));

        for(int i = 0; i < nombreDes; i++)
        {
            desLances[j] = rand() % NB_FACES + UN;
            j++;
        }
    }
}

void initialiserTableauDes(int (&tableauDes)[NB_DES])
{
    for(int i = 0; i < NB_DES; i++)
    {
        tableauDes[i] = 0;
    }
}

void retenirDes(Plateau& plateau)
{
    int  valeurDesARetenir;
    int  sommet       = NB_DES - plateau.nombreDesRestant;
    bool saisieValide = false;

    do
    {
        afficherMessage(
          "Quels dés souhaitez-vous retenir ? (Entrez un nombre ou 'V' pour retenir les vers)");
        valeurDesARetenir = saisirValeurARetenir();
        if(!estDejaChoisie(plateau.nombreDesRestant, valeurDesARetenir, plateau.desRetenus) &&
           verifierValeurExistante(valeurDesARetenir, plateau.desLances))
        {
            saisieValide = true;
        }
        else
        {
            afficherMessage("Valeur impossible à retenir !", true);
        }
    } while(!saisieValide);

    for(int i = 0; i < NB_DES; i++)
    {
        if(plateau.desLances[i] == valeurDesARetenir)
        {
            plateau.desRetenus[sommet] = plateau.desLances[i];
            sommet++;
            plateau.nombreDesRestant--;
        }
    }
}

bool estDejaChoisie(const int& nombreDes, const int& valeurARetenir, int (&desRetenus)[NB_DES])
{
    for(int i = 0; i < NB_DES - nombreDes; i++)
    {
        if(desRetenus[i] == valeurARetenir)
        {
            return true;
        }
    }
    return false;
}

int calculerScoreTour(int& nombreDes, int (&desRetenus)[NB_DES])
{
    int scoreTotal = 0;
    for(int i = 0; i < NB_DES - nombreDes; i++)
    {
        if(desRetenus[i] == VER)
            scoreTotal += CINQ;
        else
            scoreTotal += desRetenus[i];
    }
    return scoreTotal;
}

int calculerScoreFinalTour(int& nombreDes, int (&desRetenus)[NB_DES])
{
    int scoreTotalTour = 0;
    if(verifierPresenceVers(nombreDes, desRetenus))
    {
        scoreTotalTour = calculerScoreTour(nombreDes, desRetenus);
    }
    else
        scoreTotalTour = 0;

    return scoreTotalTour;
}

bool lancerPossible(const int& nombreDes)
{
    if(nombreDes == 0)
        return false;
    else if(nombreDes > 0)
        return true;
    else
        return false;
}

bool verifierValeurExistante(const int& valeurARetenir, int (&desLances)[NB_DES])
{
    for(int i = 0; i < NB_DES; i++)
    {
        if(desLances[i] == valeurARetenir)
            return true;
    }
    return false;
}

bool verifierPresenceVers(const int& nombreDes, const int (&desRetenus)[NB_DES])
{
    for(int i = 0; i < NB_DES; i++)
    {
        if(desRetenus[i] == VER)
            return true;
    }
    return false;
}

bool verifierDesLances(int& nombreDes,
                       const int (&desLances)[NB_DES],
                       const int (&desRetenus)[NB_DES])
{
    for(int i = 0; i < nombreDes; ++i)
    {
        bool valeurDejaRetenue = false;
        for(int j = 0; j < NB_DES; ++j)
        {
            if(desLances[i] == desRetenus[j])
            {
                valeurDejaRetenue = true;
                break;
            }
        }
        if(!valeurDejaRetenue)
        {
            return false;
        }
    }
    return true;
}