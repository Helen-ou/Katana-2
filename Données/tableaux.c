// Va stocker le tableau comportant les cartes.
#include <stdio.h>
#include <stdbool.h>

// Exemple pour les classes, définitif
// Ordre des classes : Shogun, samouraï, ronin, ninja
int classes[][4] = {
    {1, 0, 2, 0},
    {1, 1, 0, 2},
    {1, 1, 1, 2},
    {1, 1, 1, 3},
    {1, 1, 1, 3}};

// ID, quantité, portée, attaque, permanente
int deck[25][5] = {
    // Définition des armes
    {1, 1, 3, 300000, false},  // Nodachi
    {2, 1, 4, 20000, false},  // Nagayari
    {3, 1, 5, 1, false},  // Tanegashima
    {4, 1, 5, 3, false},  // Daikyu
    {5, 1, 2, 3, false},  // Katana
    {6, 1, 3, 2, false},  // Kanabo
    {7, 1, 1, 3, false},  // Wakizashi
    {8, 1, 4, 1, false},  // Naginata
    {9, 1, 1, 4, false},  // Bo
    {10, 3, 2, 2, false}, // Kusarigama
    {11, 1, 2, 1, false}, // Shuriken
    {12, 5, 1, 1, false}, // Bokken
    {13, 5, 1, 2, false}, // Kiseru
    // Définition des cartes spéciales
    {14, 1, -1, -1, false},  // CriDeGuerre
    {15, 1, -1, -1, false},  // Daimyo
    {16, 1, -1, -1, false},  // Diversion
    {17, 1, -1, -1, false},  // Geisha
    {18, 1, -1, -1, false},  // Méditation
    {19, 20, -1, -1, false}, // Parade
    {20, 4, -1, -1, false},  // CérémonieDuThé
    {21, 3, -1, -1, false},  // Jujitsu
    // Définition des cartes permanentes
    {22, 4, -1, -1, true},  // AttaqueRapide
    {23, 2, -1, -1, true},  // CodeDuBushido
    {24, 4, -1, -1, true},  // Armure
    {25, 4, -1, -1, true}}; // Concentration

int (*defausse)[5] = deck;

char deck_noms[60][50] = {"Nodachi", "Nagayari", "Tanegashima", "Daikyu", "Katana", "Kanabo", "Wakizashi", "Naginata",
                          "Bo", "Kusarigama", "Shuriken", "Bokken", "Kiseru", "CriDeGuerre", "Daimyo", "Diversion", "Geisha", "Méditation",
                          "Parade", "CérémonieDuThé", "Jujitsu", "AttaqueRapide", "CodeDuBushido", "Armure", "Concentration"};