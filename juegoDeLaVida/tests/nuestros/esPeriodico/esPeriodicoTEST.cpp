#include "../../../solucion.h"
#include "gtest/gtest.h"

using namespace std;

TEST(esPeriodicoTEST, toroideBloque) {
    toroide t = {
            {true,  true,  false},
            {true,  true,  false},
            {false, false, false}
    };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}