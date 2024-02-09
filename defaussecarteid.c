void defausserCarte(Joueurs joueur, int ID) {
    // Recherche de la carte dans le deck du joueur
    for (int i = 0; i < 7; i++) {
        if (joueur.cartes[i] == ID) {

            joueur.cartes[i] = -1;
            printf("Le joueur %s a défaussé une carte avec l'ID %d.\n", joueur.nom, ID);
            return;
        }
    }

    printf("Le joueur %s ne possède pas de carte avec l'ID %d.\n", joueur.nom, ID);
}

