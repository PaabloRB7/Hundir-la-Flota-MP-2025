#ifndef MENU_PRINCIPAL
#define MENU_PRINCIPAL

#include "configuracion.h"
#include "barcos.h"

#define TAM 10

void menu_intro();
int seleccion_opcion();
void switch_menu(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void configuracion(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void switch_configuracion(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void menu_configuracion();
void introducir_datos();
void mostrar();
void borrar();
void guardar();
void cargar();
void jugar(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void menu_jugar();
void switch_jugar(int aux, jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void jugar_partida(jugador *jugador1, jugador *jugador2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void Reiniciar_partida(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void Resumen(jugador *jugador1, jugador *jugador2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM], barco barcos_jug1[], barco barcos_jug2[]);
void imprimirCabeceraTabla();
void imprimirFilaJugador(const char* nombreJugador, int disparos, int vacias, int agua, int tocadas, int hundidasCasillas, int hundidosBarcos, int restanBarcos, int esGanador);
#endif
