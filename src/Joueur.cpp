#include "Joueur.h"
#include "Ihm.h"

void assignerJoueur(Joueur& joueur, std::string nom, int numero)
{
    joueur.nom    = nom;
    joueur.numero = numero;
    joueur.sommet = 0;
}

bool prendrePickomino(Jeu& jeu, int scoreJoueur)
{
    if(scoreJoueur < VALEUR_PICKOMINO_MIN || scoreJoueur > VALEUR_PICKOMINO_MAX)
    {
        afficherMessage("Vous ne pouvez prendre aucun pickomino !", true);
        return false;
    }
    if(aDejaPickomino(jeu.joueurs[jeu.plateau.joueurActuel], scoreJoueur))
    {
        scoreJoueur--;
        prendrePickomino(jeu, scoreJoueur);
        return true;
    }
    if(scoreJoueur >= VALEUR_PICKOMINO_MIN && scoreJoueur <= VALEUR_PICKOMINO_MAX &&
       jeu.plateau.brochette[scoreJoueur - VALEUR_PICKOMINO_MIN].etat == Pickomino::VISIBLE)
    {
        prendrePickominoBrochette(jeu, scoreJoueur);
        return true;
    }
    else if(jeu.plateau.brochette[scoreJoueur - VALEUR_PICKOMINO_MIN].etat == Pickomino::PRIS)
    {
        for(unsigned int i = 0; i < jeu.nbJoueurs; i++)
        {
            if(jeu.plateau.joueurActuel == i)
                i++;
            if(estAuSommet(jeu.joueurs[i], scoreJoueur))
            {
                picorer(jeu, jeu.joueurs[i], scoreJoueur);
                return true;
            }
        }
    }
    scoreJoueur--;
    prendrePickomino(jeu, scoreJoueur);
    return true;
}

void perdreTour(Jeu& jeu)
{
    rendrePickomino(jeu);
    retournerDernierPickomino(jeu.plateau.brochette);
}

void rendrePickomino(Jeu& jeu)
{
    if(jeu.joueurs[jeu.plateau.joueurActuel].sommet > 0)
    {
        jeu.plateau
          .brochette[jeu.joueurs[jeu.plateau.joueurActuel]
                       .pile[jeu.joueurs[jeu.plateau.joueurActuel].sommet - 1]
                       .valeur -
                     VALEUR_PICKOMINO_MIN]
          .etat = Pickomino::VISIBLE;
        jeu.joueurs[jeu.plateau.joueurActuel].sommet--;
    }
}

void retournerDernierPickomino(Pickomino (&brochette)[NB_PICKOMINOS])
{
    for(int i = NB_PICKOMINOS; i >= 0; i--)
    {
        if(brochette[i - 1].etat == Pickomino::VISIBLE)
        {
            retournerPickomino(brochette[i - 1]);
            return;
        }
    }
}

void retournerPickomino(Pickomino& pickomino)
{
    pickomino.etat = Pickomino::RETOURNE;
}

bool aDejaPickomino(Joueur& joueur, int valeurPickomino)
{
    for(int i = joueur.sommet - 1; i >= 0; i--)
    {
        if(joueur.pile[i].valeur == valeurPickomino)
            return true;
    }
    return false;
}

bool estAuSommet(Joueur& joueur, int valeurPickomino)
{
    if(joueur.pile[joueur.sommet - 1].valeur == valeurPickomino)
        return true;
    else
        return false;
}

bool prendrePickominoBrochette(Jeu& jeu, int valeurPickomino)
{
    jeu.joueurs[jeu.plateau.joueurActuel].pile[jeu.joueurs[jeu.plateau.joueurActuel].sommet] =
      jeu.plateau.brochette[valeurPickomino - VALEUR_PICKOMINO_MIN];
    jeu.joueurs[jeu.plateau.joueurActuel].sommet++;
    jeu.plateau.brochette[valeurPickomino - VALEUR_PICKOMINO_MIN].etat = Pickomino::PRIS;
    return true;
}

bool picorer(Jeu& jeu, Joueur& cible, int valeurPickomino)
{
    jeu.joueurs[jeu.plateau.joueurActuel]
      .pile[jeu.joueurs[jeu.plateau.joueurActuel].sommet]
      .valeur = valeurPickomino;
    jeu.joueurs[jeu.plateau.joueurActuel].sommet++;
    cible.sommet--;
    return true;
}