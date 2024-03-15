// Este fichero se le da al alumno
#ifndef COLORES_H
#define	COLORES_H

// Constantes con las que invocar printf_color
#define COLOR_DEFAULT			0
#define COLOR_NEGRITA			1
#define COLOR_LETRA_Y_POSICION_OK	2
#define COLOR_LETRA_OK			3
#define COLOR_LETRA_KO			4

/*
 * Despues de llamar a printf_color() con un color determinado,
 * todo lo que imprimimamos por pantalla apareceran en ese color.
 */
void printf_color(int color);

/*
 * Lo que viene a continuación no lo necesitais pero os lo doy por si quereis
 * mas colores. :-)
 */

// Posibles valores del argumento color para las funciones printf_fgcolor() y printf_bgcolor()
#define BLACK		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define WHITE		7
#define BOLD_BLACK	8
#define BOLD_RED	9
#define BOLD_GREEN	10
#define BOLD_YELLOW	11
#define BOLD_BLUE	12
#define BOLD_MAGENTA	13
#define BOLD_CYAN	14
#define BOLD_WHITE	15
#define NUM_COLORS	16

void printf_fgcolor(int color);	// Color de las letras
void printf_bgcolor(int color);	// Color de fondo
void printf_reset_color();	// Imprimir en color por defecto del terminal
void printf_negrita_color();	// Imprimir en color por defecto pero en negrita
void borrar_pantalla();

#endif	/* COLORES_H */

