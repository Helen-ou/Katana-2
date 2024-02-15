// Code qui gère la phase 1, phase de récupération des PDVs. 
#include <stdio.h>
#include <stdlib.h>

#include "phase2.c"
#include "phase3.c"
#include "phase4.c"

void phase_1(Joueurs *joueurs, int nb_joueurs, int joueur_actif)
{
    printf("Nous allons procéder à la phase de récupération de %s\n", joueurs[joueur_actif].nom);
    if (joueurs[joueur_actif].vies <= 0)
    {
        joueurs[joueur_actif].vies = recup_pdv(joueurs, joueur_actif);
    }
    verifierCodeBushido(joueurs, joueur_actif, nb_joueurs);
}

