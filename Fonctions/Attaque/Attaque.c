// Va gérer l'attaque d'un joueur sur un autre
#include <stdio.h>
#include <stdlib.h>

#include "diff_attaque.c"

void attaque(Joueurs *joueurs, int precision, int degat, int nb_joueurs, int position[2])
{
    int parade = 0;
    int distance = diff_attaque(joueurs, position[0], position[1], nb_joueurs);
    if (joueurs[position[1]].vies <= 0)
    {
        printf("Le joueur que vous souhaitez attaquer n'a déjà plus de vies !\n");
        return;
    }
    if (precision >= distance)
    {
        int stop = 0;
        char string[3];
        printf("La fonction attaque s'est bien lancée \n");
        // Vérifier si le joueur visé à une carte parade
        for (int i = 0; i < 14; i++)
        {
            if (stop == 1)
            {
                break;
            }
            if (joueurs[position[1]].cartes[i] == 18) // Si id carte vaut id 19 pour parade
            {
                while (1)
                { // Boucle si joueur ne mets pas une entrée correcte ; parade
                    printf("%s, souhaitez-vous utiliser votre carte parade ? Rentrez 'oui' ou 'non' : ", joueurs[position[1]].nom);
                    scanf("%s", string);
                    if (strcmp(string, "non") == 0)
                    {
                        stop = 1;
                        break;
                    }
                    else if (strcmp(string, "oui") == 0)
                    {
                        printf("\n Votre carte parade annule tout vos dégats\n");
                        joueurs[position[1]].cartes[i] = -1;
                        parade = 1;
                        return;
                    }
                    printf("Veuillez écrire soit 'oui' soit 'non'.\n" );
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
