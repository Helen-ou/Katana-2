#include <stdio.h>

/*// Va vérifier le nombre de points de chaque joueurs et les afficher
#include <stdio.h>

// Echanger 2 éléments
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size)
{
  for (int step = 0; step < size - 1; step++)
  {
    int min_idx = step;
    for (int i = step + 1; i < size; i++)
    {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d par le joueur %d", array[i]);
  }
  printf("\n");
}

// Fonction à exécuter
void point_calcul(Joueurs *joueurs, int nb_joueurs)
{
  int i;
  int tableau_p[nb_joueurs]; // tableau points

  for (i; i < nb_joueurs; i++)
  { // On met les points dans un tableau
    tableau_p[i] = joueurs[i].points;
  }

  int taille = sizeof(tableau_p) / sizeof(tableau_p[0]);
  selectionSort(tableau_p, taille);
  printf("Les résultats des points de la partie sont : \n");
  printArray(tableau_p, taille);
}*/

void point_calcul(Joueurs *joueurs, int nb_joueurs)
{
  int multiplicateurs[5][4] = {{2, 0, 1, 0}, {1, 2, 1.5, 0}, {1, 1, 1, 2}, {1, 2, 1, 3}, {1, 1, 1, 3}};
  int points_factions[4];
  for (int i = 0; i < nb_joueurs; i++)
  {
      
  }
}