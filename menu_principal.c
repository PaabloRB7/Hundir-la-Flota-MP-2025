#include <stdio.h>
#include <string.h>

#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"

#define TAM 10
#define NUM_BARCOS 5

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

void switch_menu(int aux){
    switch(aux){
        case 1:
            configuracion();
            break;
        case 2:
            jugar();
            break;
        case 3:
            //funcion salir
            break; 
        default:
            printf("Opcion no valida\n");
            break;
    }
}

void configuracion(){
    int aux=0;
    menu_configuracion();
    aux=seleccion_opcion();
    switch_configuracion(aux);
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

void switch_configuracion(int aux){
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

void jugar(){
    int aux=0;
    menu_jugar();
    aux=seleccion_opcion();
    switch_jugar(aux);
}

void menu_jugar(){
    printf("Menu Jugar\n");
    printf("1. Jugar partida\n");
    printf("2. Reiniciar partida\n");
    printf("3. Resumen\n");
    printf("4. Volver\n");
}

void switch_jugar(int aux){
    switch (aux){
        case 1:
            jugar_partida();
            break;
        case 2:
            Reiniciar_partida();
            break;
        case 3:
            Resumen();
            break;
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
    printf("[En desarrollo]\n");
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

    //Test (hay que quitarlo)
    jugador1.disparo = 'M';
    jugador2.disparo = 'M';
    strcpy(jugador1.nombre,"Jugador 1");
    strcpy(jugador2.nombre,"Jugador 2");

    //inicializar los tableros vacíos
    inicializar_espacio(flota_jug1);
    inicializar_agua(oponente_jug1);
    inicializar_espacio(flota_jug2);
    inicializar_agua(oponente_jug2);

    inicializar_barcos(barcos_jug1); //ejemplo de barcos (hay que quitarlo, se deben añadir en "Introducir datos")
    inicializar_barcos(barcos_jug2);

    colocar_barcos(flota_jug1, barcos_jug1);

    while (1) {
        //Comienza el turno
        realizar_disparo(jugador1, flota_jug1, oponente_jug1);
        imprimirTableros(flota_jug1, oponente_jug1);
        realizar_disparo(jugador2, flota_jug2, oponente_jug2);
        imprimirTableros(flota_jug2, oponente_jug2);

        //Comprobar si hay ganador (queda por hacer)
        break;
    }



}
void Reiniciar_partida(char flota_jug1[][TAM],char oponente_jug1[][TAM],char flota_jug2[][TAM],char oponente_jug2[][TAM]){
    printf("[En desarrollo]\n");
    //se reinician los tableros
    inicializar_espacio(flota_jug1);
    inicializar_agua(oponente_jug1);
    inicializar_espacio(flota_jug2);
    inicializar_agua(oponente_jug2);

    //se reinician las estadisticas (falta por hacer)
}

void Resumen(){
    printf("[En desarrollo]\n");
    //imprimir tabla resumen
    imprimirCabeceraTabla();
    //datos jug1
    imprimirFilaJugador("Jugador1", 49, 18, 69, 0, 13, 4, 0, 1);

    //datos jug2
    imprimirFilaJugador("Jugador2", 49, 27, 61, 0, 12, 3, 1, 0);


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
