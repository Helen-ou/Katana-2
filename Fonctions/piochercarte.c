#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Carte drawCard(Deck *deck)
{
    // Vérifie si le deck n'est pas vide
    if (deck->taille > 0)
    {
        // Pioche la première carte du deck
        Carte cartePiochee = deck->cartes[0];

        // Décale les cartes restantes dans le deck
        for (int i = 1; i < deck->taille; i++)
        {
            deck->cartes[i - 1] = deck->cartes[i];
        }

        // Réduit la taille du deck
        deck->taille--;

        printf("Une carte a été piochée.\n");
        
        return cartePiochee;
    }
    else
    {
        // Si le deck est vide, retourne une carte avec un ID -1
        Carte carteVide = {-1, "", false};
        return carteVide;
    }


}

