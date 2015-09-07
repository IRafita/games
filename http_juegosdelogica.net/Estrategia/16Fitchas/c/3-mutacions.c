#include <stdio.h>

#define sizeMutacions 10

void generateListMutations (o)
short int o [sizeMutacions]; /* Llista que generara per les mutacions */
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

int main ()
{
	short int a [sizeMutacions], x;
	int i;

	generateListMutations (a);
	x = 3075;
	output (x);
	for (i = 0; i < sizeMutacions; i++)	
	{
		printf ("\nposicio %d\n", i);
		x = x ^ a[i];
		output (x);
	}
return 0;
}
