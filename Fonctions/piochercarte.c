// Code qui permet de gérer la première distribution des cartes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "distribution.c"

void pioche_tour1(Joueurs *joueurs, int nombre_joueurs)
{
    int joueur_x = 5; // Compte le joueur pour la distribution, permet d'éviter le shogun qui fait +0
    int add_1 = 1;
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (joueurs[i].classe == 0) // Si shogun dans la partie, gère sa distribution spéciale
        {
            printf("\nJe distribue au shogun\n");
            distribution(joueurs, i, 4, nombre_joueurs);
        }
        else
        {
            printf("Je distribue à %s\n", joueurs[i].nom);
            distribution(joueurs, i, joueur_x, nombre_joueurs);
            if (add_1 % 2 == 0)
            {
                joueur_x++;
            }
            add_1++;
        }
    }
}