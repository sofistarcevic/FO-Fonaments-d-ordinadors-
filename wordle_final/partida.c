#include <stdio.h>
#include "partida.h"

void inicializar_partida(tpartida *p)
{
    inicializar_tablero(&p->t);  
    inicializar_teclado(&p->tec);
}

void imprimir_estado_partida(tpartida p, tmenu m)
{
    imprimir_tablero(p.t, m);
    imprimir_teclado(p.tec);
}
 
void realizar_jugada(tpartida *p, tmenu m)
{
    int i, j, k;
    char car;
	
    printf("Introduce palabra: ");

    for(i=0; i<NUM_LETRAS_PALABRA; i++)
    {
        scanf("%c", &p->introducida[i]);
        if (p->introducida[i]>='a' && p->introducida[i]<='z')
        p->introducida[i]=p->introducida[i]-'a'+'A';    //si se introducen minúsculas, se cambia a mayúsculas
    }
    scanf("%c", &car);
    while(car!='\n')
        scanf("%c", &car);
    
    while (es_palabra_correcta(m.opc, p->introducida)==FALSE)
    {
        printf("Palabra invalida. Introduce palabra: ");

        for(i=0; i<NUM_LETRAS_PALABRA; i++)
        {
            scanf("%c", &p->introducida[i]);
            if (p->introducida[i]>='a' && p->introducida[i]<='z')
            p->introducida[i]=p->introducida[i]-'a'+'A';    //si se introducen minúsculas, se cambia a mayúsculas
        }
        scanf("%c", &car);
        while(car!='\n')
            scanf("%c", &car);
    }

    for (i=0; i<NUM_LETRAS_PALABRA; i++)
	{
        p->t.nc = i;
        
        p->t.tablero[p->t.nf][i]=p->introducida[i];     //actualiza letra en el tablero

        actualizar_colores (&p->t, m);

        for (k=0; k<FIL; k++)
        {
            for (j=0; j<COL; j++)
            {
                if ((p->t.tablero[p->t.nf][i]==p->tec.teclado[k][j]) && (p->tec.colores_tec[k][j] != 2))
                    p->tec.colores_tec[k][j]=p->t.colores[p->t.nf][i];
            }
        }
    }
}

int palabra_adivinada(char palabra1[NUM_LETRAS_PALABRA], char palabra2[NUM_LETRAS_PALABRA])
{
    int i;
    
    for(i=0; i<NUM_LETRAS_PALABRA; i++)
    {
        if(palabra1[i]!=palabra2[i])
            return 0;
    }

    return 1;
}