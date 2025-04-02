#ifndef DISPAROS_H
#define DISPAROS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

// Prototipos de funciones
int disparo(int fila, int columna, char tablero[][N], char tablero_v[][N]);
int disparo_manual(char tablero[][N], char tablero_v[][N]);
int disparo_automatico(char tablero[][N], char tablero_v[][N]);
int tocado_o_hundido(char tablero_v[][N], char tablero[][N], int fila, int columna, char barco);
void hundido(char tablero_v[][N], char tablero[][N], int fila, int columna, char barco);
void buscar_proa(int *fila, int *columna, char barco, char tablero[][N]);

#endif
