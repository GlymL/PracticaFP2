#pragma once
#include "listaposiciones.h"

const int MAX_UNDO = 10;

typedef struct {
    tListaPosiciones lista[MAX_UNDO];
    int cont;
} tListaUndo;

// inicializa la lista poniendo el cont a 0
// @param La lista a inicializar
void inicializar(tListaUndo& lista_pos); 
// añade el elemento en la lista, si esta llena, descarta el primer elemento
// @param La lista de movimientos a insertar, y la lista de listas a modificar
void insertar_final(tListaUndo& lista_undo, tListaPosiciones lista_pos); 
// devuelve la ultima lista de posiciones, y mueve el contador hacia atras (estilo pop_back())
// @param La lista de listas a consultar
// @return La lista de movimientos en la ultima posicion
tListaPosiciones& ultimos_movimientos(tListaUndo& lista_undo);