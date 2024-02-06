#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pioche_tour1(Joueurs *joueurs, int nombre_joueurs)
{
    int joueur_x = 5; // Compte le joueur pour la distribution, permet d'éviter le shogun qui fait +0
    int add_1;
    for (int i; i < nombre_joueurs; i++)
    {
        if (joueurs[i].classe == 0)
        {
            // Fonction distribution(4)
        }
        else
        {
            // fonction distribution(joueur_x)
            if (add_1 % 2 == 0)
            {
                joueur_x++;
                
            }
            add_1++;
        }
    }
}