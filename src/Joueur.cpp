#include "Joueur.h"
#include "Ihm.h"
#include <iostream>

void assignerJoueur(Joueur& joueur, std::string nom, int numero)
{
    joueur.nom    = nom;
    joueur.numero = numero;
    joueur.sommet = 0;
}

bool prendrePickomino(Jeu& jeu, int& scoreJoueur)
{
    if(scoreJoueur < VALEUR_PICKOMINO_MIN || scoreJoueur > VALEUR_PICKOMINO_MAX)
        return false;
    if(jeu.plateau.brochette[scoreJoueur - VALEUR_PICKOMINO_MIN].etat == Pickomino::VISIBLE)
        prendrePickominoBrochette(jeu, scoreJoueur);
    else if(jeu.plateau.brochette[scoreJoueur - VALEUR_PICKOMINO_MIN].etat == Pickomino::PRIS)
    {
        for(unsigned int i = 0; i < jeu.nbJoueurs; i++)
        {
            if(jeu.plateau.joueurActuel == i)
                i++;
            if(estAuSommet(jeu.joueurs[i], scoreJoueur)) {
                picorer(jeu, jeu.joueurs[i], scoreJoueur);
                return true;
            }
                
        }
    }
    return true;
}

bool estAuSommet(Joueur& joueur, int valeurPickomino)
{
    if(joueur.pile[joueur.sommet - 1].valeur == valeurPickomino)
        return true;
    else
        return false;
}

bool prendrePickominoBrochette(Jeu& jeu, int& valeurPickomino)
{
    jeu.joueurs[jeu.plateau.joueurActuel].pile[jeu.joueurs[jeu.plateau.joueurActuel].sommet] =
      jeu.plateau.brochette[valeurPickomino - VALEUR_PICKOMINO_MIN];
    jeu.joueurs[jeu.plateau.joueurActuel].sommet++;
    jeu.plateau.brochette[valeurPickomino - VALEUR_PICKOMINO_MIN].etat = Pickomino::PRIS;
    return true;
}

bool picorer(Jeu& jeu, Joueur cible, int& valeurPickomino)
{
    jeu.joueurs[jeu.plateau.joueurActuel].pile[jeu.joueurs[jeu.plateau.joueurActuel].sommet].valeur = valeurPickomino;
    jeu.joueurs[jeu.plateau.joueurActuel].sommet++;
    std::cout << "AVANT : " << cible.sommet << std::endl;
    cible.sommet--;
    std::cout << "APRES : " << cible.sommet << std::endl;
    return true;
}