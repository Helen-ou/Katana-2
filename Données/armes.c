#include <stdio.h>
#include "libraries.h"

//Définition des armes
Arme *armes = malloc(13 * sizeof(Arme));
armes[0] = {0, "Nodachi", 3, 3};
armes[1] = {1, "Nagayari", 4, 2};
armes[2] = {2, "Tanegashima", 5, 1};
armes[3] = {3, "Daikyu", 5, 3};
armes[4] = {4, "Katana", 2, 3};
armes[5] = {5, "Kanabo", 3, 2};
armes[6] = {6, "Wakizashi", 1, 3};
armes[7] = {7, "Naginata", 4, 1};
armes[8] = {8, "Bo", 1, 4};
armes[9] = {9, "Kusarigama", 2, 2};
armes[10] = {10, "Shuriken", 2, 1};
armes[11] = {11, "Bokken", 1, 1};
armes[12] = {12, "Kiseru", 1, 2};