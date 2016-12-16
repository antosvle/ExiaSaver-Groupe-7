#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void  beginning (FILE* fstats, char launchType);

void readStats() //Lit le fichier "history.txt" et l'affiche à l'écran.
{
  FILE* fstats = NULL;
  fstats = fopen("/home/EXIASAVER/stats/history.txt", "r");

  int choixMenu;
  int caractere;
  char *chaine;
  chaine = malloc(sizeof(char));
  system("clear");

  printf("                                === Menu ===\n\n"); // Affiche le menu
  printf("                          1. Rechercher par date\n");
  printf("                          2. Rechercher par type\n");
  printf("                       3. Rechercher par nom de fichier\n");
  printf("                     4. Rechercher par tailles utilisees\n");
  printf("\nVotre choix?");
  scanf("%d", &choixMenu);

  printf("\n");
  system("clear");

  switch (choixMenu)
  {
    case 1:
      printf("Voici l'historique eXiasaver par date:\n\n\n");
      while(caractere != EOF)
      {
        caractere = fgetc(fstats);
        printf ("%c", caractere);
      }
      printf("\n");
      break;

    case 2:
      printf("Voici l'historique eXiasaver par type:\n");



      break;
    case 3:
      printf("Voici l'historique eXiasaver par nom de fichier:\n");



      break;
    case 4:
      printf("Voici l'historique eXiasaver par tailles utilisees:\n");
      break;
    default:
      printf("Vous n'avez pas choisit une option valide");
      break;
  }

  fclose(fstats);
  free(chaine);
}

void writeStats(char launchType, char imgWay[], int x, int y) //Écrit dans le fichier "hisory.txt".
{
  FILE* fstats = NULL;
  fstats = fopen("/home/EXIASAVER/stats/history.txt", "r+");
  beginning(fstats, launchType);



  time_t temps;
  struct tm date;

  time(&temps);
  date=*localtime(&temps);

  fseek(fstats, 0, SEEK_END);   // Permet d'écrire à la fin du fichier
  fprintf(fstats, "\n");


  fprintf(fstats, "%s", asctime(&date));

  fseek(fstats, -1, SEEK_CUR);


  if (launchType == 's') // Ecrit les différentes images utilisées
  {
    fprintf(fstats," %s                              STATIC", imgWay);
  }

  else if (launchType == 'd') // Ecrit les  dimensions de l'heure 
  {
    fprintf(fstats,"  Dimension de l'heure: x= %d y= %d      DYNAMIC", x, y);
  }

  else if (launchType == 'i')// Ecrit les coordonnées de l'avion quand il apparaît
  {
    fprintf(fstats,"  Coordonnées de l'avion: x= %d y=%d     INTERACTIVE", x, y);
  }
}

void  beginning (FILE* fstats, char launchType)
{

  int j =0;

  if (launchType == 's')
  {
    fseek(fstats, 48, SEEK_SET);  // On déplace le curseur jusqu'au nombre de statique qu'on a  ouvert$
    fscanf(fstats, "%d", &j);
    fseek(fstats, 48, SEEK_SET);
    fprintf(fstats,"%d", j+1);
  }
  else if (launchType == 'd')
  {
    fseek(fstats, 102, SEEK_SET);  // On déplace le curseur jusqu'au nombre de statique qu'on a  ouvert$
    fscanf(fstats, "%d", &j);
    fseek(fstats, 102, SEEK_SET);
    fprintf(fstats,"%d", j+1);
  }
  else if(launchType == 'i')
  {
    fseek(fstats, 157, SEEK_SET);  // On déplace le curseur jusqu'au nombre de statique qu'on a  ouvert$
    fscanf(fstats, "%d", &j);
    fseek(fstats, 157, SEEK_SET);
    fprintf(fstats,"%d", j+1);
  }

  else
  {
    exit(-1);
  }
}