#include <stdio.h>
#include <string.h>
#include "menu_principal.h"

//Estructuras
typedef struct{
char nombre[40];
char disparo[12];
}jugador;

//Prototipos
void config();
void introducir_datos(); //Es funcional pero tiene mejoras planteadas
void mostrar(); //Pendiente
void borrar(); //Dudas sobre restablecer o borrar
void guardar(); //Pendiente
void cargar(); //Pendiente

int main(){
config();

}



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
    int n, num_tiposbarcos, tiposbarcos[10], primerturno, bucle, respuesta;
    //int vacio = 1; Esta variable es para una futura mejora de la introduccion de datos
    jugador j1, j2;


/*    if ((f = fopen("config.txt", "r")) != NULL) {
        if (fgetc(f) != EOF) {
            vacio = 0;

        }
        fclose(f);
    }

    if (vacio = 1) {
        if ((f = fopen("config.txt", "w")) != NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }
        else {
            fprintf(f, "Jugador1\0 manual\0 Jugador2\0 automatico\0 \n 9 4 1 2 1 2 \n 1")
        }
        fclose(f);

        printf("Archivo config.txt estaba vacío. Se creó una configuracion predeterminada.\n");
*/

    if ((f = fopen("config.txt", "w")) != NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }
    else {
        //Introducir valores (tengo pensado pasarlo a una funcion a parte para mayor claridad visual)
        printf("\nIntroduzca el nombre del jugador 1: ");
        fflush(stdin);
        fgets(j1.nombre, sizeof(j1.nombre), stdin);
        bucle = 1;
        while(bucle = 1){
            printf("\nEl tipo de disparo del jugador 1 es manual? (s/n): ");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's' || respuesta == 'n'){
                bucle = 0;
                if(respuesta == 's')
                    strcpy(j1.disparo, "manual");
                else
                    strcpy(j1.disparo, "automatico");
            }
            else
                printf("\nOpcion no valida\n");
        }
        printf("\nIntroduzca el nombre del jugador 2: ");
        fflush(stdin);
        fgets(j2.nombre, sizeof(j2.nombre), stdin);
        bucle = 1;
        while(bucle = 1){
            printf("\nEl tipo de disparo del jugador 2 es manual? (s/n): ");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's' || respuesta == 'n'){
                bucle = 0;
                if(respuesta == 's')
                    strcpy(j2.disparo, "manual");
                else
                    strcpy(j1.disparo, "automatico");
            }
            else
                printf("\nOpcion no valida\n");
        }
        //Falta imolementar tipos de barocs y cuantos barcos de cada se podra usar
        printf("\nIntroduzca el numero del jugador que comenzara la partida (1/2): ");
        scanf("%d", &primerturno);

        //Guardar en fichero
        fprintf("%s %s %s %s \n", j1.nombre, j1.disparo, j2.nombre, j2.disparo);
        //Falta implementar tipos de barcos y cuantos barcos de cada se podra usar
        fprintf("%d", primerturno);

    }

fclose(f);
printf("\n\nConfiguracion guardada");
}

void mostrar(){
//Pendiente
}

void borrar(){
//Dudas sobre restablecer o borrar
}

void guardar(){
//Pendiente por dudas
}

void cargar(){
//Pendiente por dudas
}
