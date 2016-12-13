#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "TS2_Fheader.h"

void main()
{
	int i, temps;
	temps = atoi(getenv("EXIASAVER2_SLEEP"));
	printf("%d\n", temps);
	// getenv permet de chercher la valeur stocker dans une variable environnement.
	// Cependant, cette valeur est de type char.
	// On utilise donc atoi qui permet de transformer un char en int.
	
	//clockPost(heure);
	
	while(1)
	{
		system("clear");
		clockPost(timeLoader());
		system("sleep 1");
		//faire fonction pour afficher message

		/*for (i = 0; i < temps; i++)
		// Le for s'execute donc en fonction de EXIASAVER2_SLEEP.
		{

			//faire fonction pour afficher point
			system("sleep 1");
			printf(".");
		}*/
	}


}	