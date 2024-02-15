// Récupère les PDV par rapport au personnage du joueur
#include <stdio.h>

int recup_pdv(Joueurs *joueurs, int joueur_actif)
{
    for (int i = 0; i < 12; i++) // 12 correspondant à nb_joueurs
    {
        if (strcmp(joueurs[joueur_actif].personnage, nom_cartes_personnages[i]) == 0)
        {
            return cartes_personnage[i][1];
        }
    }
}