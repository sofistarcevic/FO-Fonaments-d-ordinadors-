#ifndef PALABRAS_H
#define PALABRAS_H

#define TRUE	1
#define FALSE	0
#define NUM_LETRAS_PALABRA	5
#define IDIOMA_DEBUG	0
#define IDIOMA_CAT	1
#define IDIOMA_EN	2
#define IDIOMA_ES	3
#define IDIOMA_FI	4
#define IDIOMA_MIO	5
#define NUM_IDIOMAS	6

void imprimir_nombre_idioma(int idioma);
//muestra porpantalla el didioma (en letras)pasado como parametro//
int contar_palabras(int idioma);
//devuelve el numero de palabras que hay en eñ fichero del idioma pasado como parametro//
void inicializar_azar();
//inicializa el generador de numero aleatorios, se debe llamar una sola vez al inicio del programa//
void palabra_al_azar(int idioma, int num_palabras, char palabra[NUM_LETRAS_PALABRA]);
//devyelve  a través del parametropalabra, una palabra al azar del idioma pasado como primer parámetro, se debe pasar como segundo parámetro el número de palabras que hay en el fichero del idiooma correspondido//
int es_palabra_correcta(int idioma, char palabra[NUM_LETRAS_PALABRA]);
//Devolver TRUE si la palabra pasado como segundo parámetro existe en el idioma pasado como primer parámetro. En caso contrario devuelve FALSE//

#endif // PALABRAS_H

