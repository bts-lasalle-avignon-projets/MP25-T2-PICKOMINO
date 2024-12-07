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
    int scoreTour = 0;

    while(lancerPossible(jeu.plateau.nombreDes))
    {
        lancerDes(jeu.plateau.nombreDes, jeu.plateau.desLances);
        afficherDesLances(jeu.plateau.nombreDes, jeu.plateau.desLances);

        if(verifierDesLances(jeu.plateau.nombreDes, jeu.plateau.desLances, jeu.plateau.desRetenus))
        {
            afficherMessage("Toutes les valeurs des dés lancés sont déjà retenues. Fin du tour.");
            scoreTour = 0;
            break;
        }

        afficherMessage(
          "Quels dés souhaitez-vous retenir ? (Entrez un nombre ou 'V' pour retenir les vers)");
        retenirDes(jeu.plateau.nombreDes, jeu.plateau.desLances, jeu.plateau.desRetenus);

        afficherDesRetenus(jeu.plateau.nombreDes, jeu.plateau.desRetenus);

        scoreTour = calculerScoreTour(jeu.plateau.nombreDes, jeu.plateau.desRetenus);
        afficherScore(scoreTour);

        if(!choisirRelancer(jeu.plateau.nombreDes) || jeu.plateau.nombreDes < 0)
        {
            scoreTour = calculerScoreFinalTour(jeu.plateau.nombreDes, jeu.plateau.desRetenus);
            afficherMessage("Merci d'avoir joué ! Votre score final est de : " +
                            std::to_string(scoreTour) + " points !");
            break;
        }
    }
}
