// Définition de la fonction CriDeGuerre
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CriDeGuerre(Joueurs *joueurs, int nombre_joueurs, int joueur_actif)
{
    // Afficher les joueurs disponibles
    printf("Joueurs disponibles :\n");
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (i != joueur_actif && joueurs[i].vies > 0)
        {
            printf("%d. %s\n", i + 1, joueurs[i].nom);
        }
    }

    // Demander au joueur de choisir le joueur affecté
    int choix;
    printf("Choisissez le joueur affecté (1-%d) : ", nombre_joueurs);
    scanf("%d", &choix);

    // Vérifier si le choix est valide
    if (choix < 1 || choix > nombre_joueurs)
    {
        printf("Choix invalide.\n");
        return;
    }

    // Récupérer l'indice du joueur choisi
    int index = choix - 1;

    // Vérifier si le joueur est à terre
    if (joueurs[index].vies <= 0)
    {
        printf("%s est à terre et n'est pas affecté par le Cri de guerre.\n", joueurs[index].nom);
        return;
    }

    // Demande au joueur s'il veut défausser une parade ou perdre un point de vie

    int choixAction;
    while (1)
    {
        printf("%s, vous devez défausser une parade ou perdre 1 point de vie.\n", joueurs[index].nom);
        printf("1. Défausser une parade\n");
        printf("2. Perdre 1 point de vie\n");
        scanf("%d", &choixAction);
        if (choixAction == 1 || choixAction == 2)
        {
            break;
        }
        else
        {
            printf("Votre choix n'est pas correct, veuillez le ressaisir.\n");
            continue;
        }
    }
    switch (choixAction)
    {
    case 1:
        printf("%s défausse une parade.\n", joueurs[index].nom);
        if (defausserCarte(joueurs, index, 19) == 1)
        {
            printf("L'effet de Cri de Guerre à été éxécuté.\n"); // l'ID de la parade est 19
            break;
        }
        else if (defausserCarte(joueurs, index, 19) == 2)
        {
            joueurs[index].vies--;
            printf("%s perd 1 point de vie à cause du Cri de guerre.\n", joueurs[index].nom);
            break; // Si le joueur ne possède pas de parade, il perd automatiquement 1 PV.
        }
        case 2:
            joueurs[index].vies--;
            printf("%s perd 1 point de vie à cause du Cri de guerre.\n", joueurs[index].nom);
            if (joueurs[index].vies <= 0)
            {
                printf("%s a été vaincu.\n", joueurs[index].nom);
            }
            printf("L'effet de Cri de Guerre à été éxécuté.\n");
            break;

        
    }
    defausserCarte(joueurs, joueur_actif, 13); // Défausse la carte Cri de Guerre
}