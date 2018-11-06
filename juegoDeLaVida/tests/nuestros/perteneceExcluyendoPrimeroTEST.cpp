#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(perteneceExcluyendoPrimeroTEST, excluido){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };
    toroide t2 = {
            {false, false, false},
            {false, true, false},
            {false, false, false}
    };
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);

    EXPECT_FALSE(perteneceExcluyendoPrimero(t1, ts));
}

TEST(perteneceExcluyendoPrimeroTEST, noPertenece){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };
    toroide t2 = {
            {false, false, false},
            {false, true, false},
            {false, false, false}
    };
    vector<toroide> ts;
    ts.push_back(t1);

    EXPECT_FALSE(perteneceExcluyendoPrimero(t2, ts));
}

TEST(perteneceExcluyendoPrimeroTEST, pertenece){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };
    toroide t2 = {
            {false, false, false},
            {false, true, false},
            {false, false, false}
    };
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t2);

    EXPECT_TRUE(perteneceExcluyendoPrimero(t2, ts));
}


TEST(perteneceExcluyendoPrimeroTEST, listaVacia){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true}
    };
    vector<toroide> ts;


    EXPECT_FALSE(perteneceExcluyendoUltimo(t, ts));
}