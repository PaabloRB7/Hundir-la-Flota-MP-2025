#ifndef DISPAROS_H
#define DISPAROS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "configuracion.h"


#define N 10

// Cabecera: Realiza un disparo en una posición específica del tablero.
// Precondición: La fila y columna deben estar dentro de los límites del tablero.
// Postcondición: Devuelve 1 si el disparo impacta un barco, 0 en caso contrario.
int disparo(int fila, int columna, char tablero[][N], char tablero_v[][N]);

// Cabecera: Permite al jugador realizar un disparo manual en el tablero del oponente.
// Precondición: El jugador debe ingresar coordenadas válidas dentro del tablero.
// Postcondición: Actualiza el tablero del oponente según el resultado del disparo.
int disparo_manual(char tablero[][N], char tablero_v[][N], jugador *player);

// Cabecera: Realiza un disparo automático en el tablero del oponente.
// Precondición: El tablero del oponente debe estar inicializado.
// Postcondición: Actualiza el tablero del oponente según el resultado del disparo.
int disparo_automatico(char tablero[][N], char tablero_v[][N], jugador *player);

// Cabecera: Determina si un disparo ha tocado o hundido un barco en el tablero.
// Precondición: La posición disparada debe ser válida y corresponder a un barco.
// Postcondición: Devuelve 1 si el barco está hundido, 0 si solo está tocado.
int tocado_o_hundido(char tablero_v[][N], char tablero[][N], int fila, int columna, char barco);

// Cabecera: Marca todas las casillas de un barco como hundidas en el tablero.
// Precondición: El barco debe estar completamente hundido.
// Postcondición: Actualiza el tablero marcando las casillas del barco como hundidas.
void hundido(char tablero_v[][N], char tablero[][N], int fila, int columna, char barco);

// Cabecera: Busca la proa de un barco en el tablero a partir de una posición dada.
// Precondición: La posición inicial debe corresponder a una parte del barco.
// Postcondición: Devuelve las coordenadas de la proa del barco.
void buscar_proa(int *fila, int *columna, char barco, char tablero[][N]);

// Cabecera: Realiza un disparo en el tablero del oponente y actualiza el tablero de disparos del jugador.
// Precondición: Los tableros deben estar inicializados y las coordenadas deben ser válidas.
// Postcondición: Actualiza el tablero del oponente y el tablero de disparos del jugador.
void realizar_disparo(jugador *jug, char tablero_oponente[][10], char tablero_disparos[][10]);

#endif
