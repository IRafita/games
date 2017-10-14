#include <stdio.h>
#include <string.h>

#include "ordenar.h"

int main (int argc, char *argv[])
{
	if (argc == 1) return 1;
	ordenar (strlen (argv[1]), argv[1]);
	printf ("%s\n", argv[1]);
	return 0;
}
