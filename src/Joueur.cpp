#include "Joueur.h"

void creerJoueurs(int nbJoueurs)
{
    std::string nomJoueur;
    for(int i = 0; i < nbJoueurs; ++i)
    {
        nomJoueur = "Joueur" + std::to_string(nbJoueurs);
        Joueur nomJoueur;
    }
}

void assignerJoueur(Joueur joueur, std::string nom, int numero)
{
    joueur.nom    = nom;
    joueur.numero = numero;
    joueur.sommet = -1;

    for(int i = 0; i <= NB_PICKOMINO; ++i)
        joueur.pile[i] = 0;
}

void prendrePickomino(Joueur& joueur, Pickomino (&brochette)[NB_PICKOMINO], int valeur)
{
    brochette[valeur - VALEUR_PICKOMINO_MIN].etat = Pickomino::PRIS;
    joueur.sommet++;
    joueur.pile[joueur.sommet] = valeur;
}

void picorer(Joueur& attaquant, Joueur& cible)
{
    attaquant.sommet++;
    attaquant.pile[attaquant.sommet] = cible.pile[cible.sommet];
    cible.sommet--;
}