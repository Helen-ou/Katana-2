void defausserCarte(Joueurs *joueur, int joueur_actif, int id)
{
    // Recherche de la carte dans le deck du joueur
    for (int i = 0; i < 14; i++)
    {
        if (joueur[joueur_actif].cartes[i] == id)
        {
            joueur[joueur_actif].cartes[i] = -1;
            printf("Le joueur %s a défaussé une carte avec l'id %d.\n", joueur[joueur_actif].nom, id);
            return;
        }
    }

    printf("Le joueur %s ne possède pas de carte avec l'id %d.\n", joueur[joueur_actif].nom, id);
}
