// Code qui gère la distribution de cartes au joueurs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomise_index()
{
    // Choisis un index aléatoire
    int total = 0;
    for (int i = 0; i < 25; i++)
    {
        total += deck[i][1];
    }
    int random_Index = rand() % total;

    // Ajuste l'index aléatoire en ajoutant au fur et à mesure les cartes
    int cumulativeCount = 0;
    for (int i = 0; i < 25; i++)
    {
        cumulativeCount += deck[i][1];
        if (random_Index < cumulativeCount)
        {
            return i;
        }
    }
}

// S'il n'y a plus de cartes dans le deck
int deck_vide()
{
    for (int i = 0; i < sizeof(deck) / sizeof(deck[0]); i++)
    {
        if (deck[i][1] > 0)
        {
            return 0; // S'il reste encore une carte, la distribue
        }
    }
    return 1;
}

void remettre_defausse(Joueurs *joueurs, int nb_joueurs)
{
    // Réinitialise le tableau deck
    int(*deck)[5] = defausse;
    // Boucle dans les joueurs pour enlever les cartes déjà présentes
    for (int i = 0; i < nb_joueurs; i++)
    {
        for (int j = 0; j < 15; j++) // 15 = nombre de cartes max dans un deck à un moment t
        {
            if (joueurs[i].cartes[j] > 0)
            {
                deck[j][1] -= 1; // Enlève un exemplaire du deck dédoublé
            }
        }
    }
}

void distribution(Joueurs *joueurs, int id_joueur, int nb_cartes_dist, int nb_joueurs)
{
    int randomIndex;
    if (deck_vide() == 1)
    {
        remettre_defausse(joueurs, nb_joueurs);
    }
    if (nb_cartes_dist == 2) // Distribution pas au tour 1
    {
        for (int k = 0; k < 2; k++)
        {
            randomIndex = randomise_index(deck);
            for (int i = 0; i < 14; i++)
            {
                if (joueurs[id_joueur].cartes[i] < 0)
                {
                    joueurs[id_joueur].cartes[i] = randomIndex; // Assigne une ID de carte
                    deck[randomIndex][1] -= 1;                  // Décrémente les cartes
                    break;
                }
            }
        }
        return;
    }
    for (int k = 0; k < nb_cartes_dist; k++)
    {
        randomIndex = randomise_index(deck);
        joueurs[id_joueur].cartes[k] = randomIndex;
        deck[randomIndex][1] -= 1;
    }
}