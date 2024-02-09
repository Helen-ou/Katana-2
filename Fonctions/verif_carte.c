#include <stdio.h>

int verif_carte(Joueurs *joueurs, int joueur_actif, char carte_joue[25])
{
    char nom_carte[25];
    for (int i = 0; i < 14; i++)
    {
        strcpy(nom_carte, deck_noms[joueurs[joueur_actif].cartes[i]]);
        if (strcmp(nom_carte, carte_joue) == 0)
        {
            return 1;
        }
    }
    return 0;
}