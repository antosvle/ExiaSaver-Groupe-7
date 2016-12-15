#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include "functions.h"

int captureConsoleSize(Coordinates *consoleSize, Coordinates const imgSize)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if(consoleSize->x != w.ws_row - 1 || consoleSize->y != w.ws_col - 1);
	{
		consoleSize->x = w.ws_col - 1;
		consoleSize->y = w.ws_row - 1;

		if(imgSize.x > consoleSize->x || imgSize.y > consoleSize->y)
		{
			printf("ERROR: The image is too large for this console size.");
			return -1;
		}

		return 1;
	}

	return 0;
}

void positionCursor(FILE *img)
{
	int charRead;

	charRead = fgetc(img);

	while(charRead == '#' || charRead == '\n' || charRead == ' ')
	{
		while(charRead == '#')
		{
			while (charRead != '\n')
			{
				charRead = fgetc(img);
			}
		}

		charRead = fgetc(img);
	}

	fseek(img, -1, SEEK_CUR);
}

char getch()
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
