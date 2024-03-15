#include <stdio.h>
#include "colores.h"

int main() {
	int i;

	printf("TEST COLORES\n");
	printf("Invocando printf_color con los siguientes argumentos:\n");
	printf_color(COLOR_NEGRITA);
	printf("COLOR_NEGRITA");
	printf_color(COLOR_DEFAULT); printf("\n");
	printf_color(COLOR_LETRA_Y_POSICION_OK);
	printf("COLOR_LETRA_Y_POSICION_OK");
	/*printf_color(COLOR_DEFAULT);*/ printf("\n");
	printf_color(COLOR_LETRA_OK);
	printf("COLOR_LETRA_OK");
	printf_color(COLOR_DEFAULT); printf("\n");
	printf_color(COLOR_LETRA_KO);
	printf("COLOR_LETRA_KO");
	printf_color(COLOR_DEFAULT); printf("\n");
	printf("COLOR_DEFAULT\n");
	printf("Como podéis ver (esta linea verde larga que no queriamos):\n");
	printf("Antes de imprimir un retorno de carro volved a COLOR_DEFAULT\n");
	printf("si habéis cambiado el color de fondo.\n");

	printf("\nprintf_fgcolor y printf_bgcolor no son necesarios, pero os los doy\npor si quereis más colores.\n");

	printf("- printf_fgcolor:\n");
	for (i=0; i < NUM_COLORS; i++) {
		printf_fgcolor(i);
		printf("HOLA");
	}
	printf_color(COLOR_DEFAULT); printf("\n");

	printf("- printf_bgcolor:\n");
	for (i=0; i < NUM_COLORS; i++) {
		printf_bgcolor(i);
		printf("HOLA");
	}
	printf_color(COLOR_DEFAULT); printf("\n");
	printf("Y, volvemos al color por defecto antes de cerrar el main.\n");
}

