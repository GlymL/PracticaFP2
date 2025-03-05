#pragma once
#include "listaposiciones.h"

const int MAX_UNDO = 10;

typedef struct {
    tListaPosiciones lista[MAX_UNDO];
    int cont;
} tListaUndo;


void inicializar(tListaUndo& lista_pos); // inicializa la lista poniendo el cont a 0
void insertar_final(tListaUndo& lista_undo, tListaPosiciones lista_pos); // añade el elemento en la lista, si esta llena, descarta el primer elemento
tListaPosiciones& ultimos_movimientos(tListaUndo& lista_undo); // devuelve la ultima lista de posiciones, y mueve el contador hacia atras (estilo pop_back())