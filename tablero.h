#ifndef Tablero
#define Tablero
#define TAM 10

// Cabecera: Imprime los dos tableros de juego (flota y oponente).
// Precondición: Los tableros deben estar inicializados.
// Postcondición: Se muestran los tableros en pantalla.
void imprimirTableros(char tablero1[][TAM], char tablero2[][TAM]);

// Cabecera: Imprime un único tablero de juego.
// Precondición: El tablero debe estar inicializado.
// Postcondición: Se muestra el tablero en pantalla.
void imprimirTablero(char flota[][TAM]);

// Cabecera: Inicializa el tablero con espacios vacíos.
// Precondición: El tablero debe estar declarado.
// Postcondición: Todas las casillas del tablero se llenan con espacios.
void inicializar_espacio(char tablero[][TAM]);

// Cabecera: Inicializa el tablero con agua ('~').
// Precondición: El tablero debe estar declarado.
// Postcondición: Todas las casillas del tablero se llenan con agua.
void inicializar_agua(char tablero[][TAM]);
#endif