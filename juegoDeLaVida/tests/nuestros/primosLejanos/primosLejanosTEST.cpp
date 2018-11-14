#include "../../../solucion.h"
#include "gtest/gtest.h"

using namespace std;


TEST(primosLejanosTEST, toroidesIgualesPeriodicos) {
    toroide t = {
            {true,  true,  false},
            {true,  true,  false},
            {false, false, false}
    };

    EXPECT_TRUE(primosLejanos(t, t));


}
TEST(primosLejanosTEST, toroidesIgualesNoPeriodicos) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, true,  false}
    };

    EXPECT_TRUE(primosLejanos(t, t));


}