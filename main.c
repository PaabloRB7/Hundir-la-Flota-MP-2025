#include <stdio.h>

void menu_intro();
int seleccion_opcion();
void switch_menu(int);
void Configuracion();
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



int main(){
    int aux=0;
    menu_intro();
    aux=seleccion_opcion();
    switch_menu(aux);
    return 0;
}

void menu_intro(){
    printf("Bienvenido a Hundir la flota\n");
    printf("1. Configuracion\n");
    printf("2. Jugar\n");
    printf("3. Salir\n");
}

int seleccion_opcion(){
    int opcion=0;
    printf("Seleccione una opcion\n");
    scanf("%i",&opcion);
    return opcion;
}

void switch_menu(int aux){
    switch(aux){
        case 1:
            Configuracion();
            break;
        case 2:
            jugar();
            break;
        case 3:
            //funcion salir
            break; 
        default:
            printf("Opcion no valida\n");
            main();
            break;
    }
}

void Configuracion(){
    int aux=0;
    menu_configuracion();
    aux=seleccion_opcion();
    switch_configuracion(aux);
}

void menu_configuracion(){
    printf("Menu Configuracion\n");
    printf("1. Introducir datos\n");
    printf("2. Mostrar\n");
    printf("3. Borrar\n");
    printf("4. Guardar\n");
    printf("5. Cargar\n");
    printf("6. Volver\n");
}

void switch_configuracion(int aux){
    switch (aux){
        case 1:
            introducir_datos();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            borrar();
            break;
        case 4:
            guardar();
            break;
        case 5:
            cargar();
            break;
        case 6:
            main();
            break;
        default:
            printf("Opcion no valida\n");
            Configuracion();
            break;
    }
}

void introducir_datos(){
}

void mostrar(){
}

void borrar(){

}

void guardar(){

}

void cargar(){

}


void jugar(){
    int aux=0;
    menu_jugar();
    aux=seleccion_opcion(aux);
    switch_jugar(aux);
}

void menu_jugar(){
    printf("Menu Jugar\n");
    printf("1. Jugar partida\n");
    printf("2. Reiniciar partida\n");
    printf("3. Resumen\n");
}

void switch_jugar(int aux){
    switch (aux){
        case 1:
            jugar_partida();
            break;
        case 2:
            Reiniciar_partida();
            break;
        case 3:
            Resumen();
            break;
        case 4:
            main();
            break;
        default:
            printf("Opcion no valida\n");
            jugar();
            break;
    }
}

void jugar_partida(){

}
void Reiniciar_partida(){

}

void Resumen(){

}