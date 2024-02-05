// Boucle principale du jeu
#include <stdio.h>
#include <stdlib.h>

#include "launch.c"

int main()
{
    lancement(); // Fonction de launch.c qui lance le jeu
    while (1) // Boucle principale du jeu
    {
        break; // Pour tester le code, à mettre derrière une condition de fin de jeu
    }
    return 0;
}