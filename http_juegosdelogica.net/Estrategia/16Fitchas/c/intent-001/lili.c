#include "lib16.h"
/*
Llegenda
	SA	Struct active
	SPF	Struct pasive first
	SPE	Struct pasive end
	ST	Struct temporal
	iM	i for the mutations
	shA	short int active
	shT	short int temporal
	lM	list of mutation
	lA	list All

	newS	Funcio per a crear una nova structura
*/



int main (void)
{
	init16 ();
	unsigned int level = 0, iM, contador = 0;
	struct lista * SA, * SPFirst, * SPEnd, *ST;
	unsigned short int shA, shT;

	SPFirst = newS ( 16282, contador );


	do
	{
		SA = SPFirst;
/* Normalment aquesta sobraria per la versio del futur SPFirst = NULL; */
		SPFirst = NULL;
		level++;

/* El codi el intento fer el mes proxim al dibuix */
		do
		{
			shA = SA->element;

			for (iM = 0; iM < sizeMutation; iM++)
			{
				shT = shA ^ lM [ iM ];
				if ( shT )
					if ( ! lA [ shT ] )
					{
						lA [ shT ] = shA;
						contador++;

/* Add SP, aqui es el punt clau per afegir o no el codi del futur */
				//		SPF = newS ( shT, contador ); /* canvi, ja que se repetie en els dos cassos */ he detectat que no funciona com volia ;)
						if (SPFirst)
						{
/* Seria facilment millorable, ja que un va seguit de l'altre, no necessitariem estructures amb punters ' sobren les estructures ' */
							ST = SPEnd;
							SPEnd = newS ( shT, contador );
							ST->next = SPEnd;
						} else
						{
							SPEnd = newS ( shT, contador );
							SPFirst = SPEnd;
						}
					}
				else
				{
					printf ("Finish game al nivell %d\n i trobats %d\n", level, contador);
					exit (0);
				}
			}

			SA = SA->next;
		} while ( SA );
	} while ( SPFirst );

printf ("No ha trobat solucio, el més probable es que no existeixi\n");
end16 ();
return 0;
}
