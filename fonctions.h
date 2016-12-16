typedef struct dirent dirent; //raccourci la création d'une variable de type dirent

int idArg1(char *argv); // fonction qui est utilisé lorsqu'on rentre un 2eme argument lors de l'exécution du ScreenSaver

void launchStatic(int argc, char *argv); //Execute le screenSaver statique en lui envoyant les bons paramètres.
void launchDyna(int argc, char *argv); //Execute le screenSaver dynamique en lui envoyant les bons paramètres.
void launchInter(int argc, char *argv); //Execute le screenSaver interactif en lui envoyant les bons paramètres.

int countFiles(char *imgWay); // compte le nombre de fichier dnas un répertoire

void readStats(); //Lit le fichier "history.txt" et l'affiche à l'écran.
void writeStats(char launchType, char imgWay[], int x, int y); //Écrit dans le fichier "hisory.txt".