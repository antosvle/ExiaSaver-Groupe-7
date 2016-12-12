#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{
    if(argc > 3)
    {
        printf("ERROR: Too many arguments\n");
        exit(-1);
    }

    int option;

    srand(time(NULL));

    if(argc == 1)
    {
        option = rand() % 3;
    }
    else
    {
        option = idArg1(argv[1]);
    }

    switch(option)
    {
        case 0:
            launchStatic(argc, argv[2]); //launchStatic
            break;
        case 1:
            launchDyna(argc, argv[2]); //launchDyna
            break;
        case 2:
            launchInter(argc, argv[2]); //launchInter
            break;
        case 3:
            //readStats();
            break;
        }

        return 0;
    }