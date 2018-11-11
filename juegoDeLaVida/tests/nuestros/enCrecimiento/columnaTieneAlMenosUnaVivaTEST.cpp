#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(columnaTieneAlMenosUnaVivaTEST, toroideMuerto) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    posicion p(0,0);
    EXPECT_FALSE(columnaTieneAlMenosUnaViva(t, p));
}

TEST(columnaTieneAlMenosUnaVivaTEST, viva) {
    toroide t = {
            {false, false, false},
            {true,  false, false},
            {false, false, false}
    };

    posicion p(0,0);
    EXPECT_TRUE(columnaTieneAlMenosUnaViva(t, p));
}

TEST(columnaTieneAlMenosUnaVivaTEST, otrasVivas) {
    toroide t = {
            {false, true,  false},
            {false, false, false},
            {false, false, false}
    };

    posicion p(0,0);
    EXPECT_FALSE(columnaTieneAlMenosUnaViva(t, p));
}