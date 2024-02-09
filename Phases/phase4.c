#include <stdio.h>

void phase_4(Joueurs *joueurs, int k) // Reitère pour chaque joueur qui joue
{
    int index;
    int verification = 1;
    for (int i = 0; i < 7; i++)
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
        for (int i = 0; i < 7; i++)
        {
            if (joueurs[k].cartes[i] == 0)
                break;
            printf("%d. Carte %c\n", i + 1, joueurs[k].cartes[i]);
        }

        int choix;
        do
        {
            printf("Veuillez choisir la carte que vous souhaitez défausser (1-%d) : ", index);
            scanf("%d", &choix);
        } while (choix < 1);

        for (int i = choix - 1; i < index - 1; i++)
            joueurs[k].cartes[i] = joueurs[k].cartes[i + 1];

        joueurs[k].cartes[index - 1] = '\0';
        printf("La carte a été défaussée avec succès.\n");
    }
    else
    {
        printf("Le joueur %s possède 7 cartes ou moins, aucune défausse nécessaire.\n", joueurs[k].nom);
    }
}
