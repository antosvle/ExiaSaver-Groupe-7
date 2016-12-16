#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include "fonctions.h"

void launchStatic(int argc, char *argv) //Execute le screenSaver statique en lui envoyant les bons paramètres.
{
	int k;
	char img[10]; // creation d'un chaine de caractere de taille 10
	char cheminStatic[100]; // creation d'un chaine de caractere de taille 100
	strcpy(cheminStatic, getenv ("EXIASAVER1_PBM")); // copie du chemin d'acces des fichiers PBM de l'economiseur 1 dans cheminStatic
	strcat(cheminStatic, "/"); //ajoute un"/" à la chaine cheminStatic
	char imgWay[100]; // creation d'un chaine de caractere de taille 100

	for(k=0; k<100; k++){imgWay[k]=0;} // initialise notre chaine de caractere imgWay

	pid_t f;
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
		kill(0, SIGTERM); //tue le processus fils
		system("clear"); // vide la console
		perror ("wait"); // renvoit une erreur système si probleme detecté
	}
	else // processus fils
	{
		countFiles(imgWay); // fonction qui compte le nombre de fichiers pbm dans un répertoire et squi renvoit le nom d'un fichier dans un pointeur
		strcat (cheminStatic, imgWay); // ajoute le nom de l'image dans la chaine de caractere cheminStatic
		system("clear"); //vide la console
	}

	writeStats('s', imgWay, 0, 0);
	char ExeWay[100]; // creation d'un chaine de caractere de taille 100
	strcpy(ExeWay, getenv ("EXIASAVER_HOME")); // copie du chemin d'acces de l'executable statique de l'economiseur 1 dans ExeWay
	strcat(ExeWay, "/termSaver1/termSaver1"); // on ajoute /termSaver1 à la fin de la chaine de caractere ExeWay
	execl(ExeWay, "termSaver1", cheminStatic, NULL); // exécute l'économiseur d'écran statique facon 1
	perror("execl"); // renvoit une erreur système si probleme detecté
	exit(0);

}

void launchDyna(int argc, char *argv) //Execute le screenSaver dynamique en lui envoyant les bons paramètres.
{
	writeStats('d', "z", 5, 3);
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
	strcpy(cheminInter, getenv ("EXIASAVER3_PBM")); // copie du chemin d'acces des fichiers PBM de l'economiseur 3 dans cheminInter
	strcat(cheminInter, "/"); //ajoute un"/" à la chaine cheminStatic
	char ExeWay[100]; // creation d'un chaine de caractere de taille 100
	strcpy(ExeWay, getenv ("EXIASAVER_HOME")); // copie du chemin d'acces de l'executable statique de l'economiseur 3 dans ExeWay
	strcat(ExeWay, "/termSaver3/termSaver3"); // on ajoute /termSaver3 à la fin de la chaine de caractere ExeWay
	execl(ExeWay, "termSaver3", cheminInter, "10", "10",NULL); // exécute l'économiseur d'écran dynamic
	perror("execl"); // renvoit une erreur système si probleme detecté
	writeStats('i', "z", 10, 10);
	exit(0);
}