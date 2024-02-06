// Fonctions qui vont faire toute les vérifications régulières
#include <stdio.h>
#include <stdlib.h>

#include "Fonctions/points.c"
#include "Fonctions/fin.c"
#include "Fonctions/check_fin.c"

int routine(Joueurs *joueurs, int nombre_joueurs)
{
    int fin;
    fin += check_honneur(joueurs, nombre_joueurs);
    fin += check_pv_fin(joueurs, nombre_joueurs);
    if (fin == 1)
    {
        printf("La fin du jeu approche, comptons les points ! ");
        point_calcul(joueurs, nombre_joueurs);
        return 1; // Si fonction routine renvoie 1, break boucle jeu dans launch.c
    }
    else
    {
        printf("\nLa partie continue, place à la phase suivante ! \n");
        return 0;
    }
}