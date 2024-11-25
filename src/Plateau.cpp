#include "Plateau.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

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
            desLances[j] = rand() % NB_FACES + UN;
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

int valeurARetenir(int& nombreDes, int (&desLances)[NB_DES], int (&desRetenus)[NB_DES])
{
    std::string valeur;
    std::cin >> valeur;

    int valeurDesARetenir = transformerStringInt(valeur);

    if(!estChoisie(nombreDes, valeurDesARetenir, desRetenus))
    {
        if(verifierValeurExistante(valeurDesARetenir, desLances))
            return valeurDesARetenir;
    }

    std::cout << "Valeur impossible à choisir, choisissez une autre valeur :" << std::endl;
    return valeurARetenir(nombreDes, desLances, desRetenus);
}

void retenirDes(int& nombreDes, int (&desLances)[NB_DES], int (&desRetenus)[NB_DES])
{
    int valeurDesARetenir;
    int sommet = NB_DES - nombreDes;

    valeurDesARetenir = valeurARetenir(nombreDes, desLances, desRetenus);

    for(int i = 0; i < NB_DES; i++)
    {
        if(desLances[i] == valeurDesARetenir)
        {
            desRetenus[sommet] = desLances[i];
            sommet++;
            nombreDes--;
        }
    }
}

bool estChoisie(const int& nombreDes, const int& valeurARetenir, int (&desRetenus)[NB_DES])
{
    if(valeurARetenir < 0 || valeurARetenir > 6)
        return true;

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

int transformerStringInt(std::string valeur)
{
    if(valeur == "V" || valeur == "v")
        return VER;
    else
        return std::stoi(valeur);
}

bool verifierDesLances(int& nombreDes,
                       const int (&deslances)[NB_DES],
                       const int (&desRetenus)[NB_DES])
{
}