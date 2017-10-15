#include <stdio.h>
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

int evaluar_e (int l, char *p)
{ return preguntar_maxim (l, p)/l; }

int troba_valor_representatiu (int i, char *p)
{
	char c = p[i];

	while ( i-- )
		if (p[i] != c)
			return i +1;

	return 0;
}

void pseudo_elimina (char *p, int r)
{
	char c = p[r];

	memcpy (p +1, p, r);
	*p = c;
}

int min (int a, int b)
{
	if (a < b) return a;
	return b;
}

/**
 * l longitud de p
 * p ordenat per a que funcioni
 * v valor que vols que mostr
 */
void concret (int l, char *p, int v)
{
	int e, r;
char* t=p;

	while (v && l)
	{
		// Parxe pel cas 0011 2
		//e = evaluar_e (l--, p); // Poden haver fraccions!
		e = preguntar_maxim (l, p);
		//r = troba_valor_representatiu ( v/e, p);
		r = troba_valor_representatiu ( (v*l)/e, p);
		//v-= r * e; // evitar fraccions!
		v-= (r*e)/l--;
		pseudo_elimina (p++, r);
//printf ("e: %d i: %d r: %d v: %d t: %s a: %s l: %d\n", e, v/e, r, v, p, t, l);
	}
}
