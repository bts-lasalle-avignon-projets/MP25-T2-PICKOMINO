#ifndef IHM_H
#define IHM_H

#include <string>

#include "Donnees.h"
#include "Plateau.h"
#include "Joueur.h"
#include "Jeu.h"

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

/*
void afficherInstructions();
*/
void afficherReglesDeJeu();
int  selectionnerOptionsDeJeu();
int  selectionnerModeDeJeu();
void afficherBienvenue();
void afficherHistorique();
void traiterTrame(const std::string& trame);
void afficherMenu(const std::string& texte, int largeur);
void afficherTitre(const std::string& asciiArt, int largeur);
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
void clearAffichage();
int  convertirValeur(std::string valeur);

#endif // IHM_H