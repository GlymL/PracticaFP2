#pragma once
typedef enum { NUMERO, VACIA, MINA } tEstado;

typedef struct {
    bool visible;
    tEstado estado;
    int numero;
    bool marcada;
} tCelda;


// crea una celda VACIA, no visible, con numero 0, y sin marcar 
// @param La celda que vas a inicializar
void inicializar(tCelda& celda); 
// @param La celda de la que quieres conocer informacion
// @return El estado (En tipo enum tEstado)
tEstado dame_estado(const tCelda& celda); 
// @param La celda de la que quieres conocer informacion
// @return El numero que tiene la celda (En tipo int)
int dame_numero(const tCelda& celda);
// @param La celda de la que quieres conocer informacion
// @return Si es visible o no (En tipo bool)
bool es_visible(const tCelda& celda); 
// @param La celda de la que quieres conocer informacion
// @return Si tiene una mina o no (En tipo bool)
bool es_mina(const tCelda& celda); 
// @param La celda de la que quieres conocer informacion
// @return Si la celda esta vacia (En tipo bool)
bool esta_vacia(const tCelda& celda);
// @param La celda de la que quieres conocer informacion
// @return Si contiene un numero o no (En tipo bool)
bool contiene_numero(const tCelda& celda);
// @param La celda de la que quieres conocer informacion
// @return Si la celda esta marcada o no (En tipo bool)
bool esta_marcada(const tCelda& celda);
// descubre la celda, cambiando el bool "visible" de false a true
// @param La celda que quieres modificar
void descubrir_celda(tCelda& celda);
// oculta la celda, cambiando el bool "visible" de true a false
// @param La celda que quieres modificar
void ocultar_celda(tCelda& celda); 
// cambia el "estado" de la celda a MINA
// @param La celda que quieres modificar
void poner_mina(tCelda& celda); 
// cambia el bool "marcada" de false a true
// @param La celda que quieres modificar
void marcar_celda(tCelda& celda); 
// cambia el bool "marcada" de true a false
// @param La celda que quieres modificar
void desmarcar_celda(tCelda& celda); 
// cambia el "numero" asociado a la celda, y cambia el "estado" a NUMERO
// @param La celda que quieres modificar
void poner_numero(tCelda& celda, const int num);