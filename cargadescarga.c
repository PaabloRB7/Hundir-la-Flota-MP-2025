#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"
#include "cargadescarga.h"

void cargar_barcos(barco barcos[], int num_barcos) {
    FILE *f = fopen("barcos.txt", "r");
    if (!f) {
        printf("Error al abrir barcos.txt para cargar.\n");
        return;
    }

    for (int i = 0; i < num_barcos; i++) {
        fscanf(f, "%s %d %c\n", barcos[i].nombre, &barcos[i].longitud, &barcos[i].tipo);
    }

    fclose(f);
    printf("Barcos cargados correctamente.\n");
}
void guardar_barcos(barco barcos[], int num_barcos) {
    FILE *f = fopen("barcos.txt", "w");
    if (!f) {
        printf("Error al abrir barcos.txt para guardar.\n");
        return;
    }

    for (int i = 0; i < num_barcos; i++) {
        fprintf(f, "%s-%d-%c\n", barcos[i].nombre, barcos[i].longitud, barcos[i].tipo);
    }

    fclose(f);
    printf("Barcos guardados correctamente.\n");

void guardar_jugador(jugador *jugador, FILE *f) {
    FILE *f = fopen("config.txt", "w");
    if (!f) {
        printf("Error al abrir barcos.txt para guardar.\n");
        return;
    }
    fprintf(f, "%s-%d-%c-%d\n", jugador->nombre, jugador->disparos_realizados, jugador->disparo, jugador->ganador);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            fprintf(f, "%c", jugador->tablero_propio[i][j]);
        }
        fprintf(f, "\n");
    }
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            fprintf(f, "%c", jugador->tablero_oponente[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printf("Jugadores guardados correctamente.\n");
}

void cargar_jugador(jugador j[], FILE *f) {
    int i;
    FILE *f = fopen("config.txt", "w");
    if (!f) {
        printf("Error al abrir barcos.txt para cargar.\n");
        return;
    }
    for (i=0; i < 2; i++) {
        fscanf(f, "%s-%d-%c-%d\n", j[i].nombre, j[i].disparos_realizados, j[i].disparo, j[i].ganador);  
        for (int i = 0; i < TAM; i++) fscanf(f, "%s\n", jugador->tablero_propio[i]);
        for (int i = 0; i < TAM; i++) fscanf(f, "%s\n", jugador->tablero_oponente[i]);
    }
    fclose(f);
    printf("Jugadores cargados correctamente.\n");
}
    


