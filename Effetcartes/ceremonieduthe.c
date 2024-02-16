// Définition de la carte Cérémonie du thé
void CeremonieDuThe(Joueurs *joueurs, int nombre_joueurs, int k, int deck[60][5])
{
    distribution(joueurs, k, 3, nombre_joueurs);  // Fait piocher 3 cartes au joueur qui joue la carte
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (i != k)
        {
            distribution(joueurs, i, 1, nombre_joueurs); // Fait piocher 1 cartes à tout les autres joueurs
        }
    }
    printf("L'effet de la carte Ceremonie du thé à été effectué\n");
}
