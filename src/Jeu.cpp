#include "Jeu.h"
#include "Ihm.h"
#include "Plateau.h"
#include "Joueur.h"

void jouerPickomino()
{
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
    terminerPartie(jeu);
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
    int  scoreTour;
    bool tourFini  = false;
    bool lancerNul = false;

    debuterTour(jeu, scoreTour);

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
            retenirDes(jeu.plateau);
            afficherDesRetenus(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);

            scoreTour = calculerScoreTour(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);
            afficherScore(scoreTour);

            if(!choisirRelancer(jeu.plateau.nombreDesRestant))
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
            tourFini = true;
        }

        if(!lancerPossible(jeu.plateau.nombreDesRestant))
        {
            tourFini = true;
        }

        afficherPileJoueurEnCours(jeu.joueurs[nbJoueur]);
        afficherSeparation();
        afficherBrochette(jeu.plateau.brochette);
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

void terminerPartie(Jeu& jeu)
{
    calculerVers(jeu);
    int indexVainqueur = determinerVainqueur(jeu);
    afficherScores(jeu);
    afficherVainqueur(jeu, indexVainqueur);
}

int determinerVainqueur(Jeu& jeu)
{
    int scoreMax           = 0;
    int indexVainqueur     = -1;
    int maxValeurPickomino = 0;

    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        if(jeu.joueurs[i].score > scoreMax)
        {
            scoreMax           = jeu.joueurs[i].score;
            indexVainqueur     = i;
            maxValeurPickomino = trouverMaxValeurPickomino(jeu.joueurs[i]);
        }
        else if(jeu.joueurs[i].score == scoreMax)
        {
            int valeurMaxCourante = trouverMaxValeurPickomino(jeu.joueurs[i]);
            if(valeurMaxCourante > maxValeurPickomino)
            {
                indexVainqueur     = i;
                maxValeurPickomino = valeurMaxCourante;
            }
        }
    }

    return indexVainqueur;
}

int trouverMaxValeurPickomino(const Joueur& joueur)
{
    int maxValeur = 0;

    for(int j = joueur.sommet - 1; j >= 0; --j)
    {
        if(joueur.pile[j].valeur > maxValeur)
        {
            maxValeur = joueur.pile[j].valeur;
        }
    }

    return maxValeur;
}

void calculerVers(Jeu& jeu)
{
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        jeu.joueurs[i].score = 0;
        for(int j = jeu.joueurs[i].sommet - 1; j >= 0; j--)
        {
            jeu.joueurs[i].score += jeu.joueurs[i].pile[j].nombreDeVers;
        }
    }
}