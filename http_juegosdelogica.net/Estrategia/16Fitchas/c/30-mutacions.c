#include "lib16Fitxes.h"

int main ()
{
	int i;
	init16Fitxes ();

	for (i = 0; i < sizeMutacions; i++)
	{
		printf ("%d\n", i);
		print16Fitxes (listMutation[i]);
	}
return 0;
}
