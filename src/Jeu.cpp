#include "Jeu.h"
#include "Ihm.h"
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
#ifdef SIMULATION
    // Créer les joueurs pour la partie
    creerJoueurs(jeu);
    afficherJoueurs(jeu);

    // Initialiser le plateau de jeu
    assignerBrochette(jeu.plateau.brochette);
    afficherBrochette(jeu.plateau.brochette);

    jouerTour(jeu);

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

void jouerTour(Jeu& jeu)
{
    int nombreDes          = NB_DES;
    int desLances[NB_DES]  = { 0 };
    int desRetenus[NB_DES] = { 0 };
    int scoreTour          = 0;

    while(lancerPossible(nombreDes))
    {
        lancerDes(nombreDes, desLances);
        afficherDesLances(nombreDes, desLances);

        std::cout
          << "Quels dés souhaitez-vous retenir ? (Entrez un nombre ou 'V' pour retenir les vers)"
          << std::endl;
        retenirDes(nombreDes, desLances, desRetenus);

        afficherDesRetenus(nombreDes, desRetenus);

        scoreTour = calculerScoreTour(nombreDes, desRetenus);
        afficherScore(scoreTour);

        if(!choisirRelancer(nombreDes) || nombreDes < 0)
        {
            scoreTour = calculerScoreFinalTour(nombreDes, desRetenus);
            std::cout << "Merci d'avoir joué ! Votre score final est de " << scoreTour << " points."
                      << std::endl;
            break;
        }
    }
}