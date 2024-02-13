#include <stdio.h>

void afficherCartes(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[k].cartes[i] < 0)
        {
            break;
        }
        else
        {
            int id_carte = joueurs[k].cartes[i];
            printf("%s possède %s d'id %d.\n", joueurs[k].nom, deck_noms[id_carte],joueurs[k].cartes[i]);
        }
    }
}

void afficherCartesPerma(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[k].cartes[i] == 0)
        {
            break;
        }
        else
        {
            if (deck[joueurs[k].cartes[i] ][4] == true)
            {
                int id_carte = joueurs[k].cartes[i];
                printf("Le joueur %s possède %s.\n", joueurs[k].nom, deck_noms[id_carte]);
            }
        }
    }
}

void afficherCartesActions(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[k].cartes[i] == 0)
        {
            break;
        }
        else
        {
            if (deck[joueurs[k].cartes[i]][2] == -1 && deck[joueurs[k].cartes[i]][4] == false)
            { 
                int id_carte = joueurs[k].cartes[i];
                printf("Le joueur %s possède %s.\n", joueurs[k].nom, deck_noms[id_carte]);
            }
        }
    }
}

void afficherCartesAttaques(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[k].cartes[i] == 0)
        {
            break;
        }
        else
        {
            if (deck[joueurs[k].cartes[i]][2] > 0)
            {
                int id_carte = joueurs[k].cartes[i];
                printf("Le joueur %s possède %s qui a %d d'attaque et %d de précision.\n", joueurs[k].nom, deck_noms[id_carte], deck[joueurs[k].cartes[i]][3], deck[joueurs[k].cartes[i]][2]);
            }
        }
    }
}