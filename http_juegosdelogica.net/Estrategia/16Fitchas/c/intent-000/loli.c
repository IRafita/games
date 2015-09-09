#include "lib16.h"


/* Un gran canvi em de fer, s'ha d'entendre que necessitem una llista molt gran amb els objectes corresponents,
sino hi ha risc que ocupi el mateix espai de memoria, cosa que m'esta passant actualment */
int main (void)
{
	init16 ();
	int i, imut, contador = 0, profunditat = 0;
	unsigned short int shortInput = 0x111e, shortActiu, shortTmp;

/*	for (i = 0; i < sizeMutacions; i++) Comprovant el seu bon funcionament del init16
	{
		printf ("Mutacio %d\n", i);
		output ( listMutation[i] );
	}*/

	struct cosElemental * StructActiu, * StructPasiuPrimer, * StructPasiuFinal, * StructTmp;

	StructPasiuPrimer = newCosElemental (contador, shortInput);
	listAll[shortActiu] = 3; /* CACA, vigilar amb aixo, ara no busco resultat, ara nomes investigo que passa */

	for (i = 0; i < 10; i++)
	{
	profunditat++;
		if (!StructPasiuPrimer) break; /* petit sistema de seguretat */

		StructActiu = StructPasiuPrimer;/* Me pregunto fins a quin punt es legal fer aixo */
		StructPasiuPrimer = NULL;
		shortActiu = StructActiu->element;

		do
		{
			for (imut = 0; imut < sizeMutacions; imut++)
			{
				shortTmp = shortActiu ^ listMutation[imut];
				if (shortTmp)
				{
					if (!listAll[shortTmp])
					{
						contador++;
						listAll[shortTmp] = shortActiu; /* Per enmagatzemar que em fet fins ara */

						if (StructPasiuPrimer)
						{
							StructTmp = StructPasiuFinal;
							StructPasiuFinal = newCosElemental (contador, shortTmp);
							StructTmp->next = StructPasiuFinal;
						} else
						{
							StructPasiuFinal = newCosElemental (contador, shortTmp);
							StructPasiuPrimer= StructPasiuFinal;
						}
					}
				} else
				{
					ShowSolution (shortTmp, profunditat);
					end16 ();
					printf ("Solucio trobada\n");
					exit (0);
				}
			}
			StructActiu = StructActiu->next;
		} while (StructActiu);
		printf ("Em llegit %d\n", contador);
	}
	printf ("Em llegit %d\n", contador);

end16 (); return 0;
}
