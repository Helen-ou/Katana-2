void defausserCarte(Joueurs *joueur, int id) {
    // Recherche de la carte dans le deck du joueur
    for (int i = 0; i < 7; i++) {
        if (joueur[id].cartes[i] == id) {

            joueur[id].cartes[i] = -1;
            printf("Le joueur %s a défaussé une carte avec l'id %d.\n", joueur[id].nom, id);
            return;
        }
    }

    printf("Le joueur %s ne possède pas de carte avec l'id %d.\n", joueur[id].nom, id);
}

