#include "inputoutput.h"
#include "tablero.h"
#include "listaundo.h"
#include "juego.h"
#include <iostream>

using namespace std;


void juega(tJuego& juego, const int fila, const int columna, tListaUndo& listaundo) {
    tListaPosiciones listapos;
    inicializar(listapos);
    juega(juego, fila, columna, listapos);
    insertar_final(listaundo, listapos);
}


int main() {  
    bool salir = true;
    int fila, columna;
    tJuego juego;
    mostrar_cabecera();
    inicializar(juego);
    if (carga_juego(juego)) { // si el juego se carga correctamente, se juega
        tListaUndo listaundo;
        inicializar(listaundo);
        cout << "Este es el tablero: " << endl;
        mostrar_juego_consola(juego); // se muestra el juego una primera vez
        while (salir == true) { // minetras no se haya acabado el juego
            pedir_pos(fila, columna);
            if (fila == -1 && columna == -1) { // caso especial 1: finalizar el juego
                salir = false;
                mostrar_resultado(juego);
            }
            else if (fila == -2 && columna == -2) { // caso especial 2: marcar una posicion
                cout << "Que casilla deseas marcar?" << endl;
                pedir_pos(fila, columna); // pos marcada
                marcar_desmarcar(juego, fila, columna);
            }
            else if (fila == -3 && columna == -3) { // caso especial 3: deshacer movimientos
                tListaPosiciones pos = ultimos_movimientos(listaundo);
                for (int i = 0; i < longitud(pos); i++) // itera la lista
                    ocultar(juego, dame_posX(pos, i), dame_posY(pos, i)); // para ocultar las celdas descubieras
                mostrar_juego_consola(juego);
                
            }
            else { // caso base, jugar de manera normal
                juega(juego, fila, columna, listaundo);
                mostrar_juego_consola(juego); // muestra el tablero para saber la pos actual
                // se ejecuta antes de saber si esta terminado el juego, pues cuando ganas tambien deberias ver el tablero
                if (esta_terminado(juego)) { // si el juego termina de manera natural, 
                    mostrar_resultado(juego); // salimos del bucle en la proxima iteracion y madnamos el mensaje de salida
                    salir = false;
                }
            }

        }
    }
    else // en caso contario, se acaba la ejecucion
        cout << "El archivo no ha podido abrirse, parando la ejecucion";
    return 0;
};