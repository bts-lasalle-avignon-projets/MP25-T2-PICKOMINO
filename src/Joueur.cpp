#include "Joueur.h"

void assignerJoueur(Joueur& joueur, std::string nom, int numero)
{
    joueur.nom    = nom;
    joueur.numero = numero;
    joueur.sommet = 0;
}

bool prendrePickomino(Joueur& joueur, Pickomino (&brochette)[NB_PICKOMINOS], int valeur)
{
    brochette[valeur - VALEUR_PICKOMINO_MIN].etat = Pickomino::PRIS;
    if(joueur.sommet == NB_PICKOMINOS)
    {
        return false;
    }
    joueur.pile[joueur.sommet] = brochette[valeur - VALEUR_PICKOMINO_MIN];
    joueur.sommet++;
    return true;
}

bool picorer(Joueur& joueur, int& valeur)
{
    if(joueur.sommet == 0)
    {
        return false;
    }
    valeur = joueur.pile[joueur.sommet - 1].valeur;
    --joueur.sommet;
    return true;
}