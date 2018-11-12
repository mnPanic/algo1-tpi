#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(obtenerVecinosTEST, 3x3) {
    toroide t = {
            {true,  true,  false},
            {false, false, false},
            {false, false, false}
    };

    posicion p(1, 1);
    vector<posicion> ps = {
            posicion(0, 0),
            posicion(0, 1),
            posicion(0, 2),
            posicion(1, 0),
            posicion(1, 2),
            posicion(2, 0),
            posicion(2, 1),
            posicion(2, 2)
    };

    EXPECT_EQ(obtenerVecinos(t, p), ps);
}

TEST(obtenerVecinosTEST, 2x2) {
    toroide t = {
            {true,  true},
            {false, false}
    };

    posicion p(0, 1);
    vector<posicion> ps = {
            posicion(1, 0),
            posicion(1, 1),
            posicion(1, 0),
            posicion(0, 0),
            posicion(0, 0),
            posicion(1, 0),
            posicion(1, 1),
            posicion(1, 0)
    };

    EXPECT_EQ(obtenerVecinos(t, p), ps);
}

TEST(obtenerVecinosTEST, unaFilaTrueEnElMedio) {
    toroide t = {
        {false, true, false}
    };

    posicion p(0, 1);
    vector<posicion> ps = {
            posicion(0, 0),
            posicion(0, 1),
            posicion(0, 2),
            posicion(0, 0),
            posicion(0, 2),
            posicion(0, 0),
            posicion(0, 1),
            posicion(0, 2)
    };

    EXPECT_EQ(obtenerVecinos(t, p), ps);
}


