#include <stdio.h>
#include <stdlib.h>

#define sizeMutation 10

struct lista
{
	unsigned short int element;
	struct lista * next;
};

unsigned short int *lM;
unsigned short int *lA;
struct lista *listaMemoria;


/* Llista que generara per les mutacions */
void generateListMutations ( short int *); /* dc set  9 15:54:13 CEST 2015 Funciona */

struct lista * newS ( unsigned short int, unsigned short int); /* canvi inportant en aquesta funcio */


void init16	(); /* dc set  9 15:54:13 CEST 2015 Funciona */
void end16	(); /* dc set  9 15:54:13 CEST 2015 Funciona */

void output	( short int ); /* dc set  9 15:54:13 CEST 2015 Funciona */
unsigned short int input (void);


void ShowSolution ( unsigned short int, unsigned int );


/* usat basicament per debugegar... pero tambe per a mes :) */
/*
void
showS16 (struct cosElemental *e)
{
	int i = 0;
	while (e)
	{
		printf ("sicle %d\n", i++);
		output (e->element);
		e = e->next;
	}
}*/
