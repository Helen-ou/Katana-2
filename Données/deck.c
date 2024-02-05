#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libraries.h"

// Définition de la taille du deck
#define DECK_SIZE 60

void createDeck(Carte *deck) {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Création du deck
    deck[DECK_SIZE] = {
        // Armes
        {0, "Nodachi", 3, 3}, {1, "Nagayari", 4, 2}, {2, "Tanegashima", 5, 1},
        {3, "Daikyu", 5, 3}, {4, "Katana", 2, 3}, {5, "Kanabo", 3, 2},
        {6, "Wakizashi", 1, 3}, {7, "Naginata", 4, 1}, {8, "Bo", 1, 4},
        {9, "Kusarigama", 2, 2}, {10, "Kusarigama", 2, 2}, {11, "Kusarigama", 2, 2},
        {12, "Shuriken", 2, 1}, {13, "Bokken", 1, 1}, {14, "Bokken", 1, 1},
        {15, "Bokken", 1, 1}, {16, "Bokken", 1, 1}, {17, "Bokken", 1, 1},
        {18, "Kiseru", 1, 2}, {19, "Kiseru", 1, 2}, {20, "Kiseru", 1, 2},
        {21, "Kiseru", 1, 2}, {22, "Kiseru", 1, 2},
        // Cartes
        {23, "Cri de Guerre", false}, {24, "Daimyo", false}, {25, "Diversion", false},
        {26, "Geisha", false}, {27, "Méditation", false},
        {28, "Parade", false}, {29, "Parade", false}, {30, "Parade", false},
        {31, "Parade", false}, {32, "Parade", false}, {33, "Parade", false},
        {34, "Parade", false}, {35, "Parade", false}, {36, "Parade", false},
        {37, "Parade", false}, {38, "Parade", false}, {39, "Parade", false},
        {40, "Parade", false}, {41, "Parade", false}, {42, "Parade", false},
        {43, "Parade", false}, {44, "Parade", false}, {45, "Parade", false},
        {46, "Parade", false}, {47, "Parade", false}, {48, "Cérémonie du thé", false},
        {49, "Cérémonie du thé", false}, {50, "Cérémonie du thé", false},
        {51, "Cérémonie du thé", false}, {52, "Ju jitsu", false},
        {53, "Ju jitsu", false}, {54, "Ju jitsu", false},
        // Cartes permanentes
        {55, "Attaque Rapide", true}, {56, "Attaque Rapide", true},
        {57, "Attaque Rapide", true}, {58, "Attaque Rapide", true},
        {59, "Code du Bushido", true}, {60, "Code du Bushido", true},
        {61, "Armure", true}, {62, "Armure", true}, {63, "Armure", true},
        {64, "Armure", true}, {65, "Concentration", true}, {66, "Concentration", true},
        {67, "Concentration", true}, {68, "Concentration", true},
    };
}
