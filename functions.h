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

void readImgFormat(FILE *img, int *formatId);
void readImgSize(FILE *img, Coordinates *imgSize);
void readImgPixels(FILE *img, Coordinates *imgSize, int imgPixel[imgSize->x][imgSize->y]);

void positionCursor(FILE *img);

void centerImg(Coordinates *imgSize, Coordinates *consoleSize, Frame *imgFrame);
void printImg(Coordinates *consoleSize, Coordinates *imgSize, Frame *imgFrame, int imgPixel[imgSize->x][imgSize->y]);
