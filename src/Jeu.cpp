#include "Jeu.h"
#include "Ihm.h"
#include "Plateau.h"
#include "Joueur.h"
#include <string>

void jouerPickomino()
{
    Jeu jeu;

    initialiserJeu(jeu);
}

void initialiserJeu(Jeu& jeu)
{
#ifdef SIMULATION
    // Créer les joueurs pour la partie
    creerJoueurs(jeu);
    afficherJoueurs(jeu);

    // Initialiser le plateau de jeu
    assignerBrochette(jeu.plateau.brochette);
    afficherBrochette(jeu.plateau.brochette);
#endif // SIMULATION
}

void creerJoueurs(Jeu& jeu)
{
    jeu.nbJoueurs = saisirNbJoueurs();

    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        afficherMessage("Entrez le nom du joueur " + std::to_string(i + 1) + " : ", false);
        std::string nomJoueur = saisirNomJoueur();
        assignerJoueur(jeu.joueurs[i], nomJoueur, i + 1);
    }
}