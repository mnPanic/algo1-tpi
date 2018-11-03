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

/**
 * Dado un nombre de archivo, lee e interpreta el contenido del mismo como un toroide.
 * Modifica status para indicar si el procesamiento fue exitoso o no.
 * Los motivos por los que status = false (no exitoso) son:
 *   - No se pudo abrir el archivo (inexistente o sin permisos).
 * 	 - Los datos contenidos en el archivo no respetan el formato descripto anteriormente.
 *
 * @param nombreArchivo El nombre del archivo.
 * @param status El estado. Indica si fue exitoso.
 * @return El toroide cargado.
 */
toroide cargarToroide(string nombreArchivo, bool &status) {
	toroide t;

	if (esArchivoValido(nombreArchivo) && esFormatoValido(nombreArchivo)) {
		t = leerToroide(nombreArchivo);
	} else {
		status = false;
	}

	return t;
}

private bool esArchivoValido(String nombreArchivo) {
	ifstream fin(nombreArchivo);

	return fin.fail()
}


/*
 *
5 4

 1 1
 1 0
 1 0
 0 0
 0 0
 0 0
 0 0
 0 0
 0 0

1 0 0 0
0 0 1 0
0 0 0 1
0 1 0 0
0 0 0 0
4
 */

// supone que es un archivo válido
private bool esFormatoValido(String nombreArchivo) {
	bool valido = true;

	ifstream fin(nombreArchivo);

	int filasEsperadas = 0;
	int columnasEsperadas = 0;
	int cantVivasEsperadas = -1;	// comienza en -1...

	fin >> filasEsperadas;
	fin >> columnasEsperadas;

	int filas = 0;
	int columnas = 0;
	int vivas = 0;

	int valor = 0;

	for (int i = 0; i < filasEsperadas * columnasEsperadas && !fin.eof(); i ++) {
		// problema: no diferenciamos entre dimensiones para misma cantidad de elementos
		fin >> valor;

		if (valor == 1 || valor == 0) {
			vivas += valor;
		} else {
			valido = false;
		}
	}

	if (!fin.eof()) {
		fin >> cantVivasEsperadas;
		// deberñia ser true fin.eof()
	}

	// falta chequear que cantVivasEsperadas sea correcto
	// y que haya solo 0 y 1
	return fin.eof() && filas == filasEsperadas && columnas == columnasEsperadas;
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