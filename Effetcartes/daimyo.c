 // Définition de la carte Daimyo
void Daimyo(Joueurs *joueurs, int k, int deck[60][5]) {
    printf("Pioche deux cartes.\n");
    distribution(joueurs, k, deck, 2); // Pioche deux cartes
    printf("L'effet de Daimyo à été éxécuté.\n");
}
