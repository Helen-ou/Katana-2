#include <stdio.h>
#include <string.h>

// Définition de la fonction Geisha
void Diversion(Joueurs *joueurs, int nombre_joueurs, int joueur_actif)
{
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