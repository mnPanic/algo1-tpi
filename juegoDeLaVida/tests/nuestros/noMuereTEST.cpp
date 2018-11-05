#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(noMuereTEST, toroideMuerto){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    EXPECT_FALSE(noMuere(t));
}

TEST(noMuereTEST, toroidePeriodico){
    toroide t = {
            {true, true, false},
            {true, true, false},
            {false, false, false}
    };

    EXPECT_TRUE(noMuere(t));
}