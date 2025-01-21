#ifndef JEU_H
#define JEU_H

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"

#define VERSION "1.0"

// #define DEBUG_JEU // ou -DDEBUG_JEU dans g++

#define JOUEUR_PAR_DEFAUT 0

struct Jeu
{
    unsigned int nbJoueurs;
    Joueur       joueurs[NB_JOUEURS_MAX];
    Plateau      plateau;
};

void jouerPickomino();
void initialiserJeu(Jeu& jeu);
void choisirOptionJeu(Jeu& jeu);
void creerJoueurs(Jeu& jeu);
void choisirModeDeJeu(Jeu& jeu);
void jouerTour(Jeu& jeu, int nbJoueur);
void debuterTour(Jeu& jeu, int& scoreTour);
bool estPartieFinie(const Jeu& jeu);
void terminerPartie(Jeu& jeu);
int  determinerVainqueur(Jeu& jeu);
int  trouverMaxValeurPickomino(const Joueur& joueur);
void calculerVers(Jeu& jeu);
void enregistrerScore(const Jeu& jeu, int indexVainqueur);

#endif // JEU_H