#include "Jeu.h"
#include "Donnees.h"
#include "Affichage.h"
#include "Plateau.h"
#include "Joueur.h"

void assignerJoueurs(int nbJoueurs)
{
    std::string nomJoueur = "";

    for(int i = 0; i < nbJoueurs; ++i)
    {
        afficherMessage("Inscrivez le nom du joueur");
        std::cin >> nomJoueur;
        assignerJoueur(joueurs[i], nomJoueur, i);
    }
}

void jouerPickomino()
{
}
