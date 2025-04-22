#include <stdio.h>
#include <string.h>

#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"

#define TAM 10
#define NUM_BARCOS 3

void menu_intro(){
    printf("Bienvenido a Hundir la flota\n");
    printf("1. Configuracion\n");
    printf("2. Jugar\n");
    printf("3. Salir\n");
}

int seleccion_opcion(){
    int opcion=0;
    printf("Seleccione una opcion\n");
    scanf("%i",&opcion);
    return opcion;
}

void switch_menu(int aux){ //ESTA FUNCION TIENE QUE RECIBIR TODO
    switch(aux){
        case 1:
            configuracion();
            break;
        case 2:
            jugar();
            break;
        case 3:
            break; 
        default:
            printf("Opcion no valida\n");
            break;
    }
}

void configuracion(){ //ESTA FUNCION TIENE QUE RECIBIR TODO
    int aux=0;
    aux=seleccion_opcion();
    switch_configuracion(aux);
}



void switch_configuracion(int aux){ //ESTA FUNCION TIENE QUE RECIBIR TODO

    printf("Menu Configuracion\n");
    printf("1. Introducir datos\n");
    printf("2. Mostrar\n");
    printf("3. Borrar\n");
    printf("4. Guardar\n");
    printf("5. Cargar\n");
    printf("6. Volver\n");

    switch (aux){
        case 1:
            introducir_datos();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            borrar();
            break;
        case 4:
            guardar();
            break;
        case 5:
            cargar();
            break;
        case 6:
            menu_intro();
            aux=seleccion_opcion();
            switch_menu(aux);
            break;
        default:
            printf("Opcion no valida\n");
            configuracion();
            break;
    }
}

void introducir_datos(){
    printf("[Queda por terminar]\n");
}

void mostrar(){
    printf("[Queda por terminar]\n");

}

void borrar(){
    printf("[Queda por terminar]\n");

}

void guardar(){
    printf("[Queda por terminar]\n");

}

void cargar(){
    printf("[Queda por terminar]\n");

}

void jugar(){ //ESTA FUNCION TIENE QUE RECIBIR TODO
    int aux=0;
    aux=seleccion_opcion();
    switch_jugar(aux);
}



void switch_jugar(int aux){ //ESTA FUNCION TIENE QUE RECIBIR TODO

    printf("Menu Jugar\n");
    printf("1. Jugar partida\n");
    printf("2. Reiniciar partida\n");
    printf("3. Resumen\n");
    printf("4. Volver\n");

    switch (aux){
        case 1:
            jugar_partida();
            break;
        //case 2:
        //    Reiniciar_partida();
        //    break;
        //case 3:
            //Resumen();
        //    break;
        case 4:
            menu_intro();
            aux=seleccion_opcion();
            switch_menu(aux);
            break;
        default:
            printf("Opcion no valida\n");
            jugar();
            break;
    }
}

void jugar_partida(){

    // tablero[eje y][eje x]
    //falta crearla dinamicamente
    char flota_jug1[TAM][TAM];
    char oponente_jug1[TAM][TAM];
    char flota_jug2[TAM][TAM];
    char oponente_jug2[TAM][TAM];

    //barcos

    barco barcos_jug1[NUM_BARCOS];
    barco barcos_jug2[NUM_BARCOS];



    //jugadores

    jugador jugador1;
    jugador jugador2;

    // inicializacion
    strcpy(jugador1.nombre,"Jugador1");
    //jugador1.disparos_realizados = 0;
    jugador1.disparo = 'M';
    //jugador1.disparos_agua = 0;
    //jugador1.casillas_tocadas = 0;
    //jugador1.casillas_hundidas = 0;
    //jugador1.barcos_hundidos = 0;
    //jugador1.ganador = 0;

    strcpy(jugador2.nombre,"Jugador2");
    jugador2.disparo = 'M';
    //jugador2.disparos_realizados = 0;
    //jugador2.disparos_agua = 0;
    //jugador2.casillas_tocadas = 0;
    //jugador2.casillas_hundidas = 0;
    //jugador2.barcos_hundidos = 0;
    //jugador2.ganador = 0;

    //inicializar los tableros vacíos
    inicializar_espacio(flota_jug1);
    inicializar_espacio(oponente_jug1);
    inicializar_espacio(flota_jug2);
    inicializar_espacio(oponente_jug2);

    inicializar_barcos(barcos_jug1); //ejemplo de barcos (hay que quitarlo, se deben añadir en "Introducir datos")
    inicializar_barcos(barcos_jug2);

    colocar_barcos(flota_jug1, barcos_jug1);
    colocar_barcos(flota_jug2, barcos_jug2);

    int turnoJugador = 1; // 1 jugador1, 2 jugador2
    int juegoTerminado = 0;


    while (!juegoTerminado) {
        printf("\n--- Turno de %s ---\n", (turnoJugador == 1) ? jugador1.nombre : jugador2.nombre);

        if (turnoJugador == 1) {
            imprimirTableros(flota_jug1, oponente_jug1);
            realizar_disparo(&jugador1, flota_jug2, oponente_jug1);
            if (jugador1.barcos_hundidos == NUM_BARCOS) { //comprueba si ha ganado
                jugador1.ganador = 1;
                juegoTerminado = 1;
                printf("\n¡¡¡ %s HA GANADO !!!\n", jugador1.nombre);
            }
            turnoJugador = 2;
        } else {
            imprimirTableros(flota_jug2, oponente_jug2);
            realizar_disparo(&jugador2, flota_jug1, oponente_jug2);
            if (jugador2.barcos_hundidos == NUM_BARCOS) {
                jugador2.ganador = 1;
                juegoTerminado = 1;
                printf("\n¡¡¡ %s HA GANADO !!!\n", jugador2.nombre);
            }
            turnoJugador = 1;
        }

    }

    Resumen(&jugador1, &jugador2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2);

    jugar();

}



// Implementación actualizada en menu_principal.c
void Resumen(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM]){

    printf("\n--- RESUMEN DE LA PARTIDA ---\n\n");

    imprimirCabeceraTabla();
/*
    // --- Calcular y mostrar datos Jugador 1 ---
    int vacias_j2 = 0; // Casillas no disparadas por J1 en el tablero de J2
    // Contar casillas en el tablero de vista de J1 (oponente_jug1) que aún están en estado inicial (agua no disparada, ej '.')
    // ¡¡ASEGÚRATE que '.' es tu carácter inicial para agua en el tablero de vista!!
    for(int i=0; i<TAM; ++i) {
        for(int j=0; j<TAM; ++j) {
            // Si no es Tocado, Hundido o Agua ('*'), es una casilla vacía para el atacante
            if(oponente_jug1[i][j] != 'T' && oponente_jug1[i][j] != 'H' && oponente_jug1[i][j] != '*') {
                 vacias_j2++;
            }
        }
    }

    int restan_j2 = NUM_BARCOS - j1->barcos_hundidos; // Barcos de J2 que J1 no ha hundido
*/
    imprimirFilaJugador(j1->nombre,
                       j1->disparos_realizados,
                       0,//vacias_j2,          // Calculado ahora
                       j1->disparos_agua,
                       j1->casillas_tocadas, // Contadas en disparo
                       j1->casillas_hundidas, // Contadas en disparo
                       j1->barcos_hundidos,  // Contados en disparo
                       0,//restan_j2,          // Calculado ahora
                       j1->ganador);         // Actualizado en el bucle principal


    // --- Calcular y mostrar datos Jugador 2 ---
    /*
    int vacias_j1 = 0; // Casillas no disparadas por J2 en el tablero de J1
    for(int i=0; i<TAM; ++i) {
        for(int j=0; j<TAM; ++j) {
            if(oponente_jug2[i][j] != 'T' && oponente_jug2[i][j] != 'H' && oponente_jug2[i][j] != '*') {
                 vacias_j1++;
            }
        }
    }
    int restan_j1 = NUM_BARCOS - j2->barcos_hundidos; // Barcos de J1 que J2 no ha hundido
*/
    imprimirFilaJugador(j2->nombre,
                       j2->disparos_realizados,
                       0,//vacias_j1,          // Calculado ahora
                       j2->disparos_agua,
                       j2->casillas_tocadas,
                       j2->casillas_hundidas,
                       j2->barcos_hundidos,
                       0,//restan_j1,          // Calculado ahora
                       j2->ganador);

    printf("\nTablero final %s:\n", j1->nombre);
    imprimirTableros(flota_jug1, oponente_jug1);

    printf("\nTablero final %s:\n", j2->nombre);
    imprimirTableros(flota_jug2, oponente_jug2);

}

void Reiniciar_partida(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM]){
    // reiniciar tableros
    inicializar_espacio(flota_jug1);
    inicializar_agua(oponente_jug1);
    inicializar_espacio(flota_jug2);
    inicializar_agua(oponente_jug2);

    // reiniciar estadísticas de los jugadores
    j1->disparos_realizados = 0;
    j1->disparos_agua = 0;
    j1->casillas_tocadas = 0;
    j1->casillas_hundidas = 0;
    j1->barcos_hundidos = 0;
    j1->ganador = 0;

    j2->disparos_realizados = 0;
    j2->disparos_agua = 0;
    j2->casillas_tocadas = 0;
    j2->casillas_hundidas = 0;
    j2->barcos_hundidos = 0;
    j2->ganador = 0;

    printf("Partida reiniciada (estadísticas y tableros).\n");
    //volver al menu
    jugar();
}

void imprimirCabeceraTabla() {
    printf("          |             Valor de las casillas                |            Barcos           |\n");

    printf(" Jugador  | Disparos | Vacías  | Agua    | Tocadas | Hundidas| Hundidos| Restan  | Ganador |\n");

    printf("----------|----------|---------|---------|---------|---------|---------|---------|---------|\n");
}

void imprimirFilaJugador(const char* nombreJugador, int disparos, int vacias, int agua, int tocadas, int hundidasCasillas, int hundidosBarcos, int restanBarcos, int esGanador) {
    printf(" %-8s | %8d | %7d | %7d | %7d | %7d | %7d | %7d | %7d |\n",
           nombreJugador,
           disparos,
           vacias,
           agua,
           tocadas,
           hundidasCasillas,
           hundidosBarcos,
           restanBarcos,
           esGanador);
}
