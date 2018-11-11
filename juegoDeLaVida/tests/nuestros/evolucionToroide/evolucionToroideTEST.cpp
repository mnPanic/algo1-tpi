#include "../../../solucion.h"
#include "gtest/gtest.h"

TEST(evolucionToroideTEST, toroideDiagonalSeHaceTodoTrue){
    toroide t1 = {
      {true, false, false},
      {false, true, false},
      {false, false, true}
    };
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};

    evolucionToroide(t1);
    EXPECT_EQ(t1, t2);
}