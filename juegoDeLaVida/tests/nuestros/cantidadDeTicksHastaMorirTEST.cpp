#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


TEST(cantidadDeTicksHastaMorirTEST, toroideMuerto) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };
    EXPECT_EQ(cantidadDeTicksHastaMorir(t), 0);
}

TEST(cantidadDeTicksHastaMorirTEST, toroideVivoUnTicks) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, true, true}
    };
    EXPECT_EQ(cantidadDeTicksHastaMorir(t), 1);
}

TEST(cantidadDeTicksHastaMorirTEST, toroideVivoDosTicks) {
    toroide t = {
            {false, false, false},
            {false, false, true},
            {false, true, true}
    };
    EXPECT_EQ(cantidadDeTicksHastaMorir(t), 2);
}