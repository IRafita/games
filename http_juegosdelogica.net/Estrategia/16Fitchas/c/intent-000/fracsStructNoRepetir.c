#include "lib16.h"


int main (void)
{
	init16 ();
	int i, imut, contador = 0;
	unsigned short int shortInput = 0x8421, shortActiu, shortTmp;

/*	for (i = 0; i < sizeMutacions; i++) Comprovant el seu bon funcionament del init16
	{
		printf ("Mutacio %d\n", i);
		output ( listMutation[i] );
	}*/

	struct cosElemental * StructActiu, * StructPasiuPrimer, * StructPasiuFinal, * StructTmp;

	StructPasiuPrimer = newCosElemental (shortInput);
	listAll[0] = 3; /* CACA, vigilar amb aixo, ara no busco resultat, ara nomes investigo que passa */

	for (i = 0; i < 10; i++)
	{
		if (!StructPasiuPrimer) break; /* petit sistema de seguretat */

		StructActiu = StructPasiuPrimer;
		StructPasiuPrimer = NULL;
		shortActiu = StructActiu->element;

		do
		{
			for (imut = 0; imut < sizeMutacions; imut++)
			{
				shortTmp = shortActiu ^ listMutation[imut];
				if (!listAll[shortTmp] && shortTmp)
				{
					contador++;
					listAll[shortTmp] = shortActiu; /* Per enmagatzemar que em fet fins ara */

					if (StructPasiuPrimer)
					{
						StructTmp = StructPasiuFinal;
						StructPasiuFinal = newCosElemental (shortTmp);
						StructTmp->next = StructPasiuFinal;
					} else
					{
						StructPasiuFinal = newCosElemental (shortTmp);
						StructPasiuPrimer= StructPasiuFinal;
					}
				}
			}
			StructActiu = StructActiu->next;
			printf ("Em llegit %d\n", contador);
		} while (StructActiu);
		printf ("Em llegit %d\n", contador);
	}
	printf ("Em llegit %d\n", contador);

end16 (); return 0;
}
