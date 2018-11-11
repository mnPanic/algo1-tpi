#include "../../../solucion.h"
#include "gtest/gtest.h"

using namespace std;

TEST(seleccionNaturalTEST, listaVacia){
    vector<toroide> ts;
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, -1);
}