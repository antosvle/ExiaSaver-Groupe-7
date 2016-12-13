#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void readImgFormat(FILE *img, int *formatId)
{
	char formatChain[3];

	positionCursor(img);

	fgets(formatChain, 3, img);

	formatChain[2] = '\0';

	if(strcmp(formatChain, "P1") == 0)
	{
		*formatId == 0;
	}
	else
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

	fscanf(img, "%d", &imgSize->y);
}

void readImgPixels(FILE *img, Coordinates *imgSize, int imgPixel[imgSize->x][imgSize->y])
{
	Coordinates i;

	for(i.y = 0; i.y < imgSize->y; i.y++)
	{
		for(i.x = 0; i.x < imgSize->x; i.x++)
		{
			positionCursor(img);

			fscanf(img, "%d", &imgPixel[i.x][i.y]);
		}
	}
}

void positionCursor(FILE *img)
{
	int charRead;

	charRead = fgetc(img);

	while(charRead == '#' || charRead == '\n' || charRead == ' ')
	{
		while(charRead == '#')
		{
			while (charRead != '\n')
			{
				charRead = fgetc(img);
			}
		}

		charRead = fgetc(img);
	}

	fseek(img, -1, SEEK_CUR);
}
