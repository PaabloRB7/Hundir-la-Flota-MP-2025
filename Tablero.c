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
}

int main() {
    // tablero[eje y][eje x]
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



    return 0;
}
