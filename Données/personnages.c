// Initialise les cartes personnage
#include <stdio.h>

typedef struct
{
    int id;
    char nom[20];
    int PDV;
} Personnage;

Personnage *personnages = malloc(12 * sizeof(Personnage));
int i;

for (i; i < 12; i++)
{
    personnages[i] = cartes_personnage[i];
}

cartes_personnage = {
    {0, "Hanzo", 4},
    {1, "Ushiwaka", 4},
    {2, "Chiyome", 4},
    {3, "Hideyoshi", 4},
    {4, "Ginchiyo", 4},
    {5, "Goemon", 5},
    {6, "Nobugana", 5},
    {7, "Tomoe", 5},
    {8, "Ieyasu", 5},
    {9, "Benkai", 5},
    {10, "Musashi", 5},
    {11, "Kojiro", 5}
}