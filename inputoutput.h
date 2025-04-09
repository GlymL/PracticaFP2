#pragma once
#include "juego.h"
#include "colors.h"
#include <fstream>

// huecos a dejar en el formato de las celdas.
const int N_HUECOS = 2; 

// imprime por pantalla la cabecera del juego (solo 1 vez, cuando inicia la partida)
void mostrar_cabecera(); 
// pide al usuario una posicion para el juego, y la almacena en las variables de salida "fila" y "columna"
// @return La fila y la columna dadas por el usuario (se asegura de que es un entero)
void pedir_pos(int& fila, int& columna);
// cuando el juego termina, muestra por pantalla el modo de terminar (ganar, perder, o salirse)
// @param El juego a mostrar
void mostrar_resultado(const tJuego& juego); 
// se encarga de exponer los datos de juego de manera visual
// @param El juego a mostrar
void mostrar_juego_consola(tJuego& juego); 
// pide al usuario un archivo, y se encarga de cargar todo el contenido del archivo en el juego proporcionado
// @param El juego donde se cargara el archivo
// @return Exito o fallo (bool)
bool carga_juego(tJuego& juego); 