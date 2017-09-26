#include <stdio.h>

/* Suposo que son de 16 bits, on se vol de 4 x 4*/
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

short int /* es la matriu enmagatzemada */
input1 (void)
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

int main ()
{
	short int a;
	a = input1 ();
	printf ("comprovem el seu bon funcionament\n");
	output (a);
return 0;
}
