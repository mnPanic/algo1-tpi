#include "../../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(contarCantidadVivasTEST, dos) {
    toroide t = {
            {true,  true,  true},
            {false, false, false},
            {true,  false, true}
    };

    vector<posicion> ps = {
            posicion(0, 0),
            posicion(1, 0),
            posicion(1, 1),
            posicion(2, 2)
    };

    EXPECT_EQ(contarCantidadVivas(t, ps), 2);
}