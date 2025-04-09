cmake_minimum_required(VERSION 3.30)
project(Hundir_la_Flota_MP_2025 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Hundir_la_Flota_MP_2025
    barcos.c
    barcos.h
    #configuracion.c
    #configuracion.h
    disparos.c
    disparos.h
    main.c
    #menu_principal.c
    #menu_principal.h
    tablero.c
    tablero.h)