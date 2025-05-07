#include <stdio.h>
#include "tablero.h"
#include "barcos.h"
#include <string.h>


#define TAM 10
#define NUM_BARCOS 3

void inicializar_barcos(barco test[]){ //barcos de ejemplo
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
    /*

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
    */
}

//void barcos_principal(){
//    int aux=0,a2;
//    menu_barcos();
//    aux=seleccion_opcion(a2);
//    switch_barcos(aux);
//}


void menu_barcos(){
    printf("Seleccione el barco que desea colocar:\n");
    printf("1. Portaaviones\n");
    printf("2. Acorazado\n");
    printf("3. Crucero\n");
    printf("4. Destructor\n");
    printf("5. Fragata\n");
    printf("6. Submarino\n");
}


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


int comprobar_casillas(char tablero[][TAM],int ejey,int ejex, barco barco[], int num_barco){
    switch (barco[num_barco].orientacion) {
        case 'H':
            if (tablero[ejey-1][ejex-1]=='X' || tablero[ejey-1][ejex]=='X' || tablero[ejey-1][ejex+1]=='X' || tablero[ejey][ejex]=='X' || tablero[ejey][ejex+1]=='X' || tablero[ejey+1][ejex-1]=='X' || tablero[ejey+1][ejex]=='X' || tablero[ejey+1][ejex+1]=='X') {
                return 1;       // si existe un barco en las casillas alrededores devuelve 1
            }
            break;
        case 'V':
            if (tablero[ejey-1][ejex-1]=='X' || tablero[ejey-1][ejex+1]=='X' || tablero[ejey][ejex-1]=='X' || tablero[ejey][ejex]=='X' || tablero[ejey][ejex+1]=='X' || tablero[ejey+1][ejex-1]=='X' || tablero[ejey+1][ejex]=='X') {
                return 1;       // si existe un barco en las casillas alrededores devuelve 1
            }
            break;
        case 'D':
            if (tablero[ejey-1][ejex-1]=='X' || tablero[ejey-1][ejex]=='X' || tablero[ejey - 1][ejex + 1]=='X' || tablero[ejey-1][ejex+1]=='X' || tablero[ejey][ejex]=='X' || tablero[ejey][ejex+1]=='X' || tablero[ejey+1][ejex]=='X') {
                return 1;       // si existe un barco en las casillas alrededores devuelve 1
            }
        break;
        case'I':
            if (tablero[ejey-1][ejex-1]=='X' || tablero[ejey-1][ejex]=='X' || tablero[ejey - 1][ejex + 1]=='X' || tablero[ejey-1][ejex+1]=='X' || tablero[ejey][ejex]=='X' || tablero[ejey][ejex+1]=='X' || tablero[ejey+1][ejex]=='X') {
                return 1;       // si existe un barco en las casillas alrededores devuelve 1
            }
        break;

    }

    return 0;
}
/*
void colocar_barcos(char tablero[][TAM], barco test[]){

    int i=0;
    
    
    for(i=0;i<NUM_BARCOS;i++){
        printf("Indica la posicion inicial del barco %i, %s (Longitud: %i) [Eje Y][Eje X]\n",i+1,test[i].nombre,test[i].longitud);
        scanf("%i%i",&test[i].eje_y,&test[i].eje_x);

        if (test[i].longitud == 1) {
            tablero[test[i].eje_y][test[i].eje_x]='X';
            imprimirTablero(tablero);
        }
        else {
            printf("Indica la orientacion del barco %i,%s:\n[H: Horizontal, V:Vertical, D: Diagonal derecha, I: Diagonal izquierda]  ",i+1,test[i].nombre);
            do
            {
                scanf("%c",&test[i].orientacion);
            } while (test[i].orientacion !='H' && test[i].orientacion !='V' && test[i].orientacion !='D' && test[i].orientacion !='I');

            direccionar_barcos(test,i,tablero);
        }
    }
}
*/
void colocar_barcos(char tablero[][TAM], barco test[]) {
    for (int i = 0; i < NUM_BARCOS; i++) {
        int valido = 0;
        while (!valido) {
            printf("Indica la posicion inicial del barco %i, %s (Longitud: %i) [Eje Y][Eje X]\n", i + 1, test[i].nombre, test[i].longitud);
            scanf("%i %i", &test[i].eje_y, &test[i].eje_x);

            if (test[i].longitud == 1) {
                if (comprobar_casillas(tablero, test[i].eje_y, test[i].eje_x, test, i) == 0) {
                    tablero[test[i].eje_y][test[i].eje_x] = 'X';
                    imprimirTablero(tablero);
                    valido = 1;
                } else {
                    printf("No es posible colocar el barco en esa posicion\n");
                }
            } else {
                printf("Indica la orientacion del barco %i, %s:\n[H: Horizontal, V: Vertical, D: Diagonal derecha, I: Diagonal izquierda]  ", i + 1, test[i].nombre);
                do {
                    scanf(" %c", &test[i].orientacion);
                } while (test[i].orientacion != 'H' && test[i].orientacion != 'V' && test[i].orientacion != 'D' && test[i].orientacion != 'I');

                if (comprobar_casillas(tablero, test[i].eje_y, test[i].eje_x, test, i) == 0) {
                    direccionar_barcos(test, i, tablero);
                    valido = 1;
                } else {
                    printf("No es posible colocar el barco en esa posicion\n");
                }
            }
        }
    }
}

void direccionar_barcos(barco test[], int num_barco, char tablero[][TAM]){
    switch (test[num_barco].orientacion) {
        case 'H':
            if (tablero[test[num_barco].eje_y][test[num_barco].eje_x-1] =='X'){
                printf("No es posible colocar el barco en esa posicion\n");
                inicializar_espacio(tablero);
                imprimirTablero(tablero);
                colocar_barcos(tablero,test);
            }
            colocar_horizontal(test,num_barco,tablero);
        break;
        case 'V':
            if (tablero[test[num_barco].eje_y-1][test[num_barco].eje_x] =='X'){
                printf("No es posible colocar el barco en esa posicion\n");
                inicializar_espacio(tablero);
                imprimirTablero(tablero);
                colocar_barcos(tablero,test);
            }
            colocar_vertical(test,num_barco,tablero);
        break;
        case 'D':
            if (tablero[test[num_barco].eje_y+1][test[num_barco].eje_x-1] =='X'){
                printf("No es posible colocar el barco en esa posicion\n");
                inicializar_espacio(tablero);
                imprimirTablero(tablero);
                colocar_barcos(tablero,test);
            }
            colocar_diagonal_der(test,num_barco,tablero);
        break;
        case 'I':
            if (tablero[test[num_barco].eje_y+1][test[num_barco].eje_x+1] =='X'){
                printf("No es posible colocar el barco en esa posicion\n");
                inicializar_espacio(tablero);
                imprimirTablero(tablero);
                colocar_barcos(tablero,test);
            }
            colocar_diagonal_izq(test,num_barco,tablero);
        break;
    }
}



void colocar_horizontal(barco test[],int num_barco,char tablero[][TAM]){
    int i,comp;
    for (i=0;i<test[num_barco].longitud;i++){
        comp = comprobar_casillas(tablero,test[num_barco].eje_y,test[num_barco].eje_x+i,test,num_barco);
        if (comp == 1) {
            printf("No es posible colocar el barco en esa posicion\n");
            inicializar_espacio(tablero);
            imprimirTablero(tablero);
            colocar_barcos(tablero,test);
            break;
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
            inicializar_espacio(tablero);
            imprimirTablero(tablero);
            colocar_barcos(tablero, test);
            break;
        }
        tablero[test[num_barco].eje_y + i][test[num_barco].eje_x] = 'X';
    }
    imprimirTablero(tablero);

}

void colocar_diagonal_der(barco test[],int num_barco,char tablero[][TAM]) {
    int i,comp;
    for (i=0;i<test[num_barco].longitud;i++){
        comp = comprobar_casillas(tablero,test[num_barco].eje_y-i,test[num_barco].eje_x+i,test,num_barco);
        if (comp == 1) {
            printf("No es posible colocar el barco en esa posicion\n");
            inicializar_espacio(tablero);
            imprimirTablero(tablero);
            colocar_barcos(tablero,test);
            break;
        }
        tablero[test[num_barco].eje_y-i][test[num_barco].eje_x+i]='X';
    }
    imprimirTablero(tablero);

}

void colocar_diagonal_izq(barco test[],int num_barco,char tablero[][TAM]) {
    int i, comp;
    for (i = 0; i < test[num_barco].longitud; i++) {
        comp = comprobar_casillas(tablero, test[num_barco].eje_y - i, test[num_barco].eje_x - i, test, num_barco);
        if (comp == 1) {
            printf("No es posible colocar el barco en esa posicion\n");
            inicializar_espacio(tablero);
            imprimirTablero(tablero);
            colocar_barcos(tablero, test);
            break;
        }
        tablero[test[num_barco].eje_y - i][test[num_barco].eje_x - i] = 'X';
    }
    imprimirTablero(tablero);
}