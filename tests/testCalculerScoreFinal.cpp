#include "doctest.h"
#include "../src/Plateau.h"

TEST_CASE("Test de calculerScoreFinalTour")
{
    // Cas avec "vers"
    int desRetenus1[NB_DES] = { 1, 2, 3, 4, VER }; // Le dernier dé est un "vers"
    int nombreDes1          = 5;

    // Le score sera la somme de tous les dés + la valeur du "vers"
    // 1 + 2 + 3 + 4 + 5 (le "vers") = 15
    int score1 = calculerScoreFinalTour(nombreDes1, desRetenus1);

    CHECK(score1 == 15); // Vérifie que le score est bien de 15

    // Cas sans "vers"
    int desRetenus2[NB_DES] = { 1, 2, 3, 4, 6 }; // Pas de "vers" ici
    int nombreDes2          = 5;

    // Ici, il n'y a pas de "vers", donc le score doit être 0
    int score2 = calculerScoreFinalTour(nombreDes2, desRetenus2);

    CHECK(score2 == 0); // Vérifie que le score est de 0
}