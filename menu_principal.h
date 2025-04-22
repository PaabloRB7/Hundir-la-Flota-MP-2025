#ifndef MENU_PRINCIPAL
#define MENU_PRINCIPAL

#include "configuracion.h"

#define TAM 10

void menu_intro();
int seleccion_opcion();
void switch_menu(int);
void configuracion();
void switch_configuracion(int);
void introducir_datos();
void mostrar();
void borrar();
void guardar();
void cargar();
void jugar();
void switch_jugar(int);
void jugar_partida();
void Reiniciar_partida(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM]);
void Resumen(jugador *j1, jugador *j2, char flota_jug1[][TAM], char oponente_jug1[][TAM], char flota_jug2[][TAM], char oponente_jug2[][TAM]);
void imprimirCabeceraTabla();
void imprimirFilaJugador(const char* nombreJugador, int disparos, int vacias, int agua, int tocadas, int hundidasCasillas, int hundidosBarcos, int restanBarcos, int esGanador);
#endif
