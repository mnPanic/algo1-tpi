#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(trasladarToroideTEST, toroideMuerto) {
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    direccion dir(2, 2);
    EXPECT_EQ(trasladarToroide(t1, dir), t1);
}

TEST(trasladarToroideTEST, toroideVivo) {
    toroide t1 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}
    };

    direccion dir(2, 2);
    EXPECT_EQ(trasladarToroide(t1, dir), t1);
}

TEST(trasladarToroideTEST, L) {
    toroide t1 = {
            {true, false, false},
            {true, false, false},
            {true, true,  true}
    };
    toroide t2 = {
            {true, true,  true},
            {true, false, false},
            {true, false, false}
    };

    direccion dir(1, 0);
    EXPECT_EQ(trasladarToroide(t1, dir), t2);
}

TEST(trasladarToroideTEST, tetris) {
    toroide t1 = {
            {false,  false, false},
            {false, true, false},
            {true,  true,  true}
    };
    toroide t2 = {
            {false, false, false},
            {true, false, false},
            {true, true,  true}
    };

    direccion dir(0, 2);
    EXPECT_EQ(trasladarToroide(t1, dir), t2);
}

TEST(trasladarToroideTEST, bloqueEscondido) {
    toroide t1 = {
            {false,  true,  true},
            {false,  false, false},
            {false,  true,  true}
    };
    toroide t2 = {
            {true,  true,  false},
            {true,  true,  false},
            {false, false, false}
    };

    direccion dir(1, 2);
    EXPECT_EQ(trasladarToroide(t1, dir), t2);
}



