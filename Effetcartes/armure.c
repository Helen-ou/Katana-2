int armure(Joueurs *joueurs, int j_visé)
{
    int nb_carte_armure = 0;
    
    for (int i; i < 14; i++)
    {
        if (joueurs[j_visé].carte_perma[0] == 24)// carte numero I des cartes perma du joueur == armure
        { 
            nb_carte_armure++;
        }
    }
    return nb_carte_armure; /*"nb_carte_armure" a mettre a la place du 0 une fois le systeme de carte perma setup, je laisse comme ca pour l'instant pour pas faire beuger le programme*/
    
}
