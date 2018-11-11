#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(modTEST, nPositivoMayorAM){
    EXPECT_EQ(mod(14, 5), 4);
}

TEST(modTEST, nPositivoDivisiblePorM){
    EXPECT_EQ(mod(15, 5), 0);
}

TEST(modTEST, nPositivoMenorAM){
    EXPECT_EQ(mod(2, 5), 2);
}

TEST(modTEST, nNegativo){
    EXPECT_EQ(mod(-2, 5), 3);
}

TEST(modTEST, nCero){
    EXPECT_EQ(mod(0, 5), 0);
}