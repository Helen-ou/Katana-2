// Définition de la carte permanante Attaque
int attaque_rapide(Joueurs *joueurs, int j_visé)
{
    int nb_carte_attaque = 0;
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[j_visé].cartes[i] == 23) // Ajoute +1 à un compteur pour chaque carte attaque que possède le joueur
        {
            nb_carte_attaque++;
        }
    }
    if(nb_carte_attaque >= 1)
    {
    printf("La carte AttaqueRapide a bien été jouée et a rajouté %d de puissance d'attaque\n", nb_carte_attaque);
    }
    return nb_carte_attaque; 
}