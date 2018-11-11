#include "../../../auxiliares.h"
#include "gtest/gtest.h"

TEST(trasladarTEST, direccionesUnitarias){
    toroide t = {
        {true, false, false},
        {false, true, false},
        {false, false, true}
    };
    posicion pos(0, 0);
    EXPECT_EQ(trasladar(t, pos, make_tuple(-1, -1)), make_tuple(2,2));
    EXPECT_EQ(trasladar(t, pos, make_tuple(-1, 0)),  make_tuple(2,0));
    EXPECT_EQ(trasladar(t, pos, make_tuple(-1, 1)),  make_tuple(2,1));
    EXPECT_EQ(trasladar(t, pos, make_tuple(0, -1)),  make_tuple(0,2));
    EXPECT_EQ(trasladar(t, pos, make_tuple(0, 1)),   make_tuple(0,1));
    EXPECT_EQ(trasladar(t, pos, make_tuple(0, 0)),   make_tuple(0,0));
    EXPECT_EQ(trasladar(t, pos, make_tuple(1, -1)),  make_tuple(1,2));
    EXPECT_EQ(trasladar(t, pos, make_tuple(1, 0)),   make_tuple(1,0));
    EXPECT_EQ(trasladar(t, pos, make_tuple(1, 1)),   make_tuple(1,1));
}

TEST(trasladarTEST, direccionesNoUnitarias){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true}
    };
    posicion pos(0, 0);
    EXPECT_EQ(trasladar(t, pos, make_tuple(-5, -1)), make_tuple(1,2));
    EXPECT_EQ(trasladar(t, pos, make_tuple(10, 69)), make_tuple(1,0));


}