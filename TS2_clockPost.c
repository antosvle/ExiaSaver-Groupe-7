#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TC 50
#define Colonne 40
#define Ligne 7


char* PBMchange(char heure[],int indic);






void clockPost(char heure[])
{
	/* Ce bloc permet de recupérer la direction du repertoire des fichiers pbm
	stocké dans une variable d'environnement. On peut donc modifier a tout instant 
	cette variable pour changer de dossier.*/
	char repertoire[TC];
	strcpy(repertoire, getenv("EXIASAVER2_PBM"));
	strcat(repertoire, "/");



	/* Le bloc suivant permet de decomposer chiffre par chiffre l'heure,
	pour ensuite placer ce chiffre dans une chaine de caractere avec '.pbm' precede du
	chemin d'acces du fichier.
	Cette action permet de stocker dans des chaines de caractere tout les fichiers
	necessaire pour afficher l'heure en pbm, qu'importe celle-ci.*/
	char point [TC], un[TC], deux[TC], trois[TC], quatre[TC], cinq[TC], six[TC];

	strcpy(un, repertoire); strcat(un, PBMchange(heure, 0)); //Premier chiffre
	strcpy(deux, repertoire); strcat(deux, PBMchange(heure, 1)); //Deuxieme chiffre
	strcpy(trois, repertoire); strcat(trois, PBMchange(heure, 3)); //Troisieme chiffre
	strcpy(quatre, repertoire); strcat(quatre, PBMchange(heure, 4)); //Quatrieme chiffre
	strcpy(cinq, repertoire); strcat(cinq, PBMchange(heure, 6)); //Cinquieme chiffre
	strcpy(six, repertoire); strcat(six, PBMchange(heure, 7)); //Sixieme chiffre
	//L'heure a pour format HH:MM:SS, c'est pourquoi on passe la case 2 et 5 de la chaine.
	strcpy(point, repertoire); strcat(point, "point.pbm");


	char* tableauChiffre[8]={un, deux, point, trois, quatre, point, cinq, six};


	/**/
	int count = 0, x, y;
	char affichage[Ligne][Colonne];

	for(x=0; x<Ligne; x++)
	{
		for(y=0; y<Colonne; y++)
		{
			affichage[x][y] = ' ';
		}
	}





	int a = 0, b = count, i, caractere;

	for(i=0; i<8; i++)
	{
		//printf("%s\n",tableauChiffre[i] );

		a = 0;
		b = 0;
		FILE* pbm = NULL;
		pbm = fopen(tableauChiffre[i], "r");

		if(pbm != NULL)
		{
			fseek(pbm, -35, SEEK_END);
			do
			{
				caractere = fgetc(pbm);
				if(caractere == '1')
				{
					affichage[a][b + count]='#';
					b++;
					fgetc(pbm);
				}
				else if(caractere == '0')
				{
					affichage[a][b + count]=' ';
					b++;
					fgetc(pbm);
				}
				else
				{
					affichage[a][b + count]=' ';
					b++;
					
				}

				if(b == 3)
				{
					a++;
					b = 0;
					fgetc(pbm);
				}

		 	} while (caractere != EOF);
			fclose(pbm);
		}

		else
		{
			printf("Error = cant open the file %s.\n", tableauChiffre[i]);
			exit(0);
		}

		switch(i)
		{
			case 0:
				count = 4;
				break;
			case 1:
				count += 3;
				break;
			case 2:
				count += 5;
				break;
			case 3:
				count += 4;
				break;
			case 4:
				count += 3;
				break;
			case 5:
				count += 5;
				break;
			case 6:
				count += 4;
				break;
			case 7:
				count += 3;
				break;
		}

	}
	
	for(x=0; x<Ligne; x++)
	{
		for(y=0; y<Colonne; y++)
		{
			printf("%c", affichage[x][y]);
		}
		printf("\n");
	}
}















char* PBMchange(char heure[],int indic)
/* Cette fonction prend l'heure et l'indicateur envoyer. Elle prend ensuite
le chiffre correspondant et rajoute '.pbm' a celui-ci.*/
{
	char*item = NULL;
	item = malloc(sizeof(char));

	sprintf(item, "%c", heure[indic]);
	strcat(item, ".pbm");

	return item;
	free(item);
}
