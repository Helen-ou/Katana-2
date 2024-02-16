// Crée trois fonctions "bool verif_deck_perma()", "bool verif_deck_atta()", "bool verif_deck_act()" 
// Qui vérifient si le deck contient des cartes permanantes, d'attaques, et d'action.
// Renvoie true si la carte est présente, renvoie False si ce n'est pas le cas.

// Vérifie si le deck contient des cartes permanante
bool verif_deck_perma(Joueurs *joueurs, int k)
{
    bool avoir_carte_perma = false;
    for (int i = 0; i < 14; i++)
    {
        if (deck[joueurs[k].cartes[i]][4] == true)
        {
            avoir_carte_perma = true;
        }
    }
    return avoir_carte_perma;
}

// Vérifie si le deck contient des cartes d'action
bool verif_deck_act(Joueurs *joueurs, int k)
{
    bool avoir_carte_act = false;
    for (int i = 0; i < 14; i++)
    {
        if (deck[joueurs[k].cartes[i]][2] == -1 && deck[joueurs[k].cartes[i]][4] == false)
        {
            avoir_carte_act = true;
        }
    }
    return avoir_carte_act;
}

// Vérifie si le deck contient des cartes d'attaque
bool verif_deck_atta(Joueurs *joueurs, int k)
{
    bool avoir_carte_atta = false;
    for (int i = 0; i < 14; i++)
    {
        if (deck[joueurs[k].cartes[i]][2] > 0)
        {
            avoir_carte_atta = true;
        }
    }
    return avoir_carte_atta;
}