#include "../../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(obtenerEsquinasQueEncierranPosVivasTEST, toroideMuerto) {
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };

    vector<posicion> esquinas = {
            posicion(0,0),
            posicion(-1,-1)
    };
    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, unaSola) {
    toroide t = {
            {true, false, false},
            {false, false, false},
            {false, false, false}
    };

    vector<posicion> esquinas = {
            posicion(0,0),
            posicion(0,0)
    };
    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, toroideVivo) {
    toroide t = {
            {true, true, true},
            {true, true, true},
            {true, true, true}
    };

    vector<posicion> esquinas = {
            posicion(0,0),
            posicion(2,2)
    };

    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, 1x1) {
    toroide t = {
            {false, false, false},
            {false, true,  false},
            {false, false, false}
    };

    vector<posicion> esquinas = {
            posicion(1,1),
            posicion(1,1)
    };

    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, columna) {
    toroide t = {
            {false, true, false},
            {false, true, false},
            {false, true, false}
    };

    vector<posicion> esquinas = {
            posicion(0,1),
            posicion(2,1)
    };


    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}


TEST(obtenerEsquinasQueEncierranPosVivasTEST, fila) {
    toroide t = {
            {false, false, false},
            {true,  true,  false},
            {false, false, false}
    };
    vector<posicion> esquinas = {
            posicion(1,0),
            posicion(1,1)
    };

    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, L) {
    toroide t = {
            {true, false, false},
            {true, false, false},
            {true, true, false}
    };

    vector<posicion> esquinas = {
            posicion(0,0),
            posicion(2,1)
    };

    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, costados) {
    toroide t = {
            {true, false, true},
            {true, false, true},
            {true, false, true}
    };

    vector<posicion> esquinas = {
            posicion(0,0),
            posicion(2,2)
    };

    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, tetris) {
    toroide t = {
            {false, true, false},
            {true,  true, false},
            {false, true, false}
    };

    vector<posicion> esquinas = {
            posicion(0,0),
            posicion(2,1)
    };

    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, formaRara) {
    toroide t = {
            {false, true, false},
            {true,  true, false},
            {false, true, true}
    };

    vector<posicion> esquinas = {
            posicion(0,0),
            posicion(2,2)
    };

    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}

TEST(obtenerEsquinasQueEncierranPosVivasTEST, columnasDerecha) {
    toroide t = {
            {false, true, true},
            {false, true, true},
            {false, true, true}
    };

    vector<posicion> esquinas = {
            posicion(0,1),
            posicion(2,2)
    };
    EXPECT_EQ(obtenerEsquinasQueEncierranPosVivas(t), esquinas);
}