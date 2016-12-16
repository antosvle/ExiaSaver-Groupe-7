#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	Coordinates consoleSize;
    Coordinates imgSize[4];

    Coordinates planePosition;

    Direction i; //création de i pouvant prendre 

	char planePath[256]; //création d'une chaine de caractère

    int imgPixel[4][6][6]; //création de 4 tableaux bi-dimensionnels pouvant contenir des données binaires d'une image pbm.

    int cnt; //cnt est un compteur.

    planePosition.x = atoi(argv[2]);
    planePosition.y = atoi(argv[3]); //attribution des coordonnées initiales de l'avion à planePosition.

	captureConsoleSize(&consoleSize); //fonction cherchant la taille de la console.

	if(planePosition.x > consoleSize.x || planePosition.x < 0 ||  planePosition.y > consoleSize.y || planePosition.y < 0) //erreur si la position initiale de l'avion  sont hors du terminal.
	{
		printf("ERROR: Plane position is out of console size.");
		exit(-1);
	}

	FILE* img = NULL; //création d'une variable pointant ensuite dans un fichier.

	for(cnt = 0; cnt < 4; cnt++) //répétition de l'ouverture d'une image 4 fois, l'image changeant grâce à la variable cnt.
	{
		strcpy(planePath, argv[1]);

		switch(cnt) //ajout du nom de l'image à planePath.
		{
			case 0:
				strcat(planePath, "plane_up.pbm");
				break;
			case 1: 
				strcat(planePath, "plane_right.pbm");
				break;
			case 2:
				strcat(planePath, "plane_down.pbm");
				break;
			case 3:
				strcat(planePath, "plane_left.pbm");
				break;
		}

		img = fopen(planePath , "r"); //ouverture de l'image pbm.

	 	if (img == NULL) //erreur si impossible d'ouvrir une image pbm.
	    {
	        printf("ERROR: unable to open %s (inexisting file ?).", planePath);
	        exit(-1); 
	    }


	   	readImgFormat(img); //lis le format des pbm.

		readImgSize(img, &imgSize[cnt]); //lis la taille des pbm.

		readImgPixels(img, imgSize[cnt], imgPixel[cnt]); //lis les pixels de l'avion pour les écrire dans le tableau imgPixel[cnt].
	}

	Frame imgFrame; //création de imgFrame, contenant le cadre de l'avion.

    i = RIGHT; //initialisation de i.

    while(1)
    {
    	moveImg(i, consoleSize, &planePosition); //Fonction faisant bouger l'avion en fonction de la direction i.

		frameImg(consoleSize, planePosition, &imgFrame); //Fonction cadrant l'avion en fonction de son emplacement.

		system("clear"); //nettoyage du terminal.

		printImg(consoleSize, imgFrame, imgPixel[i]); //affichage de l'image.

		fflush(stdout);
		sleep(0.5); //attente de 0.5 secondes avant de faire bouger l'avion.

		changeDirection(&i); //Fonction changeant la valeur de i si l'utilisateur appuie sur Z Q S D.
    }

	return 0;
}
