#include <stdio.h>
#define N 9

//Prototipos
int disparo_manual(char tablero[][N], char tablero_v[][N]);
int disparo_automatico(char tablero[][N], char tablero_v[][N]);
int disparo(int fila, int columna, char tablero[][N],char tablero_v[][N]);

//Main
int main(){





}


//Funciones
int disparo(int fila, int columna, char tablero[][N],char tablero_v[][N]){
int tocado = 0, i, j, hundido = 1;
char barco;
if(tablero[fila][columna] != '*' && tablero[fila][columna] != 'T' && tablero[fila][columna] != 'H'){
    tocado = 1;
    barco = tablero[fila][columna];
    tablero[fila][columna] = 'T';
    for(i = 0;i <= N || hundido = 0;i++)          //Falta implementar las nuevas funciones de deteccion de hundidos
       for(j = 0;j <= N || hundido = 0;j++)
          if(barco == tablero[i][j])
            hundido = 0;
    if(hundido == 1){
        tocado = 2;
        tablero[fila][columna] = 'H';
        tablero_v[fila][columna] = 'H';
        //Falta implementar las nuevas funciones de marcado de barcos hundidos
    }
    else
        tablero_v[fila][columna] = 'T';
}
else
    tablero_v[fila][columna] = '*';

return tocado;
}

int disparo_manual(char tablero[][N], char tablero_v[][N]){
int fila, column, resultado;

printf("\nIntroduce las coordenadas del disparo (separando la fila y columna por un espacio): ");
scanf("%d %d", &fila, &column);
resultado = disparo(fila, columna, tablero, tablero_v);

switch(resultado)
 case 1:
    printf("\nTocado!\n\n");
    break;
 case 2:
    printf("\nHUNDIDO!!!\n\n");
    break;
 default:
    printf("\nAgua...\n\n");


return resultado;
}

int disparo_automatico(){
}

int tocado_o_hundido(char tablero[][N], int fila, int columna, char barco){ //INCOMPLETO
int i, j, hundido = 1, bucle = 0, nfila, ncolumna;
fila = nfila;
columna = ncolumna;

while(bucle = 1){
bucle = 0;
fila = nfila;
columna = ncolumna;
for(i = fila - 1;i <= fila + 1;i++)
    for(j = columna -1;j <= columna + 1;j++)
        if(i != fila || j != columna){
            if(tablero[i][j] == 'T'){
                    nfila = i;
                    ncolumna = j;
                    bucle = 1;
            }
            if(barco == tablero[i][j])
                hundido = 0;
        }
}
return hundido;
}

void hundido(char tablero_v[][N], char tablero[][N], int fila, int columna, char barco){
int i, j, hundido = 1, bucle = 0, nfila, ncolumna;
fila = nfila;
columna = ncolumna;

while(bucle = 1){
bucle = 0;
fila = nfila;
columna = ncolumna;
tablero[fila][columna] = 'H';
tablero_v[fila][columna] = 'H';
for(i = fila - 1;i <= fila + 1;i++)
    for(j = columna -1;j <= columna + 1;j++)
        if(i != fila || j != columna){
            if(tablero[i][j] == 'T'){
                    nfila = i;
                    ncolumna = j;
                    bucle = 1;
            }
        }
}

}

void buscar_proa(int *fila, int *columna, char barco, char tablero[][N]){
int i, j, nfila, ncolumna, bucle = 0;
nfila = fila;
ncolumna = columna;

while(bucle = 1){
bucle = 0;
fila = nfila;
columna = ncolumna;
for(i = fila - 1;i <= fila + 1;i++)
    for(j = columna -1;j <= columna + 1;j++)
        if(i != fila || j != columna)
            if(barco == tablero[i][j] || tablero[i][j] == 'T')
                if(i > fila || j > columna){
                    nfila = i;
                    ncolumna = j;
                    bucle = 1;
                }
}

}
