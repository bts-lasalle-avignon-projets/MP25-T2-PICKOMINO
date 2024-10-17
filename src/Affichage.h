#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <string>

#include "Donnees.h"

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

// Utilitaires

void afficherMessage(const std::string& message, bool nouvelleLigne = true);

#endif