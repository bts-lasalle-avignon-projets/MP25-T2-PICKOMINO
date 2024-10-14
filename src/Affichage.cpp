#include "Affichage.h"
#include "Plateau.h"


//Affichage des dialogues
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

//Affichage du plateau
/*
void afficherPileJoueurEnCours()
{

}

void afficherDes()
{

}
*/
void afficherBrochette(Pickomino brochette[NB_PICKOMINO]){
    for (int i = 0; i < NB_PICKOMINO; ++i)
    {
        if (brochette[i].etat == 0)
        {
            std::cout << brochette[i].valeur 
                      << brochette[i].nombreDeVers
                      << std::endl;
        }
        else if (brochette[i].etat == 1)
            std::cout << 'X';
    }
}