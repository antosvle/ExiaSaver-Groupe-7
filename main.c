#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	Coordinates consoleSize;

	consoleSize.x = atoi(argv[2]);
	consoleSize.y = atoi(argv[3]);

	FILE* img = NULL;

	img = fopen(argv[1] , "r");

 	if (img == NULL)
    {
        printf("ERROR: Impossible to open %s (inexisting file ?).", argv[1]);
        exit(-1); 
    }

    int format;

    readImgFormat(img, &format);

    Coordinates imgSize;

	readImgSize(img, &imgSize);

	if(imgSize.x > consoleSize.x || imgSize.y > consoleSize.y)
	{
		printf("ERROR: Image %s is too large for this console.", argv[1]);
		exit(-1);
	}

    int imgPixel[imgSize.x][imgSize.y];

	readImgPixels(img, &imgSize, imgPixel);

    fclose(img);

    Frame imgFrame;

	centerImg(&imgSize, &consoleSize, &imgFrame);

	printImg(&consoleSize, &imgSize, &imgFrame, imgPixel);

	return 0;
}
