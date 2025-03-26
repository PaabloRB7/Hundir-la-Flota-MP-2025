#ifndef barcos
#define barcos

#define TAM 10

typedef struct {
    char[20] nombre;
    int longitud;
    char tipo;
    int eje_y;
    int eje_x;
    char orientacion;
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


