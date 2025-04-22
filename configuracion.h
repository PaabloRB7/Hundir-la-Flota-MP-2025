#ifndef configuracion_h
#define configuracion_h

//Estructuras
typedef struct{
    char nombre[40];
    char disparo; //A: automatico, M: manual
    int disparos_realizados;
    int disparos_agua;
    int casillas_tocadas;    // n de casillas marcadas como 'T' tablero del oponente
    int casillas_hundidas;   // n de casillas marcadas como 'H' tablero del oponente
    int barcos_hundidos;
    int ganador;             //(se actualiza al final)

}jugador;

//Prototipos
void config();
void introducir_datos(); //Es funcional pero tiene mejoras planteadas
void mostrar(); //Pendiente
void borrar(); //Dudas sobre restablecer o borrar
void guardar(); //Pendiente
void cargar(); //Pendiente

#endif
