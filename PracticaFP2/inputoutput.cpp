#include "inputoutput.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;


const char CHAR_MINA = '*';  // Mina



void mostrar_cabecera() {
    cout << "Buscaminas" << endl;
    cout << "----------" << endl;
}


void pedir_pos(int& fila, int& columna) {
    cout << "Introduce la fila y la columna: ";
    string f, c;
    cin >> f >> c;
    while (!all_of(f.begin(), f.end(), isdigit) || !all_of(c.begin(), c.end(), isdigit)){
        cout << "Numero no valido. Introduce un numero: ";
        f = "";
        c = "";
        cin >> f >> c;
        cin.ignore();
    }
    cin.ignore();
    fila = stoi(f);
    columna = stoi(c);
}

void mostrar_resultado(const tJuego& juego) {
    if (esta_terminado(juego)) {
        if (mina_explotada(juego)) {
            cout << "Has explotado una mina. Has perdido." << endl;
        }
        else {
            cout << "¡Enhorabuena! Has ganado." << endl;
        }
    }
    else
        cout << "Has abandonado la partida." << endl;
}

istream& operator>> (istream& in, tJuego& juego) {
    int f, c;
    in >> f >> c;
    inicializar(juego, f, c); // lee e inicializa filas y columnas
    int num_minas;
    in >> num_minas;
    for (int i = 0; i < num_minas; i++) { // for para leer todas las minas
        int f, c;
        in >> f >> c; // las minas añaden +1 a num_minas, asi que
        poner_mina(juego, f, c); // no hace falta inicializar el valor aquí
    }
    return in;
}

bool carga_juego(tJuego& juego) {
    cout << "Escriba el nombre del fichero donde se encuentra la partida: ";
    bool abrirFichero = false; // presupone un error en la apertura. Si no se abre -> false
    string nombre_fichero;
    cin >> nombre_fichero;
    ifstream fichero;
    fichero.open(nombre_fichero); // abre fichero
    if (fichero.is_open()) { // si esta abierto
        fichero >> juego;
        fichero.close();
        abrirFichero = true; // Si el archivo está bien abierto, lo cambia
    }
    return abrirFichero; // devuelve el bool. O un error de apertura, o la apertura correcta
}


void color_numero(int numero) {
    switch (numero) {
    case 1: cout << BLUE; break;
    case 2: cout << GREEN; break;
    case 3: cout << RED; break;
    case 4: cout << DBLUE; break;
    case 5: cout << DGREEN; break;
    case 6: cout << DRED; break;
    default:
        break;
    }
}


void mostrar_separador(const tJuego& juego) {
    cout << "\t -+";
    for (int col = 0; col < dame_num_columnas(juego); ++col) {
        cout << setw(N_HUECOS + 1) << setfill('-') << '+' << setfill(' ');
    }
    cout << endl;
}

void mostrar_celda(tJuego& juego, int fila, int columna) {
    if (!es_visible(juego, fila, columna) && !esta_marcada(juego, fila, columna)) {
        cout << BG_GRAY << GRAY << N_HUECOS << setfill(' ') << ' ' << RESET;
    }
    else {
        cout << BG_BLACK << BLACK;
        if (!esta_marcada(juego, fila, columna)) {
            if (contiene_mina(juego, fila, columna)) {
                cout << RED << setw(N_HUECOS) << setfill(' ') << CHAR_MINA << RESET;
            }
            else {
                if (esta_vacia(juego, fila, columna)) {
                    cout << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
                }
                else {
                    if (contiene_numero(juego, fila, columna)) {
                        int numero = dame_numero(juego, fila, columna);
                        color_numero(numero);
                        cout << setw(N_HUECOS) << setfill(' ') << numero << RESET;
                    }
                    else {
                        cout << BG_RED << RED << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
                    }
                }
            }
        }
        else {
            cout << BG_ORANGE << ORANGE << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
        }
    }
}


void mostrar_juego_consola(tJuego& juego) {

    // mostrar el número de jugadas del juego
    cout << "\tJugadas: " << dame_num_jugadas(juego) << endl;

    // mostrar cabecera
    cout << "\t  |";
    for (int col = 0; col < dame_num_filas(juego); col++) {
        cout << LBLUE << setw(N_HUECOS) << col << RESET << '|';
    }
    cout << endl;

    // mostrar separador
    mostrar_separador(juego);

    // mostrar juego
    for (int f = 0; f < dame_num_filas(juego); f++) {
        // mostrar numero de fila
        cout << "\t" << LBLUE << setw(2) << f << RESET << '|';
        // mostrar la fila
        for (int c = 0; c < dame_num_columnas(juego); c++) {
            mostrar_celda(juego, f, c);
            cout << '|';
        }
        cout << endl;

        mostrar_separador(juego);
    }
    cout << endl;
}


