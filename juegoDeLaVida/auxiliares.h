#include "definiciones.h"

// generales
int rows(toroide t);
int cols(toroide t);
bool estaViva(toroide t, posicion p);

// esValido
bool noEsVacio(toroide t);
bool esMatrizValida(toroide t);

// densidadPoblacion
int superficieTotal(toroide t);
int cantidadVivas(toroide t);

// evolucionDePosicion
int mod(int n, int m);
posicion trasladar(toroide t, posicion p, direccion dir);
int cantidadVecinosVivos(toroide t, posicion p);
bool debeVivir(toroide t, posicion p);

// esPeriodico
bool estaMuerto(toroide t);
bool esEvolucion (toroide t1, toroide t2, int &k);
bool perteneceExcluyendoUltimo(toroide t, vector<toroide> ts);
bool perteneceExcluyendoPrimero(toroide t, vector<toroide> ts);

// primosLejanos
bool mismaDimension (toroide t1, toroide t2);

// seleccionNatural
int cantidadDeTicksHastaMorir(toroide t);
bool noMuere(toroide t);