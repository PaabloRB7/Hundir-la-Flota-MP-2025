#include <stdio.h>
#include "menu_principal.h"

int main(){
    int aux=0;
    menu_intro();
    aux=seleccion_opcion();
    switch_menu(aux);
    return 0;
}

