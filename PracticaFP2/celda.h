#pragma once
typedef enum { NUMERO, VACIA, MINA } tEstado;

typedef struct {
    bool visible;
    tEstado estado;
    int numero;
    bool marcada;
} tCelda;

void inicializar(tCelda& celda); // crea una celda VACIA, no visible, con numero 0, y sin marcar 
tEstado dame_estado(const tCelda& celda); // devuelve el estado de la celda
int dame_numero(const tCelda& celda); // devuelve el numero de la celda
bool es_visible(const tCelda& celda); // devuelve si es visible o no la celda
bool es_mina(const tCelda& celda); // devuelve si la celda contiene una mina
bool esta_vacia(const tCelda& celda); // devuelve si la celda está vacía
bool contiene_numero(const tCelda& celda); // devuelve si la celda contiene un número
bool esta_marcada(const tCelda& celda); // devuelve si la celda está marcada
void descubrir_celda(tCelda& celda); // descubre la celda, cambiando el bool "visible" de false a true
void ocultar_celda(tCelda& celda); // oculta la celda, cambiando el bool "visible" de true a false
void poner_mina(tCelda& celda); // cambia el "estado" de la celda a MINA
void marcar_celda(tCelda& celda); // cambia el bool "marcada" de false a true
void desmarcar_celda(tCelda& celda); // cambia el bool "marcada" de true a false
void poner_numero(tCelda& celda, const int num); // cambia el "numero" asociado a la celda, y cambia el "estado" a NUMERO