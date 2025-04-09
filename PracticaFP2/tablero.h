#pragma once
#include "celda.h"

const int MAX_FILS = 50;
const int MAX_COLS = 50;

typedef struct {
    int nFils, nCols;
    tCelda datos[MAX_FILS][MAX_COLS];
} tTablero;

// @param El tablero a inicializar vacio
void inicializar(tTablero& tablero);
// @param El tablero a inicializar, las filas y columnas iniciales
void inicializar(tTablero& tablero, const int nfils, const int ncols);
// @param El tablero a consultar
// @return el numero de filas
int num_filas(const tTablero& tablero);
// @param El tablero a consultar
// @return el numero de columnas
int num_columnas(const tTablero& tablero);
// @param El tablero a consultar, la fila y la columna
// @return La celda (tipo tCelda), en la posicion
tCelda dame_celda(tTablero& tablero, const int fila, const int columna);
// devuelve si una posicion es valida
// @param El tablero a consultar
// @return Si la posicion es valida
bool es_valida(const tTablero& tablero, const int fila, const int columna);
// @param El tablero a modificar, la posicion a modificar, y la celda a poner
void poner_celda(tTablero& tablero, const int fila, const int columna, const tCelda celda);