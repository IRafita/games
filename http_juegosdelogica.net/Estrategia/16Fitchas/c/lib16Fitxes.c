#include "lib16Fitxes.h"


void generateListMutations ()
/*short int o [sizeMutacions]; *//* Llista que generara per les mutacions */
{
	int i;
	short int t;
	t = 0xf; i = 0;

	while (i < 4)
	{
		listMutation[i++] = t;
		t <<= 4;
	}
	t = 0x1111;
	while(i < 8)
	{
		listMutation[i++] = t;
		t <<= 1;
	}
	listMutation[8] = 0x8421;
	listMutation[9] = 0x1248;
}

/* Suposo que son de 16 bits, on se vol de 4 x 4*/
void print16Fitxes (n)
short int n;
{
	short int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d", !!((n << (i*4 + j)) & 0x8000));
		printf ("\n");
	}
}

void end16Fitxes ()
{
	free (listTrobats);
	free (listMutation);
}
void init16Fitxes ()
{
	listMutation = (short int *) calloc (sizeMutacions, sizeof(short int));
	if (!listMutation)
	{
		printf ("Error en reservar memoria a listMutation\n");
		exit (1);
	}
	generateListMutations ();
	listTrobats = (char *)calloc (0x10000, sizeof(char));
	if (!listTrobats)
	{
		printf ("No ha pogut reservar memoria listTrobats!\n");
		exit (1);
	}
}
