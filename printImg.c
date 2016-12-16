#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void frameImg(Coordinates const consoleSize, Coordinates const planePosition, Frame *imgFrame)
{
	imgFrame->xmin = (planePosition.x - 3) % consoleSize.x;

	imgFrame->ymin = (planePosition.y - 3) % consoleSize.y;

	imgFrame->xmax = (planePosition.x + 3) % consoleSize.x;

	imgFrame->ymax = (planePosition.y + 3) % consoleSize.y; //attribution des valeurs du carde de l'avion à imgFrame;
}

void printImg(Coordinates const consoleSize, Frame const imgFrame, int imgPixel[6][6])
{
	Coordinates i, j;

	j.x = 0;
	j.y = 0;

	for(i.y = 0; i.y < consoleSize.y; i.y++) //le double for parcourt l'ensemble du terminal visible à l'aide de i.
	{
		if(i.y < imgFrame.ymin || i.y >= imgFrame.ymax)
		{
			for(i.x = 0; i.x <= consoleSize.x; i.x++)
			{
				printf(" ");
			}
		}
		else
		{
			for(i.x = 0; i.x <= consoleSize.x; i.x++)
			{
				if(i.x < imgFrame.xmin || i.x >= imgFrame.xmax)
				{
					printf(" ");
				}
				else //si on se situe dans le carde de l'image, imprimer l'image et j parcourt l'image pbm.
				{
					if(imgPixel[j.x][j.y] == 1)
					{
						printf("\u2588");
					}
					else
					{
						printf(" ");
					}
					j.x++;
				}
			}
			j.x = 0;
			j.y++;
		}
		printf("\n");
	}
}
