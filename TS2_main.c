#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "TS2_Fheader.h"

void main()
{
	char *heure=NULL;
	heure = timeLoader();
	//printf("%s\n", heure);

	int i, temps;
	temps = atoi(getenv("EXIASAVER2_SLEEP"));
	// getenv permet de chercher la valeur stocker dans une variable environnement.
	// Cependant, cette valeur est de type char.
	// On utilise donc atoi qui permet de transformer un char en int.
	
	printf("%s\n", heure);
	clockPost(heure);
	
	/*do
	{
		system("clear");
		clockPost(heure);
		//faire fonction pour afficher message

		for (i = 0; i < temps; i++)
		// Le for s'execute donc en fonction de EXIASAVER2_SLEEP.
		{
			//faire fonction pour afficher point
			sleep(1);
		}
	}while(1);*/


	free(heure);
}	