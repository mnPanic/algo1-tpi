#include "../../solucion.h"
#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(minimaSuperficieDeTraslacionesQueCubreTEST, toroideVivo){
    toroide t = {
            {true, true, true},
            {true, true, true},
            {true, true, true}
    };

    EXPECT_EQ(minimaSuperficieDeTraslacionesQueCubre(t), 9);
}

TEST(minimaSuperficieDeTraslacionesQueCubreTEST, toroideMuerto){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    EXPECT_EQ(minimaSuperficieDeTraslacionesQueCubre(t), 0);
}

TEST(minimaSuperficieDeTraslacionesQueCubreTEST, miniL){
    toroide t = {
            {true,  false, false},
            {true,  true,  false},
            {false, false, false}
    };

    EXPECT_EQ(minimaSuperficieDeTraslacionesQueCubre(t), 4);
}

TEST(minimaSuperficieDeTraslacionesQueCubreTEST, bloque){
    toroide t = {
        {false, true,  true},
        {false, false, false},
        {false, true,  true}
    };

    EXPECT_EQ(minimaSuperficieDeTraslacionesQueCubre(t), 4);
}

TEST(minimaSuperficieDeTraslacionesQueCubreTEST, columnasSeparadas){
    toroide t = {
            {true, false, true},
            {true, false, true},
            {true, false, true}
    };

    EXPECT_EQ(minimaSuperficieDeTraslacionesQueCubre(t), 6);
}