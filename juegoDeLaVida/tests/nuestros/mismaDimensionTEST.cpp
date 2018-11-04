#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


TEST(mismaDimensionTEST, toroidesConDimensionesIguales) {
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    toroide t2 = {
            {false, true,  false},
            {false, true,  false},
            {false, false, false}
    };

    toroide t3 = {
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    toroide t4 = {
            {false, true,  false},
            {false, true,  false},
            {false, false, false},
            {false, true,  false}
    };
    EXPECT_TRUE(mismaDimension(t1, t2));
    EXPECT_TRUE(mismaDimension(t3, t4));
}

TEST(mismaDimensionTEST, toroidesColumnasDiferentes) {
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    toroide t2 = {
            {false, true,  false, true},
            {false, true,  false, true},
            {false, false, false, false}
    };
    EXPECT_FALSE(mismaDimension(t1, t2));
}

TEST(mismaDimensionTEST, toroidesFilasDiferentes) {
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    toroide t2 = {
            {false, true,  false},
            {false, true,  false},
            {false, false, false},
            {false, false, false}
    };
    EXPECT_FALSE(mismaDimension(t1, t2));
}