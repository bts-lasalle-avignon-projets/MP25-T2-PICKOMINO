#include "Joueur.h"
#include "Ihm.h"

void assignerJoueur(Joueur& joueur, std::string nom, int numero)
{
    joueur.nom    = nom;
    joueur.numero = numero;
    joueur.sommet = 0;
}
/*
bool prendrePickomino(Jeu& jeu, int numJoueur, int valeur)
{
    if(jeu.plateau.brochette[valeur - VALEUR_PICKOMINO_MIN].etat == Pickomino::VISIBLE)
    {
        jeu.joueurs[numJoueur].pile[jeu.joueurs[numJoueur].sommet] =
          jeu.plateau.brochette[valeur - VALEUR_PICKOMINO_MIN];
        jeu.plateau.brochette[valeur - VALEUR_PICKOMINO_MIN].etat = Pickomino::PRIS;
        jeu.joueurs[numJoueur].sommet++;
        return true;
    }
    else if(jeu.plateau.brochette[valeur - VALEUR_PICKOMINO_MIN].etat == Pickomino::PRIS)
    {
        for(unsigned int i = 0; i < jeu.nbJoueurs;)
            for(int i = valeur; i >= VALEUR_PICKOMINO_MIN; i--)
            {
                if(brochette[i - VALEUR_PICKOMINO_MIN].etat == Pickomino::RETOURNE)
                {
                    afficherMessage("Vous ne pouvez prendre aucun pickomino :(");
                    return false;
                }
            }
    }
}
*/
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