#include <stdio.h>

//Estructuras
typedef struct{
char nombre[40];
char disparo[12];
}jugador;

//Prototipos
void config();
void introducir_datos();
void mostrar();
void borrar();
void guardar();
void cargar();
