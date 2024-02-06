#include <stdio.h>
#include <stdlib.h>

#include "phase2.c"
#include "phase3.c"
#include "phase4.c"

// Va gérer la récup de PV
void phase_1(Joueurs *joueurs, int nb_joueurs)
{
    printf("Nous allons procéder à la phase de récupération ")
    int i = 0;
    for (i; i < nb_joueurs; i++)
    {
        if (joueurs[i].vies <= 0)
        {
            joueurs[i].vies = cartes_personnages[joueurs[i].index_perso][1];
        }
    }
}