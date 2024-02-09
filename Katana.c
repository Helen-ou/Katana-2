// Boucle principale du jeu
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#include "launch.c"
#include "Phases/phase1.c"

int main()
{
    int nombre_joueurs;
    Joueurs *joueurs = lancement(&nombre_joueurs); // Fonction de launch.c qui lance le jeu
    int joueur_actif;
    while (1) // Boucle principale du jeu
    {
        phase_1(joueurs, nombre_joueurs, joueur_actif);
        phase_2(joueurs, joueur_actif);
        phase_3(joueurs, joueur_actif, nombre_joueurs);
        int fin = routine(joueurs, nombre_joueurs);
        if (fin == 1)
        {
            break;
        }
        phase_4(joueurs, joueur_actif);

        if (joueur_actif == nombre_joueurs)
        {
            joueur_actif = 0;
        }
        else
        {
            joueur_actif++;
        }
    }
    printf("\nMerci d'avoir joué !");
    return 0;
}