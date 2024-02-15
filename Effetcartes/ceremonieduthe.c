void CeremonieDuThe(Joueurs *joueurs, int nombre_joueurs, int k, int deck[60][5])
{
    distribution(joueurs, k, deck, 3);
    for (int i = 0; i < nombre_joueurs; i++)
    {
        if (i != k)
        {
            distribution(joueurs, i, deck, 1);
        }
    }
    printf("L'effet de lamcarte Ceremonie du thé à été effectué");
}
