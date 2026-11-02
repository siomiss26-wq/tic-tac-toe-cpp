// Tic Tac Toe en C++
// Mini proyecto de Programacion Dinamica
// Juego de dos jugadores en la consola

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
        for (int columna = 0; columna < 3; columna++) {
            cout << tablero[fila][columna];
            if (columna < 2) {
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

// vuelve a poner los numeros en el tablero
void reiniciarTablero() {
    char numeros[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            tablero[fila][columna] = numeros[fila][columna];
        }
    }
}

// revisa si la ficha gano en filas, columnas o diagonales
bool hayGanador(char ficha) {
    for (int numero = 0; numero < 3; numero++) {
        if (tablero[numero][0] == ficha && tablero[numero][1] == ficha && tablero[numero][2] == ficha) {
            return true;
        }
        if (tablero[0][numero] == ficha && tablero[1][numero] == ficha && tablero[2][numero] == ficha) {
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
    int columna = (posicion - 1) % 3;

    // si la casilla ya esta ocupada pido otra
    while (tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O') {
        cout << "Esa casilla ya esta ocupada, elige otra del 1 al 9: ";
        cin >> posicion;
        fila = (posicion - 1) / 3;
        columna = (posicion - 1) % 3;
    }

    tablero[fila][columna] = ficha;
}

int main() {
    cout << "Tic Tac Toe" << endl;
    cout << "Juego para dos personas" << endl;

    char respuesta;

    do {
        // limpio el tablero antes de empezar cada partida
        reiniciarTablero();

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

        cout << "Quieres jugar otra vez? (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    cout << "Gracias por jugar" << endl;

    return 0;
}
