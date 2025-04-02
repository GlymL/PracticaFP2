#pragma once
#include "tablero.h"
#include "listaposiciones.h"

typedef struct {
    tTablero tablero;
    int num_jugadas;
    bool mina_explotada;
    int num_minas;
    int num_descubiertas;
} tJuego;


void inicializar(tJuego& juego); // inicializa un juego vacío, con un tablero de 0 elementos
void inicializar(tJuego& juego, const int nfils, const int ncols); // inicializa un juego vacio, con un tablero del tamaño pasado por parametro
int dame_num_jugadas(const tJuego& juego); // devuelve el numero de jugadas
int dame_num_filas(const tJuego& juego); // devuelve el numero de filas
int dame_num_columnas(const tJuego& juego); // devuelve el numero de columnas
int dame_num_minas(const tJuego& juego); // devuelve el numero de minas
bool contiene_mina(tJuego& juego, const int fila, const int columna); // deveulve si la celda está en el estado MINA o no (llama la función subsecuente de celda)
bool es_visible(tJuego& juego, const int fila, const int columna); // deveulve si la celda está revelada o no (llama la función subsecuente de celda)
bool esta_marcada(tJuego& juego, const int fila, const int columna); // devuelve si la celda está marcada o no (llama la función subsecuente de celda)
bool esta_vacia(tJuego& juego, const int fila, const int columna); // devuelve si la celda está vacía o no (llama la función subsecuente de celda)
bool contiene_numero(tJuego& juego, const int fila, const int columna); // devuelve si la celda está en el estado NUMERO o no (llama la función subsecuente de celda)
int dame_numero(tJuego& juego, const int fila, const int columna); // si la celda tiene el estado NUMERO, devuelve el numero. en caso contrario devuelve 0
bool esta_completo(const tJuego& juego); // devuelve si se han descubierto todas las casillas y se han marcado todas las bombas
bool mina_explotada(const tJuego& juego); // deuvelve el bool mina_explotada (para indicar el final del juego cuando se pierde)
bool esta_terminado(const tJuego& juego); // llama a las dos funciones anteriores para determinar si el juego esta terminado o no
void poner_mina(tJuego& juego, const int fila, const int columna); // en la posicion indicada, pone una mina, y actualiza las casillas adyacentes
void marcar_desmarcar(tJuego& juego, const int fila, const int columna); // llama a la funcion marcar o desmarcar de la celda 
                                                                         // correspondiente a la posicion dependiendo del estado de esta
void ocultar(tJuego& juego, const int fila, const int columna); // si la posicion es valida, y la celda está visible, la oculta
void juega(tJuego& juego, const int fila, const int columna, tListaPosiciones& lista_pos); // descubre la posicion indicada, guarda las posiciones descubiertas
                                                                                           // y actualiza el estado de juego en caso de que se pierda