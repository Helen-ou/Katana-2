// Définition de la fonction Ju Jitsu
void JuJitsu(Joueurs *joueurs, int nombre_joueurs, int joueur) {
    // Parcourir tous les joueurs sauf le joueur actuel
    for (int i = 0; i < nombre_joueurs; i++) {
        if (i != joueur) {
            // Vérifier si le joueur n'est pas à terre (a plus de 0 PV)
            if (joueurs[i].vies > 0) {
                printf("%s doit défausser une arme ou perdre 1 point de vie.\n", joueurs[i].nom);
                
                // Demander au joueur de choisir entre défausser une arme ou perdre 1 point de vie
                printf("1. Défausser une arme\n");
                printf("2. Perdre 1 point de vie\n");
                
                int choix;
                scanf("%d", &choix);

                switch (choix) {
                    case 1:
                        printf("%s défausse une arme.\n", joueurs[i].nom);
                        // Défausser une arme ayant un ID de 1 à 13
                        for (int j = 0; j < 7; j++) {
                            if (joueurs[i].cartes[j] >= 1 && joueurs[i].cartes[j] <= 13) {
                                defausserCarte(joueurs, joueurs[i].cartes[j]);
                                break; // Sortir de la boucle une fois qu'une arme est défaussée
                            }
                        }
                        break;
                    case 2:
                        printf("%s perd 1 point de vie.\n", joueurs[i].nom);
                        joueurs[i].vies--;
                        break;
                    default:
                        printf("Choix invalide pour %s.\n", joueurs[i].nom);
                }
            } else {
                printf("%s est à terre et n'est pas affecté par Ju Jitsu.\n", joueurs[i].nom);
            }
        }
    }
    printf("L'effet de Jujitsu à été éxécuté.\n");
}