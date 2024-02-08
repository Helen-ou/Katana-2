#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void distribution(Joueurs *joueurs, int id_joueur, int deck[60][5], int nb_cartes_dist)
{
    for (int k = 0; k < nb_cartes_dist; k++)
    {
        // Seed the random number generator

        // Choose a random element index
        int randomIndex = rand() % 60;

        // Adjust the randomIndex based on the counts in the second field of each sub-array
        int cumulativeCount = 0;
        for (int i = 0; i < 60; i++)
        {
            cumulativeCount += deck[i][1]; // Assuming the count is in the second field
            if (randomIndex < cumulativeCount)
            {
                randomIndex = i;
                break;
            }
        }

        // Now randomIndex points to the randomly selected sub-array
        joueurs[id_joueur].cartes[k] = deck[randomIndex][0];
        deck[randomIndex][1] -= 1;
    }
}