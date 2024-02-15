#include <stdio.h>
#include <stdlib.h>

// Définition de la fonction Ju Jitsu

void JuJitsu(Joueurs *joueurs, int nombre_joueurs, int joueur_actif, int deck[25][5])
{
    int choix = 0;
    int arme_existe = 0;
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (i != joueur_actif && joueurs[i].vies > 0)
        {
            while (1)
            {
                printf("%s, rentrez 1 si vous préférez défausser une arme et 2 si vous préférez perdre un PV : ", joueurs[i].nom);
                scanf("%d", &choix);
                for (int j = 0; j < 14; j++)
                {
                    if (deck[joueurs[i].cartes[j]][2] > 0)
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
                afficherCartesAttaques(joueurs, i);
                char arme_defausse[25];
                int breaking = 0; // Pour sortir de while
                int id_carte;

                while (1)
                { // Question arme à défausser
                    printf("Entrez le nom de la carte que vous voulez jouer :\n");
                    char arme_defausse[25];
                    scanf("%s", &arme_defausse);

                    for (int i = 0; i < 14; i++)
                    {
                        if (strcmp(arme_defausse, deck_noms[i]) == 0)
                        {
                            id_carte = i;
                            breaking = 1;
                        }
                    }
                    if (breaking)
                    {
                        break;
                    }
                    else
                    {
                        printf("Le nom que vous avez rentré n'est pas correct !\n");
                        continue;
                    }
                }

                // Défausser carte
                defausserCarte(joueurs, i, id_carte);
            }
            else
            {
                joueurs[i].vies -= 1;
            }
        }

        printf("L'effet de Jujitsu à été éxécuté.\n");
    }
}
