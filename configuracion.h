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

// Cabecera: Configura los parámetros iniciales del juego.
// Precondición: Ninguna.
// Postcondición: Se establecen los parámetros iniciales del juego.
void config();

// Cabecera: Permite introducir datos en el sistema.
// Precondición: Ninguna.
// Postcondición: Los datos introducidos se almacenan correctamente.
void introducir_datos();

// Cabecera: Muestra los datos almacenados en el sistema.
// Precondición: Deben existir datos almacenados previamente.
// Postcondición: Se imprimen los datos en pantalla.
void mostrar();

// Cabecera: Borra datos almacenados en el sistema.
// Precondición: Deben existir datos almacenados previamente.
// Postcondición: Los datos seleccionados se eliminan o restablecen.
void borrar();

// Cabecera: Guarda los datos actuales en un archivo.
// Precondición: Deben existir datos para guardar.
// Postcondición: Los datos se almacenan en un archivo correctamente.
void guardar();

// Cabecera: Carga datos desde un archivo al sistema.
// Precondición: El archivo debe existir y contener datos válidos.
// Postcondición: Los datos se cargan en el sistema correctamente.
void cargar();
#endif
