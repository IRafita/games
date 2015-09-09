#include <stdio.h>
#include <stdlib.h>

#define sizeMutacions 10

struct cosElemental
{
	unsigned short int element;
	struct cosElemental * next;
};

unsigned short int *listMutation;
unsigned short int *listAll;
struct cosElemental *listCosElemental;


/* Llista que generara per les mutacions */
void generateListMutations ( short int *); /* dc set  9 15:54:13 CEST 2015 Funciona */

struct cosElemental * newCosElemental (short int, short int); /* canvi inportant en aquesta funcio */


void init16	(); /* dc set  9 15:54:13 CEST 2015 Funciona */
void end16	(); /* dc set  9 15:54:13 CEST 2015 Funciona */

void output	( short int ); /* dc set  9 15:54:13 CEST 2015 Funciona */
unsigned short int input (void);


void ShowSolution ( short int, int );


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
