#ifndef IHM_H
#define IHM_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"
#include "Jeu.h"
#include "Ia.h"

// Mise en page
#define LARGEUR_MAX 80
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"
#define ITALIC      "\033[3m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define ORANGE      "\033[0;33m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// Affichage des dialogues

void afficherReglesDeJeu();
void afficherBienvenue();
void afficherHistorique();
void traiterLigne(const std::string& trame);
void afficherMenu(const std::string& texte, int largeur);
void afficherTitre(const std::string& asciiArt, int largeur);
void afficherScores(const Jeu& jeu);
void afficherVainqueur(const Jeu& jeu, int indexVainqueur);

// Affichage de jeu

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS]);
void afficherJoueurs(const Jeu& jeu, bool vuePile = false);
void afficherDesLances(const int& nombreDes, const int (&desLances)[NB_DES]);
void afficherDesRetenus(const int& nombreDes, const int (&desRetenus)[NB_DES]);
void afficherScore(const int& score);
bool afficherPileJoueurEnCours(const Joueur& joueur);

// Sélection

int  selectionnerOptionsDeJeu();
int  selectionnerModeDeJeu();
int  selectionnerNiveauIa();

// Saisies

unsigned int saisirNbJoueurs(bool partieIa);
unsigned int saisirNbIa(Jeu& jeu, bool partieJoueur);
std::string  saisirNomJoueur();
unsigned int saisirAge();
int          saisirValeurARetenir();
bool         choisirRelancer(int& nombreDes);
bool         relancerPartie();

// Utilitaires

void afficherMessage(const std::string& message, bool nouvelleLigne = true);
void afficherSeparation();
void clearAffichage();
int  convertirValeur(std::string valeur);
void attendre(int millisecondes);

#endif // IHM_H