#include "Jeu.h"
#include "Plateau.h"
#include "Affichage.h"

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
#endif // SIMULATION_NB_JOUEURS
}

void creerJoueurs(Jeu& jeu)
{
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        assignerJoueur(jeu.joueurs[i], "Joueur" + std::to_string(i + 1), i + 1);
    }
}