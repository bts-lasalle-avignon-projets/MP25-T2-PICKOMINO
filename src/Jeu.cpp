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

    while(!estPartieFinie(jeu))
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
    // afficherJoueurs(jeu);

    initialiserPlateau(jeu, true);
    afficherSeparation();
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
    debuterTour(jeu, scoreTour);

    while(lancerPossible(jeu.plateau.nombreDesRestant))
    {
        lancerDes(jeu.plateau.nombreDesRestant, jeu.plateau.desLances);
        afficherDesLances(jeu.plateau.nombreDesRestant, jeu.plateau.desLances);

        if(verifierDesLances(jeu.plateau.nombreDesRestant,
                             jeu.plateau.desLances,
                             jeu.plateau.desRetenus))
        {
            afficherMessage("Toutes les valeurs des dés lancés sont déjà retenues !");
            scoreTour = 0;
            break;
        }

        afficherMessage(
          "Quels dés souhaitez-vous retenir ? (Entrez un nombre ou 'V' pour retenir les vers)");
        retenirDes(jeu.plateau.nombreDesRestant, jeu.plateau.desLances, jeu.plateau.desRetenus);

        afficherDesRetenus(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);

        scoreTour = calculerScoreTour(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);
        afficherScore(scoreTour);

        if(!choisirRelancer(jeu.plateau.nombreDesRestant) || jeu.plateau.nombreDesRestant <= 0)
        {
            scoreTour =
              calculerScoreFinalTour(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);
            afficherMessage("Votre score est de " + std::to_string(scoreTour) + " points !");
            prendrePickomino(jeu, scoreTour);
            afficherPileJoueurEnCours(jeu.joueurs[nbJoueur]);
            afficherSeparation();
            afficherBrochette(jeu.plateau.brochette);
            break;
        }
    }
}

void debuterTour(Jeu& jeu, int& scoreTour)
{
    initialiserPlateau(jeu);
    afficherSeparation();
    afficherMessage("C'est au tour du joueur " + std::to_string(jeu.plateau.joueurActuel + 1) +
                      " : " + jeu.joueurs[jeu.plateau.joueurActuel].nom,
                    true);
}

void initialiserPlateau(Jeu& jeu, bool initialisationBrochette /*= false*/)
{
    jeu.plateau.nombreDesRestant = NB_DES;
    if(initialisationBrochette)
        initialiserBrochette(jeu.plateau.brochette);
    initialiserTableauDes(jeu.plateau.desRetenus);
}

bool estPartieFinie(const Jeu& jeu)
{
    return !verifierPresencePickomino(jeu.plateau);
}