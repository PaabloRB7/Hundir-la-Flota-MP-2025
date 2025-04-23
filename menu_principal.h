#ifndef MENU_PRINCIPAL
#define MENU_PRINCIPAL

#include "configuracion.h"
#include "barcos.h"

#define TAM 10

// Cabecera: Muestra el menú de introducción al juego.
// Precondición: Ninguna.
// Postcondición: Se imprime el menú de introducción.
void menu_intro();

// Cabecera: Permite al usuario seleccionar una opción del menú.
// Precondición: El usuario debe ingresar un número válido.
// Postcondición: Devuelve la opción seleccionada.
int seleccion_opcion();

// Cabecera: Ejecuta la acción correspondiente a la opción seleccionada en el menú principal.
// Precondición: La opción seleccionada debe ser válida.
// Postcondición: Se ejecuta la acción asociada a la opción.
void switch_menu(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Configura los parámetros iniciales del juego.
// Precondición: Los jugadores y tableros deben estar inicializados.
// Postcondición: Se configuran los parámetros del juego.
void configuracion(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Ejecuta la acción correspondiente a la opción seleccionada en el menú de configuración.
// Precondición: La opción seleccionada debe ser válida.
// Postcondición: Se ejecuta la acción asociada a la opción.
void switch_configuracion(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Muestra el menú de configuración del juego.
// Precondición: Ninguna.
// Postcondición: Se imprime el menú de configuración.
void menu_configuracion();

// Cabecera: Permite introducir datos en el sistema.
// Precondición: Ninguna.
// Postcondición: Los datos introducidos se almacenan.
void introducir_datos(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Muestra los datos almacenados en el sistema.
// Precondición: Deben existir datos almacenados.
// Postcondición: Se imprimen los datos en pantalla.
void mostrar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Borra datos almacenados en el sistema.
// Precondición: Deben existir datos almacenados.
// Postcondición: Los datos seleccionados se eliminan.
void borrar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Guarda los datos actuales en un archivo.
// Precondición: Deben existir datos para guardar.
// Postcondición: Los datos se almacenan en un archivo.
void guardar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Carga datos desde un archivo al sistema.
// Precondición: El archivo debe existir y ser válido.
// Postcondición: Los datos se cargan en el sistema.
void cargar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Inicia el flujo principal del juego.
// Precondición: Los jugadores y tableros deben estar configurados.
// Postcondición: Se ejecuta la lógica del juego.
void jugar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Muestra el menú de opciones para jugar.
// Precondición: Ninguna.
// Postcondición: Se imprime el menú de opciones para jugar.
void menu_jugar();

// Cabecera: Ejecuta la acción correspondiente a la opción seleccionada en el menú de juego.
// Precondición: La opción seleccionada debe ser válida.
// Postcondición: Se ejecuta la acción asociada a la opción.
void switch_jugar(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Ejecuta una partida entre dos jugadores.
// Precondición: Los jugadores y tableros deben estar configurados.
// Postcondición: Se desarrolla una partida completa.
void jugar_partida(jugador *jugador1, jugador *jugador2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Reinicia los datos y tableros para una nueva partida.
// Precondición: Los jugadores y tableros deben estar inicializados.
// Postcondición: Se reinician los datos y tableros.
void Reiniciar_partida(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Muestra un resumen de la partida jugada.
// Precondición: La partida debe haber finalizado.
// Postcondición: Se imprime un resumen con las estadísticas de la partida.
void Resumen(jugador *jugador1, jugador *jugador2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);

// Cabecera: Imprime la cabecera de la tabla de estadísticas.
// Precondición: Ninguna.
// Postcondición: Se imprime la cabecera de la tabla.
void imprimirCabeceraTabla();

// Cabecera: Imprime una fila con las estadísticas de un jugador.
// Precondición: Los datos del jugador deben estar inicializados.
// Postcondición: Se imprime una fila con las estadísticas del jugador.
void imprimirFilaJugador(const char* nombreJugador, int disparos, int vacias, int agua, int tocadas, int hundidasCasillas, int hundidosBarcos, int restanBarcos, int esGanador);

#endif
