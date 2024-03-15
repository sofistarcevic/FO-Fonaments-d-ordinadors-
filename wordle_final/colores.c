// Este fichero se le da al alumno
#include <stdio.h>
#include "colores.h"

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BOLD    "\x1b[1m"
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_BGCOL_BLACK   "\x1b[40m"
#define ANSI_BGCOL_RED     "\x1b[41m"
#define ANSI_BGCOL_GREEN   "\x1b[42m"
#define ANSI_BGCOL_YELLOW  "\x1b[43m"
#define ANSI_BGCOL_BLUE    "\x1b[44m"
#define ANSI_BGCOL_MAGENTA "\x1b[45m"
#define ANSI_BGCOL_CYAN    "\x1b[46m"
#define ANSI_BGCOL_WHITE   "\x1b[47m"

void printf_fgcolor(int color) {
	switch (color % NUM_COLORS) {
		case BLACK:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_BLACK  ); break;
		case RED:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_RED    ); break;
		case GREEN:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_GREEN  ); break;
		case YELLOW:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_YELLOW ); break;
		case BLUE:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_BLUE   ); break;
		case MAGENTA:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_MAGENTA); break;
		case CYAN:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_CYAN   ); break;
		case WHITE:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_COLOR_WHITE  ); break;
		case BOLD_BLACK:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_BLACK  ); break;
		case BOLD_RED:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_RED    ); break;
		case BOLD_GREEN:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_GREEN  ); break;
		case BOLD_YELLOW:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_YELLOW ); break;
		case BOLD_BLUE:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_BLUE   ); break;
		case BOLD_MAGENTA:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_MAGENTA); break;
		case BOLD_CYAN:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_CYAN   ); break;
		case BOLD_WHITE:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_WHITE  ); break;
	}
}

void printf_bgcolor(int color) {
	switch (color % NUM_COLORS) {
		case BLACK:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_BLACK  ); break;
		case RED:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_RED    ); break;
		case GREEN:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_GREEN  ); break;
		case YELLOW:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_YELLOW ); break;
		case BLUE:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_BLUE   ); break;
		case MAGENTA:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_MAGENTA); break;
		case CYAN:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_CYAN   ); break;
		case WHITE:
			printf(ANSI_COLOR_RESET  ); printf(ANSI_BGCOL_WHITE  ); break;
		case BOLD_BLACK:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_BLACK  ); break;
		case BOLD_RED:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_RED    ); break;
		case BOLD_GREEN:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_GREEN  ); break;
		case BOLD_YELLOW:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_YELLOW ); break;
		case BOLD_BLUE:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_BLUE   ); break;
		case BOLD_MAGENTA:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_MAGENTA); break;
		case BOLD_CYAN:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_CYAN   ); break;
		case BOLD_WHITE:
			printf(ANSI_COLOR_BOLD   ); printf(ANSI_BGCOL_WHITE  ); break;
	}
}

void printf_reset_color() {
	printf(ANSI_COLOR_RESET);
}

void printf_negrita_color() {
	printf(ANSI_COLOR_RESET);
	printf(ANSI_COLOR_BOLD);
}

void printf_color(int color) {
	switch (color) {
		case COLOR_NEGRITA:
			// printf_fgcolor(BOLD_WHITE);
			printf_negrita_color();
			break;
		case COLOR_LETRA_Y_POSICION_OK:
			printf_bgcolor(BOLD_GREEN);
			break;
		case COLOR_LETRA_OK:
			printf_bgcolor(BOLD_YELLOW);
			break;
		case COLOR_LETRA_KO:
			printf_bgcolor(BOLD_WHITE);
			break;
		case COLOR_DEFAULT:
		default:
			// printf_fgcolor(WHITE);
			printf_reset_color();
			break;
	}
}

void borrar_pantalla() {
	printf("\e[1;1H\e[2J");
}

