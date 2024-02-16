// Ce fichier lancera le jeu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ascii.c"
#include "Données/libraries.h" // Contient les structures
#include "Fonctions/nb_joueurs.c"
#include "Données/tableaux.c"
#include "Fonctions/positions.c"
#include "Fonctions/assignation_noms.c"
#include "routine.c"
#include "Fonctions/attribuerPersonnage.c"
#include "Données/personnages.c"
#include "Fonctions/piochercarte.c"
#include "Fonctions/montrer_deck.c"
#include "Fonctions/valeur_defaut.c"
#include "Fonctions/defaussecarteid.c"
#include "Fonctions/get_pdv.c"
#include "Fonctions/shogun_begin.c"


Joueurs* lancement(int* nombre_joueurs) {
    srand(time(NULL));
    ascii();    // Fonction ascii art
    printf("Bienvenue sur Katana le jeu de cartes !\n");
    *nombre_joueurs = nb_joueurs();
    int random;
    int i; // pour les boucles
    char nom_joueur[25];
    printf("%d personnes jouent.\n", *nombre_joueurs);

    Joueurs* joueurs = malloc(*nombre_joueurs * sizeof(Joueurs)); // Alloue dynamiquement le nombre de joueurs dans un array

    // Alloue dynamiquement un tableau pour stocker les positions
    int* pos = malloc(*nombre_joueurs * sizeof(int));

    // Appelle la fonction return_pos en passant le tableau alloué en paramètre
    return_pos(*nombre_joueurs, pos);

    // Demande et attribue les noms et classes aux joueurs
    assignerNomEtClasse(joueurs, *nombre_joueurs, classes);
    printf("beep");
    attribuerPersonnage(joueurs, *nombre_joueurs, cartes_personnage, nom_cartes_personnages);
    printf("Nous allons pouvoir commencer la distribution des cartes !\n");
    modif_valeur_defaut(joueurs, *nombre_joueurs);
    pioche_tour1(joueurs, *nombre_joueurs);
    return joueurs;
}