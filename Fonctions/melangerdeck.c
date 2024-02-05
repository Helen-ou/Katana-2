// Fonction Mélange le deck
#include <stdio.h>

void shuffleDeck(Carte *deck, int size) {
    // Mélange le deck
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carte temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}