#ifndef barcos_h
#define barcos_h

#define TAM 10

typedef struct {
    char nombre[20];
    int longitud;
    char tipo;
    int eje_y;
    int eje_x;
    char orientacion;
}barco;

// Cabecera: Función principal para gestionar los barcos.
// Precondición: Ninguna.
// Postcondición: Se ejecutan las operaciones relacionadas con los barcos.
void barcos_principal();

// Cabecera: Permite al usuario seleccionar una opción del menú de barcos.
// Precondición: El usuario debe ingresar un número válido.
// Postcondición: Devuelve la opción seleccionada.
int seleccion_opcion();

// Cabecera: Muestra el menú de opciones para gestionar los barcos.
// Precondición: Ninguna.
// Postcondición: Se imprime el menú de opciones.
void menu_barcos();

// Cabecera: Ejecuta la acción correspondiente a la opción seleccionada en el menú de barcos.
// Precondición: La opción seleccionada debe ser válida.
// Postcondición: Se ejecuta la acción asociada a la opción.
void switch_barcos(int opcion);

// Cabecera: Permite al usuario seleccionar la orientación para colocar un barco.
// Precondición: Ninguna.
// Postcondición: Devuelve la orientación seleccionada.
int menu_colocaccion();

// Cabecera: Ejecuta la acción correspondiente a la orientación seleccionada para colocar un barco.
// Precondición: La orientación seleccionada debe ser válida.
// Postcondición: Se ejecuta la acción asociada a la orientación.
void switch_colocacion();

// Cabecera: Configura y coloca un portaaviones en el tablero.
// Precondición: El tablero debe estar inicializado.
// Postcondición: El portaaviones se coloca en el tablero.
void portaaviones();

// Cabecera: Configura y coloca un acorazado en el tablero.
// Precondición: El tablero debe estar inicializado.
// Postcondición: El acorazado se coloca en el tablero.
void acorazado();

// Cabecera: Configura y coloca un crucero en el tablero.
// Precondición: El tablero debe estar inicializado.
// Postcondición: El crucero se coloca en el tablero.
void crucero();

// Cabecera: Configura y coloca un destructor en el tablero.
// Precondición: El tablero debe estar inicializado.
// Postcondición: El destructor se coloca en el tablero.
void destructor();

// Cabecera: Configura y coloca una fragata en el tablero.
// Precondición: El tablero debe estar inicializado.
// Postcondición: La fragata se coloca en el tablero.
void fragata();

// Cabecera: Configura y coloca un submarino en el tablero.
// Precondición: El tablero debe estar inicializado.
// Postcondición: El submarino se coloca en el tablero.
void submarino();

// Cabecera: Inicializa los datos de los barcos.
// Precondición: El arreglo de barcos debe estar declarado.
// Postcondición: Los datos de los barcos se inicializan correctamente.
void inicializar_barcos(barco test[]);

// Cabecera: Coloca los barcos en el tablero según su configuración.
// Precondición: El tablero y los datos de los barcos deben estar inicializados.
// Postcondición: Los barcos se colocan en el tablero.
void colocar_barcos(char tablero[][TAM], barco test[]);

// Cabecera: Direcciona un barco específico en el tablero según su orientación.
// Precondición: El tablero y los datos del barco deben estar inicializados.
// Postcondición: El barco se direcciona en el tablero.
void direccionar_barcos(barco test[], int num_barco, char tablero[][TAM]);

// Cabecera: Coloca un barco de forma horizontal en el tablero.
// Precondición: El tablero y los datos del barco deben estar inicializados.
// Postcondición: El barco se coloca horizontalmente en el tablero.
void colocar_horizontal(barco test[], int num_barco, char tablero[][TAM]);

// Cabecera: Coloca un barco de forma vertical en el tablero.
// Precondición: El tablero y los datos del barco deben estar inicializados.
// Postcondición: El barco se coloca verticalmente en el tablero.
void colocar_vertical(barco test[], int num_barco, char tablero[][TAM]);

// Cabecera: Coloca un barco de forma diagonal hacia la derecha en el tablero.
// Precondición: El tablero y los datos del barco deben estar inicializados.
// Postcondición: El barco se coloca diagonalmente hacia la derecha en el tablero.
void colocar_diagonal_der(barco test[], int num_barco, char tablero[][TAM]);

// Cabecera: Coloca un barco de forma diagonal hacia la izquierda en el tablero.
// Precondición: El tablero y los datos del barco deben estar inicializados.
// Postcondición: El barco se coloca diagonalmente hacia la izquierda en el tablero.
void colocar_diagonal_izq(barco test[], int num_barco, char tablero[][TAM]);

// Cabecera: Comprueba si las casillas alrededor de un barco están libres.
// Precondición: El tablero y los datos del barco deben estar inicializados.
// Postcondición: Devuelve 1 si las casillas están ocupadas, 0 en caso contrario.
int comprobar_casillas(char tablero[][TAM], int ejey, int ejex, barco barco[], int num_barco);
#endif


