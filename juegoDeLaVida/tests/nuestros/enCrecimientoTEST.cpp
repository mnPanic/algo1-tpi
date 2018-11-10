#include "../../solucion.h"
#include "gtest/gtest.h"

using namespace std;

TEST(enCrecimientoTEST, bloque){
    toroide t1 = {
            {false, true,  true},
            {false, false, false},
            {false, true,  true}};
    EXPECT_FALSE(enCrecimiento(t1));
}


TEST(enCrecimientoTEST, miniL){
    // se convierte en todo true
    toroide t1 = {
            {true,  false, false},
            {true,  true,  false},
            {false, false, false}};
    EXPECT_TRUE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, toroideQueMuere){
    toroide t1 = {
            {false, false, false},
            {false, true,  false},
            {false, false, false}};

    EXPECT_FALSE(enCrecimiento(t1));
}
