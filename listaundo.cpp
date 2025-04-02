#include "listaundo.h"
#include "listaposiciones.h"

void inicializar(tListaUndo& lista_undo) {
    lista_undo.cont = 0;
}

void insertar_final(tListaUndo& lista_undo, tListaPosiciones lista_pos) { // si no cabe, borra el ultimo elemento
    if (lista_undo.cont == MAX_UNDO) {
        for (int i = 0; i < MAX_UNDO - 1; i++) {
            lista_undo.lista[i] = lista_undo.lista[i + 1];
        }
        lista_undo.cont--;
    }
    lista_undo.lista[lista_undo.cont] = lista_pos;
    lista_undo.cont++;
}

tListaPosiciones& ultimos_movimientos(tListaUndo& lista_undo) {
    lista_undo.cont--;
    return lista_undo.lista[lista_undo.cont];
}