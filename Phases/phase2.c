#include <stdio.h>
#include "../Données/libraries.h"
#include <time.h>
#include "../Fonctions/piochercarte.c"


void phase_2(Joueurs *joueurs, int k) // Reitère pour chaque joueurs qui joue
{
    for (int i = 0; i < 7; i++)
    {
        if (joueurs[k].cartes[i] == 0)
        {
            break;
        }
        else
        {
            distribution(joueurs, k, deck, 2); // Pioche deux cartes
        }
    }
}
