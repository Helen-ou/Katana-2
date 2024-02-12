#include <stdio.h>

void phase_4(Joueurs *joueurs, int k) // Reitère pour chaque joueur qui joue
{
    int index = 0;
    int verification = 1;
    for (int i = 0; i < 15; i++)
    {
        if (joueurs[k].cartes[i] > 0)
        {
            index += 1;
            if (index > 7)
            {
                verification = 0;
                break;
            }
        }
    }

    if (verification == 0)
    {
        printf("Le joueur %s possède plus de 7 cartes :\n", joueurs[k].nom);
        for (int i = 0; i < 15; i++)
        {
            if (joueurs[k].cartes[i] > 0)
            {
                printf("%d. Carte %s\n", i + 1, deck_noms[joueurs[k].cartes[i]]);
            }
        }

        int choix;
        int doublon[7]; // éviter que la même carte soit retirée 2 fois
        do
        {
            do
            {
                printf("Veuillez choisir la carte que vous souhaitez défausser  : ");
                scanf("%d", &choix);
                for (int j = 0; j < 7; j++)
                {
                    if (choix == doublon[j])
                    {
                        verification = 1 break
                    }
                    else
                    {
                        verification = 0;
                    }
                }
            } while (choix < 1 && verification == 1);

            printf("Ceci est le variable Index : %d\n", index);

            for (int i = choix - 1; i < index - 1; i++)
                joueurs[k].cartes[i] = joueurs[k].cartes[i + 1];

            joueurs[k].cartes[index - 1] = '\0';
            printf("La carte a été défaussée avec succès.\n");
            index -= 1;
        } while (index > 7);
    }
    else
    {
        printf("Le joueur %s possède 7 cartes ou moins, aucune défausse nécessaire.\n", joueurs[k].nom);
    }
}
