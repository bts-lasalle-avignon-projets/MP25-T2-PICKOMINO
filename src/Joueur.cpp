#include "Joueur.h"
#include "Ihm.h"

void assignerJoueur(Joueur& joueur, std::string nom, int numero)
{
    joueur.nom    = nom;
    joueur.numero = numero;
    joueur.sommet = 0;
}

bool prendrePickomino(Jeu& jeu, int& valeurPickomino)
{
    if(jeu.plateau.brochette[valeurPickomino - VALEUR_PICKOMINO_MIN].etat == Pickomino::VISIBLE)
    {
        jeu.joueurs[jeu.plateau.joueurActuel].pile[jeu.joueurs[jeu.plateau.joueurActuel].sommet] =
          jeu.plateau.brochette[valeurPickomino - VALEUR_PICKOMINO_MIN];
        jeu.joueurs[jeu.plateau.joueurActuel].sommet++;
        jeu.plateau.brochette[valeurPickomino - VALEUR_PICKOMINO_MIN].etat = Pickomino::PRIS;
        return true;
    }
    return false;
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