#include "Affichage.h"

// Affichage des dialogues

void afficherMessage(std::string message)
{
    std::cout << message << std::endl;
}

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

// Affichage du plateau
/*
void afficherPileJoueurEnCours()
{

}

void afficherDes()
{

}
*/
void afficherJoueurs(Joueur (&joueurs)[NB_JOUEURS_MAX], int nbJoueurs)
{
    for(int i = 0; i < nbJoueurs; ++i)
    {
        std::cout << "Joueur numéro " << joueurs[i].numero << " :" << joueurs[i].nom << std::endl;
    }
}

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINO])
{
    std::string ligneValeur       = "";
    std::string ligneNombreDeVers = "";

    for(int i = 0; i < NB_PICKOMINO; ++i)
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