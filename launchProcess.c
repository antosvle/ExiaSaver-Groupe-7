#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

void launchStatic(int argc, char *argv[]) //Execute le screenSaver statique en lui envoyant les bons paramètres.
{
	FILE* img = NULL; // initialisation du pointeur à NULL

	char cheminStatic[100]; // creation d'un chaine de caractere de taille 100
	strcpy(cheminStatic, getenv (EXIASAVER1_PBM)); // copie du chemin d'acces des fichiers PBM de l'economisateur 1 dans cheminStatic

	if(argc == 2) // si il y a 2 arguments 
    {
        option = rand() % 5; // nombre aleatoire entre 0 et 4
    }
	switch(option)
    {
        case 0:
			strcat(cheminStatic, "/cesi.pbm"); // on ajoute /cesi.pbm à la fin de la chaine de caractere cheminStatic
            break;
        case 1:
			strcat(cheminStatic, "/coeur.pbm"); // on ajoute /coeur.pbm à la fin de la chaine de caractere cheminStatic
            break;
        case 2:
			strcat(cheminStatic, "/voiture.pbm"); // on ajoute /voiture.pbm à la fin de la chaine de caractere cheminStatic
            break;
        case 3:
			strcat(cheminStatic, "/fusée.pbm"); // on ajoute /fusée.pbm à la fin de la chaine de caractere cheminStatic
            break;
        case 4:
			strcat(cheminStatic, "/mario.pbm"); // on ajoute /mario.pbm à la fin de la chaine de caractere cheminStatic
            break;
    }
    else if(arg == 3) // si il y a 3 arguments
    {
    if (strcmp(argv[3], "cesi.pbm") == 0 ) // si il y a 3 arguments et que la chaine est cesi.pbm alors
    {
        strcat(cheminStatic, "/cesi.pbm"); // on ajoute /cesi.pbm à la fin de la chaine de caractere cheminStatic
    }
    else if (strcmp(argv[3], "coeur.pbm") == 0 ) // si il y a 3 arguments et que la chaine est coeur.pbm alors
    {
    	strcat(cheminStatic, "/coeur.pbm"); // on ajoute /coeur.pbm à la fin de la chaine de caractere cheminStatic
    }
    else if (strcmp(argv[3], "voiture.pbm") == 0 ) // si il y a 3 arguments et que la chaine est voiture.pbm alors
    {
    	strcat(cheminStatic, "/voiture.pbm"); // on ajoute /voiture.pbm à la fin de la chaine de caractere cheminStatic
    }
    else if (strcmp(argv[3], "fusée.pbm") == 0 ) // si il y a 3 arguments et que la chaine est fusée.pbm alors
    {
    	strcat(cheminStatic, "/fusée.pbm"); // on ajoute /fusée.pbm à la fin de la chaine de caractere cheminStatic
    }
    else if (strcmp(argv[3], "mario.pbm") == 0 ) // si il y a 3 arguments et que la chaine est mario.pbm alors
    {
    	strcat(cheminStatic, "/mario.pbm"); // on ajoute /mario.pbm à la fin de la chaine de caractere cheminStatic
    }
            
	}

	pid_t f;
	f = fork; // fonction permettant de créer le processus fils
	if (f = -1)
	{
		printf ("Error : the processus can't be created\n") // On envoit un message d'erreur
		exit (1); // on quitte le programme
	}
	else if(f != 0) // processus père
	{
		wait(&f); // attend la fin du processus fils
	}
	else
	{
		exec (cheminStatic, argv[2]); // exécute l'économiseur d'écran statique
	}


	char *imgWay = NULL; // initialisation du pointeur à NULL
	imgWay = malloc(sizeof(char)); // allocation dynamique
	strcpy(imgWay, cheminStatic); // copie la chaine chemin static dans imgWay
	return imgWay; // envoie le chemain d'accès de l'image à termSaver1


}

void launchDyna(int argc, char *argv[]); //Execute le screenSaver dynamique en lui envoyant les bons paramètres.
void launchInter(int argc, char *argv[]); //Execute le screenSaver interactif en lui envoyant les bons paramètres.

void readStats(); //Lit le fichier "history.txt" et l'affiche à l'écran.
{
	FILE* fichier = NULL; // initialisation du pointeur à NULL

	fichier = fopen("history.txt", "r"); // ouvre le fichier txt

	if (fichierPBM == NULL) // On ne peut pas lire le fichier
    {
    	printf("File opening error \n"); // On affiche un message d'erreur 
    	exit(-1); // On quitte le programme
    }  


    fclose (fichier); // ferme le fichier txt

	return 0;
}

void writeStats(); //Écrit dans le fichier "hisory.txt".
{
	FILE* fichier = NULL; // initialisation du pointeur à NULL

	fichier = fopen("history.txt", "w"); // ouvre le fichier txt

	if (fichierPBM == NULL) // On ne peut pas ecrire dans le fichier
    {
    	printf("File opening error \n"); // On affiche un message d'erreur 
    	exit(-1); // On quitte le programme
    }  

	fclose (fichier); // ferme le fichier txt

	return 0;
}
