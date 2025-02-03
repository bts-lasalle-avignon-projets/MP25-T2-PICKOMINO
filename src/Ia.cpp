#include "Ia.h"
#include "Jeu.h"
#include "Ihm.h"
#include "Plateau.h"
#include "Joueur.h"

void debuterTourIa(Jeu& jeu, int& scoreTour)
{
    clearAffichage();
    initialiserPlateau(jeu.plateau);
    afficherBrochette(jeu.plateau.brochette);
    afficherSeparation();
    afficherMessage("C'est au tour de l'IA " + std::to_string(jeu.plateau.joueurActuel) + " : " +
                      jeu.joueurs[jeu.plateau.joueurActuel].nom,
                    true);
    afficherPileJoueurEnCours(jeu.joueurs[jeu.plateau.joueurActuel]);
}

void jouerTourIa(Jeu& jeu, int numIa)
{
    int  scoreTour;
    bool tourFini  = false;
    bool lancerNul = false;

    debuterTourIa(jeu, scoreTour);

    while(!tourFini)
    {
        lancerDes(jeu.plateau.nombreDesRestant, jeu.plateau.desLances);
        afficherDesLances(jeu.plateau.nombreDesRestant, jeu.plateau.desLances);

        if(verifierDesLances(jeu.plateau.nombreDesRestant,
                             jeu.plateau.desLances,
                             jeu.plateau.desRetenus))
        {
            afficherMessage("Toutes les valeurs des dés lancés sont déjà retenues !");
            scoreTour = 0;
            lancerNul = true;
        }
        else
        {
            retenirDesIa(jeu);
            afficherDesRetenus(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);

            scoreTour = calculerScoreTour(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);
            afficherScore(scoreTour);

            if(scoreTour > verifierMinPickomino(jeu))
            {
                scoreTour =
                  calculerScoreFinalTour(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);
                afficherMessage("Votre score est de " + std::to_string(scoreTour) + " points !");
                lancerNul = !prendrePickomino(jeu, scoreTour);
                tourFini  = true;
            }
        }
        if(lancerNul)
        {
            afficherMessage("Lancer nul !");
            perdreTour(jeu);
            tourFini = true;
        }

        if(!lancerPossible(jeu.plateau.nombreDesRestant))
        {
            tourFini = true;
        }

        system("sleep 2");
        clearAffichage();
        afficherSeparation();
        afficherBrochette(jeu.plateau.brochette);
        afficherSeparation();
        afficherDesRetenus(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);
        afficherPileJoueurEnCours(jeu.joueurs[numIa]);
    }
}

void retenirDesIa(Jeu& jeu)
{
    int valeurDesARetenir;
    int sommet = NB_DES - jeu.plateau.nombreDesRestant;

    afficherMessage("L'IA va choisir une valeur de dés à retenir...");
    valeurDesARetenir = choisirFaceDifficulteIA(jeu);

    for(int i = 0; i < NB_DES; i++)
    {
        if(jeu.plateau.desLances[i] == valeurDesARetenir)
        {
            jeu.plateau.desRetenus[sommet] = jeu.plateau.desLances[i];
            sommet++;
            jeu.plateau.nombreDesRestant--;
        }
    }
}

int choisirFaceDifficulteIA(Jeu& jeu)
{
    switch(jeu.niveauIa)
    {
        case FACILE:
            return choisirFaceAleatoireIa(jeu);
        case MOYEN:
        case DIFFICILE:
        default:
            return choisirFaceAleatoireIa(jeu);
    }
}

int trouverValeurMax(Jeu& jeu)
{
    int valeurMax = 0;

    for(int i = 0; i < jeu.plateau.nombreDesRestant; ++i)
    {
        if(jeu.plateau.desLances[i] > valeurMax)
        {
            if(!estDejaChoisie(jeu.plateau.nombreDesRestant,
                               jeu.plateau.desLances[i],
                               jeu.plateau.desRetenus))
            {
                valeurMax = jeu.plateau.desLances[i];
            }
        }
    }
    return valeurMax;
}

int choisirFaceAleatoireIa(Jeu& jeu)
{
    return trouverValeurMax(jeu);
}

int verifierMinPickomino(Jeu& jeu)
{
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(jeu.plateau.brochette[i].etat == Pickomino::VISIBLE)
        {
            return jeu.plateau.brochette[i].valeur;
        }
    }
    return -1;
}