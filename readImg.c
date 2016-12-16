#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void readImgFormat(FILE *img)
{
	char formatChain[3];

	positionCursor(img);

	fgets(formatChain, 3, img); //lecture du format du pbm.

	formatChain[2] = '\0';

	if(strcmp(formatChain, "P1") != 0) //erreur format inconnu.
	{
		printf("ERROR: Unknown pbm format %s.", formatChain);
		exit(-1);
	}
}

void readImgSize(FILE *img, Coordinates *imgSize)
{
	positionCursor(img);

	fscanf(img, "%d", &imgSize->x);

	positionCursor(img);

	fscanf(img, "%d", &imgSize->y); //récupérer les coordonnées pour les mettres dans imgSize.
}

void readImgPixels(FILE *img, Coordinates const imgSize, int imgPixel[imgSize.x][imgSize.y])
{
	Coordinates i;

	for(i.y = 0; i.y < imgSize.y; i.y++)
	{
		for(i.x = 0; i.x < imgSize.x; i.x++)
		{
			positionCursor(img);

			fscanf(img, "%d", &imgPixel[i.x][i.y]); //mettre les valeurs binaires dans le tableau.
		}
	}
}

void positionCursor(FILE *img)
{
	int charRead;

	charRead = fgetc(img);

	while(charRead == '#' || charRead == '\n' || charRead == ' ') //tant que le caractère lu est # \n ou space, avancer d'un caractère.
	{
		if(charRead == '#')
		{
			while (charRead != '\n')
			{
				charRead = fgetc(img); //si un # est détecté, aller jusqu'à la prochaine ligne.
			}
		}

		charRead = fgetc(img);
	}

	fseek(img, -1, SEEK_CUR); //reculer d'un caractère.
}
