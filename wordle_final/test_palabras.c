#include <stdio.h>
#include "palabras.h"

int main() {
	int idioma = IDIOMA_ES, i;
	char palabra[NUM_LETRAS_PALABRA];

	printf("TEST PALABRAS\n");

	printf("Llamamos a inicializar_azar una y sólo una vez al principio del main.\n");
	inicializar_azar();

	printf("Jugamos con palabras del idioma: ");
	imprimir_nombre_idioma(idioma);
	printf("\n");

	printf("Una palabra al azar: ");
	palabra_al_azar(idioma, contar_palabras(idioma), palabra);
	for (i=0; i<NUM_LETRAS_PALABRA; i++) {
		printf("%c", palabra[i]);
	}
	printf("\n");

	printf("Intro una palabra de %d letras en mayúsculas: ",
		       NUM_LETRAS_PALABRA);
	for (i=0; i<NUM_LETRAS_PALABRA; i++) {
		scanf("%c", &palabra[i]);
	}
	scanf("%*c");

	if (es_palabra_correcta(idioma, palabra)) {
		printf("Es una palabra correcta.\n");
	} else {
		printf("No es una palabra correcta.\n");
	}
}

