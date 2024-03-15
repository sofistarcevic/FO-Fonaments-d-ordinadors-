#include <stdio.h>
#include "tablero.h"


void inicializar_tablero (ttablero *t)
{
	int i,j;
    char tab[FILAS][COLUMNAS] = {{"     "},{"     "},{"     "},{"     "},{"     "},{"     "}};
    int tcolor[FILAS][COLUMNAS] = {{00000},{00000},{00000},{00000},{00000},{00000}};

	for(i=0;i<FILAS;i++)
    {
		for(j=0;j<COLUMNAS;j++)
        {
    			t->tablero[i][j] = tab[i][j];
                t->colores[i][j] = tcolor[i][j];
        }
    }

    t->nf = 0;
}

void imprimir_tablero (ttablero t, tmenu m)
{
    int i, j;

    printf_color(COLOR_DEFAULT);
    printf("\n         +-+-+-+-+-+\n");
    for (i=0; i<FILAS; i++)
    {
	    printf("         ");
        for (j=0; j<COLUMNAS; j++)
        {
            printf("|");
            cambiar_color_t(t, i, j);
            printf("%c", t.tablero[i][j]);
            printf_color(COLOR_DEFAULT);
        }
        printf("|\n");
	printf("         +-+-+-+-+-+\n");
    }
	printf("\n");
}

void actualizar_colores (ttablero *t, tmenu m)
{
    int encontrada, k;

    if (t->tablero[t->nf][t->nc]==' ')
        t->colores[t->nf][t->nc]=0;

    else if (t->tablero[t->nf][t->nc]==m.palabra_adivinar[t->nc])
        t->colores[t->nf][t->nc]=2;

    else
    {
            encontrada=0;
            for (k=0; k<NUM_LETRAS_PALABRA && encontrada==0; k++)
            {
                if (t->tablero[t->nf][t->nc]==m.palabra_adivinar[k] && m.palabra_adivinar[k]!=t->tablero[t->nf][k])
                    encontrada=1;
            }
            if (encontrada)
                t->colores[t->nf][t->nc]=3;
            else
                t->colores[t->nf][t->nc]=4;        
    }
}

void cambiar_color_t (ttablero t, int nf, int nc)
{
    if (t.colores[nf][nc]==0)
        printf_color(COLOR_DEFAULT);
    else if (t.colores[nf][nc]==2)
        printf_color(COLOR_LETRA_Y_POSICION_OK);
    else if (t.colores[nf][nc]==3)
        printf_color(COLOR_LETRA_OK);
    else
        printf_color(COLOR_LETRA_KO);
}