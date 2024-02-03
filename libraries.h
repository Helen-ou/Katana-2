// Ce fichier contiendra toutes les classes du projet
#include <stdio.h>

typedef struct {
	int vies;
    int honneur;
	char nom[25];
    int classe; // 0 = shogun, 1 = samuraï, 2 = ninja, 3 = ronin
    int cartes[25]; // Stockes les cartes d'un joueur selon son id
    int armes[25];
    int points; // self-explanatory
    int fin; // fin de partie si honneur = 0 
} Joueurs;