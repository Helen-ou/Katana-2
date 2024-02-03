// Fonctions qui vont faire toute les vérifications régulières
#include <stdio.h>
#include <stdlib.h>

#include "libraries.h"
#include "fin.c"

int check_honneur(Joueurs *joueurs, nombre_joueurs)
{
    int i;
    int fin; // condition de fin dans routine
    int n;   // nombre de mort
    for (i; i < nombre_joueurs; i++)
    {
        if (joueurs[i].honneur <= 0)
        {
            joueurs[i].fin = 0; // ded
            printf("\nLe joueur %d n'a plus d'honneur et commet le seppuku!", i);
        }
    }
    return fin;
}

void check_pv_fin(Joueurs *joueurs, nombre_joueurs)
{
    int i;
    int fin; // condition de fin dans routine
    int n;
    for (i; i < nombre_joueurs; i++)
    {
        if (n >= nombre_joueurs - 1)
        {
            fin = 1;
        }
        else if (joueurs[i].vies <= 0)
        {
            n += 1;
        }
    }
    return fin;
}

int routine(Joueurs *joueurs, nombre_joueurs)
{
    int fin;
    check_honneur(joueurs, nombre_joueurs);
    check_pv_fin(joueurs, nombre_joueurs);
    if (fin == 1)
    {
        fin_jeu(joueurs, nombre_joueurs) return 1; // Si fonction routine renvoie 1, break boucle jeu dans launch.c
    }
    else
    {
        printf("\nLa partie continue, place à la manche suivante ! ");
        return 0;
    }
}