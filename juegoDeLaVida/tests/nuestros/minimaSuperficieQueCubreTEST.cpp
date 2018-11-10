#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(minimaSuperficieQueCubreTEST, toroideMuerto) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 0);
}

TEST(minimaSuperficieQueCubreTEST, toroideVivo) {
    toroide t = {
            {true, true, true},
            {true, true, true},
            {true, true, true}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 9);
}

TEST(minimaSuperficieQueCubreTEST, 1x1) {
    toroide t = {
            {false, false, false},
            {false, true,  false},
            {false, false, false}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 1);
}

TEST(minimaSuperficieQueCubreTEST, columna) {
    toroide t = {
            {false, true, false},
            {false, true, false},
            {false, true, false}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 3);
}


TEST(minimaSuperficieQueCubreTEST, fila) {
    toroide t = {
            {false, false, false},
            {true,  true,  false},
            {false, false, false}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 2);
}

TEST(minimaSuperficieQueCubreTEST, L) {
    toroide t = {
            {true, false, false},
            {true, false, false},
            {true, true, false}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 6);
}

TEST(minimaSuperficieQueCubreTEST, costados) {
    toroide t = {
            {true, false, true},
            {true, false, true},
            {true, false, true}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 9);
}

TEST(minimaSuperficieQueCubreTEST, tetris) {
    toroide t = {
            {false, true, false},
            {true,  true, false},
            {false, true, false}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 6);
}

TEST(minimaSuperficieQueCubreTEST, formaRara) {
    toroide t = {
            {false, true, false},
            {true,  true, false},
            {false, true, true}
    };

    EXPECT_EQ(minimaSuperficieQueCubre(t), 9);
}