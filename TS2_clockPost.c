#include <stdio.h> //Bibliotheque basique.
#include <stdlib.h> //Bibliotheque basique.
#include <string.h> //Bibliotheque permettant la manipulation des chaines de caracteres.
#include "TS2_Fheader.h" //Notre header qui contient les prototypes des fonctions secondaires ainsi que les structures.

#define TC 50 //Taille des tableau contenant le chemin d'acces de chaque fichiers.
#define Colonne 31 // Nombre de colonne de l'affichage de l'horloge.
#define Ligne 6 // Nombre de ligne de l'affichage de l'horloge.

//Prototypes des fonctions secondaires ecrites dans ce fichier.
char* PBMchange(char heure[],int indic);
void framer(Coordinates const imgSize, Coordinates const consoleSize, Frame *imgFrame);
void printImg(Coordinates const consoleSize, Coordinates const imgSize, Frame const imgFrame, char affichage[imgSize.x][imgSize.y]);






void clockPost(char heure[], Coordinates consoleSize)
{
	/* Ce bloc permet de recupérer la direction du repertoire des fichiers pbm
	stocké dans une variable d'environnement. On peut donc modifier a tout instant 
	cette variable pour changer de dossier.*/
	char repertoire[TC];
	strcpy(repertoire, getenv("EXIASAVER2_PBM"));
	strcat(repertoire, "/");



	/* Le bloc suivant permet de decomposer chiffre par chiffre l'heure,
	pour ensuite placer ce chiffre dans une chaine de caractere avec '.pbm' precede du
	chemin d'acces du fichier.
	Cette action permet de stocker dans des chaines de caractere tout les fichiers
	necessaire pour afficher l'heure en pbm, qu'importe celle-ci.*/
	char point [TC], un[TC], deux[TC], trois[TC], quatre[TC], cinq[TC], six[TC];

	strcpy(un, repertoire); strcat(un, PBMchange(heure, 0)); //Premier chiffre
	strcpy(deux, repertoire); strcat(deux, PBMchange(heure, 1)); //Deuxieme chiffre
	strcpy(trois, repertoire); strcat(trois, PBMchange(heure, 3)); //Troisieme chiffre
	strcpy(quatre, repertoire); strcat(quatre, PBMchange(heure, 4)); //Quatrieme chiffre
	strcpy(cinq, repertoire); strcat(cinq, PBMchange(heure, 6)); //Cinquieme chiffre
	strcpy(six, repertoire); strcat(six, PBMchange(heure, 7)); //Sixieme chiffre
	//L'heure a pour format HH:MM:SS, c'est pourquoi on passe la case 2 et 5 de la chaine car celle-ci concerne les deux points.

	strcpy(point, repertoire); strcat(point, "point.pbm"); //On complete de la meme maniere la chaine contenant le chemin d'acces vers point.pnm

	/*On initialisa ici un tableau contenant, dans l'ordre les valeurs de l'heure.
	Les valeurs de ce tableau seront lues une a une par notre fonction qui stockera les chiffres lu dans le tableau a deux dimension affichage.*/
	char* tableauChiffre[8]={un, deux, point, trois, quatre, point, cinq, six};
	/*Initialisation : - le compteur count (il permet de placer chaque chiffres sur la bonne colonne de notre affichage, cela evite que tout les chiffres se superposent).
		               - on initialise notre tableau avec des espaces vide pour eviter d'eventuel reste de valeur.*/
	int count = 0, x, y;
	char affichage[Ligne][Colonne];

	for(x=0; x<Ligne; x++)
	{
		for(y=0; y<Colonne; y++)
		{
			affichage[x][y] = ' ';
		}
	}




	/*La partie suivante permet de remplir le tableau affichage. 
	Il sera remplit de cette maniere : - si le caractere lu est 1, alors on place un 1 a la case correspondante de l'affichage
 									   - si le caractere lu est 0, alors on place un espace.
 									   - si le caractere lu est un espace ou un retour a la ligne alors on place un espace aussi.*/

	//b prend la valeur du compteur (il vaut 0 au debut donc le premier chiffre sera tout a gauche du tableau, ensuite, le deuxieme chiffre viendra apres le premier).
	int a = 0, b = count, i, caractere;
	//On effectue 8 fois la boucle pour les 8 symboles (HH:MM:SS)
	for(i=0; i<8; i++)
	{
		a = 0;
		b = 0;
		FILE* pbm = NULL;
		pbm = fopen(tableauChiffre[i], "r"); //On charge le fichier en fonction du nombre d'itération effectué.

		if(pbm != NULL) // Si pbm est different de NULL alors le fichier est bien ouvert.
		{
			fseek(pbm, -35, SEEK_END); // On place notre curseur a la fin du pbm puis on recule de 35 caracteres (nombre de 0 et 1 avec espace et retour a la ligne).
			do
			{
				caractere = fgetc(pbm); //On lis notre premier caractere.
				if(caractere == '1')
				{
					affichage[a][b + count]= '1'; //On ajoute toujour count a b pour eviter la superposition des chiffres dans le tableau.
					b++;
					fgetc(pbm);
					/*- La case du tableau venant de prendre une valeur, on se deplace dans la prochaine avec b++
					  - Le fgetc a la fin permet de sauter l'espace qui suit la valeur qui nous interesse.*/

				}
				else if(caractere == '0')
				{
					affichage[a][b + count]=' ';
					b++;
					fgetc(pbm);
					/*- La case du tableau venant de prendre une valeur, on se deplace dans la prochaine avec b++
					  - Le fgetc a la fin permet de sauter l'espace qui suit la valeur qui nous interesse.*/
			
				}
				else
				{
					affichage[a][b + count]=' ';
					b++;
					/* Si le caractere lu n'est ni un 0 ni un 1 alors on passe ce caractere (donc b++)	
					   Cependant, on ne passe pas le caratere comme precedement car si cette valeur est un espace ou un retour a la ligne, la prochaine est une valeur qui nous interesse.*/				
					
				}

				if(b == 3) // Notre fichier est en 3x5, il faut donc effectuer un retour a la ligne dans notre tableau 'affichage' pour eviter d'afficher tout sur une seul ligne.
				{
					a++; // a correspond à la ligne, il prend donc +1 pour permettre de rentrer les valeurs dans la ligne suivante et ainsi correctement afficher un chiffre.
					b = 0; // b est quand a lui reinitialiser pour permettre de revenir a la colonne initial et donc permettre au chiffre de s'afficher correctement (et non en decalage).
					fgetc(pbm); // Enfin, on avance le curseur pour ne pas lire le retour a la ligne.
				}

		 	} while (caractere != EOF); /* La boucle de lecture prend fin lorsque le curseur atteint la fin du fichier.
		 								   A ce stade, le fichier ouvert est entierement retranscrit dans notre tableau sous forme de 1.*/

			fclose(pbm); // On ferme le fichier ouvert pour ouvrir le suivant et ainsi de suite jusqu'a ce que tous les chiffres de notre tableau[8] soient transcris dans affichage.
		}

		else // Ce else permet d'afficher et de couper le programme si une erreur survient avec un fichier (probleme d'extension, absence du fichier ...)
		{
			printf("Error = cant open the file %s.\n", tableauChiffre[i]);
			exit(0);
		}


		/* La derniere partie de notre 'for' concerne le compteur. 
		En effet, celui-ci doit evoluer a chaque itération pour permettre un affichage à la suite des chiffre, avec un espace regulier entre chacun d'entte eux.*/
		switch(i)
		{
			case 0:
				count += 4; /*Le compteur, qui valait zero, prend 4 a la fin de la premiere iteration. Ce 4 vient du fait que un chiffre fait 3 caracteres de large et on a besoin
							  d'un espace d'un caractere entre chaque chiffre.*/
				break;
			case 1:
				count += 3; /* Ici on ajoute 3 au compteur car le second chiffre fait toujours 3 caracteres, cependant on n'ajoute pas de 4eme caractere pour l'espace car le format 
							   du double points comporte deja deux colonnes de caractere vide.*/
				break;
			case 2:
				count += 5;/* Ici on ajoute 3 pour le chiffre, 1 pour l'espace et encore 1 pour avoir un affichage plus clair.
							  (Ces valeurs peuvent etre modifié pour changer l'espacement des chiffres).*/
				break;
			case 3:
				count += 4; //Voir avant.
				break;
			case 4:
				count += 3; //Voir avant.
				break;
			case 5:
				count += 5; //Voir avant.
				break;
			case 6:
				count += 4; //Voir avant.
				break;
			case 7:
				count += 3; //Voir avant.
				break;
		} //Le compteur permet donc de correctement afficher nos chiffres ainsi que changer l'espacement entre eux pour une meilleur lisibilié a l'ecran.


	}// Notre tableau d'affichage est desormais REMPLI !! Il est composé uniquement de 1 et d'espace. Il forme donc entierement l'horloge.



	//Il faut maintenant afficher ce tableau a deux dimensions ainsi que le centrer dans la console.
	
	Frame imgFrame; //On créé une variable de type frame, elle sera notre cadre pour le centrage de l'horloge.

	Coordinates imgSize; //On créé une variable de type Coordinates.
	imgSize.x = Ligne;
	imgSize.y = Colonne; // Cette variable prend comme valeur la taille de notre affichage[][] cad Ligne et Colonne ( ou 6 et 31).


	framer(imgSize, consoleSize, &imgFrame); // Fonction qui créé le cadre centré dans la console.
	//Une fois le cadre créé, il siffit simplement d'afficher le tableau a l'interieur, celui-ci ayant les memes dimensions.

	printImg(consoleSize, imgSize, imgFrame, affichage); //Fonction qui affiche et centre notre horloge

}












char* PBMchange(char heure[],int indic)
/* Cette fonction prend l'heure et l'indicateur envoyer. Elle prend ensuite
le chiffre correspondant et rajoute '.pbm' a celui-ci.*/
{
	char*item = NULL;
	item = malloc(sizeof(char));

	sprintf(item, "%c", heure[indic]); // On place dans item le chiffre correspondant a l'indic ('indic' indique quel chiffre HH:MM:SS de l'heure on selectionne)
	strcat(item, ".pbm"); // On ajoute l'extension a ce chiffre. 

	return item; // On retourne l'élément créé, il suffit juste desormais de lui ajouter le chemin d'acces au fichier grace a la varible global.
	free(item);
}


















void framer(Coordinates const imgSize, Coordinates const consoleSize, Frame *imgFrame)
{
	//On calcul pour x minimum, x maximum, y minimum et y maximum les valeurs en fonction de la taille de la console et de la taille de l'horloge.

	imgFrame->xmin = (consoleSize.x - imgSize.x)/2;

	imgFrame->ymin = (consoleSize.y - imgSize.y)/2;

	imgFrame->xmax = (consoleSize.x - imgSize.x)/2 + imgSize.x;

	imgFrame->ymax = (consoleSize.y - imgSize.y)/2 + imgSize.y;

	//Cette fonction a donc pour resultat la creation virtuelle (il ne sera pas affiché) d'un cadre ou de limite dans la console.
	//Notre horloge prendra place dans ce cadre ce qui aura pour effet de la centrer selon la taille de la console.
}
















void printImg(Coordinates const consoleSize, Coordinates const imgSize, Frame const imgFrame, char affichage[imgSize.x][imgSize.y])
{
    Coordinates i, j;

    j.x = 0;   //On initialise un systeme de coordonnée i et j pour ldx utiliser comme iteration dans les 'for' tout en permettant d'afficher un tableau a deux dimensions.
    j.y = 0;

    for(i.x = 0; i.x < consoleSize.x; i.x++)               
    {													
        if(i.x < imgFrame.xmin || i.x >= imgFrame.xmax)    /* Cette premiere partie permet de remplir la partie horizontale (x) de la 
        													  console (ou l'exterieur du cadre) avec des " " tant que la condition est verifié.*/
        {													
            for(i.y = 0; i.y <= consoleSize.y; i.y++)
            {												//On ajoute les " " du bas vers le haut de la console(c'est pourquoi on a '<=consoleSize.y').
                printf(" ");
            }
        }
        else
        {
            for(i.y = 0; i.y <= consoleSize.y; i.y++)            
            {
                if(i.y < imgFrame.ymin || i.y >= imgFrame.ymax)   // On fait ensuite de meme mais sur l'axe vertical.
                {
                    printf(" ");
                }
                else                       /*Lorsque que l'on entre dans la condition else, cela signifie que la partie horizontale exterieur du cadre est entierement
                							 composé de " " tout comme la partie vertical (grace au deux if).*/
                {
                	if(affichage[j.x][j.y] == '1')    //La console est entierement remplie d'espace, il reste seulement son centre qui a pour dimension notre tableau.
                	{
                		printf("#");  // On affiche donc un symbole lorsque la case du tableau correspondante vaut 1.
                	}
                	else
                	{
                    	printf("%c", affichage[j.x][j.y]);  // Sinon on affiche le tableau (sachant que le tableau ne possede que des 1 et des " ").
                	}
                    j.y++;
                }
            }
            j.y = 0;
            j.x++;
        }
        printf("\n");
    }
}


/* RESULTAT NOTRE CONSOLE AFFICHE UNE HORLOGE CENTRÉ GRACE A DES ESPACES AUTOUR D'ELLE. LES CHIFFRES SONT TOUS AFFICHÉ PAR UN SYMBOLE DEFINIT ET 
   SONT TOUS CORRECTEMENT ESPACÉ.*/













