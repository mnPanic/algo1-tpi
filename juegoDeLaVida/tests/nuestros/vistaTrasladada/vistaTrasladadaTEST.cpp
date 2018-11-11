#include "../../../solucion.h"
#include "gtest/gtest.h"

using namespace std;

TEST(vistaTrasladadaTEST, diferenteDimension) {
    toroide t1 = {
            {false, false, false},
            {true,  true,  false},
            {false, false, false}
    };
    toroide t2 = {
            {false, false},
            {true,  true}
    };

    EXPECT_FALSE(vistaTrasladada(t1, t2));
}
