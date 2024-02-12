// Va gérer l'attaque d'un joueur sur un autre
#include <stdio.h>
#include <stdlib.h>

#include "diff_attaque.c"

void attaque(Joueurs *joueurs, int precision, int degat, int nb_joueurs, int position[2])
{
    int parade;
    int distance = diff_attaque(joueurs, position[0], position[1], nb_joueurs);
    if (joueurs[position[1]].vies <= 0)
    {
        printf("Le joueur que vous souhaitez attaquer n'a déjà plus de vies !\n");
        return;
    }
    if (precision >= distance)
    {
        // Vérifier si le joueur visé à une carte parade
        for (int i = 0; i < 7; i++)
        {
            if (joueurs[position[1]].cartes[i] == 19) // Si id carte vaut id 19 pour parade
            {
                while (1)
                { // Boucle si joueur ne mets pas une entrée correcte ; parade
                    printf("%s, souhaitez-vous utiliser votre carte parade ? Rentrez 'oui' ou 'non'", joueurs[position[1]].nom);
                    char string[3];
                    scanf("%s", string);
                    if (string == "non")
                    {
                        printf("\n%s reçoit normalement %d dégats\n", joueurs[position[1]].nom, degat);
                        joueurs[position[1]].vies -= degat;
                        return;
                    }
                    else if (string == "oui")
                    {
                        printf("\n Votre carte parade annule tout vos dégats\n");
                        parade = 1;
                        return;
                    }
                }
            }
            if (parade == 0)
            {
                printf("%s infligez %d dégats à %s\n", joueurs[position[0]].nom, degat, joueurs[position[1]].nom);
                joueurs[position[1]].vies -= degat;
                return;
            }
        }
    }
}