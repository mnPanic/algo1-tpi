#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(perteneceTEST, perteneceEnElMedio) {
    vector<posicion> ps = {
            posicion(0, 0),
            posicion(1, 0),
            posicion(1, 1),
            posicion(2, 2)
    };

    posicion p(1, 1);

    EXPECT_TRUE(pertenece(p, ps));
}

TEST(perteneceTEST, perteneceEnElFinal) {
    vector<posicion> ps = {
            posicion(0, 0),
            posicion(1, 0),
            posicion(1, 1),
            posicion(2, 2)
    };

    posicion p(2, 2);

    EXPECT_TRUE(pertenece(p, ps));
}

TEST(perteneceTEST, noPertenece) {
    vector<posicion> ps = {
            posicion(0, 0),
            posicion(1, 0),
            posicion(1, 1),
            posicion(2, 2)
    };

    posicion p(4, 4);

    EXPECT_FALSE(pertenece(p, ps));
}

TEST(perteneceTEST, listaVacia) {
    vector<posicion> ps = {};
    posicion p(1, 1);

    EXPECT_FALSE(pertenece(p, ps));
}