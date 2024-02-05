// Va gérer la fin du jeu
#include <stdio.h>
#include <stdlib.h>

void fin_jeu(Joueurs *joueurs, int nombre_joueurs)
{
    printf("La fin du jeu approche, comptons les points ! ");
    point_calcul(joueurs, nombre_joueurs);
}