#ifndef JEU_H
#define JEU_H

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"

struct Jeu
{
    unsigned int nbJoueurs;
    Joueur       joueurs[NB_JOUEURS_MAX];
    Plateau      plateau;
};

void jouerPickomino();
void initialiserJeu(Jeu& jeu);
void creerJoueurs(Jeu& jeu);
void jouerTour(Jeu& jeu, int nbJoueur);
void debuterTour(Jeu& jeu, int& scoreTour);
void initialiserPlateau(Jeu& jeu, bool initialisationBrochette = false);
bool estPartieFinie(const Jeu& jeu);
void terminerPartie(Jeu& jeu);
int  determinerVainqueur(Jeu& jeu);
int  trouverMaxValeurPickomino(const Joueur& joueur);
void calculerVers(Jeu& jeu);

#endif