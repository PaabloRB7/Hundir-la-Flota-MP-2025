#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"

#define TAM 10



int main(){

    srand(time(NULL));
    int aux=0;
    menu_intro();
    aux=seleccion_opcion();
    switch_menu(aux);

    return 0;
}
