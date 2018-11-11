#include "../../../solucion.h"
#include "gtest/gtest.h"

using namespace std;

TEST(soloBloquesTEST, soloBloquesConTraslacion){

    toroide t = {
            {true,  false, true,  true,  false, false, false, false, true},
            {true,  false, true,  true,  false, false, false, false, true},
            {false, false, false, false, false, true,  true,  false, false},
            {false, false, false, false, false, true,  true,  false, false}
    };

    EXPECT_TRUE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideMuerto){

    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideVivo){

    toroide t = {
            {true, true, true},
            {true, true, true},
            {true, true, true}
    };

    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, bloqueIncompleto){

    toroide t = {
            {false, false, false, false},
            {true,  false, false, false},
            {true,  true,  false, false}
    };

    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, bloqueConBordeConUnaViva){

    toroide t = {
            {false, true,  false, false},
            {true,  true,  false, false},
            {true,  true,  false, false}
    };

    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideConBloquePeroMuyPequeño){

    toroide t = {
            {true, true},
            {true, true}
    };

    EXPECT_FALSE(soloBloques(t));
}
TEST(soloBloquesTEST, toroideConDimensionInsuficienteParaUnBloque){

    toroide t = {
            {true}
    };

    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, bloqueEsquinas){

    toroide t = {
            {true,  false, false, true},
            {false, false, false, false},
            {false, false, false, false},
            {true,  false, false, true}

    };

    EXPECT_TRUE(soloBloques(t));
}
