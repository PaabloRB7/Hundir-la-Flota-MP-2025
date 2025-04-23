#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"

#define N 10
#define NUM_BARCOS 3

// Funciones
int disparo(int fila, int columna, char tablero[][N], char tablero_v[][N]) //tablero: tablero barcos personales, tablero_v: tablero
{
    int tocado = 0, i, j, hundido = 1;
    char barco;
    //if (fila < 0 || fila >= N || columna < 0 || columna >= N) { //comprueba si las coordenadas están dentro del tablero
    //    printf("Coordenadas fuera del tablero.\n");
    //    return -1; //error
    //}


    if (tablero[fila][columna] != ' ' && tablero[fila][columna] != 'T' && tablero[fila][columna] != 'H')
    {
        tocado = 1;
        barco = tablero[fila][columna];
        tablero[fila][columna] = 'T';
        tablero_v[fila][columna] = 'T';
        buscar_proa(&fila, &columna, barco, tablero);
        tocado = tocado + tocado_o_hundido(tablero_v, tablero, fila, columna, barco);
    }
    else
        tablero_v[fila][columna] = '*';

    return tocado;
}

int disparo_manual(char tablero[][N], char tablero_v[][N], jugador *player)
{
    int fila=1, columna=1, resultado;

    printf("\nIntroduce las coordenadas del disparo (separando la fila y columna por un espacio): ");
    printf("Numero de barcos hundidos: %d\n", player->barcos_hundidos);

    scanf("%i %i", &fila, &columna);
    fflush(stdin);
    resultado = disparo(fila, columna, tablero, tablero_v);

    switch (resultado)
    {
    case 1:
        printf("\nTocado!\n\n");
        player->casillas_tocadas++;
        break;
    case 2:
        printf("\nHUNDIDO!!!\n\n");
        player->casillas_tocadas++;
        player->barcos_hundidos++;
        break;
    default:
        printf("\nAgua...\n\n");
        player->disparos_agua++;
    }

    player->disparos_realizados++;
    return resultado;
}

int disparo_automatico(char tablero[][N], char tablero_v[][N], jugador *player)
{
    int fila, columna, i, j, barco_tocado = 0, resultado = 0;
    int repeticiones = 0;
    int intentos_maximos = 100;

    for (i = 0; i < N && barco_tocado == 0; i++)
    {
        for (j = 0; j < N && barco_tocado == 0; j++)
        {
            if (tablero_v[i][j] == 'T')
            {
                barco_tocado = 1;
                do
                {
                    int intentos = 0;
                    int min_f = (i - 1 < 0) ? 0 : i - 1;
                    int max_f = (i + 1 >= N) ? N - 1 : i + 1;
                    int min_c = (j - 1 < 0) ? 0 : j - 1;
                    int max_c = (j + 1 >= N) ? N - 1 : j + 1;

                    fila = (rand() % (max_f - min_f + 1)) + min_f;
                    columna = (rand() % (max_c - min_c + 1)) + min_c;

                    repeticiones++;
                    intentos++;


                    if (repeticiones >= 10 || intentos >= intentos_maximos)
                    {
                        barco_tocado = 0;
                        break;
                    }

                } while (tablero_v[fila][columna] == 'T' || tablero_v[fila][columna] == '*');

                if (barco_tocado == 1)
                {
                    resultado = disparo(fila, columna, tablero, tablero_v);
                }
            }
        }
    }


    if (barco_tocado == 0)
    {
        int intentos = 0;
        do
        {
            fila = rand() % N;
            columna = rand() % N;
            intentos++;
            if (intentos >= intentos_maximos)
                break;
        } while (tablero_v[fila][columna] == 'T' || tablero_v[fila][columna] == '*');

        resultado = disparo(fila, columna, tablero, tablero_v);
    }


    switch (resultado)
    {
    case 1:
        printf("\nTocado!\n\n");
        player->casillas_tocadas++;
        break;
    case 2:
        printf("\nHUNDIDO!!!\n\n");
        player->casillas_tocadas++;
        player->barcos_hundidos++;
        break;
    default:
        printf("\nAgua...\n\n");
        player->disparos_agua++;
    }

    player->disparos_realizados++;
    return resultado;
}


/* Version anterior disparo_automatico
int disparo_automatico(char tablero[][N], char tablero_v[][N], jugador *player)
{
    int max, min, fila, columna, i, j, barco_tocado, resultado = 0, repeticiones = 0;
    barco_tocado = 0;
    srand(time(NULL));
    for (i = 0; i <= 9 && barco_tocado == 0; i++)
        for (j = 0; j <= 9 && barco_tocado == 0; j++)
            if (tablero_v[i][j] == 'T')
            {
                barco_tocado = 1;
                do
                {
                    repeticiones++;
                    if (repeticiones >= 10)
                    {
                        repeticiones = 0;
                        barco_tocado = 0;
                    }
                    min = i - 1;
                    max = i + 1;
                    fila = (rand() % (max - min + 1)) + min;
                    min = j - 1;
                    max = j + 1;
                    columna = (rand() % (max - min + 1)) + min;
                } while (tablero_v[fila][columna] == 'T' || tablero_v[fila][columna] == '*');
                if (barco_tocado == 1)
                    resultado = disparo(fila, columna, tablero, tablero_v);
            }

    if (barco_tocado == 0)
    {
        min = 0;
        max = N;
        do
        {
            fila = (rand() % (max - min + 1)) + min;
            columna = (rand() % (max - min + 1)) + min;
        } while (tablero_v[fila][columna] == 'T' || tablero_v[fila][columna] == '*');
        resultado = disparo(fila, columna, tablero, tablero_v);
    }
    switch (resultado)
    {
    case 1:
        printf("\nTocado!\n\n");
        player->casillas_tocadas++;
        break;
    case 2:
        printf("\nHUNDIDO!!!\n\n");
        player->casillas_tocadas++;
        player->barcos_hundidos++;
        break;
    default:
        printf("\nAgua...\n\n");
        player->disparos_agua++;
    }
    player->disparos_realizados++;
    return resultado;
}
*/

void hundido(char tablero_v[][N], char tablero[][N], int fila, int columna, char barco)
{
    int i, j, hundido = 1, bucle = 1, nfila, ncolumna;
    nfila = fila;
    ncolumna = columna;

    while (bucle == 1)
    {
        bucle = 0;
        fila = nfila;
        columna = ncolumna;
        tablero[fila][columna] = 'H';
        tablero_v[fila][columna] = 'H';
        for (i = fila - 1; i <= fila + 1; i++)
            for (j = columna - 1; j <= columna + 1; j++)
                if (i != fila || j != columna)
                {
                    if (tablero[i][j] == 'T')
                    {
                        nfila = i;
                        ncolumna = j;
                        bucle = 1;
                    }
                }
    }
}

int tocado_o_hundido(char tablero_v[][N], char tablero[][N], int fila, int columna, char barco)
{
    int i, j, hundid = 1, bucle = 1, nfila, ncolumna, mfila=100, mcolumna=100;
    nfila = fila;
    ncolumna = columna;

    while (bucle == 1)
    {
        bucle = 0;
        fila = nfila;
        columna = ncolumna;
        for (i = fila - 1; i <= fila + 1; i++)
            for (j = columna - 1; j <= columna + 1; j++)
                if (i != fila || j != columna)
                {
                    if (tablero[i][j] == 'T' && i != mfila && j != mcolumna)
                    {
                        mfila = fila;
                        mcolumna = columna;
                        nfila = i;
                        ncolumna = j;
                        bucle = 1;
                    }
                    if (barco == tablero[i][j])
                        hundid = 0;
                }
    }
    if (hundid == 1)
    {
        buscar_proa(&fila, &columna, barco, tablero);
        hundido(tablero_v, tablero, fila, columna, barco);
    }
    return hundid;
}

void buscar_proa(int *fila, int *columna, char barco, char tablero[][N])
{
    int i, j, nfila, ncolumna, bucle = 1;
    nfila = *fila;
    ncolumna = *columna;

    while (bucle == 1)
    {
        bucle = 0;
        *fila = nfila;
        *columna = ncolumna;
        for (i = *fila - 1; i <= *fila + 1; i++)
            for (j = *columna - 1; j <= *columna + 1; j++)
                if (i != *fila || j != *columna)
                    if (barco == tablero[i][j] || tablero[i][j] == 'T')
                        if (i > *fila || j > *columna)
                        {
                            nfila = i;
                            ncolumna = j;
                            bucle = 1;

                        }
    }
}

void realizar_disparo(jugador *jug, char tablero_oponente[][10], char tablero_disparos[][10]) {
    if (jug->disparo == 'M')
        disparo_manual(tablero_oponente, tablero_disparos, jug);
    else if (jug->disparo == 'A')
        disparo_automatico(tablero_oponente, tablero_disparos, jug);
}
