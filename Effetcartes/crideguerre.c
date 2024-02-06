void CriDeGuerre(Joueurs *joueur) {
    // Vérifier si le joueur est à terre
    if (joueur->vies <= 0) {
        printf("%s est à terre et n'est pas affecté par le Cri de guerre.\n", joueur->nom);
        return;
    }

    // Réduire les points de vie du joueur de 1
    joueur->vies--;

    printf("%s perd 1 point de vie à cause du Cri de guerre.\n", joueur->nom);
    // Vérifier si le joueur est vaincu
    if (joueur->vies <= 0) {
        printf("%s a été vaincu.\n", joueur->nom);
        // Autres actions à effectuer lorsqu'un joueur est vaincu
    }
}


// AJOUTER EFFET PARADE