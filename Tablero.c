#include <stdio.h>

#define FILAS 10
#define COLUMNAS 10

void imprimirTableros(char flota[FILAS][COLUMNAS], char oponente[FILAS][COLUMNAS]) {
    int i, j;

    printf("\nJugadorX:");
    printf("  FLOTA");
    printf("                     OPONENTE\n");

    // Encabezados de columnas
    printf("           ");
    for (j = 0; j < COLUMNAS; j++) {
        printf("|%d", j);
    }
    printf("|   ");


    for (j = 0; j < COLUMNAS; j++) {
        printf("|%d", j);
    }
    printf("|\n");

    // Línea divisoria superior
    printf("         --");
    for (j = 0; j < COLUMNAS; j++) {
        printf("|-");
    }

    printf("| --");

    for (j = 0; j < COLUMNAS; j++) {
        printf("|-");
    }
    printf("|\n");

    // Contenido de los tableros, línea por línea
    for (i = 0; i < FILAS; i++) {
        printf("          %d|", i);
        for (j = 0; j < COLUMNAS; j++) {
            printf("%c|", flota[i][j]);
        }

        printf("  %d|", i);
        for (j = 0; j < COLUMNAS; j++) {
            printf("%c|", oponente[i][j]);
        }

        printf("   \n");  // Separación entre tableros

    }
}

int main() {
    char flota_jug1[FILAS][COLUMNAS];
    char oponente_jug1[FILAS][COLUMNAS];
    char flota_jug2[FILAS][COLUMNAS];
    char oponente_jug2[FILAS][COLUMNAS];

    // Inicializar los tableros vacíos
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            flota_jug1[i][j] = ' ';
            oponente_jug1[i][j] = ' ';
            flota_jug2[i][j] = ' ';
            oponente_jug2[i][j] = ' ';
        }
    }

    // Colocar algunas fichas en el tablero de flota del jugador 1
    flota_jug1[0][0] = 'a';
    flota_jug1[1][2] = 'X';
    flota_jug1[1][4] = 'X';
    flota_jug1[2][3] = 'X';
    flota_jug1[3][1] = 'X';
    flota_jug1[3][3] = 'X';
    flota_jug1[3][5] = 'X';
    flota_jug1[6][2] = 'X';
    flota_jug1[6][4] = 'X';
    flota_jug1[8][3] = 'X';

    // Colocar algunos disparos en el tablero de oponente del jugador 1
    oponente_jug1[4][4] = 'a';
    oponente_jug1[5][5] = '*';
    oponente_jug1[6][6] = '*';
    oponente_jug1[7][7] = 'r';
    oponente_jug1[8][8] = '*';
    oponente_jug1[9][9] = 'e';
    oponente_jug1[0][3] = 'H';
    oponente_jug1[0][4] = 'H';
    oponente_jug1[0][5] = 'H';

    // Lo mismo para el jugador 2 (puedes personalizarlo)
    flota_jug2[1][2] = 'X';
    flota_jug2[1][4] = 'X';
    flota_jug2[2][3] = 'X';
    flota_jug2[3][1] = 'X';
    flota_jug2[3][3] = 'X';
    flota_jug2[3][5] = 'X';
    flota_jug2[6][2] = 'X';
    flota_jug2[6][4] = 'X';
    flota_jug2[8][3] = 'X';

    oponente_jug2[0][0] = '*';
    oponente_jug2[1][1] = '*';
    oponente_jug2[2][2] = '*';
    oponente_jug2[3][3] = '*';
    oponente_jug2[4][4] = '*';
    oponente_jug2[5][5] = '*';
    oponente_jug2[6][6] = '*';
    oponente_jug2[7][7] = '*';
    oponente_jug2[8][8] = '*';
    oponente_jug2[9][9] = '*';
    oponente_jug2[1][3] = 'H';
    oponente_jug2[1][4] = 'H';
    oponente_jug2[1][5] = 'H';


    for(int i=0;i<3;i++){
        // Mostrar los tableros del Jugador 1
        imprimirTableros(flota_jug1, oponente_jug1);

        // Mostrar los tableros del Jugador 2
        imprimirTableros(flota_jug2, oponente_jug2);
        system("pause");
        oponente_jug2[0][0] = 'a';
        oponente_jug2[1][1] = 'a';
        oponente_jug2[3][2] = 'a';
        oponente_jug2[3][3] = 'a';
        oponente_jug2[5][4] = 'a';
        oponente_jug2[1][5] = 'a';
        oponente_jug2[0][6] = 'a';
        oponente_jug2[4][7] = 'a';
    
        system("cls");
    }

    return 0;
}
