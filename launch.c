// Ce fichier lancera le jeu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Données/libraries.h" // les structures
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

Joueurs* lancement(int* nombre_joueurs) {
    srand(time(NULL));
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
    attribuerPersonnage(joueurs, *nombre_joueurs, cartes_personnage, nom_cartes_personnages);

    printf("Nous allons pouvoir commencer la distribution des cartes !\n");
    modif_valeur_defaut(joueurs, *nombre_joueurs);
    pioche_tour1(joueurs, *nombre_joueurs);
    printf("%s va commencer ! \n", joueurs[0].nom);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[0]);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[1]);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[2]);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[3]);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[4]);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[5]);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[6]);
    printf("%s possède la carte d'id %d\n", joueurs[0].nom, joueurs[0].cartes[7]);
    return joueurs;
}