#include <stdio.h>

void echanger_carte(Joueurs *joueurs, int attaquant, int defenseur)
{
    // int echange = {attaquant, défenseur} selon id 
    int nb_cartes = 0;
    // Cherche nombre de cartes
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[defenseur].cartes[i] > 0)
        {
            nb_cartes += 1;
        }
    }
    int random = rand() % nb_cartes;
    // Cherche carte à défausser
    int defausser = 0;
    int stock_carte_id;
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[defenseur].cartes[i] > 0)
        {
            defausser += 1;
            if (defausser == random)
            {
                stock_carte_id = joueurs[defenseur].cartes[defausser];
                joueurs[defenseur].cartes[defausser] = -1;
                break;
            }
        }
    }
    // Donne la carte au joueur utilisant la carte
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[attaquant].cartes[i] < 0)
        {
            joueurs[attaquant].cartes[i] = stock_carte_id;
            break;
        }
    }
}