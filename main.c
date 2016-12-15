#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	Coordinates consoleSize, imgSize;

	captureConsoleSize(&consoleSize);

	pid_t pid;

	FILE* img = NULL;

	img = fopen(argv[1] , "r");

 	if (img == NULL)
    {
        printf("ERROR: Impossible to open %s (inexisting file ?).", argv[1]);
        exit(-1); 
    }

    readImgFormat(img);

	readImgSize(img, &imgSize);

	captureConsoleSize(&consoleSize, imgSize);

    int imgPixel[imgSize.x][imgSize.y];

	readImgPixels(img, imgSize, imgPixel);

    fclose(img);

    Frame imgFrame;

    int continuee;

    continuee = 1;

	pid = fork();

	if(pid == -1)
	{
		printf("ERROR: Failure to create a new process.");
		exit(-1);
	}
	else if(pid ==  0)
	{
		getch();

		kill(0, SIGTERM);
	}
	else
	{
		while(continuee)
		{
			switch(captureConsoleSize(&consoleSize, imgSize))
			{
				case -1:
					continuee = 0;
					break;
				case 1:
					system("clear");
					
					centerImg(imgSize, consoleSize, &imgFrame);
					
					printImg(consoleSize, imgSize, imgFrame, imgPixel);

					break;
			}

			fflush(stdout);
			sleep(1);
		}
	}

	return 0;
}
