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

void readImgFormat(FILE *img);
void readImgSize(FILE *img, Coordinates *imgSize);
void readImgPixels(FILE *img, Coordinates const imgSize, int imgPixel[imgSize.x][imgSize.y]);

void positionCursor(FILE *img);

void centerImg(Coordinates const imgSize, Coordinates const consoleSize, Frame *imgFrame);
void printImg(Coordinates const consoleSize, Coordinates const imgSize, Frame const imgFrame, int imgPixel[imgSize.x][imgSize.y]);

int captureConsoleSize(Coordinates *consoleSize, Coordinates const imgSize);
char getch();
