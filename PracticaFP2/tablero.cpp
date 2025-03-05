#include "tablero.h"


void inicializar(tTablero& tablero) {
    tablero.nCols = 0;
    tablero.nFils = 0;
}

void inicializar(tTablero& tablero, const int nfils, const int ncols) {
    tablero.nFils = nfils;
    tablero.nCols = ncols;
    for (int i = 0; i < tablero.nFils; i++) {
        for (int j = 0; j < tablero.nCols; j++) {
            inicializar(tablero.datos[i][j]);
        }
    }
}

int num_filas(const tTablero& tablero) {
    return tablero.nFils;
}

int num_columnas(const tTablero& tablero) {
    return tablero.nCols;
}

tCelda dame_celda(tTablero& tablero, const int fila, const int columna) {
    return tablero.datos[fila][columna];
}

bool es_valida(const tTablero& tablero, const int fila, const int columna) {
    return fila >= 0 && fila < tablero.nFils && columna >= 0 && columna < tablero.nCols;
}

void poner_celda(tTablero& tablero, const int fila, const int columna, const tCelda celda) {
    tablero.datos[fila][columna] = celda;
}