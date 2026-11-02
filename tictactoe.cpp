#include <iostream>
using namespace std;

// tablero de 3x3 con los numeros de las casillas
char tablero[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// imprime el tablero en la consola
void mostrarTablero() {
    cout << endl;
    for (int fila = 0; fila < 3; fila++) {
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << tablero[fila][col];
            if (col < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (fila < 2) {
            cout << "---+---+---" << endl;
        }
    }
    cout << endl;
}

int main() {
    cout << "Tic Tac Toe" << endl;
    cout << "Juego para dos personas" << endl;

    // dos jugadas para probar que cambia el turno
    for (int jugada = 0; jugada < 2; jugada++) {
        mostrarTablero();

        char ficha;
        if (jugada % 2 == 0) {
            ficha = 'X';
        } else {
            ficha = 'O';
        }

        int posicion;
        cout << "Jugador " << ficha << ", elige una casilla del 1 al 9: ";
        cin >> posicion;

        // paso el numero de casilla a fila y columna
        int fila = (posicion - 1) / 3;
        int col = (posicion - 1) % 3;
        tablero[fila][col] = ficha;
    }

    mostrarTablero();

    return 0;
}
