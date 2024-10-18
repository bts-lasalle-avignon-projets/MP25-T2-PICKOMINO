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

void initialiserJeu(Jeu& jeu)
{
#if SIMULATION_NB_JOUEURS > 0
    jeu.nbJoueurs = SIMULATION_NB_JOUEURS;

    // Initialiser les joueurs pour la partie
    creerJoueurs(jeu);

    // Initialiser le plateau de jeu
    assignerBrochette(jeu.plateau.brochette);
    afficherBrochette(jeu.plateau.brochette);
    afficherJoueurs(jeu);
#endif // SIMULATION_NB_JOUEURS
}

void creerJoueurs(Jeu& jeu)
{
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        std::string nomJoueur = "";

        assignerJoueur(jeu.joueurs[i], "Joueur" + std::to_string(i + 1), i + 1);
        afficherMessage("Inscrivez le nom du joueur " + std::to_string(i + 1));
        std::cin >> nomJoueur;
        jeu.joueurs[i].nom = nomJoueur;
    }
}