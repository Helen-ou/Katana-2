// Code qui gère la phase 2, phase de pioche de deux cartes.
#include <stdio.h>
#include <time.h>

void phase_2(Joueurs *joueurs, int joueur_actif, int nombre_joueurs) // Reitère pour chaque joueurs qui joue
{
    distribution(joueurs, joueur_actif, 2, nombre_joueurs); // Pioche deux cartes
}
