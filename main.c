#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"

#define TAM 10
#define NUM_BARCOS 3



int main(){

    srand(time(NULL));

    // tableros   [eje y][eje x]
    //char flota_jug1[TAM][TAM];
    //char oponente_jug1[TAM][TAM];
    //char flota_jug2[TAM][TAM];
    //char oponente_jug2[TAM][TAM];

    // Crear matrices dinámicamente
    char (*flota_jug1)[TAM] = malloc(TAM * TAM * sizeof(char));
    char (*oponente_jug1)[TAM] = malloc(TAM * TAM * sizeof(char));
    char (*flota_jug2)[TAM] = malloc(TAM * TAM * sizeof(char));
    char (*oponente_jug2)[TAM] = malloc(TAM * TAM * sizeof(char));

    //barcos

    barco barcos_jug1[NUM_BARCOS];
    barco barcos_jug2[NUM_BARCOS];

    //jugadores

    jugador jugador1;
    jugador jugador2;

    // inicializacion
    strcpy(jugador1.nombre,"Jugador1");
    jugador1.disparos_realizados = 0;
    jugador1.disparo = 'M';
    jugador1.disparos_agua = 0;
    jugador1.casillas_tocadas = 0;
    jugador1.casillas_hundidas = 0;
    jugador1.barcos_hundidos = 0;
    jugador1.ganador = 0;

    strcpy(jugador2.nombre,"Jugador2");
    jugador2.disparo = 'A';
    jugador2.disparos_realizados = 0;
    jugador2.disparos_agua = 0;
    jugador2.casillas_tocadas = 0;
    jugador2.casillas_hundidas = 0;
    jugador2.barcos_hundidos = 0;
    jugador2.ganador = 0;

    //inicializar los tableros vacíos
    inicializar_espacio(flota_jug1);
    inicializar_espacio(oponente_jug1);
    inicializar_espacio(flota_jug2);
    inicializar_espacio(oponente_jug2);

    inicializar_barcos(barcos_jug1); //ejemplo de barcos (hay que quitarlo, se deben añadir en "Introducir datos")
    inicializar_barcos(barcos_jug2);


    int aux=0;
    menu_intro();
    aux=seleccion_opcion();
    switch_menu(aux, &jugador1, &jugador2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);

    // libera memoria al final del programa
    free(flota_jug1);
    free(oponente_jug1);
    free(flota_jug2);
    free(oponente_jug2);

    return 0;
}
