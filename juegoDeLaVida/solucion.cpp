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

/********************************** EJERCICIO esValido **********************************/
bool noEsVacio(toroide t) {
    return (rows(t) > 0) && (cols(t) > 0);
}

bool esMatrizValida(toroide t) {
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
 * Dado un vector de posiciones válidas para un toroide, cuenta cuantas están vivas.
 */
int contarCantidadVivas (toroide t, vector<posicion> ps) {
    int cantVivas = 0;

    for (int i = 0; i < ps.size(); i++) {
        if (estaViva(t, ps[i])) cantVivas++;
    }

    return cantVivas;
}

/**
 * Dado una posicion y un vector de posiciones, dice si pertence.
 */
bool pertenece (posicion p, vector<posicion> ps) {
    int i = 0;

    while(i < ps.size() && p != ps[i]){
        i++;
    }

    return i != ps.size();
}

vector<posicion> obtenerVecinosUnicos(toroide t, posicion p) {
    vector<posicion> vecinos;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            direccion dirTraslacion(i, j);
            posicion posTrasladada = trasladar(t, p ,dirTraslacion);

            if (!pertenece(posTrasladada, vecinos) && posTrasladada != p){
                vecinos.push_back(posTrasladada);
            }
        }
    }
    return vecinos;
}

int cantidadVecinosVivos(toroide t, posicion p) {
    vector<posicion> vecinosUnicos = obtenerVecinosUnicos(t, p);

    return contarCantidadVivas(t, vecinosUnicos);
}

int cantidadVecinosVivosIncorrecta(toroide t, posicion p) {
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

    int vecinosVivos = cantidadVecinosVivosIncorrecta(t, p);

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

bool columnaTieneAlMenosUnaViva(toroide t, posicion p) {
    int j = get<1>(p); // fijo la columna
    bool viva = false;

    // recorro las filas
    for (int i = 0; i < cols(t) && !viva; i++) {
        if (estaViva(t, posicion(i, j))) {
            viva = true;
        }
    }

    return viva;
}

bool filaTieneAlMenosUnaViva(toroide t, posicion p) {
    int i = get<0>(p); // fijo la fila
    bool viva = false;

    // recorro las columnas
    for (int j = 0; j < cols(t) && !viva; j++) {
        if (estaViva(t, posicion(i, j))) {
            viva = true;
        }
    }

    return viva;
}

/**
 * Se queda con la maxima posicion que cumpla que:
 *   - La fila tiene al menos una posicion viva
 *   - La columna tiene al menos una posicion viva
 */
posicion obtenerMaxEsquina(toroide t) {
    posicion maxVertice = posicion(-1, -1);

    for (int i = 0; i < rows(t); i++) {
        for (int j = 0; j < cols(t); j++) {
            posicion actual(i, j);
            if (columnaTieneAlMenosUnaViva(t, actual) && filaTieneAlMenosUnaViva(t, actual)) {
                maxVertice = actual;
            }
        }
    }

    return maxVertice;
}

/**
 * Se queda con la minima posicion que cumpla que:
 *   - La fila tiene al menos una posicion viva
 *   - La columna tiene al menos una posicion viva
 */
posicion obtenerMinEsquina(toroide t) {
    posicion pos = posicion(0, 0);

    for (int i = 0; i < rows(t); i++) {
        for (int j = 0; j < cols(t); j++) {
            posicion actual(i, j);
            if (columnaTieneAlMenosUnaViva(t, actual) && filaTieneAlMenosUnaViva(t, actual)) {
                // Estamos conscientes de que es feo hacer un return en el medio de un for.
                return actual;
            }
        }
    }

    return pos;

}

vector<posicion> obtenerEsquinasQueEncierranPosVivas(toroide t) {
    vector<posicion> esquinas = {
            obtenerMinEsquina(t),
            obtenerMaxEsquina(t)
    };

    return esquinas;
}

/**
 * Obtiene la mínima superficie que cubre todas las posiciones vivas de una traslacion de un toroide.
 */
int minimaSuperficieQueCubre(toroide t) {
    vector<posicion> esquinas = obtenerEsquinasQueEncierranPosVivas(t);

    posicion min = esquinas[0];
    posicion max = esquinas[1];

    int superficie = (((get<1>(max) - get<1>(min)) + 1) *   // base
                      ((get<0>(max) - get<0>(min)) + 1));   // altura

    return superficie;
}

/**
 * Traslada a un toroide t en la dirección dir.
 */
toroide trasladarToroide(toroide t, direccion dir) {
    toroide trasladado(rows(t), vector<bool>(cols(t)));

    for (int i = 0; i < rows(t); i++) {
        for (int j = 0; j < cols(t); j++) {
            posicion pos(i, j);
            posicion posTrasladada = trasladar(t, pos, dir);

            int iTrasladado = get<0>(posTrasladada);
            int jTrasladado = get<1>(posTrasladada);

            trasladado[iTrasladado][jTrasladado] = estaViva(t, pos);
        }
    }

    return trasladado;
}

/**
 * Obtiene las posibles direcciones en las que se puede trasladar un toroide.
 *
 * Separamos a todas las posibles direcciones en clases de equivalencia, según su resto mod cols y rows.
 * Y nos quedamos con el mínimo positivo (contando el 0) de cada una.
 * Así, basta con ver todas las posibles combinaciones de 0 a cols(t) y 0 a rows(t).
 */
vector<direccion> obtenerDireccionesDeTraslacion(toroide t) {
    vector<direccion> direcciones;

    for (int i = 0; i < rows(t); i++) {
        for (int j = 0; j < cols(t); j++) {
            direcciones.push_back(direccion(i, j));
        }
    }
    return direcciones;
}

/**
 * Obtiene la mínima superficie de todas las traslaciones que cubre a todas las posiciones vivas.
 */
int minimaSuperficieDeTraslacionesQueCubre(toroide t) {
    vector<direccion> direcciones = obtenerDireccionesDeTraslacion(t);

    int superficieMinima = rows(t) * cols(t); // comienza desde la maxima area.

    for(int i = 0; i < direcciones.size(); i++) {
        toroide tTrasladado = trasladarToroide(t, direcciones[i]);
        int superficie = minimaSuperficieQueCubre(tTrasladado);

        if (superficie < superficieMinima) {
            superficieMinima = superficie;
        }
    }

    return superficieMinima;
}

bool enCrecimiento(toroide t){
    int superficieActual = minimaSuperficieDeTraslacionesQueCubre(t);

    evolucionToroide(t);
    int superficieDeEvolucion = minimaSuperficieDeTraslacionesQueCubre(t);

    return superficieActual < superficieDeEvolucion;
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/
bool esBloqueDesdeBordeSuperiorIzquierdo(toroide t, posicion pos) {
    bool esBloque = true;
    for (int i = 0; i <= 3 && esBloque; i++) {
        for (int j = 0; j <= 3 && esBloque; j++) {
            posicion posTrasladada = trasladar(t, pos, direccion(i, j));

            bool enRangoBloque = (0 < i) && (i < 3) &&
                                 (0 < j) && (j < 3);

            bool posViva = estaViva(t, posTrasladada);

            esBloque = (enRangoBloque == posViva);
        }
    }

    return esBloque;
}

bool perteneceAUnBloque(toroide t, posicion pos) {
    bool pertenece = false;

    vector<direccion> direccionesDesdePos = {
            direccion(-1, -1),  // esquina superior izquierda
            direccion(-1, -2),  // esquina superior derecha
            direccion(-2, -1),  // esquina inferior izquierda
            direccion(-2, -2)   // esquina inferior derecha
    };

    for (int i = 0; i < direccionesDesdePos.size() && !pertenece; i++) {
        direccion dir = direccionesDesdePos[i];
        pertenece = esBloqueDesdeBordeSuperiorIzquierdo(t, trasladar(t, pos, dir));
    }

    return pertenece;
}

bool soloBloques(toroide t){
    if (estaMuerto(t)) {
        return false;
    }

    bool res = true;
    for (int i = 0; i < rows(t) && res; i++) {
        for (int j = 0; j < cols(t) && res; j++) {
            posicion pos(i, j);
            if (estaViva(t, pos)) {
                res = perteneceAUnBloque(t, pos);
            }
        }
    }

    return res;
}
