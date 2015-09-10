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
struct lista * newS ( n, i )
/* Per problemes de violacio de segment ho hem canviat a unsigned */
unsigned short int n, i; /* n es el lloc, i i el valor que se vol entrar */
{
	struct lista *l;
	l = listaMemoria + n;
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
		t = lA [ n ];
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
	lM		= (short int *) malloc ( sizeof (short int) * sizeMutation );
	lA		= (short int *) calloc ( 0x10000, sizeof (short int) ); /* Canvis grans, he afegit un zero */
	listaMemoria	= (struct lista *) malloc ( 0x10000* sizeof (struct lista) ); /* petit canvi, ja que posava short int xD */

	/* comprovem que tot correcte */
	if ( ! lM )
	{	printf ("Fatal error make Mutation\n"); exit (1);
	}if ( ! lA )
	{	printf ("Fatal error make All\n"); exit (1);
	}if ( ! listaMemoria )
	{	printf ("Fatal error make Cos Elemental\n"); exit (1); }

	/* definim les mutacions */
	generateListMutations ( lM );
}
void end16	()
{
	free ( lM		);
	free ( lA		);
	free ( listaMemoria	);
}
