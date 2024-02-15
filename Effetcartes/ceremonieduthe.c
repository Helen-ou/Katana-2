// Définition de la carte Cérémonie du thé
void CeremonieDuThe(Joueurs *joueurs, int nombre_joueurs, int k, int deck[60][5])
{
    distribution(joueurs, k, deck, 3);  // Fait piocher 3 cartes au joueur qui joue la carte
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (i != k)
        {
            distribution(joueurs, i, deck, 1); // Fait piocher 1 cartes à tout les autres joueurs
        }
    }
    printf("L'effet de lamcarte Ceremonie du thé à été effectué");
}
