typedef struct dirent dirent;

int idArg1(char *argv);

void launchStatic(int argc, char *argv); //Execute le screenSaver statique en lui envoyant les bons paramètres.
void launchDyna(int argc, char *argv[]); //Execute le screenSaver dynamique en lui envoyant les bons paramètres.
void launchInter(int argc, char *argv[]); //Execute le screenSaver interactif en lui envoyant les bons paramètres.

int countFiles(DIR* dir);

void readStats(); //Lit le fichier "history.txt" et l'affiche à l'écran.
void writeStats(); //Écrit dans le fichier "hisory.txt".
