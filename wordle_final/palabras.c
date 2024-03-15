#include <stdio.h>
#include <string.h>
#include <time.h>	// time()
#include <stdlib.h>	// rand(), srand()
#include "palabras.h"

#define FILE_CAT	"palabras_cat.txt"
#define FILE_EN		"palabras_en.txt"
#define FILE_ES		"palabras_es.txt"
#define FILE_FI		"palabras_fi.txt"
#define FILE_MIO	"palabras_mio.txt"

const char* nombre_fichero(int idioma) {
	switch (idioma) {
		case IDIOMA_CAT:
			return FILE_CAT;
			break;
		case IDIOMA_EN:
			return FILE_EN;
			break;
		case IDIOMA_ES:
			return FILE_ES;
			break;
		case IDIOMA_FI:
			return FILE_FI;
			break;
		case IDIOMA_MIO:
		default:
			return FILE_MIO;
			break;
	}
}

void imprimir_nombre_idioma(int idioma) {
	switch (idioma) {
		case IDIOMA_DEBUG:
			printf("Debug (te pedirá la palabra solución)");
			break;
		case IDIOMA_CAT:
			printf("Català");
			break;
		case IDIOMA_EN:
			printf("Inglés");
			break;
		case IDIOMA_ES:
			printf("Castellano");
			break;
		case IDIOMA_FI:
			printf("Finlandés");
			break;
		case IDIOMA_MIO:
			printf("palabras_mio.txt (por si quieres usar un fichero tuyo");
			break;
		default:
			printf("ERROR: idioma desconocido");
			break;
	}
}

int contar_palabras(int idioma) {
	FILE *fp_in;
	int count = 0;

	if (idioma == IDIOMA_DEBUG) {
		return 0;
	}

	if ((fp_in = fopen(nombre_fichero(idioma), "r")) == NULL) return -1;
	do {
		if (fscanf(fp_in, "%*s") != EOF) {
			count++;
		}
	} while (!feof(fp_in));
	fclose(fp_in);

	return count;
}

void inicializar_azar() {
	/*
	 * Para que la sequencia de numeros aleatorios sea igual en cada
	 * ejecucion usad el srand (0) en lugar del srand(time).
	 */
	//srand(0);
	srand( (unsigned)time( NULL ) );
}

int numero_al_azar(int max) {
	return ( rand() % max); 
}

void palabra_al_azar(int idioma, int num_palabras, char palabra[NUM_LETRAS_PALABRA]) {
	FILE *fp_in;
	int i;
	int num_palabra;
	char palabra_fichero[NUM_LETRAS_PALABRA + 1];

	if (idioma == IDIOMA_DEBUG) {
		printf("Modo DEBUG: Introduce la palabra solución: ");
		for (i=0; i<NUM_LETRAS_PALABRA; i++) {
			scanf("%c", &palabra[i]);
			if (palabra[i] >= 'a' && palabra[i] <= 'z') {
				palabra[i] = palabra[i] - 'a' + 'A';
			}
		}
		scanf("%*c");
		return;
	}

	num_palabra = numero_al_azar(num_palabras);
	if ((fp_in = fopen(nombre_fichero(idioma), "r")) == NULL) return;
	for (i = 0; i < num_palabra; i++) {
		fscanf(fp_in, "%*s");
	}
	fscanf(fp_in, "%s", palabra_fichero);
	fclose(fp_in);
	for (i = 0; i < NUM_LETRAS_PALABRA; i++) {
		palabra[i] = palabra_fichero[i];
	}
}

int es_palabra_correcta(int idioma, char palabra[NUM_LETRAS_PALABRA]) {
	FILE *fp_in;
	char palabra_fichero[NUM_LETRAS_PALABRA + 1];

	if (idioma == IDIOMA_DEBUG) {
		return TRUE;
	}

	if ((fp_in = fopen(nombre_fichero(idioma), "r")) == NULL) return FALSE;
	do {
		if (fscanf(fp_in, "%s", palabra_fichero) != EOF) {
			// if (strcmp(palabra, palabra_fichero) == 0) {
			if (strncmp(palabra, palabra_fichero,
					       NUM_LETRAS_PALABRA) == 0) {
				fclose(fp_in);
				return TRUE;
			}
		}
	} while (!feof(fp_in));
	fclose(fp_in);

	return FALSE;
}

