// Boucle principale du jeu
#include <stdio.h>
#include <stdlib.h>

#include "launch.c"
// #include "routine.c"
// #include "Phases/phase1.c"

int main()
{
    int nombre_joueurs;
    Joueurs *joueurs = lancement(&nombre_joueurs); // Fonction de launch.c qui lance le jeu
    int k;
    while (1) // Boucle principale du jeu
    {
        phase_1(k);
        phase_2(k);
        phase_3(k);
        phase_4(k);
        if (k % 7 == 0)
        {
            k = 0;
        }
        else
        {
            k = 1;
        }
        break; // Pour tester le code, à mettre derrière une condition de fin de jeu
    }   
    return 0;
}