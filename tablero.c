#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void imprimirTableros(char flota[][TAM], char oponente[][TAM]) {
    int i, j;

    printf("\nJugadorX:");
    printf("  FLOTA");
    printf("                     OPONENTE\n");

    //encabezados de columnas
    printf("           ");
    for (j = 0; j < TAM; j++) {
        printf("|%d", j);
    }
    printf("|   ");


    for (j = 0; j < TAM; j++) {
        printf("|%d", j);
    }
    printf("|\n");

    printf("         --");
    for (j = 0; j < TAM; j++) {
        printf("|-");
    }

    printf("| --");

    for (j = 0; j < TAM; j++) {
        printf("|-");
    }
    printf("|\n");

    // contenido de los tableros
    for (i = 0; i < TAM; i++) {
        printf("          %d|", i);
        for (j = 0; j < TAM; j++) {
            printf("%c|", flota[i][j]);
        }

        printf("  %d|", i);
        for (j = 0; j < TAM; j++) {
            printf("%c|", oponente[i][j]);
        }

        printf("   \n");  // separacion entre tableros

    }
    printf("   \n");

}
void imprimirTablero(char flota[][TAM]) {
    int i, j;


    //encabezados de columnas
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("|%d", j);
    }


    printf("|\n");

    printf(" --");
    for (j = 0; j < TAM; j++) {
        printf("|-");
    }

    printf("|\n");

    // contenido de los tableros
    for (i = 0; i < TAM; i++) {
        printf("  %d|", i);
        for (j = 0; j < TAM; j++) {
            printf("%c|", flota[i][j]);
        }


        printf("   \n");  // separacion entre tableros

    }
    printf("   \n");

}

void inicializar_agua(char tablero[][TAM]) {
    int i, j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tablero[i][j] = '*';
        }
    }
}

void inicializar_espacio(char tablero[][TAM]) {
    int i, j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tablero[i][j] = ' ';
        }
    }
}

