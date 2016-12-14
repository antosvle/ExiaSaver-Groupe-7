#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idArg1(char *option)
{
    if(strcmp(option, "-static") == 0)
    {
        return 0;
    }
    else if(strcmp(option, "-dyna") == 0)
    {
        return 1;
    }
    else if(strcmp(option, "-inter") == 0)
    {
        return 2;
    }
    else if(strcmp(option, "-stats") == 0)
    {
        return 3;
    }
    else
    {
        printf("ERROR: Unknown argument (argument 2)\n");
        exit(-1);
    }
}