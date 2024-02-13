void Meditation(Joueurs *joueurs, int nombre_joueurs, int joueur_actif) {
    // Récupérer tous les points de vie du joueur actuel
    printf("%s utilise la carte Méditation et récupère tous ses points de vie.\n", joueurs[joueur_actif].nom);
    joueurs[joueur_actif].vies = cartes_personnage[joueurs[joueur_actif].index_perso][1];

    // Choisir un autre joueur pour piocher une carte
    printf("Choisissez un autre joueur pour piocher une carte :\n");
    for (int i = 0; i < nombre_joueurs; i++) {
        if (i != joueur_actif) {
            printf("%d. %s\n", i + 1, joueurs[i].nom);
        }
    }

    int joueurCible;
    scanf("%d", &joueurCible);
    joueurCible--;

    // Vérifier si le choix du joueur cible est valide
    if (joueurCible < 0 || joueurCible >= nombre_joueurs || joueurCible == joueur_actif) {
        printf("Choix invalide.\n");
        return;
    }

    // Piocher une carte pour le joueur cible
    int carteChoisie = rand() % 7; 
    joueurs[joueurCible].cartes[carteChoisie] = rand() % 25; // Supposons que le deck a 25 cartes au maximum

    printf("Le joueur %s pioche une carte.\n", joueurs[joueurCible].nom);
    printf("L'effet de Méditation à été éxécuté.\n");
}