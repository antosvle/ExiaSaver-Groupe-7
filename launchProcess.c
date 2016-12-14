#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

void launchStatic(int argc, char *argv) //Execute le screenSaver statique en lui envoyant les bons paramètres.
{

	int option;
	char cheminStatic[100]; // creation d'un chaine de caractere de taille 100
	strcpy(cheminStatic, getenv ("EXIASAVER1_PBM")); // copie du chemin d'acces des fichiers PBM de l'economiseur 1 dans cheminStatic

	if(argc < 3) // si il y a 1 ou 2 arguments 
    {
        option = rand() % 5; // choisit un nombre aleatoire entre 0 et 4
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
			strcat(cheminStatic, "/debian.pbm"); // on ajoute /debian.pbm à la fin de la chaine de caractere cheminStatic
            break;
        case 4:
			strcat(cheminStatic, "/mario.pbm"); // on ajoute /mario.pbm à la fin de la chaine de caractere cheminStatic
            break;
    }

    if(argc == 3) // si il y a 3 arguments
    {
	    if (strcmp(argv, "cesi.pbm") == 0 ) // si il y a 3 arguments et que la chaine est cesi.pbm alors
	    {
	        strcat(cheminStatic, "/cesi.pbm"); // on ajoute /cesi.pbm à la fin de la chaine de caractere cheminStatic
	    }
	    else if (strcmp(argv, "coeur.pbm") == 0 ) // si il y a 3 arguments et que la chaine est coeur.pbm alors
	    {
	    	strcat(cheminStatic, "/coeur.pbm"); // on ajoute /coeur.pbm à la fin de la chaine de caractere cheminStatic
	    }
	    else if (strcmp(argv, "voiture.pbm") == 0 ) // si il y a 3 arguments et que la chaine est voiture.pbm alors
	    {
	    	strcat(cheminStatic, "/voiture.pbm"); // on ajoute /voiture.pbm à la fin de la chaine de caractere cheminStatic
	    }
	    else if (strcmp(argv, "debian.pbm") == 0 ) // si il y a 3 arguments et que la chaine est debian.pbm alors
	    {
	    	strcat(cheminStatic, "/debian.pbm"); // on ajoute /debian.pbm à la fin de la chaine de caractere cheminStatic
	    }
	    else if (strcmp(argv, "mario.pbm") == 0 ) // si il y a 3 arguments et que la chaine est mario.pbm alors
	    {
	    	strcat(cheminStatic, "/mario.pbm"); // on ajoute /mario.pbm à la fin de la chaine de caractere cheminStatic
	    }
            
	}

	system ("clear"); // vide la console

	char ExeWay[100]; // creation d'un chaine de caractere de taille 100
	strcpy(ExeWay, getenv ("EXIASAVER_HOME")); // copie du chemin d'acces de l'executable statique de l'economiseur 1 dans ExeWay
	/*pid_t f;
	f=fork(); // fonction permettant de créer le processus fils
	if (f == -1)
	{
		printf ("Error : the processus can't be created\n"); // On envoit un message d'erreur
		perror("fork"); // renvoit une erreur système si probleme detecté
		exit (-1); // on quitte le programme
	}
	else if(f != 0) // processus père
	{
		wait(NULL); // attend la fin du processus fils
		perror ("wait");
	}
	else
	{*/

		/*argv[0]="termSaver1"; // utiliser ses arguments pour execv ou execl facon 2
		argv[1]=cheminStatic;
		argv[2]="80";
		argv[3]="24";
		argv[4]=NULL;*/
		
		strcat(ExeWay, "/termSaver1/termSaver1"); // on ajoute /termSaver1 à la fin de la chaine de caractere ExeWay
		//printf("%s\n%s\n", cheminStatic, ExeWay);//imprime le chemin de l'image puis celui de l'executable pour info
		execl(ExeWay, "termSaver1", cheminStatic, "80", "24", NULL); // exécute l'économiseur d'écran statique facon 1
		//execl(ExeWay, argv[0], argv[1], argv[2], argv[3], NULL); // exécute l'économiseur d'écran statique facon 2
		//execv(ExeWay, argv); // exécute l'économiseur d'écran statique facon 3
		//perror("execv"); // renvoit une erreur système si probleme detecté
		perror("execl"); // renvoit une erreur système si probleme detecté
		exit(0);
	//}

}

void launchDyna(int argc, char *argv) //Execute le screenSaver dynamique en lui envoyant les bons paramètres.
{
	char cheminDynamic[100]; // creation d'un chaine de caractere de taille 100
	strcpy(cheminDynamic, getenv ("EXIASAVER1_PBM")); // copie du chemin d'acces des fichiers PBM de l'economiseur 2 dans cheminDynamic
	char ExeWay[100]; // creation d'un chaine de caractere de taille 100
	strcpy(ExeWay, getenv ("EXIASAVER_HOME")); // copie du chemin d'acces de l'executable statique de l'economiseur 2 dans ExeWay
	strcat(ExeWay, "/termSaver2/termSaver2"); // on ajoute /termSaver2 à la fin de la chaine de caractere ExeWay
	execl(ExeWay, "termSaver2", cheminDynamic, NULL); // exécute l'économiseur d'écran dynamic
	perror("execl"); // renvoit une erreur système si probleme detecté
	exit(0);
}

void launchInter(int argc, char *argv) //Execute le screenSaver interactif en lui envoyant les bons paramètres.
{
	char cheminInter[100]; // creation d'un chaine de caractere de taille 100
	strcpy(cheminInter, getenv ("EXIASAVER1_PBM")); // copie du chemin d'acces des fichiers PBM de l'economiseur 3 dans cheminInter
	char ExeWay[100]; // creation d'un chaine de caractere de taille 100
	strcpy(ExeWay, getenv ("EXIASAVER_HOME")); // copie du chemin d'acces de l'executable statique de l'economiseur 3 dans ExeWay
	strcat(ExeWay, "/termSaver3/termSaver3"); // on ajoute /termSaver3 à la fin de la chaine de caractere ExeWay
	execl(ExeWay, "termSaver3", cheminInter, NULL); // exécute l'économiseur d'écran dynamic
	perror("execl"); // renvoit une erreur système si probleme detecté
	exit(0);
}

/*void readStats(); //Lit le fichier "history.txt" et l'affiche à l'écran.
{s
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
*/
