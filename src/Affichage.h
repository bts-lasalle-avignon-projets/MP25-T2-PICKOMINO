#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "Donnees.h"

#include <iostream>

void afficherMessage(std::string message);

/*
void afficherInstructions();
void afficherOptionsDeJeu();
void afficherTourJoueur(Joueur joueur);
void afficherScores();
void afficherVainqueur();
*/

/*
void afficherPileJoueurEnCours()
void afficherDes()
*/
void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINO]);

#endif