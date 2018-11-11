#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(filaTieneAlMenosUnaVivaTEST, toroideMuerto) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    posicion p(0,0);
    EXPECT_FALSE(filaTieneAlMenosUnaViva(t, p));
}

TEST(filaTieneAlMenosUnaVivaTEST, viva) {
    toroide t = {
            {false, false, false},
            {true,  false, false},
            {false, false, false}
    };

    posicion p(0,0);
    EXPECT_FALSE(filaTieneAlMenosUnaViva(t, p));
}

TEST(filaTieneAlMenosUnaVivaTEST, otrasVivas) {
    toroide t = {
            {false, true,  false},
            {false, false, false},
            {false, false, false}
    };

    posicion p(0,0);
    EXPECT_TRUE(filaTieneAlMenosUnaViva(t, p));
}