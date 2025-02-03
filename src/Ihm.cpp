#include "Ihm.h"

int selectionnerOptionsDeJeu()
{
    int choix;

    std::cout << "\nQue souhaitez vous faire ?\n";
    std::cout << "1. Jouer\n";
    std::cout << "2. Afficher l'historique des parties\n";
    std::cout << "3. Règles du jeu\n";
    std::cout << "4. Quitter\n";
    std::cout << "Entrez votre choix (1-4) : ";

    std::cin >> choix;
    return choix;
}

int selectionnerModeDeJeu()
{
    int choix;

    std::cout << "\nChoisissez votre mode de jeu :\n";
    std::cout << "1. Joueur contre joueur\n";
    std::cout << "2. Joueur contre IA\n";
    std::cout << "3. IA contre IA\n";
    std::cout << "4. Quitter\n";
    std::cout << "Entrez votre choix (1-4) : ";

    std::cin >> choix;
    return choix;
}

int selectionnerNiveauIa()
{
    int choix;

    std::cout << "\nChoisissez le niveau de difficulté de l'IA:\n";
    std::cout << "1. Niveau facile\n";
    std::cout << "2. Niveau moyen\n";
    std::cout << "3. Niveau difficile\n";
    std::cout << "Entrez votre choix (1-3) : ";

    std::cin >> choix;
    return choix;
}

void afficherMenu(const std::string& texte, int largeur)
{
    int espaces = (largeur - texte.size()) / 2;
    std::cout << std::string(espaces, ' ') << texte << std::endl;
}

void afficherTitre(const std::string& asciiArt, int largeur)
{
    size_t maxLength = 0;
    size_t debut     = 0;
    while(debut < asciiArt.size())
    {
        size_t fin = asciiArt.find('\n', debut);
        if(fin == std::string::npos)
        {
            fin = asciiArt.size();
        }
        maxLength = std::max(maxLength, fin - debut);
        debut     = fin + 1;
    }

    int espacesAscii = (largeur - maxLength) / 2;
    std::cout << std::string(largeur, '-') << std::endl;

    debut = 0;
    while(debut < asciiArt.size())
    {
        size_t fin = asciiArt.find('\n', debut);
        if(fin == std::string::npos)
        {
            fin = asciiArt.size();
        }
        std::cout << std::string(espacesAscii, ' ') << asciiArt.substr(debut, fin - debut)
                  << std::endl;
        debut = fin + 1;
    }

    std::cout << std::string(largeur, '-') << std::endl;
}

void afficherBienvenue()
{
    std::string asciiArt = R"(
 ____    ___    ____   _  __   ___    __  __   ___   _   _    ___  
|  _ \  |_ _|  / ___| | |/ /  / _ \  |  \/  | |_ _| | \ | |  / _ \
| |_) |  | |  | |     | ' /  | | | | | |\/| |  | |  |  \| | | | | |
|  __/   | |  | |___  | . \  | |_| | | |  | |  | |  | |\  | | |_| |
|_|     |___|  \____| |_|\_\  \___/  |_|  |_| |___| |_| \_|  \___/
                                                                   )";

    std::string version     = "Version : V" + std::string(VERSION);
    std::string releaseDate = "Release : 22/01/2025";
    std::string equipeDev   = "RAFFIN Louis & CLEMENT Aymeric";

    afficherTitre(asciiArt, LARGEUR_MAX);
    afficherMenu(version, LARGEUR_MAX);
    afficherMenu(releaseDate, LARGEUR_MAX);
    afficherMenu(equipeDev, LARGEUR_MAX);
    afficherMenu("Bienvenue dans cette partie de PICKOMINO !", LARGEUR_MAX);
}

void afficherReglesDeJeu()
{
    clearAffichage();
    std::cout << "Règles du jeu :\n" << std::endl;
    std::cout << "Lancez les 8 dés, choisissez une valeur de dés à mettre de côté, puis décidez de "
                 "relancer ou pas."
              << std::endl;

    std::cout << "Vous pouvez relancer les dés restants autant de fois que vous le souhaitez, à "
                 "condition de toujours pouvoir retenir une valeur de dés différente.\n"
              << std::endl;

    std::cout << "Si vous êtes dans l'incapacité de le faire alors vous devrez rendre un de vos "
                 "précieux Pickomino et passer votre tour !\n"
              << std::endl;

    std::cout
      << "Lorsque votre tour est fini, faites l’addition pour savoir quel Pickomino prendre au "
         "centre de la table (la brochette) ou même dans la main de vos adversaires !\n"
      << std::endl;

    std::cout
      << "La partie prend fin lorsqu'il ne reste plus aucun Pickomino visible sur la brochette."
      << std::endl;

    std::cout << "Chaque joueur va alors compter le nombre de vers qu'il possède." << std::endl;

    std::cout << "Le joueur ayant le plus de vers à remporté la partie." << std::endl;

    std::cout << "En cas d'égalité, le joueur ayant le Pickomino le plus élevé gagne." << std::endl;
    afficherSeparation();
}

void traiterLigne(const std::string& trame)
{
    size_t debutTrame = 0;

    while((debutTrame = trame.find('[', debutTrame)) != std::string::npos)
    {
        size_t      finTrame  = trame.find(']', debutTrame);
        std::string contenu   = trame.substr(debutTrame + 1, finTrame - debutTrame - 1);
        size_t      position1 = contenu.find(';');
        size_t      position2 = contenu.find(';', position1 + 1);

        std::string date  = contenu.substr(0, position1);
        std::string nom   = contenu.substr(position1 + 1, position2 - position1 - 1);
        std::string score = contenu.substr(position2 + 1);

        std::cout << "Date : " << date << std::endl;
        std::cout << "Nom du vainqueur : " << nom << std::endl;
        std::cout << "Score : " << score << " vers" << std::endl;
        std::cout << "---------------------------" << std::endl;

        debutTrame = finTrame + 1;
    }
}

void afficherHistorique()
{
    clearAffichage();
    std::cout << BOLD << "Historique des parties :\n" << RESET << std::endl;
    std::ifstream fichier(FICHIER_SCORE, std::ios::app);
    if(!fichier)
    {
        std::cout << BOLD << RED << "ERREUR : Impossible d'afficher l'historique des parties !"
                  << RESET << std::endl;
        return;
    }
    std::string ligne;
    while(std::getline(fichier, ligne))
    {
        traiterLigne(ligne);
    }
    fichier.close();
    afficherSeparation();
}

void effacerHistorique()
{
    std::ofstream fichier("docs/scores.txt", std::ios::trunc);
    if(!fichier)
    {
        std::cout << BOLD << RED << "ERREUR : Impossible d'effacer l'historique des parties !"
                  << RESET << std::endl;
        return;
    }

    fichier.close();
}

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
    afficherMessage("Le grand gagnant est : ");
    afficherMessage(jeu.joueurs[indexVainqueur].nom + " avec " +
                    std::to_string(jeu.joueurs[indexVainqueur].score) + " ver(s)");
}

// Affichage de jeu

void afficherBrochette(const Pickomino (&brochette)[NB_PICKOMINOS])
{
    int largeur = LARGEUR_MAX;

    std::string titreBrochette = "Brochette :";

    int espacesTitre = (largeur - (titreBrochette.size())) / 2;
    std::cout << std::string(espacesTitre, ' ') << titreBrochette << std::endl;
    std::cout << std::string(largeur, '-') << std::endl;

    std::string ligneValeur;
    std::string ligneNombreDeVers;

    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        std::string valeurAffichee;
        std::string versAffiche;

        if(brochette[i].etat == Pickomino::VISIBLE)
        {
            valeurAffichee = std::to_string(brochette[i].valeur);
            versAffiche    = std::to_string(brochette[i].nombreDeVers);
        }
        else if(brochette[i].etat == Pickomino::RETOURNE)
        {
            valeurAffichee = "X";
            versAffiche    = "X";
        }

        ligneValeur += valeurAffichee + std::string(4 - valeurAffichee.size(), ' ');
        ligneNombreDeVers += versAffiche + std::string(4 - versAffiche.size(), ' ');
    }

    int espacesLigneValeur = (largeur - (ligneValeur.size())) / 2;
    int espacesLigneVers   = (largeur - (ligneNombreDeVers.size())) / 2;

    if(espacesLigneValeur < 0)
        espacesLigneValeur = 0;
    if(espacesLigneVers < 0)
        espacesLigneVers = 0;

    std::cout << std::string(espacesLigneValeur, ' ') << ligneValeur << std::endl;
    std::cout << std::string(espacesLigneVers, ' ') << ligneNombreDeVers << std::endl;
    std::cout << std::string(largeur, '-') << std::endl;
}

void afficherJoueurs(const Jeu& jeu)
{
    for(unsigned int i = 0; i < jeu.nbJoueurs; ++i)
    {
        std::cout << "Joueur " << jeu.joueurs[i].numero << " : " << jeu.joueurs[i].nom << std::endl;
    }
}

void afficherDesLances(const int& nombreDes, const int (&desLances)[NB_DES])
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

void afficherDesRetenus(const int& nombreDes, const int (&desRetenus)[NB_DES])
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

void afficherScore(const int& score)
{
    std::cout << "La somme des valeurs des dés vous donne : " << score << std::endl;
}

bool afficherPileJoueurEnCours(const Joueur& joueur)
{
    std::cout << "Votre pile de pickomino" << (joueur.sommet > 1 ? "s : " : " : ") << std::endl;
    for(int i = joueur.sommet - 1; i >= 0; i--)
    {
        std::cout << joueur.pile[i].valeur << std::endl;
    }
    if(joueur.sommet == 0)
        std::cout << RED << "vide" << RESET << std::endl;
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

unsigned int saisirNbIa()
{
    unsigned int nbIa = 0;

    do
    {
        afficherMessage("Entrez le nombre d'IA : ", false);
        std::cin >> nbIa;
    } while(nbIa < NB_IA_MIN || nbIa > NB_IA_MAX);

    return nbIa;
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
    std::cout << "\n===================================================================="
                 "============\n"
              << std::endl;
}

void clearAffichage()
{
    system("clear");
}

int convertirValeur(std::string valeur)
{
    if(valeur == "V" || valeur == "v")
        return Face::VER;
    else
        return std::stoi(valeur);
}