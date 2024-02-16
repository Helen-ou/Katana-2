#include <stdio.h>

int shogun_commence(Joueurs *joueurs)
{
    int compteur = 0;
    while (1)
    {
        if (joueurs[compteur].classe == 0)
        {
            return compteur;
        }
        compteur += 1;
    }
}