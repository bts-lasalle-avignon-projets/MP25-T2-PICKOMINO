#ifndef IHM_H
#define IHM_H

#include <string>

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"
#include "Jeu.h"

// Affichage des dialogues

/*
void afficherInstructions();
void afficherOptionsDeJeu();
*/
void afficherScores(const Jeu& jeu);
void afficherVainqueur(const Jeu& jeu, int indexVainqueur);

// Affichage de jeu

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS]);
void afficherJoueurs(Jeu& jeu);
void afficherDesLances(int& nombreDes, const int (&desLances)[NB_DES]);
void afficherDesRetenus(int& nombreDes, const int (&desRetenus)[NB_DES]);
void afficherScore(int& score);
bool afficherPileJoueurEnCours(Joueur& joueur);

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