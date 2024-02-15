// Code qui permet de lancer la fin du jeu
#include <stdio.h>
#include <stdlib.h>

void fin_jeu(Joueurs *joueurs, int nombre_joueurs)
{
    printf("La fin du jeu approche, comptons les points !\n");
    point_calcul(joueurs, nombre_joueurs); // Code de calcul des points finaux
}