#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idArg1(char *option) // fonction qui est utilisé lorsqu'on rentre un 2eme argument lors de l'exécution du ScreenSaver
{
    if(strcmp(option, "-static") == 0) // si strcmp detecte -static alors il revoit 0
    {
        return 0; //revoit la valeur 0 au main
    }
    else if(strcmp(option, "-dyna") == 0) // si strcmp detecte -dyna alors il revoit 1
    {
        return 1; //revoit la valeur 1 au main
    }
    else if(strcmp(option, "-inter") == 0) // si strcmp detecte -inter alors il revoit 2
    {
        return 2; //revoit la valeur 2 au main
    }
    else if(strcmp(option, "-stats") == 0) // si strcmp detecte -stats alors il revoit 3
    {
        return 3; //revoit la valeur 3 au main
    }
    else
    {
        printf("ERROR: Unknown argument (argument 2)\n"); // affiche une erreur si l'argument est invalide
        exit(-1); // on quitte le programme
    }
}