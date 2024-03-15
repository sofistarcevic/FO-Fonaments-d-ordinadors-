#ifndef MENU_H
#define	MENU_H
#include "palabras.h"

typedef struct{
	int opc;
	char palabra_adivinar[NUM_LETRAS_PALABRA];
}tmenu;  

void imprimir_menu(tmenu *m);

#endif //MENU_H
