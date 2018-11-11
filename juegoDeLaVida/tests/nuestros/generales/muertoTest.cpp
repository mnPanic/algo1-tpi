#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(muertoTest, toroideMuerto){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    EXPECT_TRUE(estaMuerto(t));
}

TEST(muertoTest, toroideNoMuerto){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true}
    };

    EXPECT_FALSE(estaMuerto(t));
}