#include <stdio.h>

int prochain_joueur(int joueur_actuel, int nb_joueurs) {
    return (joueur_actuel % nb_joueurs) + 1;
}

void jouer(int nb_joueurs) {
    int joueur_actif = 1;

    do {
        printf("C'est le tour de %d\n", joueur_actif);
        joueur_actif = prochain_joueur(joueur_actif, nb_joueurs);
    } while (joueur_actif != 1);
}

//jouer(nb_joueurs) (pour changer de joueur)
