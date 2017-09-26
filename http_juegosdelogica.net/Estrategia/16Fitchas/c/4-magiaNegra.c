#include "lib16Fitxes.h"

/*
aixo nomes sera per descobrir fins a quin percentatje podem combrir amb nomes 10 paces :)
*/

/* Aquesta funcio tant rara, ja que sino no em permitia que els punters funcionessin adequadament */
struct fitxes16 *
newFitxes16 (n)
short int n;
{
	struct fitxes16 t, *o;
	t.matriu	= n;
	o = &t;
	return o;
}


int main ()
{
	int voltesRestants, digMut, trobats;
	unsigned short int tmpMatrix; /* ja que fa crides a un vector i ser negatiu es critic */
	struct fitxes16 *iniciF16, *seguentI16F, *seguentF16F, *tmp16Fitxa;

	init16Fitxes ();

/* aqui anira el codi */

	iniciF16 = newFitxes16 (0);
	iniciF16->next		= 0;
	listTrobats[0]		= 1;

	seguentI16F = newFitxes16 (0);
	seguentF16F = newFitxes16 (0);
	seguentI16F->next	= 0;
	seguentF16F->next	= 0;

	voltesRestants = 10; trobats = 0;

/* S'ha de tenir en compte que aixo es per anar abansant de del matriu = 0 */
	while (voltesRestants--)
	{
		do
		{
			for (digMut = 0; digMut < sizeMutacions; digMut++)
			{
				tmpMatrix = iniciF16->matriu ^ listMutation[digMut];
				if (!listTrobats[tmpMatrix])
				{
					trobats++; /* em trobat un nou element */
					if (seguentI16F->next == seguentF16F->next)
					{/* entrar aqui nomes es al inici de tot */
						if (seguentI16F->next)
						{/* segona entrada */
							seguentF16F->matriu = tmpMatrix;
							seguentF16F->next = 0;
						} else
						{/* primera entrada */ /* amb mes coneixement treuria aixo del while inicial */
							seguentI16F->matriu = tmpMatrix;
							seguentI16F->next = seguentF16F;
							seguentF16F->next = seguentF16F;
						}
					}
					else
					{ /* cas general */
						tmp16Fitxa = newFitxes16 (tmpMatrix);
						tmp16Fitxa->next = 0;
						seguentF16F->next = tmp16Fitxa;
						seguentF16F = tmp16Fitxa;
					}
				}
			}

			/* ja em sortit del for per fer totes les possibles mutacions */
			if (iniciF16->next)
			{
				iniciF16 = iniciF16->next;
			}else
			{
				iniciF16 = NULL;
			}
		}
		while (iniciF16);
		iniciF16 = seguentI16F;
		seguentI16F->next = 0;
		seguentF16F->next = 0;
		printf ("Voltes %d\t\tTrobats %d\n", voltesRestants, trobats);
	}

end16Fitxes ();
return 0;
}
