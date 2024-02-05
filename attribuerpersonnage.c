#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void attribuerPersonnage(Joueurs *joueur)
{
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Vérification si tous les personnages ont déjà été attribués
    if (joueur->personnage.id == -1)
    {
        // Génération d'un index aléatoire pour choisir un personnage
        int index_personnage = rand() % 12;

        // Attribution du personnage au joueur
        joueur->personnage = cartes_personnage[index_personnage];

        // "Retire" le personnage du tableau en lui donnant un ID spécial (par exemple, -1)
        cartes_personnage[index_personnage].id = -1;
    }
}

// Exemple d'utilisation
    Joueurs joueur1, joueur2;

    // Initialisation des IDs des personnages à -1
    for (int i = 0; i < 12; i++)
    {
        cartes_personnage[i].id = -1;
    }

    // Attribution aléatoire des personnages aux joueurs
    attribuerPersonnage(&joueur1);
    attribuerPersonnage(&joueur2);

    // Exemple : Afficher les informations des joueurs avec leurs personnages
    printf("Joueur 1 - Personnage : %s, PDV : %d\n", joueur1.personnage.nom, joueur1.personnage.PDV);
    printf("Joueur 2 - Personnage : %s, PDV : %d\n", joueur2.personnage.nom, joueur2.personnage.PDV);