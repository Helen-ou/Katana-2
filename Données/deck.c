#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libraries.h"

// Définition de la taille du deck
#define DECK_SIZE 60


void createDeck(Carte *deck) {
    // Création du deck
    // id, quantité, porté, dégats, permanente ? 
    int deck[60][5] = {{0, 1, 3, 3, false}, {1, 1, 4, 2, false}},  {2, 1, 5, 1, false}}, {3, 1, 5, 3, false}, {4, 1, 2, 3, false}, {5, 1, 3, 2, false},  {6, 1, 1, 3, false},  {7, 1, 4, 1, false},  {8, 1, 1, 4, false},  {9, 3, 2, 2, false}}, {10, 1, 2, 1, false}, {11, 5, 1, 1, false}, {12, 5, 1, 2, false}, {13, 1, -1, -1, false},  {14, 1, -1, -1, false}, {15, 1, -1, -1, false}, {16, 1, -1, -1, false}, {17, 1, -1, -1, false}, {18, 20, -1, -1, false}, {19, 4, -1, -1, false}, {20, 3, -1, -1, false},  {21, 4, -1, -1, true}, {22, 2, -1, -1, true}, {23, 4, -1, -1, true},  {24, 4, -1, -1, true};
    char deck_noms[60][50] = {"Nodachi", "Nagayari", "Tanegashima", "Daikyu", "Katana", "Kanabo", "Wakizashi", "Naginata", "Bo", "Kusarigama", "Shuriken", "Bokken", "Kiseru", "Cri de Guerre", "Daimyo", "Diversion", "Geisha", "Méditation", "Parade", "Cérémonie du thé", "Jujitsu", "AttaqueRapide", "CodeDuBushido", "Armure", "Concentration"};