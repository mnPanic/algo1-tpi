#include "solucion.h"

#include "auxiliares.h"

/************************************** GENERALES ***************************************/

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


bool mismaDimension (toroide t1, toroide t2) {
    return (rows(t1) == rows(t2)) && (cols(t1) == cols(t2));
}

/**
 * Traslada una posicion en una dirección dentro de un toroide,
 * teniendo en cuenta las propiedades del mismo.
 */
posicion trasladar(toroide t, posicion p, direccion dir) {
    posicion pTransladada(
            mod((get<0>(p) + get<0>(dir)), rows(t)),
            mod((get<1>(p) + get<1>(dir)), cols(t)));
    return pTransladada;
}

/**
 * Dado un toroide y una posicion válida,
 * retorna si esa posición está viva.
 */
bool estaViva(toroide t, posicion p) {
    return t[get<0>(p)][get<1>(p)];
}

bool estaMuerto(toroide t) {
    bool muerto = true;
    for (int i = 0; i < rows(t) && muerto; i++) {
        for (int j = 0; j < cols(t) && muerto; j++) {
            if (estaViva(t, posicion(i, j))) {
                muerto = false;
            }
        }
    }

    return muerto;
}

/********************************** EJERCICIO esValido **********************************/
bool noEsVacio(toroide t) {
    return (rows(t) > 0) && (cols(t) > 0);
}

bool esMatrizValida(toroide t) {
    // TODO
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
// TODO: Tomar en cuenta que estamos contando a la misma posicion como vecina mas de una vez,
// Solución: Guardiar en una lista todos los potenciales vecinos y quedarse con los únicos.

int cantidadVecinosVivos(toroide t, posicion p) {
    int vecinosVivos = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            direccion dir(i, j);
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
    for(int i = 0; i < k; i++) {
        evolucionToroide(t);
    }

    return t;
}

/******************************** EJERCICIO esPeriodico *********************************/
bool perteneceExcluyendoUltimo(toroide t, vector<toroide> ts) {
    int i = 0;
    int s = ts.size() - 1;
    while (i < s && ts[i] != t) {
        i++;
    }

    return i < s;
}

bool perteneceExcluyendoPrimero(toroide t, vector<toroide> ts) {
    int i = 1;
    int s = ts.size();
    while (i < s && ts[i] != t) {
        i++;
    }

    return i < s;
}

/**
 * Dice si t2 es evolución de t1 y almacena la evolución en k.
 */
 // TODO: revisar
bool esEvolucion (toroide t1, toroide t2, int &k) {
    // Caso borde
    if (estaMuerto(t1) && estaMuerto(t2)) {
        k = 1;
        return true;
    }

    vector<toroide> evoluciones;
    bool evolucionado = false;
    evoluciones.push_back(t1);

    while (!estaMuerto(t1) && !perteneceExcluyendoUltimo(t1, evoluciones) && !perteneceExcluyendoPrimero(t2, evoluciones)) {
        evolucionToroide(t1);
        evoluciones.push_back(t1);
    }

    if (evoluciones[evoluciones.size() - 1] == t2) {
        evolucionado = true;
        k = evoluciones.size() - 1;
    }

    return evolucionado;
}

bool esPeriodico(toroide t) {
    int p;
    return esPeriodico(t, p);
}

bool esPeriodico(toroide t, int& p) {
    return esEvolucion(t, t, p);
}

/******************************* EJERCICIO primosLejanos ********************************/
bool primosLejanos(toroide t1, toroide t2) {
    int evoluciones = 0;
    return mismaDimension(t1, t2) && esEvolucion(t1,t2,evoluciones);
}

/****************************** EJERCICIO seleccionNatural ******************************/

/**
 * Dado un toroide no periodico, retorna la cantidad de ticks que tarda en morir.
 */
int cantidadDeTicksHastaMorir(toroide t) {
    int ticks = 0;
    while(!estaMuerto(t)) {
        evolucionToroide(t);
        ticks++;
    }

    return ticks;
}

bool noMuere(toroide t) {
    return esPeriodico(t) && !estaMuerto(t);
}

/**
 * Dada una lista de toroides, dice cual es el que mas tarda en morir.
 * Si la lista es vacía retorna -1.
 */
int seleccionNatural(vector<toroide> ts){
    int indice = -1;
    int maxTicksEnMorir = -1;
    bool hayUnoQueNoMuere = false;

    toroide t;
    for (int i = 0; i < ts.size() && !hayUnoQueNoMuere; i++) {
        t = ts[i];
        if (noMuere(t)) {
            indice = i;
            hayUnoQueNoMuere = true;
        } else if (cantidadDeTicksHastaMorir(t) > maxTicksEnMorir){
            indice = i;
            maxTicksEnMorir = cantidadDeTicksHastaMorir(t);
        }
    }
    return indice;
}

/********************************** EJERCICIO fusionar **********************************/
toroide fusionar(toroide t1, toroide t2){
    toroide t(rows(t1), vector<bool>(cols(t1)));

    bool celdaViva;

    for (int i = 0; i < rows(t1); i++) {
        for (int j = 0; j < cols(t2); j++) {
            celdaViva = t1[i][j] && t2[i][j];
            t[i][j] = celdaViva;
        }
    }

    return t;
}

/****************************** EJERCICIO vistaTrasladada *******************************/
/**
 * Dice si t2 es una traslación en una dirección de t1.
 * Requiere que ambos sean de la misma dimensión.
 */
bool esTraslacionEnDireccion(toroide t1, toroide t2, direccion dir) {
    bool esTraslacion = true;

    for (int i = 0; i < rows(t1) && esTraslacion; i++) {
        for (int j = 0; j < cols(t1) && esTraslacion; j++) {
            posicion pos(i, j);
            posicion posTrasladada = trasladar(t1, pos, dir);

            if (estaViva(t1, pos) != estaViva(t2, posTrasladada)) {
                esTraslacion = false;
            }
        }
    }

    return esTraslacion;
}

bool vistaTrasladada(toroide t1, toroide t2){
    if (!mismaDimension(t1, t2)) {
        return false;
    }

    bool esTraslacion = false;

    // itero sobre todas las posibles direcciones que estén en rango
    for (int i = 0; i < rows(t1) && !esTraslacion; i++) {
        for (int j = 0; j < cols(t1) && !esTraslacion; j++) {
            direccion dir(i, j);
            if (esTraslacionEnDireccion(t1, t2, dir)) {
                esTraslacion = true;
            }
        }
    }
    return esTraslacion;
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
