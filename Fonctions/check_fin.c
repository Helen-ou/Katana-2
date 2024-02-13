#include <stdio.h>
#include <stdlib.h>

int check_honneur(Joueurs *joueurs, int nombre_joueurs)
{
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (joueurs[i].honneur <= 0)
        {
            return 1;
        }
    }
    return 0;
}

int check_pv_fin(Joueurs *joueurs, int nombre_joueurs)
{
    int compteur;
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (joueurs[i].vies <= 0)
        {
            compteur += 1;
        }
    }
    if (compteur >= nombre_joueurs - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}