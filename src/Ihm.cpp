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
*/
void afficherScores(const Jeu& jeu)
{
    afficherSeparation();
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        afficherMessage("Joueur " + std::to_string(jeu.joueurs[i].numero) + " " +
                        jeu.joueurs[i].nom + " : " + std::to_string(jeu.joueurs[i].score) +
                        " ver(s)");
    }
}

void afficherVainqueur(const Jeu& jeu, int indexVainqueur)
{
    afficherSeparation();
    if(indexVainqueur == -1)
    {
        afficherMessage("Il n'y a aucun vainqueur !");
    }
    else
    {
        afficherMessage("Le grand gagnant est : ");
        afficherMessage(jeu.joueurs[indexVainqueur].nom + " avec " +
                        std::to_string(jeu.joueurs[indexVainqueur].score) + " ver(s)");
    }
}

// Affichage de jeu

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS])
{
    std::string ligneValeur;
    std::string ligneNombreDeVers;

    std::cout << "Brochette : " << std::endl;
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
    std::cout << ligneNombreDeVers << std::endl;
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
    std::cout << "Lancer des " << nombreDes << " dé" << (nombreDes > 1 ? "s" : "") << " : ";
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
    std::cout << "La somme des valeurs des dés vous donne : " << score << std::endl;
}

bool afficherPileJoueurEnCours(Joueur& joueur)
{
    std::cout << "Votre pile de pickomino" << (joueur.sommet > 1 ? "s : " : " : ") << std::endl;
    for(int i = joueur.sommet - 1; i >= 0; i--)
    {
        std::cout << joueur.pile[i].valeur << std::endl;
    }
    if(joueur.sommet == 0)
        std::cout << "vide" << std::endl;
    return true;
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
    std::cout << "Il vous reste " << nombreDes << " dés" << std::endl;
    if(nombreDes > 0)
    {
        std::cout << "Voulez-vous relancer les dés (O/N) ? ";
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

int saisirValeurARetenir()
{
    std::string valeur;
    bool        saisieValide = false;

    do
    {
        std::cin >> valeur;
        if(valeur == "V" || valeur == "v")
            saisieValide = true;
        else
            saisieValide =
              (convertirValeur(valeur) >= Face::UN && convertirValeur(valeur) <= Face::CINQ);
        if(!saisieValide)
            std::cout << "Valeur invalide !" << std::endl;
    } while(!saisieValide);

    int valeurDesARetenir = convertirValeur(valeur);

    return valeurDesARetenir;
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

int convertirValeur(std::string valeur)
{
    if(valeur == "V" || valeur == "v")
        return Face::VER;
    else
        return std::stoi(valeur);
}