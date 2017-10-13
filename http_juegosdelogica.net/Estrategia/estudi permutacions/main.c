#include <stdio.h>
#include <string.h>

#include "next.h"

int main (int argc, char *argv[])
{
	int i;
	i = next (strlen (argv[1]), argv[1]);
	printf ("%s\n", argv[1]);
	return 0;
}
