#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{
    if(argc > 3) // nombre d'aguments suppérieur à 3
    {
        printf("ERROR: Too many arguments\n"); // affiche une erreur
        exit(-1); // quitte le programme
    }

    int option;

    srand(time(NULL)); // initialisation de la generation aleatoire

    if(argc == 1) // nombre d'aguments égale a 1
    {
        option = rand() % 3; // genere un nombre aleatoire
    }
    else
    {
        option = idArg1(argv[1]); // fonction qui est utilisé lorsqu'on rentre un 2eme argument lors de l'exécution du ScreenSaver
    }

    switch(option)
    {
        case 0:
            launchStatic(argc, argv[2]); //Execute le screenSaver statique en lui envoyant les bons paramètres.
            break;
        case 1:
            launchDyna(argc, argv[2]); //Execute le screenSaver dynamique en lui envoyant les bons paramètres.
            break;
        case 2:
            launchInter(argc, argv[2]); //Execute le screenSaver interactif en lui envoyant les bons paramètres.
            break;
        case 3:
            readStats(); //Lit le fichier "history.txt" et l'affiche à l'écran.
            break; 
    }

    return 0;
}