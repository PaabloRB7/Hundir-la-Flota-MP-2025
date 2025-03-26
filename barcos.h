#ifndef barcos
#define barcos

#define TAM 10

typedef struct {
    int longitud;
    char tipo;
    int eje_y;
    int eje_x;
}barco;

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


