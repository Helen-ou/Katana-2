#include <stdio.h>
#include <stdlib.h>

// Définition de la fonction Ju Jitsu

void JuJitsu(Joueurs *joueurs, int nombre_joueurs, int joueur_actif)
{
    int choix = 0;
    int arme_existe = 0;
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (i != joueur_actif && joueurs[i].vies > 0)
        {
            while (1)
            {
                printf("Rentrez 1 si vous préférez défausser une arme et 2 si vous préférez perdre un PV : ");
                scanf("%d", &choix);
                for (int j = 0; j < 14; j++)
                {
                    if (joueurs[i].cartes[j] > 0 && joueurs[i].cartes[j] < 14)
                    {   
                        arme_existe = 1;
                        break;
                    }
                }
                if ((choix == 1 && arme_existe == 1) || choix == 2)
                {
                    break;
                }
                else
                {
                    printf("Le nombre que vous avez renseigné n'est pas valide\n");
                }
            }

            if (choix == 1)
            {
                printf("Parmi ces armes, lesquels souhaitez vous défausser ?\n");
                int compteur;
                for (int j = 0; i < 14; i++)
                { // Nombre d'armes dans le deck & énonciation au joueur
                    if (joueurs[i].cartes[j] > 0 && joueurs[i].cartes[j] < 14)
                    {
                        printf("%s ayant %d attaque et %d précision", deck_noms[joueurs[i].cartes[j]], deck[joueurs[i].cartes[j]][2], deck[joueurs[i].cartes[j]][3]);
                        compteur += 1;
                    }
                }
                int arme_defausse;
                while (1)
                { // Question arme à défausser
                    printf("Choisissez quelle arme vous souhaitez défausser (1-%d)", compteur);
                    scanf("%d", arme_defausse);
                    if (arme_defausse > compteur || arme_defausse < 0)
                    {
                        printf("Vous avez rentré un chiffre trop grand ou trop petit !");
                        continue;
                    }
                }
                int compteur_2 = 0;
                // Défausser carte
                for (int j = 0; i < 14; i++)
                {
                    if (joueurs[i].cartes[j] > 0 && joueurs[i].cartes[j] < 14)
                    {
                        compteur_2 += 1;
                        if (compteur == compteur_2)
                        {
                            joueurs[i].cartes[j] = -1;
                        }
                    }
                }
            }
            else
            {
                joueurs[i].vies -= 1;
            }
            printf("L'effet de Jujitsu à été éxécuté.\n");
        }
    }
}