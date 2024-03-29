// Code qui prend en charge le fonctionnement de l'attaque
#include <stdio.h>
#include <stdlib.h>
#include "diff_attaque.c"

int attaque(Joueurs *joueurs, int precision, int degat, int nb_joueurs, int position[2])
{
    // Définition de la distance entre joueurs
    int parade = 0;
    int distance = diff_attaque(joueurs, position[0], position[1], nb_joueurs);
    if (joueurs[position[1]].vies <= 0)
    {
        printf("Le joueur que vous souhaitez attaquer n'a déjà plus de vies !\n");
        return 1;
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
            if (joueurs[position[1]].cartes[i] == 18) // L'ID de la carte parade est 18
            {
                while (1)
                { // Boucle si joueur ne mets pas une entrée correcte ; Parade
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
                        return 0;
                    }
                    printf("Veuillez écrire soit 'oui' soit 'non'.\n");
                }
            }
        }
        if (parade == 0)
        {   // Affiche le résultat de l'attaque et calcule la perte de points d'honneur
            int bonus_attaque = joueurs[position[1]].attaque_rapide;
            if (bonus_attaque > 0 && bonus_attaque < 11)
            {

            } else
            {
                bonus_attaque = 0;
            }
            degat += bonus_attaque;
            printf("%s infligez %d dégats à %s\n", joueurs[position[0]].nom, degat, joueurs[position[1]].nom);
            joueurs[position[1]].vies -= degat;
            if (joueurs[position[1]].vies <= 0)
            {
                joueurs[position[1]].honneur -= 1;
                joueurs[position[0]].honneur += 1;
            }
            return 0;
        }
    }
    return 0;
}
