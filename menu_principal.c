#include <stdio.h>
#include <string.h>

#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"
#include "cargadescarga.h"

#define TAM 10
#define NUM_BARCOS 4

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

void switch_menu(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){
    switch(aux){
        case 1:
            configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 2:
            jugar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 3:
            break; 
        default:
            printf("Opcion no valida\n");
            break;
    }
}

void configuracion(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){  
    int aux=0;
    menu_configuracion();
    aux=seleccion_opcion();
    switch_configuracion(aux,j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
}

void menu_configuracion(){
    printf("Menu Configuracion\n");
    printf("1. Introducir datos\n");
    printf("2. Mostrar\n");
    printf("3. Borrar\n");
    printf("4. Guardar\n");
    printf("5. Cargar\n");
    printf("6. Volver\n");
}

void switch_configuracion(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){  

    switch (aux){
        case 1:
            introducir_datos(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 2:
            mostrar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 3:
            borrar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 4:
            guardar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 5:
            cargar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 6:
            menu_intro();
            aux=seleccion_opcion();
            switch_menu(aux, j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        default:
            printf("Opcion no valida\n");
            configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
    }
}

void introducir_datos(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){
    printf("[Queda por terminar]\n");
    configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
}

void mostrar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){
    mostrar_barcos();
    mostrar_jugador();
    //mostrar_configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
    configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
    


}

void borrar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){
    printf("[Queda por terminar]\n");
    configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);


}

void guardar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){
    printf("[Queda por terminar]\n");
    configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);


}

void cargar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){
    printf("[Queda por terminar]\n");
    configuracion(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);

}

void jugar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){  
    int aux=0;
    menu_jugar();
    aux=seleccion_opcion();
    switch_jugar(aux,j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
}

void menu_jugar(){
    printf("Menu Jugar\n");
    printf("1. Jugar partida\n");
    printf("2. Reiniciar partida\n");
    printf("3. Resumen\n");
    printf("4. Volver al menu principal\n");
}

void switch_jugar(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){  

    switch (aux){
        case 1:
            jugar_partida(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 2:
            Reiniciar_partida(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 3:
            Resumen(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        case 4:
            menu_intro();
            aux=seleccion_opcion();
            switch_menu(aux, j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
        default:
            printf("Opcion no valida\n");
            jugar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
            break;
    }
}

void jugar_partida(jugador *jugador1, jugador *jugador2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){

    colocar_barcos(flota_jug1, barcos_jug1);
    colocar_barcos(flota_jug2, barcos_jug2);


    int turnoJugador = 1; // 1 jugador1, 2 jugador2
    int juegoTerminado = 0;


    while (!juegoTerminado) {
        printf("\n--- Turno de %s ---\n", (turnoJugador == 1) ? jugador1->nombre : jugador2->nombre);

        if (turnoJugador == 1) {
            imprimirTableros(flota_jug1, oponente_jug1);
            realizar_disparo(jugador1, flota_jug2, oponente_jug1);
            if (jugador1->barcos_hundidos == NUM_BARCOS) { //comprueba si ha ganado
                jugador1->ganador = 1;
                juegoTerminado = 1;
                printf("\n¡¡¡ %s HA GANADO !!!\n", jugador1->nombre);
            }
            turnoJugador = 2;
        } else {
            imprimirTableros(flota_jug2, oponente_jug2);
            realizar_disparo(jugador2, flota_jug1, oponente_jug2);
            if (jugador2->barcos_hundidos == NUM_BARCOS) {
                jugador2->ganador = 1;
                juegoTerminado = 1;
                printf("\n¡¡¡ %s HA GANADO !!!\n", jugador2->nombre);
            }
            turnoJugador = 1;
        }

    }

    Resumen(jugador1, jugador2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);

    jugar(jugador1, jugador2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);

}



// Implementación actualizada en menu_principal.c
void Resumen(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){

    printf("--- RESUMEN DE LA PARTIDA ---\n");

    imprimirCabeceraTabla();

    //calcular datos j1
    int vacias_j2 = 0;
    for(int i=0; i<TAM; ++i) {
        for(int j=0; j<TAM; ++j) {
            if(oponente_jug1[i][j] != 'T' && oponente_jug1[i][j] != 'H' && oponente_jug1[i][j] != '*') {
                 vacias_j2++;
            }
        }
    }

    int restan_j2 = NUM_BARCOS - j1->barcos_hundidos; // barcos de j2 que j1 no ha hundido

    imprimirFilaJugador(j1->nombre,
                       j1->disparos_realizados,
                       vacias_j2,
                       j1->disparos_agua,
                       j1->casillas_tocadas,
                       j1->casillas_hundidas,
                       j1->barcos_hundidos,
                       restan_j2,
                       j1->ganador);



    int vacias_j1 = 0;
    for(int i=0; i<TAM; ++i) {
        for(int j=0; j<TAM; ++j) {
            if(oponente_jug2[i][j] != 'T' && oponente_jug2[i][j] != 'H' && oponente_jug2[i][j] != '*') {
                 vacias_j1++;
            }
        }
    }
    int restan_j1 = NUM_BARCOS - j2->barcos_hundidos; // barcos de j1 que j2 no ha hundido

    imprimirFilaJugador(j2->nombre,
                       j2->disparos_realizados,
                       vacias_j1,
                       j2->disparos_agua,
                       j2->casillas_tocadas,
                       j2->casillas_hundidas,
                       j2->barcos_hundidos,
                       restan_j1,
                       j2->ganador);

    printf("\nTablero final %s:\n", j1->nombre);
    imprimirTableros(flota_jug1, oponente_jug1);

    printf("\nTablero final %s:\n", j2->nombre);
    imprimirTableros(flota_jug2, oponente_jug2);

    jugar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);

}

void Reiniciar_partida(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]){
    // reiniciar tableros
    inicializar_espacio(flota_jug1);
    inicializar_espacio(oponente_jug1);
    inicializar_espacio(flota_jug2);
    inicializar_espacio(oponente_jug2);

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
    jugar(j1, j2, flota_jug1, oponente_jug1, flota_jug2, oponente_jug2, barcos_jug1, barcos_jug2);
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

void mostrar_barcos() {
    barco barcos[4];
    //cargar_barcos(barcos, 4); // Cargar los barcos desde el archivo
    printf("Barcos disponibles:\n");
    for (int i = 0; i < NUM_BARCOS; i++) {
        printf("%s - %d - %c\n", barcos[i].nombre, barcos[i].longitud, barcos[i].tipo);
    }
}

void mostrar_jugador(){
    jugador j[2];
    FILE *f = fopen("config.txt", "r");
    if (!f) {
        printf("Error al abrir config.txt para cargar.\n");
        return;
    }
    //cargar_jugador(j, f);
    
    //for (int i = 0; i < 2; i++) {
    //    fprintf("%s-%d-%c-%d\n", j[i].nombre, j[i].disparos_realizados, j[i].disparo, j[i].ganador);
    //}
    fclose(f);
}