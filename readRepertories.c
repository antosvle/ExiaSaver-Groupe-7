#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <dirent.h>

#ifndef WIN32
#include <sys/types.h>
#endif

int countFiles(DIR* dir)
{
    int count = 0;
    struct dirent* ent = NULL;

    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) /*  Et n'est pas .. non plus */
        count++;
    }

    return count;
}
