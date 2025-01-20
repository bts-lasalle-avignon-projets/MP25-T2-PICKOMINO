#include "doctest.h"
#include "../src/Plateau.h"

TEST_CASE("Valide : Score avec ver(s)")
{
    SUBCASE("TEST 2.1 : 8 Dés - 2 ver")
    {
        int desRetenus1[NB_DES] = { 6, 5, 4, 6, 3, 2, 4, 1 };
        int nombreDes1          = 8;
        REQUIRE(calculerScoreFinalTour(nombreDes1, desRetenus1) == 29);
    }

    SUBCASE("TEST 2.2 : 4 Dés - 1 ver")
    {
        int desRetenus1[NB_DES] = { 5, 4, 3, 6 };
        int nombreDes1          = 4;
        REQUIRE(calculerScoreFinalTour(nombreDes1, desRetenus1) == 17);
    }

    SUBCASE("TEST 2.3 : 1 Dé - 1 Ver")
    {
        int desRetenus1[NB_DES] = { 6 };
        int nombreDes1          = 0;
        REQUIRE(calculerScoreFinalTour(nombreDes1, desRetenus1) == 5);
    }
}

TEST_CASE("Invalide : Score sans ver")
{
    SUBCASE("TEST 2.4 : 8 Dés sans ver")
    {
        int desRetenus1[NB_DES] = { 3, 1, 1, 2, 4, 1, 2, 5 };
        int nombreDes1          = 8;
        REQUIRE(calculerScoreFinalTour(nombreDes1, desRetenus1) == 0);
    }

    SUBCASE("TEST 2.5 : 4 Dés sans ver")
    {
        int desRetenus1[NB_DES] = { 4, 5, 2, 3 };
        int nombreDes1          = 4;
        REQUIRE(calculerScoreFinalTour(nombreDes1, desRetenus1) == 0);
    }

    SUBCASE("TEST 2.6 : Tableau vide")
    {
        int desRetenus1[NB_DES] = {};
        int nombreDes1          = 0;
        REQUIRE(calculerScoreFinalTour(nombreDes1, desRetenus1) == 0);
    }
}