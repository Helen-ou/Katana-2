int armure(Joueurs *joueurs, int j_visé)
{
    int nb_carte_armure = 0;
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[j_visé].carte[i] == 23) // carte numero I des cartes perma du joueur == armure
        {
            nb_carte_armure++;
        }
    }
    printf("La carte armure a bien été jouée et a rajouté %d armure\n", nb_carte_armure);
    return nb_carte_armure; /*"nb_carte_armure" a mettre a la place du 0 une fois le systeme de carte perma setup, je laisse comme ca pour l'instant pour pas faire beuger le programme*/
}
