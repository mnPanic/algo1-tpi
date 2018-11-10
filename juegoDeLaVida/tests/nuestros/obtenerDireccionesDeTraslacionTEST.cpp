#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


TEST(obtenerDireccionesDeTraslacionTEST, 3x3) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    vector<posicion> dir = {
            posicion(0, 0),
            posicion(0, 1),
            posicion(0, 2),
            posicion(1, 0),
            posicion(1, 1),
            posicion(1, 2),
            posicion(2, 0),
            posicion(2, 1),
            posicion(2, 2)
    };

    EXPECT_EQ(obtenerDireccionesDeTraslacion(t), dir);
}

TEST(obtenerDireccionesDeTraslacionTEST, 2x2) {
    toroide t = {
            {false, false},
            {false, false}
    };

    vector<posicion> dir = {
        posicion(0, 0),
        posicion(0, 1),
        posicion(1, 0),
        posicion(1, 1),
    };

    EXPECT_EQ(obtenerDireccionesDeTraslacion(t), dir);
}

TEST(obtenerDireccionesDeTraslacionTEST, 1x1) {
    toroide t = {
            {false},
    };

    vector<posicion> dir = {
            posicion(0, 0),
    };

    EXPECT_EQ(obtenerDireccionesDeTraslacion(t), dir);
}