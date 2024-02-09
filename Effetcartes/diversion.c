// Définition de la fonction Diversion
void Diversion(Joueurs *joueurs, int nombre_joueurs, int joueur) {
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
        printf("Choisissez le joueur à affecter (1-%d) : ", nombre_joueurs - 1);
        scanf("%d", &joueurCible);
        joueurCible--; 
    } while (joueurCible < 0 || joueurCible >= nombre_joueurs || joueurCible == joueur);

   
    int carteChoisie;
    do {
        carteChoisie = rand() % 7; 
    } while (joueurs[joueurCible].cartes[carteChoisie] == -1); 

    joueurs[joueur].cartes[0] = joueurs[joueurCible].cartes[carteChoisie];
    printf("%s a pioché une carte de %s.\n", joueurs[joueur].nom, joueurs[joueurCible].nom);

    defausserCarte(&joueurs[joueurCible], joueurs[joueurCible].cartes[carteChoisie]);
}
