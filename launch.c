// Ce fichier lancera le jeu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "libraries.h" // les structures
#include "nb_joueurs.c"
#include "tableaux.c"
#include "positions.c"
#include "assignation_noms.c"
#include "routine.c"

int main()

{
    srand(time(NULL));
    printf("Bienvenue sur Katana le jeu de cartes !\n");
    int nombre_joueurs = nb_joueurs();
    int random;
    int i; // pour les boucles
    char nom_joueur[25];
    printf("%d personnes jouent.\n", nombre_joueurs);

    Joueurs *joueurs = malloc(nombre_joueurs * sizeof(Joueurs)); // Alloue dynamiquement le nombre de joueurs dans un array

    // Alloue dynamiquement un tableau pour stocker les positions
    int *pos = malloc(nombre_joueurs * sizeof(int));

    // Appelle la fonction return_pos en passant le tableau alloué en paramètre
    return_pos(nombre_joueurs, pos);
    
    // Demande et attribue les noms et classes aux joueurs
    assignerNomEtClasse(joueurs, nombre_joueurs, classes);
    routine(joueurs);
    free(joueurs);
    free(pos);
    return 0;
}