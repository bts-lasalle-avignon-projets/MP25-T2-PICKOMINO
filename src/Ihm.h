#ifndef IHM_H
#define IHM_H

#include <string>

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"
#include "Jeu.h"

#define LARGEUR_MAX 60

// Affichage des dialogues

/*
void afficherInstructions();
void afficherOptionsDeJeu();
*/
void afficherReglesDeJeu();
void afficherBienvenue();
void afficherHistorique();
void effacerHistorique();
void traiterTrame(const std::string& trame);
void afficherScores(const Jeu& jeu);
void afficherVainqueur(const Jeu& jeu, int indexVainqueur);

// Affichage de jeu

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS]);
void afficherJoueurs(const Jeu& jeu);
void afficherDesLances(const int& nombreDes, const int (&desLances)[NB_DES]);
void afficherDesRetenus(const int& nombreDes, const int (&desRetenus)[NB_DES]);
void afficherScore(const int& score);
bool afficherPileJoueurEnCours(const Joueur& joueur);

// Saisies

unsigned int saisirNbJoueurs();
std::string  saisirNomJoueur();
bool         choisirRelancer(int& nombreDes);
int          saisirValeurARetenir();

// Utilitaires

void afficherMessage(const std::string& message, bool nouvelleLigne = true);
void afficherSeparation();
int  convertirValeur(std::string valeur);

#endif // IHM_H