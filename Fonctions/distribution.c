#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void distribution(Joueurs *joueurs, int id_joueur, int nombre_cartes)
{   
    printf("boop\n");
    for (int k; k < nombre_cartes; k++)
    {
        // Créé tableau avec les poids
        int deck_weighted[200]; // 200 éléments choisi arbitrairement
        for (int i; i < (sizeof(deck) / sizeof(deck[0])); i++)
        {
            for (int j; j < deck[i][1]; j++)
            {
                deck_weighted[sizeof(deck_weighted) / sizeof(deck_weighted[0] - 1)] = deck[i][0];
            }
        }

        // Chercher un élément aléatoire pour piocher
        srand(time(NULL));
        int random_item = rand() % (sizeof(deck_weighted) / sizeof(deck_weighted[0]));
        random_item = deck_weighted[random_item];
        printf("%d", random_item);
        joueurs[id_joueur].cartes[sizeof(joueurs[id_joueur].cartes) / sizeof(joueurs[id_joueur].cartes[0])] = deck[random_item];
    }
}