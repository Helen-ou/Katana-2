// Code qui va gérer la position des joueurs
#include <stdio.h>

void return_pos(int nombre_joueurs, int* pos) {
    int i, j;
    int temp, random_index;

    // Crée un tableau avec tous les nombres possibles
    int* all_numbers = malloc(nombre_joueurs * sizeof(int));
    for (i = 0; i < nombre_joueurs; i++) {
        all_numbers[i] = i;
    }

    // Mélange le tableau de manière aléatoire
    for (i = nombre_joueurs - 1; i > 0; i--) {
        random_index = rand() % (i + 1);

        // Échange all_numbers[i] et all_numbers[random_index]
        temp = all_numbers[i];
        all_numbers[i] = all_numbers[random_index];
        all_numbers[random_index] = temp;
    }

    // Prend les nombre_joueurs premiers éléments
    for (j = 0; j < nombre_joueurs; j++) {
        pos[j] = all_numbers[j];
    }

    free(all_numbers);
}
