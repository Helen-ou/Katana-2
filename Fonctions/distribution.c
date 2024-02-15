// Code qui gère la première distribution des cartes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomise_index(int deck[60][5])
{
    // Choisis un index a
    int random_Index = rand() % 60;

    // Adjust the randomIndex based on the counts in the second field of each sub-array
    int cumulativeCount = 0;
    for (int i = 0; i < 25; i++)
    {
        cumulativeCount += deck[i][1]; // Assuming the count is in the second field
        if (random_Index < cumulativeCount)
        {
            return i;
        }
    }
    return -1;
}

void distribution(Joueurs *joueurs, int id_joueur, int deck[60][5], int nb_cartes_dist)
{
    int randomIndex;
    if (nb_cartes_dist == 2) // Distribution pas au tour 1
    {
        for (int k = 0; k < 2; k++)
        {
            randomIndex = randomise_index(deck);
            for (int i = 0; i < 14; i++)
            {
                if (joueurs[id_joueur].cartes[i] < 0)
                {
                    joueurs[id_joueur].cartes[i] = randomIndex; // Assigne une id de carte
                    deck[randomIndex][1] -= 1; // Décrémente
                    break;
                }
            }
        }
        return;
    }
    for (int k = 0; k < nb_cartes_dist; k++)
    {

        randomIndex = randomise_index(deck);

        // Now randomIndex points to the randomly selected sub-array
        joueurs[id_joueur].cartes[k] = randomIndex;
        deck[randomIndex][1] -= 1;
    }
}