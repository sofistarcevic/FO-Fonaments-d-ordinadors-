#include <stdio.h>
#include "colores.h"
#include "menu.h"
#include "partida.h"
#include "tablero.h"

#define MAX_LETRAS	5
	
int main()
{
	//Declaración de variables
	tmenu m;
	tpartida p;
	ttablero t;
	int i, nf, nc, pcorrecta=0;

	//Mostrar menú repetidamente (hasta que sea correcto)
	imprimir_menu(&m);

	//Inicializar tablero del juego
	inicializar_partida(&p);
	imprimir_estado_partida(p, m);

	//Hacer partidas hasta que la palabra sea correcta o hasta quedarse sin opciones
	for (i=0; pcorrecta!=1 && p.t.nf!=6; i++){
		realizar_jugada(&p, m);
	
		p.t.nf++;
    	pcorrecta = palabra_adivinada(p.introducida, m.palabra_adivinar);

		if (pcorrecta==1)
		printf("PALABRA CORRECTA!!! :-)\n");
		else if (p.t.nf==6)
		printf("SE TE ACABARON LOS INTENTOS!!! :-(\nLA PALABRA CORRECTA ERA: %s\n", m.palabra_adivinar);

		imprimir_estado_partida(p, m);
	}
}
