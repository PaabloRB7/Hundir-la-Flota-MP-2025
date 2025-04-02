#include <stdio.h>
#include "tablero.h"
#include "barcos.h"
#include <string.h>


#define TAM 10

void inicializar_barcos(barco test[]){
    strcpy(test[0].nombre, "Submarino");
    test[0].longitud = 1;
    test[0].tipo = 'S';
    test[0].eje_y = 0;
    test[0].eje_x = 0;
    test[0].orientacion = '\0';

    strcpy(test[1].nombre, "Fragata");
    test[1].longitud = 2;
    test[1].tipo = 'F';
    test[1].eje_y = 0;
    test[1].eje_x = 0;
    test[1].orientacion = '\0';

    strcpy(test[2].nombre, "Crucero");
    test[2].longitud = 3;
    test[2].tipo = 'C';
    test[2].eje_y = 0;
    test[2].eje_x = 0;
    test[2].orientacion = '\0';

    strcpy(test[3].nombre,"Acorazado");
    test[3].longitud = 4;
    test[3].tipo = 'A';
    test[3].eje_y = 0;
    test[3].eje_x = 0;
    test[3].orientacion = '\0';

    strcpy(test[4].nombre,"Portaaviones");
    test[4].longitud = 5;
    test[4].tipo = 'P';
    test[4].eje_y = 0;
    test[4].eje_x = 0;
    test[4].orientacion = '\0';
}

//void barcos_principal(){
//    int aux=0,a2;
//    menu_barcos();
//    aux=seleccion_opcion(a2);
//    switch_barcos(aux);
//}

int seleccion_opcion(){
    int seleccion;
    scanf("%i",&seleccion);
    return(seleccion);
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

/*

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
            barcos_principal();
            break;
    }
}

*/

int menu_colocaccion(){
    int op;
    printf("Seleccione la orientacion del barco:\n");
    printf("1. Horizontal\n");
    printf("2. Vertical\n");
    printf("3. Diagonal derecha\n");
    printf("4. Diagonal izquierda\n");
    printf("5. Salir\n");
    scanf("%i",&op);
    return op;
}

/*
void switch_colocacion(){

}

void portaaviones(){
    int vida=6;
    char nom='P';
    menu_colocaccion();

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

*/

int comprobar_casillas(char tablero[][TAM],int ejey,int ejex, barco barco[], int num_barco){

    switch (barco[num_barco].orientacion) {
        case 'H':
            if (tablero[ejey-1][ejex-1]=='X' || tablero[ejey-1][ejex]=='X' || tablero[ejey-1][ejex+1]=='X' || tablero[ejey][ejex]=='X' || tablero[ejey][ejex+1]=='X' || tablero[ejey+1][ejex-1]=='X' || tablero[ejey+1][ejex]=='X' || tablero[ejey+1][ejex+1]=='X') {
                return 1;       // si existe un barco en las casillas alrededores devuelve 1
            }
        //case 'V':
        //    if (tablero[])
    }

    return 0;
}

void colocar_barcos(char tablero[][TAM], barco test[]){

    int i;
    
    
    for(i=0;i<5;i++){
        printf("Indica la posicion inicial del barco %i, %s (Longitud: %i) [Eje Y][Eje X]\n",i+1,test[i].nombre,test[i].longitud);
        scanf("%i%i",&test[i].eje_y,&test[i].eje_x);

        if (test[i].longitud == 1) {
            tablero[test[i].eje_y][test[i].eje_x]='X';
            imprimirTablero(tablero);
        }
        else {
            printf("Indica la orientacion del barco %i,%s:\n",i,test[i].nombre);
            do
            {
                scanf("%c",&test[i].orientacion);
            } while (test[i].orientacion !='H' && test[i].orientacion !='V' && test[i].orientacion !='D');

            direccionar_barcos(test,i,tablero);
        }
    }
}

void direccionar_barcos(barco test[], int num_barco, char tablero[][TAM]){
    switch (test[num_barco].orientacion) {
        case 'H':
            if (tablero[test[num_barco].eje_y][test[num_barco].eje_x-1] =='X'){
                printf("No es posible colocar el barco en esa posicion\n");
                inicializar_tablero(tablero);
                imprimirTablero(tablero);
                colocar_barcos(tablero,test);
            }
            colocar_horizontal(test,num_barco,tablero);
        break;
        case 'V':
            if (tablero[test[num_barco].eje_y-1][test[num_barco].eje_x] =='X'){
                printf("No es posible colocar el barco en esa posicion\n");
                inicializar_tablero(tablero);
                imprimirTablero(tablero);
                colocar_barcos(tablero,test);
            }
        colocar_vertical(test,num_barco,tablero);

        /*
        case'V':
            op = menu_colocaccion();
            
            switch (op) {
                case 1:
                    
                    for (i=0;i<2;i++){
                        comp = comprobar_casillas(tablero,ejey,ejex+i);
                        if (comp == 1) {
                            printf("No es posible colocar el barco en esa posicion\n");
                            colocar_barcos(tablero);
                        }
                        tablero[ejey][ejex+i]='X';
                    }
                break;
                case 2:
                    for (i=0;i<2;i++){
                        comp = comprobar_casillas(tablero,ejey+i,ejex);
                        if (comp == 1) {
                            printf("No es posible colocar el barco en esa posicion\n");
                            colocar_barcos(tablero);
                        }
                        tablero[ejey+i][ejex]='X';
                    }
                break;
                case 3:
                    for (i=0;i<2;i++){
                        comp = comprobar_casillas(tablero,ejey+i,ejex+i);
                        if (comp == 1) {
                            printf("No es posible colocar el barco en esa posicion\n");
                            colocar_barcos(tablero);
                        }
                        tablero[ejey+i][ejex+i]='X';
                    }
                break;
                default:
                    printf("Opcion no valida\n");
                break;
            }
        break;
        case'D'

*/

    }
}

/*

for (i=0;i<2;i++){
    comp = comprobar_casillas(tablero,ejey,ejex+i);
    if (comp == 1) {
        printf("No es posible colocar el barco en esa posicion\n");
        colocar_barcos(tablero);
    }
    tablero[ejey][ejex+i]='X';
}

*/


void colocar_horizontal(barco test[],int num_barco,char tablero[][TAM]){
    int i,comp;
    for (i=0;i<test[num_barco].longitud;i++){
        comp = comprobar_casillas(tablero,test[num_barco].eje_y,test[num_barco].eje_x+i,test,num_barco);
        if (comp == 1) {
            printf("No es posible colocar el barco en esa posicion\n");
            inicializar_tablero(tablero);
            imprimirTablero(tablero);
            colocar_barcos(tablero,test);
        }
        tablero[test[num_barco].eje_y][test[num_barco].eje_x+i]='X';
    }
    imprimirTablero(tablero);
}

void colocar_vertical(barco test[],int num_barco,char tablero[][TAM]) {
    int i, comp;
    for (i = 0; i < test[num_barco].longitud; i++) {
        comp = comprobar_casillas(tablero, test[num_barco].eje_y + i, test[num_barco].eje_x, test, num_barco);
        if (comp == 1) {
            printf("No es posible colocar el barco en esa posicion\n");
            inicializar_tablero(tablero);
            imprimirTablero(tablero);
            colocar_barcos(tablero, test);
        }
        tablero[test[num_barco].eje_y + i][test[num_barco].eje_x] = 'X';
    }

}
