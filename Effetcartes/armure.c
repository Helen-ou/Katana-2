// Définition de la carte permanante Armure
int armure(Joueurs *joueurs, int j_visé)
{
    int nb_carte_armure = 0;
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[j_visé].cartes[i] == 23) // Ajoute +1 à un compteur pour chaque carte armure que possède le joueur
        {
            nb_carte_armure++;
        }
    }
    printf("La carte armure a bien été jouée et a rajouté %d armure\n", nb_carte_armure);
    return nb_carte_armure; // TODO "nb_carte_armure" à mettre à la place du 0 à la fin.
}