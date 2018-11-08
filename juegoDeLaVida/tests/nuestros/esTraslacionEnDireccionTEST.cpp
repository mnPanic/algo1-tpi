#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(esTraslacionEnDireccionTEST, direccionCero) {
    toroide t = {
        {false, false, false},
        {true,  true,  false},
        {false, false, false}
    };

    direccion d(0, 0);
    EXPECT_TRUE(esTraslacionEnDireccion(t, t, d));
}


TEST(esTraslacionEnDireccionTEST, toroideMuerto) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    direccion d1(27, 19);
    direccion d2(-9, 10);

    EXPECT_TRUE(esTraslacionEnDireccion(t, t, d1));
    EXPECT_TRUE(esTraslacionEnDireccion(t, t, d2));
}

TEST(esTraslacionEnDireccionTEST, toroideVivo) {
    toroide t = {
            {true, true, true},
            {true, true, true},
            {true, true, true}
    };

    direccion d1(27, 19);
    direccion d2(-9, 10);

    EXPECT_TRUE(esTraslacionEnDireccion(t, t, d1));
    EXPECT_TRUE(esTraslacionEnDireccion(t, t, d2));
}

TEST(esTraslacionEnDireccionTEST, direccionUnitariaPositiva) {
    toroide t1 = {
            {true,  false, false},
            {false, true,  false},
            {false, false, false}
    };

    toroide t2 = {
            {false, false, false},
            {false, true, false},
            {false, false, true}
    };

    direccion d(1, 1);
    EXPECT_TRUE(esTraslacionEnDireccion(t1, t2, d));
}

TEST(esTraslacionEnDireccionTEST, direccionCualquiera) {
    toroide t1 = {
            {true,  false,  true},
            {false, false, false},
            {false, false, false}
    };

    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {true, true, false}
    };

    direccion d(5, -2);
    EXPECT_TRUE(esTraslacionEnDireccion(t1, t2, d));
}