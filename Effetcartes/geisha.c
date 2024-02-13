#include <stdio.h>
#include <string.h>

// Définition de la fonction Geisha
void Geisha(Joueurs *joueurs, int nombre_joueurs, int joueur_actif)
{
    // Demander au joueur de choisir l'action
    printf("%s, choisissez une action :\n", joueurs[joueur_actif].nom);
    printf("1. Défausser une carte permanente en jeu\n");
    printf("2. Piocher une carte au hasard d'un autre joueur\n");

    int choix;
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
    {
        // Les cartes permanentes ont des IDs de 21 à 24
        printf("%s choisit de défausser une carte permanente en jeu.\n", joueurs[joueur_actif].nom);
        int cartes_perma_possedes[4];
        int compteur = 0;
        // On cherche les cartes du joueur
        for (int i = 0; i < 14; i++)
        {
            if (joueurs[joueur_actif].cartes[i] >= 21)
            {
                cartes_perma_possedes[compteur] = i;
                compteur += 1;
            }
        }
        // On cherche une carte random
        if (compteur > 0)
        {
            int random = rand() % compteur;
            joueurs[joueur_actif].cartes[cartes_perma_possedes[random]] = -1;
            return;
        }
        else
        {
            printf("Aucune carte permanente en jeu dans la main de %s.\n", joueurs[joueur_actif].nom);
            return;
        }
    }
    case 2:
    {
        // Piocher une carte au hasard d'un autre joueur
        printf("%s choisit de piocher une carte au hasard d'un autre joueur.\n", joueurs[joueur_actif].nom);

        // Afficher les joueurs disponibles avec leurs indices
        printf("Joueurs disponibles :\n");
        for (int i = 0; i < nombre_joueurs; i++)
        {
            if (i != joueur_actif)
            {
                printf("%s\n", joueurs[i].nom);
            }
        }

        // Demander au joueur de choisir le joueur cible
        char joueur_cible[25];
        int joueur_valide = 0;
        while (1)
        {
            printf("Rentrez le nom du joueur que vous souhaitez cibler : ");
            scanf("%s", &joueur_cible);
            for (int i = 0; i < nombre_joueurs; i++)
            {
                if (strcmp(joueur_cible, joueurs[i].nom) == 0)
                {
                    joueur_valide = 1;
                }
            }
            if (joueur_valide == 1)
            {
                break;
            }
            else
            {
                printf("Le nom que vous avez saisi n'est pas valide !\n");
            }
        }
        int id_joueur;
        for (int i = 0; i < 7; i++)
        {
            if (strcmp(joueurs[i].nom, joueur_cible) == 0)
            {
                id_joueur = i;
            }
        }
        echanger_carte(joueurs, joueur_actif, id_joueur);
    }
    default:
        printf("Choix invalide.\n");
    }
    printf("L'effet de Geisha à été éxécuté.\n");
}