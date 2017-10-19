#include <stdlib.h>
#include <string.h>

int preguntar_maxim (int l, char *p)
{
	int n =1, d =1; // numerador denominador
	int s = 1;	// solució
	int i;
	char c = p[0];

	for (i = 1; i < l; i++)
	{
		s *= ++n;

		if (c == p[i]) s /= ++d;
		else
		{
			d=1;
			c=p[i];
		}
	}

	return s;
}

void pseudo_elimina (char *p, int r)
{
	char c = p[r];

	memcpy (p +1, p, r);
	*p = c;
}

int quies (int l, char *p, char *o)
{
	size_t v = 0, P, I;
	char *c;

	while (strcmp(p,o))
	{
		P = preguntar_maxim (l, o);
		c = strchr (o, *p);
		I = c - o;
		pseudo_elimina (o, I);

		v += (I*P)/l--;
		p++; o++;
	}
	return v;
}
