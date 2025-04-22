#include <stdio.h>
#include "menu_principal.h"
#include "tablero.h"
#include "barcos.h"
#include "disparos.h"
#include "configuracion.h"

#define TAM 10



int main(){

    int aux=0;
    menu_intro();
    aux=seleccion_opcion();
    switch_menu(aux);

    return 0;
}