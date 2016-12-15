
#ifndef FHEADER_H
#define FHEADER_H
/* Cette structure est une sécutité qui permet d'eviter une boucle d'appel infini pour notre header.
Dans notre cas, elle n'est pas forcement necessaire.
Si une fonction appel une autre et cet autre fonction appel notre fonction, avec leurs prototype dans le meme header, cela peut provoquer la lecture infini 
du header par le processeur.*/


//Cette structure concerne le cadre qui a pour talle la console. Le cadre permet de centrer notre horloge.
typedef struct Frame Frame;
struct Frame
{
	int xmin;
	int xmax;
	int ymin;
	int ymax;
};


//Structure de coordonée simple.
typedef struct Coordinates Coordinates;
struct Coordinates
{
	int x;
	int y;
};

//Prototypes de nos fonctions secondaires.
char* timeLoader();
void clockPost(char heure[], Coordinates consoleSize);

#endif