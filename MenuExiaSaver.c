#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int choixMenu;
  
  printf("=== Menu ===\n\n"); // Affiche le menu
  printf("1. Rechercher par date\n");
  printf("2. Rechercher par type\n");
  printf("3. Rechercher par nom de fichier\n");
  printf("4. Rechercher par tailles utilisées\n");
  printf("\nVotre choix ? ");
  scanf("%d", &choixMenu);
  
  printf("\n");
  
  switch (choixMenu)
  {
    case 1:
       printf("Voici l'historique eXiasaver par date : ");
       readStats(); //par date
       break;
    case 2:
       printf("Voici l'historique eXiasaver par type : ");
       readStats(); //par type
       break;
    case 3:
       printf("Voici l'historique eXiasaver par nom de fichier : ");
       readStats(); // par nom de fichier
       break;
    case 4:
       printf("Voici l'historique eXiasaver par tailles utilisées : ");
       readStats(); // par taille utilisé
       break;
    default:
       printf("Vous n'avez pas choisit une option valide"); // L'utilisateur n'a pas rentré 1, 2, 3 ou 4
       break;
  }
  
  printf("\n\n");
  
  return 0;
}