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
posicion trasladar(toroide t, posicion p, tuple<int, int> dir);
int cantidadVecinosVivos(toroide t, posicion p);
bool debeVivir(toroide t, posicion p);

// esPeriodico
bool estaMuerto(toroide t);