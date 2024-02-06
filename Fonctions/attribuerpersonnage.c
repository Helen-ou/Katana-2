#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void attribuerPersonnage(Joueurs *joueurs, int nb_joueurs, int cartes_personnage[][2], char nom_cartes_personnages[][25])
{
    // Initialisation du générateur de nombres aléatoires
    int i = 0; // boucler
    // Vérification si tous les personnages ont déjà été attribués
    int index_personnage;
    for (i; i < nb_joueurs; i++)
    {
        // Cherche nombre random
        while (1)
        {
            index_personnage = rand() % 12;
            if (cartes_personnage[index_personnage][0] != -1)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        // Génération d'un index aléatoire pour choisir un personnage
        // Attribution du personnage au joueur
        strcpy(joueurs[i].personnage, nom_cartes_personnages[index_personnage]);
        joueurs[i].index_perso = index_personnage;
        joueurs[i].vies = cartes_personnage[index_personnage][1];
        printf("Joueur %d - Personnage : %s, PDV : %d\n", i + 1, joueurs[i].personnage, joueurs[i].vies);

        // "Retire" le personnage du tableau en lui donnant un ID spécial (par exemple, -1)
        cartes_personnage[index_personnage][0] = -1;
    }
}
