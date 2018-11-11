#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(cantidadVecinosVivosTEST, posicionCentral){
    toroide t = {
            {true,  true,  true},
            {false, false, false},
            {true,  false, true}
    };

    posicion p(1, 1);
    EXPECT_EQ(cantidadVecinosVivos(t, p), 5);
}

TEST(cantidadVecinosVivosTEST, posicionEsquina){
    toroide t = {
            {true,  true,  true},
            {false, false, false},
            {true,  false, true}
    };

    posicion p(0, 0);
    EXPECT_EQ(cantidadVecinosVivos(t, p), 4);
}

TEST(cantidadVecinosVivosTEST, repetidos){
    toroide t = {
            {true,  true},
            {false, false}
    };

    posicion p(1, 1);
    EXPECT_EQ(cantidadVecinosVivos(t, p), 2);
}

TEST(cantidadVecinosVivosTEST, 1x1){
    toroide t = {
            {true},
    };

    posicion p(0, 0);
    EXPECT_EQ(cantidadVecinosVivos(t, p), 0);
}