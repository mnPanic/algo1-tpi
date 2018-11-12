#include "es.h"
#include "definiciones.h"
#include <fstream>

using namespace std;

/* Formato del archivo
 * 1. Cantidad de filas (cantidadFilas).
 *
 * 2. Cantidad de columnas (cantidadColumnas).
 *
 * 3. Lista de números que indican los valores de cada celda, ordenados primero por fila, y luego por columna.
 *      - 1 indica que la celda está viva,
 *      - 0 que está muerta.
 *    Debe haber exactamente cantidadFilas × cantidadColumnas valores.
 *
 * 4. Entero positivo que se debe corresponder a la cantidad de celdas vivas que tiene el toroide
 */

/******************************** EJERCICIO cargarToroide *******************************/

bool esArchivoValido(string nombreArchivo) {
    ifstream fin(nombreArchivo);

    return !fin.fail();
}

/**
 * Chequea que un archivo que contiene un toroide tenga el formato válido:
 *   - Los primeros dos elementos del archivo indican cantidadFilas y cantidadColumnas.
 *   - Hay exactamente cantidadFilas x cantidadColumnas elementos en el toroide.
 *   - Todos los elementos del toroide son 0 o 1.
 *   - El ultimo elememento denota la cantidad de posiciones vivas, y hay exactamente esa cantidad de posiciones vivas.
 *
 * NO importa la dimensión que tenga el toroide del archivo, solo que cumpla los puntos anteriores.
 *
 * Formato:
 * 	[cantidadFilas] [cantidadColumnas]
 * 	[toroide]
 * 	[cantidadVivas]
 */
bool esFormatoValido(string nombreArchivo) {
    bool valido = true;

    ifstream fin(nombreArchivo);

    int cantidadFilas = 0;
    int cantidadColumnas = 0;

    // Comienza en -1 para que si el archivo no contiene la cantidadVivas,
    // y el toroide no tiene ninguna viva, no lo tomemos como válido.
    int cantidadVivas = -1;

    fin >> cantidadFilas;
    fin >> cantidadColumnas;

    int cantidadElementos = cantidadFilas * cantidadColumnas;

    int vivas = 0;
    int valor = 0;
    int elem = 0;

    while (elem < cantidadElementos && valido && !fin.eof()) {
        fin >> valor;

        if (valor == 1 || valor == 0) {
            vivas += valor;
        } else {
            valido = false;
        }

        elem ++;
    }

    fin >> cantidadVivas;

    valido = valido &&
             cantidadVivas == vivas &&       // Chequeo que la cantidad de vivas sea correcta
             cantidadElementos == elem &&    // Chequeo que el toroide tenga la cant correcta de elementos
             fin.eof();                      // Chequeo que el file termine después de la cant de vivas

    return valido;
}

/**
 * Dado un archivo existente con formato válido, lee un toroide.
 */
toroide leerToroide(string nombreArchivo) {
    ifstream fin(nombreArchivo);

    int cantidadFilas = 0;
    int cantidadColumnas = 0;

    fin >> cantidadFilas;
    fin >> cantidadColumnas;

    toroide t(cantidadFilas, vector<bool>(cantidadColumnas));

    int valor = 0;
    for(int i = 0; i < cantidadFilas; i++) {
        for (int j = 0; j < cantidadColumnas; j++) {
            fin >> valor;
            t[i][j] = (valor == 1);
        }
    }

    return t;
}


/**
 * Dado un nombre de archivo, lee e interpreta el contenido del mismo como un toroide.
 * Modifica status para indicar si el procesamiento fue exitoso o no.
 * Los motivos por los que status = false (no exitoso) son:
 *   - No se pudo abrir el archivo (inexistente o sin permisos).
 * 	 - Los datos contenidos en el archivo no respetan el formato descripto anteriormente.
 *
 * Si status = false no se garantiza nada del valor retornado.
 *
 * @param nombreArchivo El nombre del archivo.
 * @param status El estado. Indica si fue exitoso.
 * @return El toroide cargado.
 */
toroide cargarToroide(string nombreArchivo, bool &status) {
	toroide t;
    status = true;

	if (esArchivoValido(nombreArchivo) && esFormatoValido(nombreArchivo)) {
		t = leerToroide(nombreArchivo);
	} else {
		status = false;
	}

	return t;
}

/******************************** EJERCICIO escribirToroide *****************************/


int filas(toroide t) {
    return t.size();
}

int columnas(toroide t) {
    int columnas = 0;

    if (!t.empty()) {
        columnas = t[0].size();
    }

    return columnas;
}

/**
 * Dado un nombre de archivo nombreArchivo y un toroide t, almacene el toroide
 * en el archivo indicado respetando el formato descripto.
 *
 * El valor de retorno indica si la operación se pudo realizar exitosamente o no.
 *
 * Los motivos por los que devuelve false (no exitoso) son:
 *   - No se pudo abrir el archivo para escritura (sin permisos, path inexistente, etc).
 *   - No se pudo escribir el toroide completo (sin espacio en disco, etc).
 *
 * @param nombreArchivo El nombre del archivo.
 * @param t El toroide válido a guardar.
 * @return Si la operación fue exitosa.
 */
bool escribirToroide(string nombreArchivo, toroide &t) {
	ofstream fout(nombreArchivo);

	int fil = filas(t);
	int col = columnas(t);

	int vivas = 0;
	int valor = 0;

	// Escribo las filas y columnas
	fout << fil << " " << col << endl;

	// Escribo el toroide
	for(int i = 0; i < fil && !fout.fail(); i++){
	    for(int j = 0; j < col && !fout.fail(); j++) {
            valor = 0;
            if (t[i][j]) {
                valor = 1;
                vivas++;
            }

            // Solo agrego un espacio antes del valor cuando no es el primer elemento de la columna
            if (j != 0) fout << " ";
            fout << valor;
        }

	    fout << endl;
	}

	// Escribo la cantidad de posiciones vivas
	fout << vivas;

	return !fout.fail();
}