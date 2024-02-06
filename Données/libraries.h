// Ce fichier contiendra toutes les classes du projet
#include <stdio.h>
#include <stdbool.h>

//Définition de la structure joueur
typedef struct
{
    int vies;       // Variable dynamique de la vie du joueurs
    int honneur;    // Points d'honneur des joueurs
    char nom[25];   // Nom des joueurs
    int classe;     // 0 = Shogun, 1 = Samuraï, 2 = Ninja, 3 = Ronin
    int cartes[7]; // Stockes les cartes d'un joueur selon son id
    int points;     // Points à la fin de la partie
    int fin;        // Fin de partie si honneur = 0
    char personnage[25];
    int index_perso;
} Joueurs;

// Définition de la structure arme
typedef struct
{
    int id;
    char nom[20];
    int portee;
    int degats;
} Arme;