#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


TEST(esEstrictamenteEvolucionTEST, igualToroidePeriodico) {
    toroide t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false}
    };

    int p = 0;
    EXPECT_TRUE(esEstrictamenteEvolucion(t, t, p));
    EXPECT_EQ(p, 2);
}

TEST(esEstrictamenteEvolucionTEST, igualToroidePeriodicoBloque) {
    toroide t = {
            {false, false, false, false, false},
            {false, true, true, false, false},
            {false, true, true, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}
    };

    int p = 0;
    EXPECT_TRUE(esEstrictamenteEvolucion(t, t, p));
    EXPECT_EQ(p, 1);
}

TEST(esEstrictamenteEvolucionTEST, igualToroideMuerto) {
    toroide t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}
    };

    int p = 0;
    EXPECT_TRUE(esEstrictamenteEvolucion(t, t, p));
    EXPECT_EQ(p, 1);
}


TEST(esEstrictamenteEvolucionTEST, igualToroideFalsoPeriodico) {
    // se convierte en un bloque
    toroide t = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false}
    };

    int p = 0;
    EXPECT_FALSE(esEstrictamenteEvolucion(t, t, p));
    EXPECT_EQ(p, 0);
}


TEST(esEstrictamenteEvolucionTEST, diferentesEvolucion) {
    // se convierte en un bloque
    toroide t1 = {
            {false, false, false, false},
            {false, true, false, false},
            {false, true, true, false},
            {false, false, false, false},
    };
    toroide t2 = {
            {false, false, false, false},
            {false, true, true, false},
            {false, true, true, false},
            {false, false, false, false},
    };

    int p = 0;
    EXPECT_TRUE(esEstrictamenteEvolucion(t1, t2, p));
    EXPECT_EQ(p, 1);
}


TEST(esEstrictamenteEvolucionTEST, diferentesPeriodicoAntes) {
    // se convierte en un bloque, volviendose periódico antes de llegar a t2
    toroide t1 = {
            {false, false, false, false},
            {false, true, false, false},
            {false, true, true, false},
            {false, false, false, false},
    };
    toroide t2 = {
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
    };

    int p = 0;
    EXPECT_FALSE(esEstrictamenteEvolucion(t1, t2, p));
    EXPECT_EQ(p, 0);
}