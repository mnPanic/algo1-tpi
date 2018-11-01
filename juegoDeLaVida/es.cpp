#include "es.h"
#include "definiciones.h"
#include <fstream>

namespace std

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
bool escribirToroide(string nombreArchivo, toroide &t)
{
	bool res;
	return res;
}
