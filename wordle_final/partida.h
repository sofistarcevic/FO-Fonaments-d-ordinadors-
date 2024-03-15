#ifndef PARTIDA_H
#define PARTIDA_H

#include "palabras.h"
#include "colores.h"
#include "tablero.h"
#include "teclado.h"
#include "menu.h"

#define NUM_LETRAS_PALABRA	5

typedef struct{
	ttablero t;
	tteclado tec;
	char introducida[NUM_LETRAS_PALABRA];
}tpartida;

void inicializar_partida(tpartida *p); //lee la partida
void imprimir_estado_partida(tpartida p, tmenu m); //imprime objetos por pantalla
void realizar_jugada(tpartida *p, tmenu m); //se introduce la palabra y se comprueba. Cuando hay teclado se muestran letras disponibles sugeridas
int palabra_adivinada(char palabra1[NUM_LETRAS_PALABRA], char palabra2[NUM_LETRAS_PALABRA]);

#endif //PARTIDA_H

