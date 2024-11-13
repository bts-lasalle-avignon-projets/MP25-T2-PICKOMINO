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
void afficherTourJoueur(Joueur joueur);
void afficherScores();
void afficherVainqueur();
*/

// Affichage de jeu

/*
void afficherPileJoueurEnCours()
void afficherDes()
*/
void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS]);
void afficherJoueurs(Jeu& jeu);
void afficherScoreFinalTour(int& score);

// Saisies

unsigned int saisirNbJoueurs();
std::string  saisirNomJoueur();
bool         choisirRelancer(int& nombreDes);

// Utilitaires

void afficherMessage(const std::string& message, bool nouvelleLigne = true);

#endif // IHM_H