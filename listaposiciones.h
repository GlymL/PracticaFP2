#pragma once
const int MAX_LISTA = 100;

typedef struct {
    int posx;
    int posy;
} tPosicion;

typedef struct {
    int capacidad;
    int cont;
    tPosicion* lista;
} tListaPosiciones;


void inicializar(tListaPosiciones& lista_pos); // iniclaiza el cont a 0
void insertar_final(tListaPosiciones& lista_pos, const int x, const int y); // inserta una pos en el final de la lista.
int longitud(const tListaPosiciones lista_pos); // devuelve la longitud de la lista
int dame_posX(const tListaPosiciones lista_pos, const int i); // devuelve la primera coordenada de la posicion en el indice i
int dame_posY(const tListaPosiciones lista_pos, const int i); // devuelve la segunda coordenada de la posicion en el indice i
                                                              // NUNCA se devuelve la pos, para no romper la encapsulacion
void destruir(tListaPosiciones &lista);