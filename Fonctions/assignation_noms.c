// Assigne le nom des joueurs, leur classe et initialise les points d'honneur des joueurs.
#include <stdio.h>
#include <string.h>

void assignerNomEtClasse(Joueurs *joueurs, int nombre_joueurs, int classes[][4])
{
    int i, random;
    char nom_joueur[25];

    for (i = 0; i < nombre_joueurs; i++)
    {
        printf("Joueur %d, quel est votre nom ? ", i + 1);
        scanf("%s", nom_joueur);
        strcpy(joueurs[i].nom, nom_joueur); // Donne le nom au joueur

        while (1)
        { // Assignation de la classe en brute force
            random = rand() % 4;
            if (classes[nombre_joueurs - 3][random] != 0)
            {
                joueurs[i].classe = random;
                classes[nombre_joueurs - 3][random] -= 1;
                break;
            }
        }
    }
    // Assigner points d'honneur
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (joueurs[i].classe == 0) // Si shogun
        {
            joueurs[i].honneur = 5;
        }
        else if (nombre_joueurs == 4 || nombre_joueurs == 5)
        {
            joueurs[i].honneur = 3;
        }
        else
        {
            joueurs[i].honneur = 5;
        }
    }
    // Mettre armure à valeur par défaut
    for (int i = 0; i < nombre_joueurs; i++)
    {
        joueurs[i].armure = 1;
    }
}
