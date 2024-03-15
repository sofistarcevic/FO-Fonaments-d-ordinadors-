#ifndef TABLERO_H
#define TABLERO_H
#define FILAS 6
#define COLUMNAS 5

#include "palabras.h"
#include "colores.h"
#include "menu.h"

typedef struct
{
    char tablero [FILAS][COLUMNAS];
    int colores [FILAS][COLUMNAS];
    int nf, nc;
}ttablero;

void inicializar_tablero (ttablero *t);

void imprimir_tablero (ttablero t, tmenu m);

void actualizar_colores (ttablero *t, tmenu m);

void cambiar_color_t (ttablero t, int nf, int nc);

#endif