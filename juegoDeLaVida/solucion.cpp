#include "solucion.h"

#include "auxiliares.h"

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

/**
 * Dado un toroide y una posicion válida,
 * retorna si esa posición está viva.
 */
bool estaViva(toroide t, posicion p) {
    return t[get<0>(p)][get<1>(p)];
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

    for (int i = 0; i < rows(t); i++){
        for (int j = 0; j < cols(t); j++) {
            posicion p(i, j);
            if (estaViva(t, p)) {
                res.push_back(p);
            }
        }
    }

    return res;
}

/***************************** EJERCICIO densidadPoblacion ******************************/
int superficieTotal(toroide t) {
    return rows(t) * cols(t);
}

int cantidadVivas(toroide t){
    return posicionesVivas(t).size();
}

float densidadPoblacion(toroide t){
    float densidad = (float) cantidadVivas(t) / superficieTotal(t);
    return densidad;
}

/**************************** EJERCICIO evolucionDePosicion *****************************/
/**
 * Dados n entero y m natural,
 * devuelve el resto en la división entera de n por m.
 */
int mod(int n, int m) {
    while (n >= m || n < 0) {
        n = (n < 0) ? n + m : n - m;
    }
    return n;
}

/**
 * Traslada una posicion en una dirección dentro de un toroide,
 * teniendo en cuenta las propiedades del mismo.
 */
posicion trasladar(toroide t, posicion p, tuple<int, int> dir) {
    posicion pTransladada(
            mod((get<0>(p) + get<0>(dir)), rows(t)),
            mod((get<1>(p) + get<1>(dir)), cols(t)));
    return pTransladada;
}

int cantidadVecinosVivos(toroide t, posicion p) {
    int vecinosVivos = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            tuple<int, int> dir(i, j);
            posicion pTrasladada = trasladar(t, p, dir);

            if (estaViva(t, pTrasladada)) {
                vecinosVivos++;
            }
        }
    }

    if (estaViva(t, p)) {
        // Ya que al ver todas las traslaciones, la (0, 0) sería
        // la misma posición, la cual no queremos contar como vecina.
        vecinosVivos--;
    }

    return vecinosVivos;
}

bool debeVivir(toroide t, posicion p) {
    bool vive;

    int vecinosVivos = cantidadVecinosVivos(t, p);

    if (estaViva(t, p)) {
        vive = (2 <= vecinosVivos) && (vecinosVivos <= 3);
    } else {
        vive = (vecinosVivos == 3);
    }

    return vive;
}

bool evolucionDePosicion(toroide t, posicion p) {
    return debeVivir(t, p);
}

/****************************** EJERCICIO evolucionToroide ******************************/
void evolucionToroide(toroide& t){
    toroide original = t;
    for (int i = 0; i < rows(original); i++) {
        for (int j = 0; j < cols(original); j++) {
            t[i][j] = evolucionDePosicion(original, posicion(i,j));
        }
    }
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
