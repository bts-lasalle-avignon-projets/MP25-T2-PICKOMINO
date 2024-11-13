#include "Plateau.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

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

void lancerDes(int& nombreDes, int (&desLances)[NB_DES])
{
    reinitialiserPlateau(desLances);
    if(nombreDes > 0)
    {
        int j = 0;
        srand(time(NULL));

        for(int i = 0; i < nombreDes; i++)
        {
            desLances[j] = rand() % 6 + 1;
            j++;
        }
    }
}

void reinitialiserPlateau(int (&desLances)[NB_DES])
{
    for(int i = 0; i < NB_DES; i++)
    {
        desLances[i] = 0;
    }
}

int valeurARetenir()
{
    std::string valeur;
    std::cin >> valeur;
    if(valeur == "V" || valeur == "v")
        return (6);
    return (std::stoi(valeur));
}

void retenirDes(int& nombreDes, int (&desLances)[NB_DES], int (&desRetenus)[NB_DES])
{
    int valeurDesARetenir;
    int sommet = NB_DES - nombreDes;

    valeurDesARetenir = valeurARetenir();

    if(!estChoisie(nombreDes, valeurDesARetenir, desRetenus))
    {
        for(int i = 0; i < NB_DES; i++)
        {
            if(desLances[i] == valeurDesARetenir && nombreDes > 0)
            {
                desRetenus[sommet] = desLances[i];
                sommet++;
                nombreDes--;
            }
        }
    }
}

bool estChoisie(const int& nombreDes, const int& valeurARetenir, int (&desRetenus)[NB_DES])
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
        if(desRetenus[i] == 6)
            scoreTotal += 5;
        else
            scoreTotal += desRetenus[i];
    }
    return scoreTotal;
}

bool lancerPossible(int& nombreDes)
{
    if(nombreDes == 0)
    {
        return false;
    }
    else if(nombreDes > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}