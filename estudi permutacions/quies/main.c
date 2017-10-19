#include <stdio.h>
#include <string.h>

#include "quies.h"

int main (int argc, char *argv[])
{
	int l, s;

	if (argc != 3) return 1;

	l = strlen (argv[1]);
	s = quies (l, argv[1], argv[2]);
	printf ("%d\n", s);
	return 0;
}
