// Code qui gère le calcul final des points
#include <stdio.h>

void point_calcul(Joueurs *joueurs, int nb_joueurs)
{
    // Rajouter point si carte Daimyo
    for (int i = 0; i < nb_joueurs; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            if (joueurs[i].cartes[j] == 15)
            {
                joueurs[i].honneur += 1;
            }
        }
    }
    int multiplicateurs[5][4] = {{2, 0, 1, 0}, {1, 2, 1.5, 0}, {1, 1, 1, 2}, {1, 2, 1, 3}, {1, 1, 1, 3}};
    char nom_factions[4][20] = {"Shogun", "Samouraï", "Ninja", "Ronin"};
    int points_factions[4] = {0, 0, 0, 0};
    // Créer le tableau points_factions avec les points de chaque faction
    for (int i = 0; i < nb_joueurs; i++)
    {
        switch (joueurs[i].classe)
        {
        case 0:
            points_factions[0] += joueurs[i].honneur * multiplicateurs[nb_joueurs - 3][0];
            break;
        case 1:
            points_factions[1] += joueurs[i].honneur * multiplicateurs[nb_joueurs - 3][1];
            break;
        case 2:
            points_factions[2] += joueurs[i].honneur * multiplicateurs[nb_joueurs - 3][2];
            break;
        case 3:
            points_factions[3] += joueurs[i].honneur * multiplicateurs[nb_joueurs - 3][3];
            break;
        }
    }

    
    // Afficher l'équipe victorieuse et les points
    int tableau_trie[4][2];     // {points_max, id_max}
    for (int i = 0; i < 4; i++) // Tri des cartes
    {
        int points_max = 0;
        int id_max = 0;
        for (int j = 0; j < 4; j++)
        {
            if (points_max < points_factions[j])
            {
                points_max = points_factions[j];
                id_max = j;
            }
        }
        tableau_trie[i][0] = points_max;
        tableau_trie[i][1] = id_max;
        points_factions[id_max] = -100;
    }
    
    printf("La faction gagnante est %s avec %d points, félicitations !\n", nom_factions[tableau_trie[0][1]], tableau_trie[0][0]);
    
}