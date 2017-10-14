#include <string.h>
#include <stdlib.h>

int compara_chars (const void *a, const void *b)
{ return *(char *)a-*(char *)b; }

void ordenar (int l, char *p)
{ qsort (p, l, sizeof(char), compara_chars); }
