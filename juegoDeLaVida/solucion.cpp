#include "solucion.h"

/************************************** GENERALES ***************************************/

int rows(toroide t) {
    return t.size();
}

int cols(toroide t) {
    int columnas = 0;

    if (!t.empty()) {
        columnas = t[0].size();
    }

    return columnas;
}

/********************************** EJERCICIO esValido **********************************/
bool noEsVacio(toroide t) {
    return (rows(t) > 0) && (cols(t) > 0);
}

bool esMatrizValida(toroide t) {
    // bool esValida = true;
    // for (int i = 0; i < rows(t) && esValida; i++) {
    //     if (t[i].size() != cols(t)){
    //         esValida = false;
    //     }
    // }
    // return esValida;

    int i = 0;
    while (i < rows(t) && t[i].size() == cols(t)) {
        i++;
    }

    return i == rows(t);
}

bool esValido(toroide t){
    return noEsVacio(t) && esMatrizValida(t);
}

/****************************** EJERCICIO posicionesVivas *******************************/
vector<posicion> posicionesVivas(toroide t){
    vector<posicion> res;
    return res;
}

/***************************** EJERCICIO densidadPoblacion ******************************/
float densidadPoblacion(toroide t){
    float densidad = 0.0;
    return densidad;
}

/**************************** EJERCICIO evolucionDePosicion *****************************/
bool evolucionDePosicion(toroide t, posicion p){
    return true;
}

/****************************** EJERCICIO evolucionToroide ******************************/
void evolucionToroide(toroide& t){
}

/***************************** EJERCICIO evolucionMultiple ******************************/
toroide evolucionMultiple(toroide t, int k){
    toroide result;
    return result;
}

/******************************** EJERCICIO esPeriodico *********************************/
bool esPeriodico(toroide t, int& p){
    return false;
}

/******************************* EJERCICIO primosLejanos ********************************/
bool primosLejanos(toroide t1, toroide t2) {
    return false;
}

/****************************** EJERCICIO seleccionNatural ******************************/
int seleccionNatural(vector<toroide> ts){
    int indice;
    return indice;
}

/********************************** EJERCICIO fusionar **********************************/
toroide fusionar(toroide t1, toroide t2){
    toroide t;
    return t;
}

/****************************** EJERCICIO vistaTrasladada *******************************/
bool vistaTrasladada(toroide t1, toroide t2){
    bool res = false;
    return res;
}

/******************************* EJERCICIO enCrecimiento ********************************/
bool enCrecimiento(toroide t){
    bool res;
    return res;
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/
bool soloBloques(toroide t){
    bool res;
    return res;
}
