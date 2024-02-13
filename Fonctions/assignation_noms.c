#include <stdio.h>
#include <string.h>

void assignerNomEtClasse(Joueurs *joueurs, int nombre_joueurs, int classes[][4]) {
    int i, random;
    char nom_joueur[50];

    for (i = 0; i < nombre_joueurs; i++)
    {
        printf("Joueur %d, quel est votre nom ? ", i + 1);
        scanf("%s", nom_joueur);            
        strcpy(joueurs[i].nom, nom_joueur); // Donne le nom au joueur

        while (1)
        { // Assignation de la classe
            random = rand() % 4;
            if (classes[nombre_joueurs - 3][random] != 0)
            {
                joueurs[i].classe = random;
                classes[nombre_joueurs - 3][random] -= 1;
                break;
            }
        }
    }
}
