#include <stdio.h>
#include <stdlib.h>

#include "phase2.c"
#include "phase3.c"
#include "phase4.c"
// Va gérer la récup de PV
void phase_1(Joueurs *joueurs, int nb_joueurs, int joueur_actif)
{
    printf("Nous allons procéder à la phase de récupération de %s\n", joueurs[joueur_actif].nom);
    if (joueurs[joueur_actif].vies <= 0)
    {
        joueurs[joueur_actif].vies = recup_pdv(joueurs, joueur_actif);
    }
}