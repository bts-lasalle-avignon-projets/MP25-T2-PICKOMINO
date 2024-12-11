#include "Ihm.h"

#include <iostream>

// Affichage des dialogues

/*
void afficherInstructions()
{

}

void afficherOptionsDeJeu()
{

}

void afficherTourJoueur(Joueur joueur)
{

}

void afficherScores()
{

}

void afficherVainqueur()
{

}
*/

// Affichage de jeu

bool afficherPileJoueurEnCours(Joueur& joueur)
{
    std::cout << "La pile de : " << joueur.nom << " est énorme ! Elle comporte " << joueur.sommet
              << " pickomino(s) !" << std::endl;

    for(int i = joueur.sommet - 1; i >= 0; i--)
    {
        std::cout << joueur.pile[i].valeur << std::endl;
    }
    return true;
}

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS])
{
    std::string ligneValeur;
    std::string ligneNombreDeVers;
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(brochette[i].etat == Pickomino::VISIBLE)
        {
            ligneValeur += std::to_string(brochette[i].valeur) + " ";
            ligneNombreDeVers += std::to_string(brochette[i].nombreDeVers) + "  ";
        }
        else if(brochette[i].etat == Pickomino::RETOURNE)
        {
            ligneValeur += "X  ";
            ligneNombreDeVers += "X  ";
        }
    }

    std::cout << ligneValeur << std::endl;
    std::cout << ligneNombreDeVers << std::endl << std::endl;
}

void afficherJoueurs(Jeu& jeu)
{
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        std::cout << "Joueur " << jeu.joueurs[i].numero << " : " << jeu.joueurs[i].nom << std::endl;
    }
}

void afficherDesLances(int& nombreDes, const int (&desLances)[NB_DES])
{
    std::cout << "Nombre de dés restants : " << nombreDes << " : ";
    for(int i = 0; i < nombreDes; ++i)
    {
        if(desLances[i] == 6)
        {
            std::cout << "[V] ";
        }
        else
        {
            std::cout << "[" << desLances[i] << "] ";
        }
    }
    std::cout << std::endl;
}

void afficherDesRetenus(int& nombreDes, const int (&desRetenus)[NB_DES])
{
    int nombreDesRetenus = NB_DES - nombreDes;
    std::cout << "\nDés retenus : ";
    for(int i = 0; i < nombreDesRetenus; ++i)
    {
        if(desRetenus[i] == 6)
        {
            std::cout << "[V] ";
        }
        else
        {
            std::cout << "[" << desRetenus[i] << "] ";
        }
    }
    std::cout << std::endl;
}

void afficherScore(int& score)
{
    std::cout << "La somme des valeurs des dés vous donne : " << score << "." << std::endl;
}

// Saisies

unsigned int saisirNbJoueurs()
{
    unsigned int nbJoueurs = 0;

    do
    {
        afficherMessage("Entrez le nombre de joueurs : ", false);
        std::cin >> nbJoueurs;
    } while(nbJoueurs < NB_JOUEURS_MIN || nbJoueurs > NB_JOUEURS_MAX);

    return nbJoueurs;
}

std::string saisirNomJoueur()
{
    std::string nomJoueur;

    do
    {
        std::cin >> nomJoueur;
    } while(nomJoueur.empty());

    return nomJoueur;
}

bool choisirRelancer(int& nombreDes)
{
    std::cout << "Il vous reste " << nombreDes << " dés restants." << std::endl;
    if(nombreDes > 0)
    {
        std::cout << "Voulez-vous relancer des dés? (O/N) ";
        std::string choix;
        std::cin >> choix;
        if(choix == "O" || choix == "o")
            return true;
        else if(choix == "N" || choix == "n")
            return false;
        else
        {
            std::cout << "Veuillez saisir O ou N." << std::endl;
            return choisirRelancer(nombreDes);
        }
    }
    return false;
}

// Utilitaires

void afficherMessage(const std::string& message, bool nouvelleLigne /*= true*/)
{
    std::cout << message;
    if(nouvelleLigne)
        std::cout << std::endl;
}
void afficherSeparation()
{
    std::cout << "\n==============================" << std::endl;
}