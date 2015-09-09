#include <stdio.h>

/* Pega, escriu el resultat al reves del desitjat */
/* copiat de http://stackoverflow.com/questions/6373093/how-to-print-binary-number-via-printf */
void printBynary (n, i)
short int n;	/* valor en binary	*/
short int i;	/* total de bits	*/
{
	while (n)
	{
		i--;
		if (n & 1)
			printf("1");
		else
			printf("0");

		n >>= 1;
	}
	while (i--)
		printf ("0");
	printf("\n");
}

void intent1Show (n)
short int n; /* Valor que necessitarem per a poder mostrar la matriu en questio */
{
	short int residu, i;
	i = 0x1000;

	while (i)
	{
		residu = n % i;
		n /= i;
		printBynary (n);
		n = residu;
		i/= 0x10;
	}
}


/* http://stackoverflow.com/questions/18327439/printing-binary-representation-of-a-char-in-c */
/* Suposo que son de 16 bits, on se vol de 4 x 4*/
/* codi orientat espagueti :) */
void intent2Show (n)
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

int main ()
{
	short int a;
	a = 11;
	printf ("decimal %d\thexa %x\tocta %o\tbinary %b\n", a, a, a, a);
/*	printBynary (a);*/
	printf ("\n My first intent %u \n", a);
	/*intent1Show (a); Abans funcionava... */
	printf ("\n My second intent %u \n", a);
	intent2Show (a);
return 0;
}
