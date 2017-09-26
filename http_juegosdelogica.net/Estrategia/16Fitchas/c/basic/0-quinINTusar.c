#include <stdio.h>
int main ()
{
	unsigned int a;
	unsigned short b;

	a = 0; b = 0;
	a--; b--;
	printf ("%u\t%u\n", a, b);
return 0;
}
/* La resolucio al dubte es unsigned short */
