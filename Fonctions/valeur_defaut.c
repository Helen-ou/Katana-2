#include <stdio.h>

    void modif_valeur_defaut(Joueurs *joueurs, int nb_joueurs)
{
    for (int i = 0; i < nb_joueurs; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            joueurs[i].cartes[j] = -1;
        }
    }
}