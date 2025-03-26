#include <stdio.h>
#include "Tablero.h"
#include "barcos.h"

#define TAM 10

int main() {
    char flota_jug1[TAM][TAM];
    char oponente_jug1[TAM][TAM];
    char flota_jug2[TAM][TAM];
    char oponente_jug2[TAM][TAM];

    //inicializar los tableros vacíos
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            flota_jug1[i][j] = ' ';
            oponente_jug1[i][j] = ' ';
            flota_jug2[i][j] = ' ';
            oponente_jug2[i][j] = ' ';
        }
    }

    //tablero Jugador 1
    imprimirTableros(flota_jug1, oponente_jug1);

    //tablero Jugador 2
    imprimirTableros(flota_jug2, oponente_jug2);

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

int comprobar_casillas(char tablero[][TAM],int ejey,int ejex){
    if (tablero[ejey-1][ejex-1]=='X' || tablero[ejey-1][ejex]=='X' || tablero[ejey-1][ejex+1]=='X' || tablero[ejey][ejex-1]=='X' || tablero[ejey][ejex]=='X' || tablero[ejey][ejex+1]=='X' || tablero[ejey+1][ejex-1]=='X' || tablero[ejey+1][ejex]=='X' || tablero[ejey+1][ejex+1]=='X') {
        return 1;       // si existe un barco en las casillas alrededores devuelve 1
    }
    return 0;
}

void colocar_barcos(char tablero[][TAM],char barco){

    int i,j,ejex,ejey,op,comp;
    printf("Indica la posicion inicial del barco: [Eje Y][Eje X]");
    scanf("%i %i",&ejey,&ejex);

    switch (barco) {
        case 'S':
            comp = comprobar_casillas(tablero,ejey,ejex);
            if (comp == 1) {
                printf("No es posible colocar el barco en esa posicion\n");
                colocar_barcos(tablero,barco);
            }
            tablero[ejey][ejex]='X';
        break;
        case'F':
            op = menu_colocaccion();
            switch (op) {
                case 1:
                    for (i=0;i<2;i++){
                        comp = comprobar_casillas(tablero,ejey,ejex+i);
                        if (comp == 1) {
                            printf("No es posible colocar el barco en esa posicion\n");
                            colocar_barcos(tablero,barco);
                        }
                        tablero[ejey][ejex+i]='X';
                    }
                break;
                case 2:
                    for (i=0;i<2;i++){
                        comp = comprobar_casillas(tablero,ejey+i,ejex);
                        if (comp == 1) {
                            printf("No es posible colocar el barco en esa posicion\n");
                            colocar_barcos(tablero,barco);
                        }
                        tablero[ejey+i][ejex]='X';
                    }
                break;
                case 3:
                    for (i=0;i<2;i++){
                        comp = comprobar_casillas(tablero,ejey+i,ejex+i);
                        if (comp == 1) {
                            printf("No es posible colocar el barco en esa posicion\n");
                            colocar_barcos(tablero,barco);
                        }
                        tablero[ejey+i][ejex+i]='X';
                    }
                break;
                default:
                    printf("Opcion no valida\n");
                break;
            }
        break;
    }


}

