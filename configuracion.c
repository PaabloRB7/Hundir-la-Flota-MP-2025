#include <stdio.h>
#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"
#include "cargadescarga.h"
#include <stdlib.h>

//Funciones
void config() {
    int opcion;
    printf("Menu Configuracion\n");
    printf("1. Introducir datos\n");
    printf("2. Mostrar\n");
    printf("3. Borrar\n");
    printf("4. Guardar\n");
    printf("5. Cargar\n");
    printf("6. Volver\n");

    opcion = seleccion_opcion();

    switch (opcion) {
        case 1: introducir_datos(); break;
        case 2: mostrar(); break;
        case 3: borrar(); break;
        case 4: guardar(); break;
        case 5: cargar(); break;
        default: printf("Opcion no valida\n");
        case 6: return;
    }
}


void introducir_datos(){
    FILE *f;
    int n, num_barcos, tiposbarcos[4], primerturno, bucle, respuesta, iter; //tipos de barcos 0 = S, 1 = F, 2 = C, 3 = A y 4 = P
    jugador j[2];
    barco barcos[4];

    if ((f = fopen("config.txt", "w")) != NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }
    else {
        for(iter = 0; iter < 2; iter++){
            printf("\nIntroduzca el nombre del jugador %i: ", iter+1);
            fflush(stdin);
            fgets(j[iter].nombre, sizeof(j[iter].nombre), stdin);
            bucle = 1;
            while(bucle = 1){
                printf("\nEl tipo de disparo del jugador %i es manual? (s/n): ", iter+1);
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta == 's' || respuesta == 'n'){
                    bucle = 0;
                    if(respuesta == 's')
                        j[iter].disparo = 'M';
                    else
                        j[iter].disparo = 'A';
                }
                else{
                    printf("\nOpcion no valida\n");
                    bucle = 1;
                }
        }

        guardar_jugador(j, f);

        printf("\nIntroduzca el tamaño del barco a usar ");
        for(bucle i = 0; i < 4; i++){
            printf("Barco %d: ", i+1);
            scanf("%d", &barcos[i].longitud);
            if(tiposbarcos[i] < 1 || tiposbarcos[i] > 5){
                printf("\nOpcion no valida\n");
                i--;
            }
            fflush(stdin);
            switch(i){
                case 1: strcpy(barcos[i].nombre, "Submarino"); break;
                case 2: strcpy(barcos[i].nombre, "Fragata"); break;
                case 3: strcpy(barcos[i].nombre, "Crucero"); break;
                case 4: strcpy(barcos[i].nombre, "Acorazado"); break;
            }
            switch(tiposbarcos[i]){
                case 1: barcos[i].tipo = 'S'; break;
                case 2: barcos[i].tipo = 'F'; break;
                case 3: barcos[i].tipo = 'C'; break;
                case 4: barcos[i].tipo = 'A'; break;

            }
        }

        cargar_barcos(barcos, 4);

        printf("\nIntroduzca el numero del jugador que comenzara la partida (1/2): ");
        scanf("%d", &primerturno);

        //Guardar en fichero
        fprintf("%s %s %s %s \n", j1.nombre, j1.disparo, j2.nombre, j2.disparo);
        fprintf("%d %d %d %d %d %d\n", tiposbarcos[0], tiposbarcos[1], tiposbarcos[2], tiposbarcos[3], tiposbarcos[4], num_barcos);
        fprintf("%d", primerturno)
    }

fclose(f);
printf("\n\nConfiguracion guardada");
}

void mostrar(){
//Pendiente
}

void borrar(){
    FILE *f = fopen("config.txt", "w");
    if (f != NULL) {
        fclose(f);
        printf("\nConfiguracion borrada correctamente.\n");
    } else {
        printf("\nError al borrar la configuracion.\n");
    }
}

extern jugador j1, j2;
extern tipo_barco tipos_barcos[10];
extern int num_tipos_barco, tam_tablero, num_barcos;

void guardar() {
    FILE *f = fopen("Juego.txt", "w");
    if (!f) {
        printf("Error al abrir Juego.txt para guardar.\n");
        return;
    }

    // Datos generales
    fprintf(f, "%d-%d-%d\n", tam_tablero, num_barcos, num_tipos_barco);

    // Tipos de barco
    for (int i = 0; i < num_tipos_barco; i++) {
        fprintf(f, "%c-%d\n", tipos_barcos[i].id, tipos_barcos[i].cantidad);
    }

    // Guardar datos del jugador 1
    fprintf(f, "1-%s-%d-%c-%d\n", j1.nombre, j1.disparos_realizados, j1.disparo, j1.ganador);
    for (int i = 0; i < tam_tablero; i++) {
        for (int j = 0; j < tam_tablero; j++) {
            fprintf(f, "%c", j1.tablero_propio[i][j]);
        }
        fprintf(f, "\n");
    }
    for (int i = 0; i < tam_tablero; i++) {
        for (int j = 0; j < tam_tablero; j++) {
            fprintf(f, "%c", j1.tablero_oponente[i][j]);
        }
        fprintf(f, "\n");
    }

    // Guardar datos del jugador 2
    fprintf(f, "2-%s-%d-%c-%d\n", j2.nombre, j2.disparos, j2.tipo_disparo, j2.ganador);
    for (int i = 0; i < tam_tablero; i++) {
        for (int j = 0; j < tam_tablero; j++) {
            fprintf(f, "%c", j2.tablero_propio[i][j]);
        }
        fprintf(f, "\n");
    }
    for (int i = 0; i < tam_tablero; i++) {
        for (int j = 0; j < tam_tablero; j++) {
            fprintf(f, "%c", j2.tablero_oponente[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    printf("Partida guardada correctamente.\n");
}

void cargar() {
    FILE *f = fopen("Juego.txt", "r");
    if (!f) {
        printf("Error al abrir Juego.txt para cargar.\n");
        return;
    }

    fscanf(f, "%d-%d-%d\n", &tam_tablero, &num_barcos, &num_tipos_barco);

    for (int i = 0; i < num_tipos_barco; i++) {
        fscanf(f, "%c-%d\n", &tipos_barcos[i].id, &tipos_barcos[i].cantidad);
    }

    fscanf(f, "1-%[^-]-%d-%c-%d\n", j1.nombre, &j1.disparos, &j1.tipo_disparo, &j1.ganador);
    for (int i = 0; i < tam_tablero; i++) fscanf(f, "%s\n", j1.tablero_propio[i]);
    for (int i = 0; i < tam_tablero; i++) fscanf(f, "%s\n", j1.tablero_oponente[i]);

    fscanf(f, "2-%[^-]-%d-%c-%d\n", j2.nombre, &j2.disparos, &j2.tipo_disparo, &j2.ganador);
    for (int i = 0; i < tam_tablero; i++) fscanf(f, "%s\n", j2.tablero_propio[i]);
    for (int i = 0; i < tam_tablero; i++) fscanf(f, "%s\n", j2.tablero_oponente[i]);

    fclose(f);
    printf("Partida cargada correctamente.\n");
}


}
