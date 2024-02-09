#include <stdio.h>
#include <time.h>

void phase_2(Joueurs *joueurs, int joueur_actif) // Reitère pour chaque joueurs qui joue
{
    distribution(joueurs, joueur_actif, deck, 2); // Pioche deux cartes
}
