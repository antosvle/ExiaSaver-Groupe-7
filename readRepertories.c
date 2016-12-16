#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

int countFiles(char *imgWay) // compte le nombre de fichier dnas un répertoire
{
    char list[] = "/home/EXIASAVER/static"; //chaine de caractere contenant le chemin d'accès aux images
    char img[11]; // chaine de caractère de taille 11

    int count = 0, i = 0; 

    DIR* rep = NULL; // curseur du dossier

    dirent* fileRead = NULL; // pointe un fichier lu

    rep = opendir(list); // on ouvre le répertoire rep

    srand(time(NULL)); // initialise la génération de nombre aleatoire 

    while((fileRead = readdir(rep)) != NULL)
    {
        count++; // ajoute +1 tant que la condition est vraie
    }

    rewinddir(rep); // permet de se remettre au début du répertoire

    char *file; // creéation d'un pointeur

    count = rand() % (count - 2); // génere un chiffre aléatoire

    while((fileRead = readdir(rep)) != NULL)
    {
        if(strcmp(fileRead->d_name, ".") != 0 && strcmp(fileRead->d_name, "..") != 0) // permet de ne pas tenir compte des dossiers "." et "..".
        {
            if(i == count) 
                file = fileRead->d_name; // on ajoute le nom du fichier dans file
            i++; // ajoute +1 tant que la condition est vraie
        }
    }

    //printf("Le ficher aléatoire est: %s.\n", file);

    strcpy(img, file); // on copie le nom de l'image dans la chaine de caractere img
    strcat(imgWay, img); // on ajoute le nom de l'image dans le pointeur imgWay

	if (closedir(rep) == -1) // on referme le répertoire
    {
        exit(-1); // on quitte le programme
    }

    return 0;
}