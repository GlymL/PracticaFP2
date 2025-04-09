#pragma once
const int MAX_LISTA = 100;

typedef struct {
    int posx;
    int posy;
} tPosicion;

typedef struct {
    tPosicion lista[MAX_LISTA];
    int cont;
} tListaPosiciones;

// iniclaiza el cont a 0
// @param La lista a inicializar
void inicializar(tListaPosiciones& lista_pos); 
// inserta una pos en el final de la lista.
// @param La lista a modificar, y la posicion (como coordenadas), a introducir
void insertar_final(tListaPosiciones& lista_pos, const int x, const int y); 
// @return La longitud de la lista
int longitud(const tListaPosiciones lista_pos); 
// @param La lista a consultar y la posicion de la lista a consultar
// @return la primera coordenada de la posicion en el indice i
int dame_posX(const tListaPosiciones lista_pos, const int i); 
// @param La lista a consultar y la posicion de la lista a consultar
// @return la segunda coordenada de la posicion en el indice i
int dame_posY(const tListaPosiciones lista_pos, const int i); 