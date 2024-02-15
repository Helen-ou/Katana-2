 // Définition de la carte Daimyo
void Daimyo(Joueurs *joueurs, int k, int deck[60][5], int nombre_joueurs) {
    printf("Pioche deux cartes.\n");
    distribution(joueurs, k, 2, nombre_joueurs); // Pioche deux cartes
    printf("L'effet de Daimyo à été éxécuté.\n");
}
