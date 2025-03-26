#include <stdio.h>
#include "Tablero.h"
#include "barcos.h"

#define TAM 10

int main() {
    char flota_jug1[TAM][TAM];
    char oponente_jug1[TAM][TAM];
    char flota_jug2[TAM][TAM];
    char oponente_jug2[TAM][TAM];

    barco test[5];
    inicializar_barcos(test);
    test.tipo = 'F';

    //inicializar los tableros vacíos
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            flota_jug1[i][j] = ' ';
            oponente_jug1[i][j] = ' ';
            flota_jug2[i][j] = ' ';
            oponente_jug2[i][j] = ' ';
        }
    }

    colocar_barcos(flota_jug1,test.tipo);

    //tablero Jugador 1
    imprimirTableros(flota_jug1, oponente_jug1);

    //tablero Jugador 2
    imprimirTableros(flota_jug2, oponente_jug2);

}

void inicializar_barcos(barco test[]){
    test[0].nombre = "Submarino";
    test[0].longitud = 1;
    test[0].tipo = 'S';
    test[0].eje_y = 0;
    test[0].eje_x = 0;
    test[0].orientacion = '\0';

    test[1].nombre = "Fragata";
    test[1].longitud = 2;
    test[1].tipo = 'F';
    test[1].eje_y = 0;
    test[1].eje_x = 0;
    test[1].orientacion = '\0';

    test[2].nombre = "Crucero";
    test[2].longitud = 3;
    test[2].tipo = 'C';
    test[2].eje_y = 0;
    test[2].eje_x = 0;
    test[2].orientacion = '\0';

    test[3].nombre = "Acorazado";
    test[3].longitud = 4;
    test[3].tipo = 'A';
    test[3].eje_y = 0;
    test[3].eje_x = 0;
    test[3].orientacion = '\0';

    test[4].nombre = "Portaaviones";
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

int comprobar_casillas(char tablero[][TAM],int ejey,int ejex){
    if (tablero[ejey-1][ejex-1]=='X' || tablero[ejey-1][ejex]=='X' || tablero[ejey-1][ejex+1]=='X' || tablero[ejey][ejex-1]=='X' || tablero[ejey][ejex]=='X' || tablero[ejey][ejex+1]=='X' || tablero[ejey+1][ejex-1]=='X' || tablero[ejey+1][ejex]=='X' || tablero[ejey+1][ejex+1]=='X') {
        return 1;       // si existe un barco en las casillas alrededores devuelve 1
    }
    return 0;
}

void colocar_barcos(char tablero[][TAM], barco test[]){

    int i,comp;
    
    
    for(i=0;i<5;i++){
        printf("Indica la posicion inicial del barco %i,%s: [Eje Y][Eje X]\n",i,test->nombre[i]);
        scanf("%i %i",&test->eje_y[i],&test->eje_x[i]);
        printf("Indica la orientacion del barco %i,%s:\n",i,test->nombre[i]);
        do
        {
            scanf("%c",&test->orientacion[i]);
        } while (test->orientacion[i]!='H' || test->orientacion[i]!='V' || test->orientacion[i]!='D');
         
        direccionar_barcos(test,i,tablero);
    }
}

void direccionar_barcos(barco test[], int num_barco, char tablero[][TAM]){
    switch (test->orientacion[num_barco]) {
        case 'H':
            colocar_horizontal(test,num_barco,tablero);
        break;
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

    }
}


for (i=0;i<2;i++){
    comp = comprobar_casillas(tablero,ejey,ejex+i);
    if (comp == 1) {
        printf("No es posible colocar el barco en esa posicion\n");
        colocar_barcos(tablero);
    }
    tablero[ejey][ejex+i]='X';
}

void colocar_horizontal(barcos test[],int num_barco,char tablero[][TAM]){
    int i,comp;
    for (i=0;i<longitud;i++){
        comp = comprobar_casillas(tablero,test.ejey[num_barco],test.ejex[num_barco]+i);
        if (comp == 1) {
            printf("No es posible colocar el barco en esa posicion\n");
            colocar_barcos(tablero);
        }
        tablero[test.ejey[num_barco]][test.ejex[num_barco]+i]='X';
    }
}