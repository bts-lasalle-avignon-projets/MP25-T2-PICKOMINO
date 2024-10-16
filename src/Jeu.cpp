#include "Jeu.h"
#include "Affichage.h"
#include "Plateau.h"
#include "Joueur.h"
#include <iostream>

void jouerPickomino()
{
    Jeu jeu;

    initialiserJeu(jeu);
}

void assignerJoueurs(Jeu jeu, int nbJoueurs)
{
    std::string nomJoueur = "";

    for(int i = 0; i < nbJoueurs; ++i)
    {
        afficherMessage("Inscrivez le nom du joueur");
        std::cin >> nomJoueur;
        assignerJoueur(jeu.joueurs[i], nomJoueur, i);
    }
}

void initialiserJeu(Jeu& jeu)
{
#if SIMULATION_NB_JOUEURS > 0
    jeu.nbJoueurs = SIMULATION_NB_JOUEURS;

    // Initialiser les joueurs pour la partie
    creerJoueurs(jeu);

    // Initialiser le plateau de jeu
    assignerBrochette(jeu.plateau.brochette);
    afficherBrochette(jeu.plateau.brochette);
#endif // SIMULATION_NB_JOUEURS
}

void creerJoueurs(Jeu& jeu)
{
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        assignerJoueur(jeu.joueurs[i], "Joueur" + std::to_string(i + 1), i + 1);
    }
}