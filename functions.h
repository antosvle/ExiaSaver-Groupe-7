#include <stdio.h>
#include <stdlib.h>

typedef struct Frame Frame;
struct Frame
{
	int xmin;
	int xmax;
	int ymin;
	int ymax;
};

typedef struct Coordinates Coordinates;
struct Coordinates
{
	int x;
	int y;
};

typedef enum Direction Direction;
enum Direction
{
	UP, RIGHT, DOWN, LEFT
};

void readImgFormat(FILE *img);
void readImgSize(FILE *img, Coordinates *imgSize);
void readImgPixels(FILE *img, Coordinates const imgSize, int imgPixel[imgSize.x][imgSize.y]);

void positionCursor(FILE *img);

void captureConsoleSize(Coordinates *consoleSize);

void moveImg(Direction const i, Coordinates const consoleSize, Coordinates *planePosition);
void changeDirection(Direction *i);
char getch();

void frameImg(Coordinates const consoleSize, Coordinates const planePosition, Frame *imgFrame);
void printImg(Coordinates const consoleSize, Frame const imgFrame, int imgPixel[6][6]);
