#include "Ihm.h"

#include <iostream>

// Affichage des dialogues

/*
void afficherInstructions()
{

}

void afficherOptionsDeJeu()
{

}

void afficherTourJoueur(Joueur joueur)
{

}

void afficherScores()
{

}

void afficherVainqueur()
{

}
*/

// Affichage de jeu

/*
void afficherPileJoueurEnCours()
{

}

void afficherDes()
{

}
*/

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS])
{
    std::string ligneValeur;
    std::string ligneNombreDeVers;

    // afficherMessage("Brochette :");

    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(brochette[i].etat == Pickomino::VISIBLE)
        {
            ligneValeur += std::to_string(brochette[i].valeur) + " ";
            ligneNombreDeVers += std::to_string(brochette[i].nombreDeVers) + "  ";
        }
        else if(brochette[i].etat == Pickomino::RETOURNE)
        {
            ligneValeur += "X  ";
            ligneNombreDeVers += "X  ";
        }
    }

    std::cout << ligneValeur << std::endl;
    std::cout << ligneNombreDeVers << std::endl;
}

void afficherJoueurs(Jeu& jeu)
{
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        std::cout << "Joueur " << jeu.joueurs[i].numero << " : " << jeu.joueurs[i].nom << std::endl;
    }
}

// Saisies

unsigned int saisirNbJoueurs()
{
    unsigned int nbJoueurs = 0;

    do
    {
        afficherMessage("Entrez le nombre de joueurs : ", false);
        std::cin >> nbJoueurs;
    } while(nbJoueurs < NB_JOUEURS_MIN || nbJoueurs > NB_JOUEURS_MAX);

    return nbJoueurs;
}

std::string saisirNomJoueur()
{
    std::string nomJoueur;

    do
    {
        std::cin >> nomJoueur;
    } while(nomJoueur.empty());

    return nomJoueur;
}

// Utilitaires

void afficherMessage(const std::string& message, bool nouvelleLigne /*= true*/)
{
    std::cout << message;
    if(nouvelleLigne)
        std::cout << std::endl;
}
