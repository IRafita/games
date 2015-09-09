#include "lib16.h"


void output (n)
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

unsigned short int /* es la matriu enmagatzemada */
input (void)
{
	short int o =  0; /* output */
/* si mai fem que sigui un short int, la divisio la fa malament i tambe el >> */
	int i = 0x8000; /* 16 caracters que han d'entrar */
	while (i)
	{
		switch (getchar ())
		{
		case '1':
			o += i;
		case '0':
			i >>= 1;
			break;
		default: break;
		}
	}
	return o;
}

/* Basicament aixo, genera totes les mutacions */
void generateListMutations (o)
short int *o; /* Llista que generara per les mutacions */
{
	int i;
	short int t;
	t = 0xf; i = 0;

	while (i < 4)
	{
		o[i++] = t;
		t <<= 4;
	}
	t = 0x1111;
	while(i < 8)
	{
		o[i++] = t;
		t <<= 1;
	}
	o[8] = 0x8421;
	o[9] = 0x1248;
}
struct cosElemental * newCosElemental ( n, i )
short int n, i; /* n es el lloc, i i el valor que se vol entrar */
{
	struct cosElemental *l;
	l = listCosElemental + n;
	l->element = i;
	l->next = 0;
	return l;
}

void ShowSolution ( n, cont )
short int n;
int cont;
{
	int t;
	while (cont--)
	{
		t = listAll[n];
		printf ("Element %d\n", cont);
		output (n);
		n = t;
	}
	printf ("Final ?\n");
	output (n);
}

/******************** Al final de tot ********************/
void init16	()
{	/* inicialitzem */
	listMutation	= (short int *) malloc ( sizeof (short int) * sizeMutacions );
	listAll		= (short int *) calloc ( 0x1000, sizeof (short int) );
	listCosElemental= (struct cosElemental *) malloc ( 0x1000* sizeof (short int) );

	/* comprovem que tot correcte */
	if (!listMutation)
	{	printf ("Fatal error make Mutation\n"); exit (1);
	}if (!listAll)
	{	printf ("Fatal error make All\n"); exit (1);
	}if (!listCosElemental)
	{	printf ("Fatal error make Cos Elemental\n"); exit; }

	/* definim les mutacions */
	generateListMutations (listMutation);
}
void end16	()
{
	free (listMutation);
	free (listAll);
	free (listCosElemental);
}
