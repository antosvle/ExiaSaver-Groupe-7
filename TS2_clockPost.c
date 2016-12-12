#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



char* BMPchange(char heure[],int indic)
/* Cette fonction prend l'heure et l'indicateur envoyer. Elle prend ensuite
le chiffre correspondant et rajoute '.pbm' a celui-ci.*/
{
	char*item = NULL;
	item = malloc((strlen(heure)+1)*sizeof(char));

	sprintf(item, "%c", heure[indic]);
	strcat(item, ".pbm");

	return item;
	free(item);
}





void clockPost(char heure[])
{
	char *un, *deux, *trois, *quatre, *cinq, *six;


	/* Le bloc suivant permet de decomposer chiffre par chiffre l'heure,
	pour ensuite placer ce chiffre dans une chaine de caractere avec '.pbm'.
	Cette action permet de stocker dans des chaines de caractere tout les fichiers
	necessaire pour afficher l'heure en pbm, qu'importe celle-ci.*/
	un=BMPchange(heure, 0);
	printf("%s  ", un);

	deux=BMPchange(heure, 1);
	printf("%s  ", deux);

	trois=BMPchange(heure, 3);
	printf("%s  ", trois);

	quatre=BMPchange(heure, 4);
	printf("%s  ", quatre);

	cinq=BMPchange(heure, 6);
	printf("%s  ", cinq);

	six=BMPchange(heure, 7);
	printf("%s\n", six);

	//char taille[];
	//taille=getenv("EXIASAVER2_TAILLE");
	//printf("%c\n", taille );

}