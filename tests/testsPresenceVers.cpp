#include "doctest.h"
#include "../src/Plateau.h"

TEST_CASE("Valide : VER PRESENT")
{
    SUBCASE("TEST 1.1 : 8 Dés - Ver présent")
    {
        int desRetenus1[NB_DES] = { 2, 5, 4, 6, 3, 2, 4, 1 };
        int nombreDes1          = 8;

        REQUIRE(verifierPresenceVers(nombreDes1, desRetenus1) == true);
    }

    SUBCASE("TEST 1.2 : 4 Dés - Ver présent")
    {
        int desRetenus1[NB_DES] = { 5, 4, 3, 6 };
        int nombreDes1          = 4;

        REQUIRE(verifierPresenceVers(nombreDes1, desRetenus1) == true);
    }

    SUBCASE("TEST 1.3 : 1 Dé - Ver présent")
    {
        int desRetenus1[NB_DES] = { 6 };
        int nombreDes1          = 1;

        REQUIRE(verifierPresenceVers(nombreDes1, desRetenus1) == true);
    }
}

TEST_CASE("Invalide : AUCUN VERS")
{
    SUBCASE("TEST 1.4 : 8 Dés - Ver présent")
    {
        int desRetenus1[NB_DES] = { 3, 1, 1, 2, 4, 1, 2, 5 };
        int nombreDes1          = 8;

        REQUIRE(verifierPresenceVers(nombreDes1, desRetenus1) == false);
    }

    SUBCASE("TEST 1.5 : 4 Dés - Ver présent")
    {
        int desRetenus1[NB_DES] = { 4, 5, 2, 3 };
        int nombreDes1          = 4;

        REQUIRE(verifierPresenceVers(nombreDes1, desRetenus1) == false);
    }

    SUBCASE("TEST 1.6 : Tableau vide")
    {
        int desRetenus1[NB_DES] = {};
        int nombreDes1          = 0;

        REQUIRE(verifierPresenceVers(nombreDes1, desRetenus1) == false);
    }
}