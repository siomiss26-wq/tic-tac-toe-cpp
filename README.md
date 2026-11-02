# Tic Tac Toe en C++

Mini proyecto de la materia de Programacion Dinamica. Es un juego de tres en raya
para dos jugadores que corre en la consola.

## Como compilar

Se necesita un compilador de C++ (g++). En la carpeta del proyecto:

    g++ tictactoe.cpp -o tictactoe

## Como jugar

1. Ejecuta el programa: `./tictactoe` (en Windows, `tictactoe.exe`).
2. El tablero muestra los numeros del 1 al 9:

        1 | 2 | 3
       ---+---+---
        4 | 5 | 6
       ---+---+---
        7 | 8 | 9

3. El jugador X empieza. Escribe el numero de la casilla y presiona Enter.
4. Los jugadores se van alternando (X y O).
5. El programa avisa cuando alguien gana en una fila, columna o diagonal, o
   cuando el tablero se llena y hay empate.
6. Al terminar pregunta si quieres jugar otra vez (s/n).

Ejemplo de una partida corta:

    Jugador X, elige una casilla del 1 al 9: 1
    Jugador O, elige una casilla del 1 al 9: 4
    Jugador X, elige una casilla del 1 al 9: 2
    Jugador O, elige una casilla del 1 al 9: 5
    Jugador X, elige una casilla del 1 al 9: 3
    Gano el jugador X

## Que incluye

- Tablero de 3x3 guardado en una matriz.
- Turnos alternados entre X y O.
- Deteccion de ganador en filas, columnas y diagonales.
- Deteccion de empate cuando se llena el tablero.
- Validacion de entradas: no acepta letras ni numeros fuera del 1 al 9,
  tampoco deja repetir una casilla ocupada.
- Opcion de jugar otra vez sin cerrar el programa.

## Estructura del codigo

El codigo esta separado en funciones:

- `mostrarTablero()`: imprime el tablero.
- `reiniciarTablero()`: vuelve a poner los numeros antes de cada partida.
- `hayGanador(ficha)`: revisa si una ficha gano.
- `turno(jugada)`: dice que ficha juega segun el numero de jugada.
- `pedirJugada(ficha)`: pide y valida la casilla, y la marca.
- `main()`: controla el ciclo del juego y el menu de volver a jugar.

## Autor

siomiss26-wq
