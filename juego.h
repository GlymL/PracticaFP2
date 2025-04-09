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

// inicializa un juego vacío, con un tablero de 0 elementos
// @param El juego a inicializar
void inicializar(tJuego& juego); 
// inicializa un juego vacio, con un tablero del tamaño pasado por parametro
// @param El juego a inicializar
void inicializar(tJuego& juego, const int nfils, const int ncols);
// @param El juego del que se quiere informacion
// @return El numero de filas
int dame_num_jugadas(const tJuego& juego); 
// @param El juego del que se quiere informacion
// @return El numero de filas
int dame_num_filas(const tJuego& juego);
// @param El juego del que se quiere informacion
// @return El numero de columnas
int dame_num_columnas(const tJuego& juego);
// @param El juego del que se quiere informacion
// @return El numero de minas
int dame_num_minas(const tJuego& juego);
// @param El juego del que se quiere informacion, la fila y la columna
// @return Si la posicion introducida es una mina o no
bool contiene_mina(tJuego& juego, const int fila, const int columna);
// @param El juego del que se quiere informacion, la fila y la columna
// @return Si la posicion introducida es visible o no
bool es_visible(tJuego& juego, const int fila, const int columna);
// @param El juego del que se quiere informacion, la fila y la columna
// @return Si la posicion introducida esa marcada o no
bool esta_marcada(tJuego& juego, const int fila, const int columna);
// @param El juego del que se quiere informacion, la fila y la columna
// @return Si la posicion introducida esta vacia o no
bool esta_vacia(tJuego& juego, const int fila, const int columna);
// @param El juego del que se quiere informacion, la fila y la columna
// @return Si la posicion introducida si contiene un numero o no
bool contiene_numero(tJuego& juego, const int fila, const int columna);
// @param El juego del que se quiere informacion, la fila y la columna
// @return El numero de la celda en la posicion introducida
int dame_numero(tJuego& juego, const int fila, const int columna);
// @param El juego del que se quiere informacion
// @return Si el juego ha terminado (si se han descubierto todas las casillas y se han marcado todas las bombas)
bool esta_completo(const tJuego& juego);
// @param El juego del que se quiere informacion
// @return Si se ha explotado alguna mina en el juego
bool mina_explotada(const tJuego& juego);
// @param El juego del que se quiere informacion
// @return Si el juego ha terminado (O esta completo, o una mina ha explotado)
bool esta_terminado(const tJuego& juego);
// en la posicion indicada, pone una mina, y actualiza las casillas adyacentes
// @param El juego del que se quiere modificar, la fila y la columna
void poner_mina(tJuego& juego, const int fila, const int columna);
// llama a la funcion marcar o desmarcar de la celda correspondiente a la posicion dependiendo del estado de esta
// @param El juego del que se quiere modificar, la fila y la columna
void marcar_desmarcar(tJuego& juego, const int fila, const int columna);
// si la posicion es valida, y la celda está visible, la oculta
// @param El juego del que se quiere modificar, la fila y la columna
void ocultar(tJuego& juego, const int fila, const int columna); 
// Juega una posicion
// @param El juego del que se quiere jugar, la fila y la columna
// @return La lista de posiciones modificadas durante esta iteracion
void juega(tJuego& juego, const int fila, const int columna, tListaPosiciones& lista_pos); 