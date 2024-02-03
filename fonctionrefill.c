void refillPDV(struct Joueurs *joueur, struct Personnage *personnage) {
    if (joueur->vies < personnage->PDV) {
        joueur->vies = personnage->PDV;
        printf("Points de vie recuperes au maximum\n");
    }
}
