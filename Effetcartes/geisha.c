// Définition de la fonction Geisha
void Geisha(Joueurs *joueurs, int nombre_joueurs, int joueur) {
    // Demander au joueur de choisir l'action
    printf("%s, choisissez une action :\n", joueurs[joueur].nom);
    printf("1. Défausser une carte permanente en jeu\n");
    printf("2. Piocher une carte au hasard d'un autre joueur\n");

    int choix;
    scanf("%d", &choix);

    switch (choix) {
        case 1: {
            // Les cartes permanentes ont des IDs de 21 à 24
            printf("%s choisit de défausser une carte permanente en jeu.\n", joueurs[joueur].nom);
            for (int i = 0; i < 7; i++) {
                if (joueurs[joueur].cartes[i] >= 21 && joueurs[joueur].cartes[i] <= 24) {
                    defausserCarte(&joueurs[joueur], joueurs[joueur].cartes[i]);
                    return; 
                }
            }
            printf("Aucune carte permanente en jeu dans la main de %s.\n", joueurs[joueur].nom);
            break;
        }
        case 2: {
            // Piocher une carte au hasard d'un autre joueur
            printf("%s choisit de piocher une carte au hasard d'un autre joueur.\n", joueurs[joueur].nom);

            // Afficher les joueurs disponibles avec leurs indices
            printf("Joueurs disponibles :\n");
            for (int i = 0; i < nombre_joueurs; i++) {
                if (i != joueur) {
                    printf("%d. %s\n", i + 1, joueurs[i].nom);
                }
            }

            // Demander au joueur de choisir le joueur cible
            int joueurCible;
            do {
                printf("Choisissez le joueur à cibler (1-%d) : ", nombre_joueurs - 1);
                scanf("%d", &joueurCible);
                joueurCible--; // Pour convertir de l'indice humain à l'indice du tableau
            } while (joueurCible < 0 || joueurCible >= nombre_joueurs || joueurCible == joueur);

            // Piocher une carte au hasard de la main du joueur cible
            int carteChoisie;
            do {
                carteChoisie = rand() % 7; // On suppose que chaque joueur a une main de 7 cartes
            } while (joueurs[joueurCible].cartes[carteChoisie] == -1); // Si la carte est invalide, piochez à nouveau

            // Ajouter cette carte à la main du joueur actuel
            // PiocherCarte(&joueurs[joueur], joueurs[joueurCible].cartes[carteChoisie]); A FAIRE!!!!!!!!
            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            printf("%s a pioché une carte de %s.\n", joueurs[joueur].nom, joueurs[joueurCible].nom);

            // Défausser cette carte de la main du joueur cible
            defausserCarte(&joueurs[joueurCible], joueurs[joueurCible].cartes[carteChoisie]);
            break;
        }
        default:
            printf("Choix invalide.\n");
    }
    printf("L'effet de Geisha à été éxécuté.\n");
}