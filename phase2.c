#include <stdio.h>
#include "libraries.h"
#include <time.h>  

 typedef struct {
    Card hand[5]; 
} Player;

void PhasePioche(Joueurs *joueur) {
        int randomIndex = rand() % (sizeof(cardAttributes) / sizeof(cardAttributes[0]));
        player->hand[i].id = cardAttributes[randomIndex][0];
        player->hand[i].att = cardAttributes[randomIndex][1];
        player->hand[i].def = cardAttributes[randomIndex][2];
        snprintf(player->hand[i].nom, sizeof(player->hand[i].nom), "%s", cardNames[randomIndex]);
        printf("Les cartes ont ete piochees\n");
}
