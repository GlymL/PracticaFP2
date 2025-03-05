#include "juego.h"
#include "inputoutput.h"

void inicializar(tJuego& juego) {
    inicializar(juego.tablero);
    juego.num_jugadas = 0;
    juego.mina_explotada = false;
    juego.num_minas = 0;
    juego.num_descubiertas = 0;
}

void inicializar(tJuego& juego, const int nfils, const int ncols) {
    inicializar(juego.tablero, nfils, ncols);
    juego.num_jugadas = 0;
    juego.mina_explotada = false;
    juego.num_minas = 0;
    juego.num_descubiertas = 0;
}

int dame_num_jugadas(const tJuego& juego) {
    return juego.num_jugadas;
}

int dame_num_filas(const tJuego& juego) {
    return num_filas(juego.tablero);
}

int dame_num_columnas(const tJuego& juego) {
    return num_columnas(juego.tablero);
}

int dame_num_minas(const tJuego& juego) {
    return juego.num_minas;
}

bool contiene_mina(tJuego& juego, const int fila, const int columna) {
    return es_mina(dame_celda(juego.tablero, fila, columna));
}

bool es_visible(tJuego& juego, const int fila, const int columna) {
    return es_visible(dame_celda(juego.tablero, fila, columna));
}

bool esta_marcada(tJuego& juego, const int fila, const int columna) {
    return esta_marcada(dame_celda(juego.tablero, fila, columna));
}

bool esta_vacia(tJuego& juego, const int fila, const int columna) {
    return esta_vacia(dame_celda(juego.tablero, fila, columna));
}

bool contiene_numero(tJuego& juego, const int fila, const int columna) {
    return contiene_numero(dame_celda(juego.tablero, fila, columna));
}

int dame_numero(tJuego& juego, const int fila, const int columna) {
    return dame_numero(dame_celda(juego.tablero, fila, columna));
}

bool esta_completo(const tJuego& juego) {
    return juego.num_descubiertas == num_filas(juego.tablero) * num_columnas(juego.tablero) - juego.num_minas;
}

bool mina_explotada(const tJuego& juego) {
    return juego.mina_explotada;
}

bool esta_terminado(const tJuego& juego) {
    return esta_completo(juego) || mina_explotada(juego);
}

void poner_mina(tJuego& juego, const int fila, const int columna) {
    if (es_valida(juego.tablero, fila, columna)) { // si esta dentro del tablero
        tCelda c = dame_celda(juego.tablero, fila, columna);
        poner_mina(c); // añade la mina
        poner_celda(juego.tablero, fila, columna, c);
        for (int i = fila - 1; i <= fila + 1; i++) // actualiza las posiciones adyacentes
            for (int j = columna - 1; j <= columna + 1; j++)
                if (es_valida(juego.tablero, i, j) && (i != fila || j != columna)) {
                    tCelda celda = dame_celda(juego.tablero, i, j);
                    if (!esta_vacia(celda))
                        poner_numero(celda, dame_numero(celda) + 1); // suma 1
                    else {
                        poner_numero(celda, 1); // si es 0 (está vacía), lo pone a 1
                    }
                    poner_celda(juego.tablero, i, j, celda);
                }
        juego.num_minas++;
    }
}

void marcar_desmarcar(tJuego& juego, const int fila, const int columna) {
    tCelda c = dame_celda(juego.tablero, fila, columna);
    if (!es_visible(c)) { // si es visible, marcar/desmarcar no tiene efecto
        if (esta_marcada(c)) { // si está marcada
            desmarcar_celda(c); // la desmarca
        }
        else { // si está desmarcada
            marcar_celda(c);  // la marca
        }
        poner_celda(juego.tablero, fila, columna, c);
    }
}

void ocultar(tJuego& juego, const int fila, const int columna) {
    if (es_visible(juego, fila, columna)) {
        tCelda celda = dame_celda(juego.tablero, fila, columna);
        ocultar_celda(celda);
        poner_celda(juego.tablero, fila, columna, celda);
        juego.num_descubiertas--;
    }
}

void juega(tJuego& juego, int fila, int columna, tListaPosiciones& lista_pos) {
    if (es_valida(juego.tablero, fila, columna) && !es_visible(dame_celda(juego.tablero, fila, columna))
        && !esta_marcada(dame_celda(juego.tablero, fila, columna))) { // si la posicion es valida y no esta marcada, la funcion se ejecuta
        tCelda c = dame_celda(juego.tablero, fila, columna);
        juego.num_jugadas++;
        descubrir_celda(c);
        juego.num_descubiertas++;
        insertar_final(lista_pos, fila, columna); // añade la pos a la lista de posiciones descubiertas
        poner_celda(juego.tablero, fila, columna, c);
        if (esta_vacia(c)) { // si esta vacía
            for (int i = fila - 1; i <=  fila + 1; i++)
                for (int j = columna - 1; j <= columna + 1; j++) {  // descubre y añade el resto
                    tCelda celda = dame_celda(juego.tablero, i, j);
                    if ((i != fila || j != columna) && !es_visible(celda) && !esta_marcada(celda)) {
                        descubrir_celda(celda);
                        juego.num_descubiertas++;
                        insertar_final(lista_pos, i, j);
                        poner_celda(juego.tablero, i, j, celda);
                    }
                }
        }
        else if (es_mina(c)) // si es una mina, marca como explotado para finalizar el juego
            juego.mina_explotada = true;
    }
}