#include <stdio.h>

void afficherCartes(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 7; i++)
    {
        if (joueurs[k].cartes[i] == 0)
        {
            break;
        }
        else
        {
            printf("Le joueur %s possède %d carte(s).\n", joueurs[k].nom, joueurs[k].cartes[i]);
        }
    }
}
