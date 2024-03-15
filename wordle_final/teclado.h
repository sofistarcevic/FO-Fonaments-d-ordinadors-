#ifndef TECLADO_H
#define TECLADO_H

#include "colores.h"
#include "tablero.h"

#define FIL 3
#define COL 10

typedef struct
{
    char teclado [FIL][COL];
    int colores_tec [FIL][COL];
    int nft, nct;
}tteclado;

void inicializar_teclado (tteclado *tec);

void imprimir_teclado (tteclado tec);

void cambiar_color_tec (tteclado tec, int nf, int nc);

#endif 