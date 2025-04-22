#ifndef MENU_PRINCIPAL
#define MENU_PRINCIPAL

void menu_intro();
int seleccion_opcion();
void switch_menu(int);
void configuracion();
void menu_configuracion();
void switch_configuracion(int);
void introducir_datos();
void mostrar();
void borrar();
void guardar();
void cargar();
void jugar();
void menu_jugar();
void switch_jugar(int);
void jugar_partida();
void Reiniciar_partida();
void Resumen();
void imprimirCabeceraTabla();
void imprimirFilaJugador(const char* nombreJugador, int disparos, int vacias, int agua, int tocadas, int hundidasCasillas, int hundidosBarcos, int restanBarcos, int esGanador);
#endif
