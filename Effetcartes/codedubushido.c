// Fonction pour choisir un joueur et placer la carte "Code du bushido" devant ce joueur
void CodeDuBushido(Joueurs *joueurs, int nb_joueurs, int joueur_actif)
{
    // Afficher les joueurs disponibles
    printf("Joueurs disponibles :\n");
    for (int i = 0; i < nb_joueurs; i++)
    {
        if (i != joueur_actif && joueurs[i].vies > 0)
        {
            printf("%d. %s\n", i + 1, joueurs[i].nom);
        }
    }

    // Demander au joueur de choisir le joueur affecté
    int choix;
    printf("Choisissez le joueur affecté (1-%d) : ", nb_joueurs);
    scanf("%d", &choix);

    // Vérifier si le choix est valide
    if (choix < 1 || choix > nb_joueurs)
    {
        printf("Choix invalide.\n");
        return;
    }

    // Récupérer l'indice du joueur choisi
    int index = choix - 1;

    // Placer le Code du bushido devant le joueur choisi
    if (!joueurs[index].code_bushido)
    {
        joueurs[index].code_bushido = true;
        printf("Le Code du bushido est placé devant %s.\n", joueurs[index].nom);
    }
    else
    {
        printf("Le Code du bushido est déjà placé devant %s.\n", joueurs[index].nom);
    }
}

// Fonction pour l'action de la carte "Code du bushido"
void actionCodeBushido(Joueurs *joueurs, int joueur_actif, int nb_joueurs)
{
    distribution(joueurs, joueur_actif, 1, nb_joueurs);

    // Si la carte piochée est une arme, faire défausser une autre carte arme
    if (joueurs[joueur_actif].cartes[0] >= 0 && joueurs[joueur_actif].cartes[0] <= 12)
    {
        printf("La carte piochée est une arme. Une autre carte arme sera défaussée.\n");
        // Chercher une autre carte arme dans la main du joueur et la défausser
        for (int i = 1; i < 14; i++)
        {
            if (joueurs[joueur_actif].cartes[i] >= 0 && joueurs[joueur_actif].cartes[i] <= 12 && joueurs[joueur_actif].cartes[i] != joueurs[joueur_actif].cartes[0])
            {
                printf("%s défausse une autre carte arme avec l'ID %d.\n", joueurs[joueur_actif].nom, joueurs[joueur_actif].cartes[i]);
                joueurs[joueur_actif].cartes[i] = -1; // Défausser la carte arme
                int choix_bushido;
                printf("Choisissez de donner le Code du Bushido  au joueur à gauche (1) ou de perdre 1 point d'honneur (2): ");
                scanf("%d", &choix_bushido);
                if (choix_bushido == 1)
                {
                    // Passer au joueur à gauche
                    if (joueur_actif == 0)
                    {
                        joueurs[joueur_actif].code_bushido = false;
                        joueurs[nb_joueurs].code_bushido = true;
                    }
                    else
                    {
                        joueurs[joueur_actif].code_bushido = false;
                        joueurs[joueur_actif - 1].code_bushido = false;
                    }
                }
                else
                {
                    joueurs[joueur_actif].honneur -= 1;
                }
                break;
            }
        }
    }
    else
    {
        printf("La carte piochée n'est pas une arme. Elle est défaussée.\n");
    }

    // Défausser la carte piochée à la fin de l'action du Code du bushido
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[joueur_actif].cartes[i] >= 0)
        {
            printf("%s défausse la carte piochée avec l'ID %d.\n", joueurs[joueur_actif].nom, joueurs[joueur_actif].cartes[i]);
            joueurs[joueur_actif].cartes[i] = -1; // Défausser la carte piochée
            break;
        }
    }
}

void verifierCodeBushido(Joueurs *joueurs, int joueur_actif, int nb_joueurs)
{
    // Vérifier si le joueur a le Code du bushido devant lui
    if (joueurs[joueur_actif].code_bushido)
    {
        printf("%s a le Code du bushido devant lui.\n", joueurs[joueur_actif].nom);
        actionCodeBushido(joueurs, joueur_actif, nb_joueurs); // Lancer l'action du Code du bushido
    }
}
