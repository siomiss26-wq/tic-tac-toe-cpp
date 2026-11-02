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

// revisa si la ficha gano en filas, columnas o diagonales
bool hayGanador(char ficha) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == ficha && tablero[i][1] == ficha && tablero[i][2] == ficha) {
            return true;
        }
        if (tablero[0][i] == ficha && tablero[1][i] == ficha && tablero[2][i] == ficha) {
            return true;
        }
    }

    if (tablero[0][0] == ficha && tablero[1][1] == ficha && tablero[2][2] == ficha) {
        return true;
    }
    if (tablero[0][2] == ficha && tablero[1][1] == ficha && tablero[2][0] == ficha) {
        return true;
    }

    return false;
}

// devuelve la ficha que le toca segun el numero de jugada
char turno(int jugada) {
    if (jugada % 2 == 0) {
        return 'X';
    }
    return 'O';
}

// pide una casilla libre y la marca con la ficha
void pedirJugada(char ficha) {
    // pido la casilla hasta que sea un numero del 1 al 9
    int posicion = 0;
    while (posicion < 1 || posicion > 9) {
        cout << "Jugador " << ficha << ", elige una casilla del 1 al 9: ";
        cin >> posicion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            posicion = 0;
            cout << "Eso no es un numero" << endl;
        } else if (posicion < 1 || posicion > 9) {
            cout << "Esa casilla no existe, tiene que ser del 1 al 9" << endl;
        }
    }

    // paso el numero de casilla a fila y columna
    int fila = (posicion - 1) / 3;
    int col = (posicion - 1) % 3;

    // si la casilla ya esta ocupada pido otra
    while (tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
        cout << "Esa casilla ya esta ocupada, elige otra del 1 al 9: ";
        cin >> posicion;
        fila = (posicion - 1) / 3;
        col = (posicion - 1) % 3;
    }

    tablero[fila][col] = ficha;
}

int main() {
    cout << "Tic Tac Toe" << endl;
    cout << "Juego para dos personas" << endl;

    bool huboGanador = false;

    for (int jugada = 0; jugada < 9; jugada++) {
        mostrarTablero();

        char ficha = turno(jugada);
        pedirJugada(ficha);

        // si hay ganador lo aviso y salgo del ciclo
        if (hayGanador(ficha)) {
            cout << "Gano el jugador " << ficha << endl;
            huboGanador = true;
            break;
        }
    }

    // si nadie gano es porque se lleno el tablero
    if (huboGanador == false) {
        cout << "Empate, ya no quedan casillas" << endl;
    }

    mostrarTablero();

    return 0;
}
