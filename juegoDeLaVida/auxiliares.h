#include "definiciones.h"

// generales
int mod(int n, int m);
int rows(toroide t);
int cols(toroide t);
bool mismaDimension (toroide t1, toroide t2);
posicion trasladar(toroide t, posicion p, direccion dir);
bool estaViva(toroide t, posicion p);
bool estaMuerto(toroide t);

// esValido
bool noEsVacio(toroide t);
bool esMatrizValida(toroide t);

// densidadPoblacion
int superficieTotal(toroide t);
int cantidadVivas(toroide t);

// evolucionDePosicion
int cantidadVecinosVivos(toroide t, posicion p);
bool debeVivir(toroide t, posicion p);

// esPeriodico
bool esEvolucion (toroide t1, toroide t2, int &k);
bool perteneceExcluyendoUltimo(toroide t, vector<toroide> ts);
bool perteneceExcluyendoPrimero(toroide t, vector<toroide> ts);

// seleccionNatural
int cantidadDeTicksHastaMorir(toroide t);
bool noMuere(toroide t);

// vistaTrasladada
bool esTraslacionEnDireccion(toroide t1, toroide t2, direccion dir);