#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "concret.h"

int main (int argc, char *argv[])
{
	int v, l;

	if (argc != 3) return 1;

	v = atoi (argv[2]);
	l = strlen (argv[1]);
	if ( preguntar_maxim (l, argv[1]) <= v ) return 1;

	concret (l, argv[1], v);
	printf ("%s\n", argv[1]);
	return 0;
}
