#ifndef barcos
#define barcos

#define TAM 10

typedef struct {
    char nombre[20];
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
void inicializar_barcos(barco test[]);
void colocar_barcos(char tablero[][TAM], barco test[]);
void direccionar_barcos(barco test[], int num_barco, char tablero[][TAM]);
void colocar_horizontal(barco test[],int num_barco,char tablero[][TAM]);
void colocar_vertical(barco test[],int num_barco,char tablero[][TAM]);
void colocar_diagonal_der(barco test[],int num_barco,char tablero[][TAM]);
void colocar_diagonal_izq(barco test[],int num_barco,char tablero[][TAM]);
int comprobar_casillas(char tablero[][TAM],int ejey,int ejex, barco barco[], int num_barco);

#endif


