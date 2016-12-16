#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include "functions.h"

void captureConsoleSize(Coordinates *consoleSize)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
	consoleSize->x = w.ws_col - 1;
	consoleSize->y = w.ws_row - 1; //attribution de la taille de la console à consoleSize.
}

void changeDirection(Direction *i)
{
	switch(getch()) //si getch prend z q s d, modification de i.
	{
		case 'z':
			*i = UP;
			break;
		case 'd':
			*i = RIGHT;
			break;
		case 's':
			*i = DOWN;
			break;
		case 'q':
			*i = LEFT;
			break;
	}
}

void moveImg(Direction const i, Coordinates const consoleSize, Coordinates *planePosition)
{
	switch(i)
	{
		case UP:
			planePosition->y = planePosition->y - 1;
			break;
		case RIGHT:
			planePosition->x = planePosition->x + 1;
			break;
		case DOWN:
			planePosition->y = planePosition->y + 1;
			break;
		case LEFT:
			planePosition->x = planePosition->x - 1; //modification des coordonnées de l'avion en fonction de i.
			break;
	}

	if(planePosition->x > consoleSize.x)
	{
		planePosition->x = 0;
	}
	else if(planePosition->x < 0)
	{
		planePosition->x = consoleSize.x;
	}

	if(planePosition->y > consoleSize.y)
	{
		planePosition->y = 0;
	}
	else if (planePosition->y < 0)
	{
		planePosition->y = consoleSize.y; //si l'avion est hors du terminal visible, réapparait de l'autre côté.
	}
}

char getch() //fonction retournant un caractère écrit dans le terminal.
{
	char buf = 0;
	struct termios old = {0}; 

	fflush(stdout);
	if(tcgetattr(0, &old) < 0)
		perror("tcsetattr()");
	old.c_lflag&= ~ICANON;
	old.c_lflag&= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if(tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANNON");
	if(read(0, &buf, 1) < 0)
		perror("read()");
	old.c_lflag|= ICANON;
	old.c_lflag|= ECHO;
	if(tcsetattr(0, TCSADRAIN, &old) < 0)
		perror("tcsetattr ~ICANNON");
	printf("%c\n", buf);
	return buf;
}
