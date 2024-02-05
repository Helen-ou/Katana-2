// Va stocker le tableau comportant les cartes.
#include <stdio.h>
#include <stdbool.h>

// Exemple pour les cartes, pas définitif
// ID, ATK, DEF
int carte[][3] = {{0, 2, 3}, {1, 1, 4}};
// Noms des cartes
char cartes[][25] = {"Farfouilleur", "Croisé"};

// Exemple pour les classes, définitif
// Ordre des classes : Shogun, samouraï, ronin, ninja
int classes[][4] = {{1, 1, 1, 0}, {1, 1, 0, 2}, {1, 1, 1, 2}, {1, 1, 1, 3}, {1, 1, 1, 3}};