#include <stdio.h>
#include <string.h>

#include "../concret/concret.h"

int main (int argc, char *argv[])
{
	if (argc != 2) return 1;

	printf ("%d\n",
	preguntar_maxim (strlen (argv[1]), argv[1]));

	return 0;
}

