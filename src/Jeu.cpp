#include "Jeu.h"
#include "Ihm.h"
#include "Plateau.h"
#include "Joueur.h"
#include <fstream>
#include <ctime>

#ifdef DEBUG_JEU
#include <iostream>
#endif

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
    clearAffichage();
    afficherBienvenue();
    choisirOptionJeu(jeu);
    initialiserPlateau(jeu.plateau, true);
}

void choisirOptionJeu(Jeu& jeu)
{
    switch(selectionnerOptionsDeJeu())
    {
        case 1: // Mode de jeu
            choisirModeDeJeu(jeu);
            break;
        case 2: // Historique
            afficherMessage("Coming soon ...");
            choisirOptionJeu(jeu);
            break;
        case 3: // Règles
            afficherMessage("Coming soon ...");
            choisirOptionJeu(jeu);
            break;
        case 4: // Quitter
            exit(0);
        default:
            afficherMessage("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
            break;
    }
}

void choisirModeDeJeu(Jeu& jeu)
{
    clearAffichage();
    switch(selectionnerModeDeJeu())
    {
        case 1:
            creerJoueurs(jeu);
            break;
        case 2:
            afficherMessage("Coming soon ...");
            choisirModeDeJeu(jeu);
            break;
        case 3:
            afficherMessage("Coming soon ...");
            choisirModeDeJeu(jeu);
            break;
        case 4:
            choisirOptionJeu(jeu);
            break;
        default:
            afficherMessage("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
            break;
    }
}

void creerJoueurs(Jeu& jeu)
{
    clearAffichage();
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
            perdreTour(jeu);
            tourFini = true;
        }

        if(!lancerPossible(jeu.plateau.nombreDesRestant))
        {
            tourFini = true;
        }

        clearAffichage();
        afficherSeparation();
        afficherBrochette(jeu.plateau.brochette);
        afficherSeparation();
        afficherDesRetenus(jeu.plateau.nombreDesRestant, jeu.plateau.desRetenus);
        afficherPileJoueurEnCours(jeu.joueurs[nbJoueur]);
    }
}

void debuterTour(Jeu& jeu, int& scoreTour)
{
    // clearAffichage();
    initialiserPlateau(jeu.plateau);
    afficherBrochette(jeu.plateau.brochette);
    afficherSeparation();
    afficherMessage("C'est au tour du joueur " + std::to_string(jeu.plateau.joueurActuel + 1) +
                      " : " + jeu.joueurs[jeu.plateau.joueurActuel].nom,
                    true);
    afficherPileJoueurEnCours(jeu.joueurs[jeu.plateau.joueurActuel]);
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
    enregistrerScore(jeu, indexVainqueur);
}

int determinerVainqueur(Jeu& jeu)
{
    int scoreLePlusEleve   = jeu.joueurs[JOUEUR_PAR_DEFAUT].score;
    int indexVainqueur     = JOUEUR_PAR_DEFAUT;
    int maxValeurPickomino = trouverMaxValeurPickomino(jeu.joueurs[JOUEUR_PAR_DEFAUT]);

    for(unsigned int i = 1; i < jeu.nbJoueurs; ++i)
    {
        if(jeu.joueurs[i].score > scoreLePlusEleve)
        {
            scoreLePlusEleve   = jeu.joueurs[i].score;
            indexVainqueur     = i;
            maxValeurPickomino = trouverMaxValeurPickomino(jeu.joueurs[i]);
        }
        else if(jeu.joueurs[i].score == scoreLePlusEleve)
        {
            int valeurMaxCourante = trouverMaxValeurPickomino(jeu.joueurs[i]);
            if(valeurMaxCourante > maxValeurPickomino)
            {
                indexVainqueur     = i;
                maxValeurPickomino = valeurMaxCourante;
            }
        }
    }

#ifdef DEBUG_JEU
    std::cout << "[" << __FILE__ << ":" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] ";
    std::cout << "indexVainqueur = " << indexVainqueur << std::endl;
#endif

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

void enregistrerScore(const Jeu& jeu, int indexVainqueur)
{
    std::ofstream fichier("docs/scores.txt", std::ios::app);
    if(!fichier)
    {
        afficherMessage("Impossible d'ouvrir le fichier");
        return;
    }

    std::time_t actuel = std::time(nullptr);
    char        dateHeure[100];
    std::strftime(dateHeure, sizeof(dateHeure), "%d-%m-%Y %Hh%M", std::localtime(&actuel));
    fichier << "[" << dateHeure << ";" << jeu.joueurs[indexVainqueur].nom << ";"
            << jeu.joueurs[indexVainqueur].score << "]" << std::endl;
    fichier.close();
    afficherMessage("Score enregistré dans le fichier !");
}