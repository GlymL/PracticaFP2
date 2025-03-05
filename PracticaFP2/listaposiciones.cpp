#include "listaposiciones.h"

void inicializar(tListaPosiciones& lista) {
    lista.cont = 0;
}

void insertar_final(tListaPosiciones& lista, const int x, const int y) {
    // si la lista esta llena, desplazar una y borrar la anterior (por si acaso)
    if (lista.cont == MAX_LISTA) {
        for (int i = 0; i < MAX_LISTA - 1; i++) {
            lista.lista[i] = lista.lista[i + 1];
        }
        lista.cont--;
    }
    lista.lista[lista.cont].posx = x;
    lista.lista[lista.cont].posy = y;
    lista.cont++;
}

int longitud(const tListaPosiciones lista) {
    return lista.cont;
}

int dame_posX(const tListaPosiciones lista, const int i) {
    return lista.lista[i].posx;
}

int dame_posY(const tListaPosiciones lista, const int i) {
    return lista.lista[i].posy;
}