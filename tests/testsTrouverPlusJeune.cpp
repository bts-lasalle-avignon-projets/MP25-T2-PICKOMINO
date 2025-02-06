#include "doctest.h"
#include "../src/Jeu.h"
#include "../src/Joueur.h"

TEST_CASE("Partie sans IA")
{
    SUBCASE("TEST 3.1 : 2 joueurs")
    {
        Jeu jeu;
        jeu.nbJoueurs = 2;
        jeu.joueurs[0] = {"Marie", 25};
        jeu.joueurs[1] = {"James", 20};
        
        CHECK(trouverPlusJeune(jeu) == 1);
    }

    SUBCASE("TEST 3.2 : 4 joueurs")
    {
        Jeu jeu;
        jeu.nbJoueurs = 4;
        jeu.joueurs[0] = {"Alice", 22};
        jeu.joueurs[1] = {"John", 20};
        jeu.joueurs[2] = {"William", 18};
        jeu.joueurs[3] = {"David", 19};

        CHECK(trouverPlusJeune(jeu) == 2);
    }

    SUBCASE("TEST 3.3 : 7 joueurs")
    {
        Jeu jeu;
        jeu.nbJoueurs = 7;
        jeu.joueurs[0] = {"Alice", 22};
        jeu.joueurs[1] = {"Paul", 20};
        jeu.joueurs[2] = {"Charles", 18};
        jeu.joueurs[3] = {"Anthony", 19};
        jeu.joueurs[4] = {"Lisa", 17};
        jeu.joueurs[5] = {"Frank", 16};
        jeu.joueurs[6] = {"Grace", 15};

        CHECK(trouverPlusJeune(jeu) == 6);
    }
}

TEST_CASE("Partie avec IA")
{
    SUBCASE("TEST 3.4 : 2 joueurs dont 1 IA")
    {
        Jeu jeu;
        jeu.nbJoueurs = 2;
        jeu.joueurs[0] = {"Lisa", 25};
        jeu.joueurs[1] = {"IA 1", 100};

        CHECK(trouverPlusJeune(jeu) == 0);
    }

    SUBCASE("TEST 3.5: 4 joueurs dont 2 IA")
    {
        Jeu jeu;
        jeu.nbJoueurs = 4;
        jeu.joueurs[0] = {"Alice", 22};
        jeu.joueurs[1] = {"Steven", 20};
        jeu.joueurs[2] = {"IA 1", 100};
        jeu.joueurs[3] = {"IA 2", 100};

        CHECK(trouverPlusJeune(jeu) == 1);
    }

    SUBCASE("TEST 3.6 : 6 joueurs dont 2 IA")
    {
        Jeu jeu;
        jeu.nbJoueurs = 6;
        jeu.joueurs[0] = {"Amanda", 22};
        jeu.joueurs[1] = {"Jason", 20};
        jeu.joueurs[2] = {"Jacob", 18};
        jeu.joueurs[3] = {"Melissa", 17};
        jeu.joueurs[4] = {"IA 1", 100};
        jeu.joueurs[5] = {"IA 2", 100};

        CHECK(trouverPlusJeune(jeu) == 3);
    }
}