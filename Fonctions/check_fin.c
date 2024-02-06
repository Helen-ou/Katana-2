#include <stdio.h>
#include <stdlib.h>

int check_honneur(Joueurs *joueurs, int nombre_joueurs)
{
    int i;
    int fin; // Condition de fin dans routine
    int n;   // Nombre de mort
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

int check_pv_fin(Joueurs *joueurs, int nombre_joueurs)
{
    int i;
    int fin; // Condition de fin dans routine
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