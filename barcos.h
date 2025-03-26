#ifndef barcos
#define barcos

#define TAM 10

void barcos_principal();
int seleccion_opcion();
void menu_barcos();
void switch_barcos(int);
int menu_colocaccion();
void switch_colocacion();
void portaaviones();
void acorazado();
void crucero();
void destructor();
void fragata();
void submarino();
void colocar_barcos(char [][TAM],char );
int comprobar_casillas(char [][TAM],int,int);

#endif


