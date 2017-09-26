#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define sizeMutacions 10

short int	*listMutation;
char		*listTrobats;

struct fitxes16
{
	short int	matriu;
	char		*cami;
	struct fitxes16	*next;
};


/* Inicialitzar, necessari */
void init16Fitxes ();
void end16Fitxes ();

/* Visualitzar el resultat */
void print16Fitxes (short int);
