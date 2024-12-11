#include "Jeu.h"
#include "Ihm.h"
#include "Plateau.h"
#include "Joueur.h"
#include <iostream>

void jouerPickomino()
{
#ifdef SIMULATION

    Jeu jeu;
    initialiserJeu(jeu);

    while(verifierPresencePickomino(jeu.plateau))
    {
        for(jeu.plateau.joueurActuel = 0; jeu.plateau.joueurActuel < jeu.nbJoueurs;
            jeu.plateau.joueurActuel++)
        {
            jouerTour(jeu, jeu.plateau.joueurActuel);
        }
    }
#endif
}

void initialiserJeu(Jeu& jeu)
{
    creerJoueurs(jeu);
    afficherJoueurs(jeu);

    assignerBrochette(jeu.plateau.brochette);
    afficherBrochette(jeu.plateau.brochette);
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

void jouerTour(Jeu& jeu, int nbJoueur)
{
    int scoreTour;
    initialiserTour(jeu, scoreTour);

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

        if(!choisirRelancer(jeu.plateau.nombreDes) || jeu.plateau.nombreDes <= 0)
        {
            scoreTour = calculerScoreFinalTour(jeu.plateau.nombreDes, jeu.plateau.desRetenus);
            afficherMessage("Votre score est de : " + std::to_string(scoreTour) + " points !");
            prendrePickomino(jeu, scoreTour);
            afficherPileJoueurEnCours(jeu.joueurs[nbJoueur]);
            afficherBrochette(jeu.plateau.brochette);
            break;
        }
    }
}

void initialiserTour(Jeu& jeu, int& scoreTour)
{
    scoreTour             = 0;
    jeu.plateau.nombreDes = NB_DES;
    reinitialiserPlateau(jeu.plateau.desRetenus);
    afficherSeparation();
    afficherMessage("C'est au tour du joueur " + std::to_string(jeu.plateau.joueurActuel) + " : " +
                      jeu.joueurs->nom,
                    true);
}