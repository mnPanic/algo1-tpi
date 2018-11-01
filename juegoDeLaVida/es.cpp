#include "es.h"
#include "definiciones.h"

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
	return t;
}


/******************************** EJERCICIO escribirToroide *****************************/
bool escribirToroide(string nombreArchivo, toroide &t)
{
	bool res;
	return res;
}
