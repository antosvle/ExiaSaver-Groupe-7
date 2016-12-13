#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define tailleT 256

char* timeLoader()
{
	typedef struct tm InTIME;
	time_t secondes;
	InTIME horloge;
	time(&secondes);
	horloge=*localtime(&secondes);

	if(horloge.tm_isdst == -1)
	{
		printf("Error : cant read intern clock.");
		exit(0);
	}

	char heures[3], minutes[3], secs[3];
	char HEURES[3], MINUTES[3], SECS[3];
	char zero[]="0";


	if(horloge.tm_hour < 10)
	{
		sprintf(heures, "%d", horloge.tm_hour);
		sprintf(HEURES, "%s", strcat(zero, heures));
	}
	else
	{
		sprintf(heures, "%d", horloge.tm_hour);
		strcpy(HEURES, heures);
	}

	if(horloge.tm_min < 10)
	{
		sprintf(minutes, "%d", horloge.tm_min);
		sprintf(MINUTES, "%s", strcat(zero, minutes));
	}
	else
	{
		sprintf(minutes, "%d", horloge.tm_min);
		strcpy(MINUTES, minutes);
	}

	if(horloge.tm_sec < 10)
	{
		sprintf(secs, "%d", horloge.tm_sec);
		sprintf(SECS, "%s", strcat(zero, secs));
	}
	else
	{
		sprintf(secs, "%d", horloge.tm_sec);
		strcpy(SECS, secs);
	}

	char Tclock[tailleT]={""};
	strcat(Tclock, HEURES);
	strcat(Tclock, ":");
	strcat(Tclock, MINUTES);
	strcat(Tclock, ":");
	strcat(Tclock, SECS);

	char *copie=NULL;
	copie = malloc(sizeof(char));
	strcpy(copie, Tclock);
	return copie;
	free(copie);
}
