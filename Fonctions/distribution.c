#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomise_index(int deck[25][5])
{
    // Choose a random element index
    int random_Index = rand() % 25;

    // Adjust the randomIndex based on the counts in the second field of each sub-array
    int cumulativeCount = 0;
    for (int i = 0; i < 25; i++)
    {
        cumulativeCount += deck[i][1]; // Assuming the count is in the second field
        if (random_Index < cumulativeCount)
        {
            random_Index = i;
            break;
        }
        return (random_Index);
    }
}

void distribution(Joueurs *joueurs, int id_joueur, int deck[25][5], int nb_cartes_dist)
{
    int randomIndex;
    if (nb_cartes_dist == 2) // Distribution pas au tour 1
    {
        for (int k = 0; k < 2; k++)
        {
            randomIndex = randomise_index(deck);
            for (int i = 0; i < 14; i++)
            {
                if (joueurs[id_joueur].cartes[i] <= 0) {
                    joueurs[id_joueur].cartes[i] = deck[randomIndex][0]; // Assigne une id de carte
                    break;
                }
            }
        }
    }
    for (int k = 0; k < nb_cartes_dist; k++)
    {

        randomIndex = randomise_index(deck);

        // Now randomIndex points to the randomly selected sub-array
        joueurs[id_joueur].cartes[k] = deck[randomIndex][0];
        deck[randomIndex][1] -= 1;
    }
}