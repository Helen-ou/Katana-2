// Code qui permet de défausser les cartes selon l'ID
int defausserCarte(Joueurs *joueurs, int joueur_actif, int id)
{
    // Recherche de la carte dans le deck du joueur
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[joueur_actif].cartes[i] == id)
        {
            joueurs[joueur_actif].cartes[i] = -1; // Donne l'ID -1 aux cartes défaussées
            printf("Le joueur %s a défaussé une carte avec l'id %d.\n", joueurs[joueur_actif].nom, id);
            return 1;
        }
    }
    return 0;
}
