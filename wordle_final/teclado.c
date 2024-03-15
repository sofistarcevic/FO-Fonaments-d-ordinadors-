#include <stdio.h>
#include "teclado.h"

void inicializar_teclado (tteclado *tec)
{
	int i,j;
    char tecla[FIL][COL] = {{"QWERTYUIOP"},
                            {"ASDFGHJKL "},
                            {"ZXCVBNM   "}};
    
    int teccolor[FIL][COL] = {{0000000000},{000000000},{0000000}};

    for(i=0;i<FIL;i++)
		for(j=0;j<COL;j++)
        {
    		tec->teclado[i][j] = tecla[i][j];
            tec->colores_tec[i][j] = teccolor[i][j];
        }  
}

void imprimir_teclado (tteclado tec)
{
    int j;

    printf_color(COLOR_DEFAULT);

    for (j=0; j<COL; j++)
    {
        cambiar_color_tec (tec, 0, j);
        printf("[%c]", tec.teclado[0][j]);
        printf_color(COLOR_DEFAULT);
    }

    printf("\n ");

    for (j=0; j<COL-1; j++)
    {
        cambiar_color_tec (tec, 1, j);
        printf("[%c]", tec.teclado[1][j]);
        printf_color(COLOR_DEFAULT);
    }
    
	printf("\n  ");

    for (j=0; j<COL-3; j++)
    {
        cambiar_color_tec (tec, 2, j);
        printf("[%c]", tec.teclado[2][j]);
        printf_color(COLOR_DEFAULT);
    }  

    printf("\n"); 
}

void cambiar_color_tec (tteclado tec, int nf, int nc)
{
    if (tec.colores_tec[nf][nc]==0)
        printf_color(COLOR_DEFAULT);
    else if (tec.colores_tec[nf][nc]==2)
        printf_color(COLOR_LETRA_Y_POSICION_OK);
    else if (tec.colores_tec[nf][nc]==3)
        printf_color(COLOR_LETRA_OK);
    else
        printf_color(COLOR_LETRA_KO);
}