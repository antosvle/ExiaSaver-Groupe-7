#include <stdio.h> //Bibliotheque basique.
#include <stdlib.h> //Bibliotheque basique.
#include <time.h> //Bibliotheque permettant la gestion du temps
#include <string.h> //Bibliotheque permettant la manipulation des chaines de caracteres.
#define tailleT 8 // HH:MM:SS = 8 caracteres

char* timeLoader() //La fonction renvoit un pointeur d'un tableau de caractere a main.
{
	/* On créé tout d'abord une varible de type 'tm'. struct tm est une structure de time.h, 
	elle contient beaucoup de variable comme l'heure, les secondes, le jour du mois, ...*/
	
	typedef struct tm InTIME;// On definit struct tm par 'InTIME', cela revient a dire que struct tm = InTIME.
	time_t secondes; // On créé une variable secondes de type time_t.
	InTIME horloge; // On créé une variable horloge de type InTIME, elle contient donc l'heure, les minutes, les secondes, ...
	time(&secondes); //On définit secondes.
	horloge=*localtime(&secondes); // On recupere les valeurs interne de kali linux.

	/*horloge contient donc toutes les valeurs de temps (heure, seconde, minute, jour, mois, ...)
	Dans notre cas nous avons besoin des heures, minutes et secondes. On va utiliser
	horloge.tm_hour, horloge.tm_min et horloge.tm_secs.*/


	//Si time(&secondes) renvoit -1 cela signifie qu'il n'a pas reussi a lire l'heure interne du pc.
	if(time(&secondes) == -1)
	{
		printf("Error : cant read intern clock.");
		exit(0);
	}


	/*La partie suivante consiste a ajouter un zero devant les chiffres seul.
	Si on affiche, par exemple, horloge.tm_hour et que l'heure interne est 06h45min,
	horloge.tm_hour affichera 6.

	Notre projet necessite d'afficher une heure de la forme HH:MM:SS et non H:MM:SS.
	On doit donc ajouter un zero a la valeur du temps lorsque la valeur est inferieur a 10.*/

	// On créé plusieurs chaines de caractere pour permettre les transformations.
	char heures[3], minutes[3], secs[3];
	char HEURES[3], MINUTES[3], SECS[3];
	char zero[]="0";

	// On doit donc ajouter un zero a la valeur du temps lorsque la valeur est inferieur a 10.*/
	if(horloge.tm_hour < 10)
	{
		sprintf(heures, "%d", horloge.tm_hour);
		//Ici on recupere l'heure et on la place dans la chaine heure.
		sprintf(HEURES, "%s", strcat(zero, heures));
		/*On ajoute ensuite a la chaine de caractere zero notre chaine heure ce qui a pour consequence d'ajouter le 0 manquant.
		Enfin, on place l'heure avec le format HH dans notre chaine final : HEURES */

		//Il suffit desormais d'appliquer cette structure pour les minutes et secondes pour resoudre notre probleme.
	}
	//Dans le cas ou la valeur comporte deja deux chiffre (ex: 14h), on envoit juste notre valeur dans la chaine final HEURES.
	else
	{
		sprintf(HEURES, "%d", horloge.tm_hour);
	}

	//On repete les phases precedentes pour les minutes.
	if(horloge.tm_min < 10)
	{
		sprintf(minutes, "%d", horloge.tm_min);
		sprintf(MINUTES, "%s", strcat(zero, minutes));
	}
	else
	{
		sprintf(MINUTES, "%d", horloge.tm_min);
	}

	//On repete les phases precedentes pour les secondes.
	if(horloge.tm_sec < 10)
	{
		sprintf(secs, "%d", horloge.tm_sec);
		sprintf(SECS, "%s", strcat(zero, secs));
	}
	else
	{
		sprintf(SECS, "%d", horloge.tm_sec);
	}





	// Maintenant que l'heure est transformer, on peut la mettre sous forme HH:MM:SS.
	char Tclock[tailleT]={""};
	strcat(Tclock, HEURES);
	strcat(Tclock, ":");
	strcat(Tclock, MINUTES);
	strcat(Tclock, ":");
	strcat(Tclock, SECS);
	//On a maintenant une heure généré en fonction de l'heure interne sous forme HH:MM:SS.


	//Pour finir, on envoit retourne l'heure a la main via un pointeur 'copie'.
	char *copie;
	copie = malloc(sizeof(char));
	strcpy(copie, Tclock); // On copie notre heure dans notre pointeur.
	return copie;
}