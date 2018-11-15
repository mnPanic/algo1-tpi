#include "../../../solucion.h"
#include "gtest/gtest.h"

using namespace std;


TEST(primosLejanosTEST, toroidesIgualesPeriodicos) {
    toroide t = {
            {true,  true,  false},
            {true,  true,  false},
            {false, false, false}
    };

    EXPECT_TRUE(primosLejanos(t, t));
}

TEST(primosLejanosTEST, toroidesIgualesNoPeriodicos) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, true,  false}
    };

    EXPECT_TRUE(primosLejanos(t, t));
}

TEST(primosLejanosTEST, evolucionNoInmediata) {
    toroide t1 = {
            {false, true,  false, false},
            {false, true,  true,  false},
            {false, false, true,  false},
            {false, false, false, false}
    };

    toroide t2 = {
            {true,  true,   true,  true},
            {true,  false,  false, true},
            {true,  true,   true,  true},
            {false, false, false, false}
    };

    EXPECT_TRUE(primosLejanos(t1, t2));
}