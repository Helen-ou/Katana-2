// Définition de la fonction CriDeGuerre
#include <stdio.h>
#include <stdlib.h>

void CriDeGuerre(Joueurs *joueurs, int nombre_joueurs)
{
    // Afficher les joueurs disponibles
    printf("Joueurs disponibles :\n");
    for (int i = 0; i < nombre_joueurs; i++)
    {
        printf("%d. %s\n", i + 1, joueurs[i].nom);
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
    while (1)
    {
        printf("%s, vous devez défausser une parade ou perdre 1 point de vie.\n", joueurs[index].nom);
        printf("1. Défausser une parade\n");
        printf("2. Perdre 1 point de vie\n");
        int choixAction;
        scanf("%d", &choixAction);
        if (strcmp((choixAction, "1") == 0) || (strcmp(choixAction, "2"), == 0))
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
        defausserCarte(joueurs, index, 19); // Suppose que l'ID de la parade est 19
        break;
        printf("L'effet de Cri de Guerre à été éxécuté.\n");
    case 2:
        joueurs[index].vies--;
        printf("%s perd 1 point de vie à cause du Cri de guerre.\n", joueurs[index].nom);
        if (joueurs[index].vies <= 0)
        {
            printf("%s a été vaincu.\n", joueurs[index].nom);
        }
        printf("L'effet de Cri de Guerre à été éxécuté.\n");
        break;

    default:
        printf("Choix invalide.\n");
    }
}