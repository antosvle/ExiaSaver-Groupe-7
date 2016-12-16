#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	Coordinates consoleSize, imgSize; //variables coordonnées contenant des tailles x, y.

	captureConsoleSize(&consoleSize, imgSize); //fonction stockant la taille de la console dans consoleSize.

	pid_t pid; //variable contenant un pid.

	FILE* img = NULL; //pointeur vers un fichier.

	img = fopen(argv[1] , "r"); //ouverture de l'image pbm envoyée en argument.

 	if (img == NULL) //erreur si échec de l'ouverture de l'image.
    {
        printf("ERROR: Impossible to open %s (inexisting file ?).", argv[1]);
        exit(-1); 
    }

    readImgFormat(img); //lis le format du pbm

	readImgSize(img, &imgSize); //lis la taille du pbm.

    int imgPixel[imgSize.x][imgSize.y]; //créer un tableau de la taille du pbm.

	readImgPixels(img, imgSize, imgPixel); //rempli le tableau avec les données binaires de l'image.

    fclose(img); //ferme le fichier image.

    Frame imgFrame; //variable contenant un cadre

    int continuee; //variable servant )à arrêter le programme.

    continuee = 1;

	pid = fork(); //création d'un processus fils

	if(pid == -1)
	{
		printf("ERROR: Failure to create a new process."); //erreur en cas d'échec processus fils.
		exit(-1);
	}
	else if(pid ==  0)
	{
		getch(); //attend que l'utilisateur tape sur son clavier.

		kill(0, SIGTERM); //tue le processus dans la boucle infinie.
	}
	else
	{
		while(continuee)
		{
			switch(captureConsoleSize(&consoleSize, imgSize))
			{
				case -1:
					continuee = 0; //arrête la boucle si l'image est plus petite que la console.
					break;
				case 1:
					system("clear"); //nettoye le terminal visible.
					
					centerImg(imgSize, consoleSize, &imgFrame); //créer un cadre centrant l'image.
					
					printImg(consoleSize, imgSize, imgFrame, imgPixel); //affiche l'image sur la console.

					break;
			}

			fflush(stdout);
			sleep(1); //attend une seconde avant de répéter la boucle.
		}
	}

	return 0;
}
