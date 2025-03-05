#pragma once
#include "celda.h"

const int MAX_FILS = 50;
const int MAX_COLS = 50;

typedef struct {
    int nFils, nCols;
    tCelda datos[MAX_FILS][MAX_COLS];
} tTablero;

void inicializar(tTablero& tablero); // inicializa un tablero sin celdas (nFilas = 0, nCols = 0)
void inicializar(tTablero& tablero, const int nfils, const int ncols); // inicializa un tablero con las dimensiones pasadas
int num_filas(const tTablero& tablero); // devuelve el numero de filas
int num_columnas(const tTablero& tablero); // devuelve el numero de columnas
tCelda dame_celda(tTablero& tablero, const int fila, const int columna); // devuelve la celda de la posicion (por referencia pues se quiere modificar)
bool es_valida(const tTablero& tablero, const int fila, const int columna); // devuelve si una posicion es valida
void poner_celda(tTablero& tablero, const int fila, const int columna, const tCelda celda); // TODO preguntar si lo hecho está mal