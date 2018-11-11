#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(obtenerVecinosUnicosTEST, 2x2) {
    toroide t = {
            {true,  true},
            {false, false}
    };

    posicion p(0, 1);
    vector<posicion> ps = {
            posicion(1, 0),
            posicion(1, 1),
            posicion(0, 0)
    };

    EXPECT_EQ(obtenerVecinosUnicos(t, p), ps);
}

TEST(obtenerVecinosUnicosTEST, unaFilaTrueEnElMedio) {
    toroide t = {
        {false, true, false}
    };

    posicion p(0, 1);
    vector<posicion> ps = {
            posicion(0, 0),
            posicion(0, 2)
    };

    EXPECT_EQ(obtenerVecinosUnicos(t, p), ps);
}


