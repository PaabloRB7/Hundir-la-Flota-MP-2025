#include <stdio.h>
#define N 9

//Prototipos
int disparo_manual(int tablero[][N], int tablero_v[][N]); //Letra y num se corresponden a la dirección del disparo y tablero al tablero del jugador al que dispara
int disparo_automatico(int tablero[][N], int tablero_v[][N]);
int disparo(int letra, int num, char tablero[][N],char tablero_v[][N]);
int letra_num(char letra);

//Main
int main(){





}


//Funciones
int disparo(int letra, int num, char tablero[][N],char tablero_v[][N]){
int tocado = 0, i, j, hundido = 1;
char barco;
if(tablero[letra][num] != '*' && tablero[letra][num] != 'T' && tablero[letra][num] != 'H'){
    tocado = 1;
    barco = tablero[letra][num];
    tablero[letra][num] = 'T';
    for(i = 0;i <= N || hundido = 0;i++)          //Se comprueba si el barco está hundido tras el impacto
       for(j = 0;j <= N || hundido = 0;j++)
          if(barco == tablero[i][j])
            hundido = 0;
    if(hundido == 1){
        tocado = 2;
        tablero[letra][num] = 'H';
        tablero_v[letra][num] = 'H';
        //Bucle que convierta los tocados adyacentes en hundidos
    }
    else
        tablero_v[letra][num] = 'T';
}
else
    tablero_v[letra][numero] = '*';

return tocado;
}

int disparo_manual(int tablero[][N], int tablero_v[][N]){
int numletra, num, resultado;
char letra;

printf("\nIntroduce las coordenadas del disparo (separando la letra y el número por un espacio): ");
scanf("%c %d", &letra, &num);
resultado = disparo(letra_num(letra), num, tablero, tablero_v);

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

int letra_num(char letra){
int num, i;
char letrasm[9] = "ABCDEFGHI";
char letras[9] = "abcdefghi";

for(i = 0;i <= 9;i++)
    if(letrasm[i] == letra || letras[i] == letra)
       num = i;

return num;
}

int disparo_automatico(){
}
