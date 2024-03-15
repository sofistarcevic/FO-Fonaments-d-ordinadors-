#include <stdio.h>
#include "menu.h"

void imprimir_menu(tmenu *m){
	int i, num_palabras;
	
	do{
		printf("WORDLE:\n\n");
		printf("Seleccione el idioma de las palabras: \n");
		printf("0) Debug (te pedirá la palabra solución) (%d palabras).\n", contar_palabras(IDIOMA_DEBUG));
		printf("1) Català (%d palabras).\n", contar_palabras(IDIOMA_CAT));
		printf("2) Inglés (%d palabras).\n", contar_palabras(IDIOMA_EN));
		printf("3) Castellano (%d palabras).\n", contar_palabras(IDIOMA_ES));
		printf("4) Finlandés (%d palabras).\n", contar_palabras(IDIOMA_FI));
		printf("5) palabras_mio.txt (por si quieres usar un fichero tuyo) (%d palabras).\n", contar_palabras(IDIOMA_MIO));
		printf("\nIntro opción: ");
		scanf("%d%*c", &m->opc);

		palabra_al_azar(m->opc, contar_palabras(m->opc), m->palabra_adivinar);
	}
	while(m->opc<0 && m->opc>5);

}
