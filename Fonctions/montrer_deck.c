// Code permetant d'afficher les différentes cartes de manière séparées
#include <stdio.h>

// Affiche toute les cartes d'un joueur en particulier
void afficherCartes(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if(joueurs[k].cartes[i]>-1)
        {
            int id_carte = joueurs[k].cartes[i];
            printf("%s possède %s.\n", joueurs[k].nom, deck_noms[id_carte]);
        }
    }
}

// Affiche toute les cartes permanantes d'un joueur
void afficherCartesPerma(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if (deck[joueurs[k].cartes[i] ][4] == true && joueurs[k].cartes[i] > -1)
        {
            int id_carte = joueurs[k].cartes[i];
            printf("Le joueur %s possède %s.\n", joueurs[k].nom, deck_noms[id_carte]);
        }
    
    }
}

// Affiche toute les cartes d'action d'un joueur
void afficherCartesActions(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if (deck[joueurs[k].cartes[i]][2] == -1 && deck[joueurs[k].cartes[i]][4] == false && joueurs[k].cartes[i]>-1)
        { 
            int id_carte = joueurs[k].cartes[i];
            printf("Le joueur %s possède %s.\n", joueurs[k].nom, deck_noms[id_carte]);
        }

    }
}

// Affiche toute les cartes d'attaque d'un joueur
void afficherCartesAttaques(Joueurs *joueurs, int k)
{
    for (int i = 0; i < 14; i++)
    {
        if (deck[joueurs[k].cartes[i]][2] > 0 && joueurs[k].cartes[i]>-1)
        {
            int id_carte = joueurs[k].cartes[i];
            printf("Le joueur %s possède %s qui a %d d'attaque et %d de précision.\n", joueurs[k].nom, deck_noms[id_carte], deck[joueurs[k].cartes[i]][3], deck[joueurs[k].cartes[i]][2]);
        }
        
    }
}