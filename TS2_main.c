#include <stdio.h> //Bibliotheque basique.
#include <stdlib.h> //Bibliotheque basique.
#include <string.h> //Bibliotheque permettant la manipulation des chaines de caracteres.
#include <unistd.h> //Bibliotheque necessaire pour 'sleep' et 'ioctl', elle fournit l'Interface de programmation des systèmes d'exploitation POSIX.
#include <sys/ioctl.h> //Bibliotheque systeme contenant la structure winsize ainsi que les variables STDOUT_FILENO et TIOCGWINSZ.
#include "TS2_Fheader.h" //Notre header qui contient les prototypes des fonctions secondaires ainsi que les structures.



void main()//Debut
{
	//On recupère ici la valeur qui définit la taille des chiffres de l'horloge.
	char taille[6];
	strcpy(taille,getenv("EXIASAVER2_TAILLE"));

	//On recupere ici la valeur du temp entre deux atualisations.
	int temps;
	temps = atoi(getenv("EXIASAVER2_SLEEP"));
	/* getenv permet de chercher la valeur stocker dans une variable d'environnement.
	Cependant, cette valeur est de type char.
	On utilise donc atoi qui permet de transformer un char en int.*/


	int i, k, y, centrage; //Initialisation de centrage (nombre de caractere necessaire pour centrer message[]).
	char* heure = NULL; 
	char message[]="Cet écran sera actualisé dans quelques secondes "; // Chaine qui contient le message.




	while(1) /*Boucle sans fin qui permet de faire fonctionner le programme indefiniment (et donc de le couper avec Ctrl^z ou Ctrl^).
			   Cette boucle permet aussi de detecter a chaque boucle la taille de la console et donc de modifier le centrage de notre affichage.
			   On peut donc modifier la taille de la console pendant l'execution du programme.*/
	
	{
		/*On recupere tout d'abord la taille de la console que l'on
		stocke dans une variable 'consoleSize' de type Coordinates.(voir structure Fheader)*/
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); //Charge la taille actuel de la console.
		int col = w.ws_col;  //On recupere le nombre de caractere sur une ligne.
		int row = w.ws_row;	 //On recupere le nombre de caractere sur une colonne.

		Coordinates consoleSize;
		consoleSize.x = (row-1);
		consoleSize.y = (col-1);
		/*Les -1 permettent d'aligner parfaitement la chaine de caractere a deux 
		dimensions avec la console.*/

		centrage = (consoleSize.y - (sizeof(message)))/2;
		/* On calcul ensuite le nombre d'espace necessaire pour centrer notre message.
		On prend pour cela en paramtre la taille de la console et celle de la chaine, puis
		on divise par 2. Cela permet de centrer parfaitement le message selon la console.*/
		
		system("clear"); // (reset ou clear) On efface la console.

		/*On recupere l'heure interne du pc dans une chaine de caractere dans le format
		HH:MM:SS*/
		heure=timeLoader();

		/*On appel ensuite la fonction d'affichage de l'heure. Elle charge l'heure récupéré
		precedemment ainsi que la taille de la console.
		Cette fonction affche l'heure en format pbm et centre celle-ci dans la console.*/
		clockPost(heure, consoleSize);

		/*Cette boucle permet de centrer le message grace a des espaces dont le nombre
		a été calculé ligne 49.*/
		for(y = 0; y < centrage; y++){printf(" ");}

		printf("%s", message);// On affiche, apres les espaces, le message. Il est donc centré.

		/*Cette boucle permet l'affichage du temps avant acutalisation a l'aide de point.
		La boucle affiche un point chaque seconde, elle repete cette action en fonction de la
		variable d'environnement EXIASAVER2_SLEEP récupéré ligne 18. */
		for(i=0; i < temps; i++)
		{
			printf(".");
			fflush(stdout);
			sleep(1);
		}
	}

	free(heure); // On libère la memoire alloué au pointeur dans timLoader et récupéré dans 'heure'.
}	