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
    for(i = 0;i <= N || hundido = 0;i++)          //Se comprueba si el barco está hundido tras el impacto
       for(j = 0;j <= N || hundido = 0;j++)
          if(barco == tablero[i][j])
            hundido = 0;
    if(hundido == 1){
        tocado = 2;
        tablero[fila][columna] = 'H';
        tablero_v[fila][columna] = 'H';
        //FALTA: Bucle que convierta los tocados adyacentes en hundidos
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

int tocado_o_hundido(char tablero, int fila, int columna, char barco){ //INCOMPLETO
int i, j, hundido = 1;
for(i = fila - 1;i <= fila + 1;i++)
    for(j = columna -1;j <= columna + 1;j++)
        if(i != fila || j != columna)
            if(barco == )


}

