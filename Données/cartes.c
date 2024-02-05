#include <stdio.h>
#include "libraries.h"
#include <stdbool.h>

//Définition des cartes
Carte *carte = malloc(12 * sizeof(Carte));
carte[0] = {0, "Cri de Guerre", false};
carte[1] = {1, "Daimyo", false};
carte[2] = {2, "Diversion", false};
carte[3] = {3, "Geisha", false};
carte[4] = {4, "Méditation", false};
carte[5] = {5, "Parade", false};
carte[6] = {6, "Cérémonie du thé", false};
carte[7] = {7, "Jujitsu", false};
carte[8] = {8, "Attaque Rapide", true};
carte[9] = {9, "Code du Bushido", true};
carte[10] = {10, "Armure", true};
carte[11] = {11, "Concentration", true};
