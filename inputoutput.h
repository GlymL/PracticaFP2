#pragma once
#include "juego.h"
#include "colors.h"
#include <fstream>

const int N_HUECOS = 2; // huecos a dejar en el formato de las celdas.

void mostrar_cabecera(); // imprime por pantalla la cabecera del juego (solo 1 vez, cuando inicia la partida)
void pedir_pos(int& fila, int& columna); // pide al usuario una posicion para el juego, y la almacena en las variables de salida "fila" y "columna"
void mostrar_resultado(const tJuego& juego); // cuando el juego termina, muestra por pantalla el modo de terminar (ganar, perder, o salirse)
void mostrar_juego_consola(tJuego& juego); // se encarga de exponer los datos de juego de manera visual
bool carga_juego(tJuego& juego); // pide al usuario un archivo, y se encarga de cargar todo el contenido del archivo en el juego proporcionado