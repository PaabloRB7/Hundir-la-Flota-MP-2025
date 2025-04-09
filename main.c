#include <stdio.h>
#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"

#define TAM 10



int main(){
    /*
    int aux=0;
    menu_intro();
    aux=seleccion_opcion();
    switch_menu(aux);
    */


    // tablero[eje y][eje x]
    char flota_jug1[TAM][TAM];
    char oponente_jug1[TAM][TAM];
    char flota_jug2[TAM][TAM];
    char oponente_jug2[TAM][TAM];

    //barcos

    barco barcos_jug1[5];
    barco barcos_jug2[5];

    //inicializar los tableros vacíos
    inicializar_espacio(flota_jug1);
    inicializar_agua(oponente_jug1);
    inicializar_espacio(flota_jug2);
    inicializar_agua(oponente_jug2);

    //tablero Jugador 1
    //imprimirTableros(flota_jug1, oponente_jug1);

    //tablero Jugador 2
    //imprimirTableros(flota_jug2, oponente_jug2);


    inicializar_barcos(barcos_jug1);
    inicializar_barcos(barcos_jug2);

    colocar_barcos(flota_jug1, barcos_jug1);

    disparo_manual(flota_jug1, oponente_jug1);


    return 0;
}