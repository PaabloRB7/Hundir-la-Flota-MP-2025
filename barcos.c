#include <stdio.h>
#include tablero.h
#define TAM 10

void barcos()´{
    int aux=0;
    menu_barcos()
    aux=seleccion_opcion(aux);
    switch_barcos(aux);
}

void menu_barcos(){
    printf("Seleccione el barco que desea colocar:\n");
    printf("1. Portaaviones\n");
    printf("2. Acorazado\n");
    printf("3. Crucero\n");
    printf("4. Destructor\n");
    printf("5. Fragata\n");
    printf("6. Submarino\n");
}

void switch_barcos(int aux){
    switch(aux){
        case 1:
            portaaviones();
            break;
        case 2:
            acorazado();
            break;
        case 3:
            crucero();
            break;
        case 4:
            destructor();
            break;
        case 5:
            fragata();
            break;
        case 6:
            submarino();
            break;
        default:
            printf("Opcion no valida\n");
            barcos();
            break;
    }
}

void colocar_barcos(){
    menu_colocaccion();
    aux=seleccion_opcion(aux);
    switch_colocacion(aux);
    
}

void menu_colocaccion(){
    printf("Seleccione la orientacion del barco:\n");
    printf("1. Horizontal\n");
    printf("2. Vertical\n");
    printf("3. Diagonal\n");
    printf("4. Regresar\n");
    printf("5. Salir\n");
}


void portaaviones(){
    int vida=6;
    char nom='P';
}

void acorazado(){
    int vida=5;
    char nom='A';
}

void crucero(){
    int vida=4;
    char nom='C';
}

void destructor(){
    int vida=3;
    char nom='D';
}

void fragata(){
    int vida=2;
    char nom='F';
}

void submarino(){
    int vida=1;
    char nom='S';
}