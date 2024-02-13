// Crée trois fonction "bool verif_deck_perma()", "bool verif_deck_atta()", "bool verif_deck_act()" qui verif si le deck contient des cartes perma, d'attaques, d'action
// Renvoie True si carte persente, renvoie False si ce n'est pas le cas

bool verif_deck_perma(Joueurs *joueurs, int k)
{
    bool avoir_carte_perma = false;
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[k].cartes[i] < 0)
        {
            break;
        }
        else
        {
            if (deck[joueurs[k].cartes[i]][4] == true)
            {
                avoir_carte_perma = true;
            }
        }
    }
    return avoir_carte_perma;
}

bool verif_deck_act(Joueurs *joueurs, int k)
{
    bool avoir_carte_act = false;
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[k].cartes[i] < 0)
        {
            break;
        }
        else
        {
            if (deck[joueurs[k].cartes[i]][2] == -1 && deck[joueurs[k].cartes[i]][4] == false)
            {
                avoir_carte_act = true;
            }
        }
    }
    return avoir_carte_act;
}

bool verif_deck_atta(Joueurs *joueurs, int k)
{
    bool avoir_carte_atta = false;
    for (int i = 0; i < 14; i++)
    {
        if (joueurs[k].cartes[i] < 0)
        {
            break;
        }
        else
        {
            if (deck[joueurs[k].cartes[i]][2] > 0)
            {
                avoir_carte_atta = true;
            }
        }
    }
    return avoir_carte_atta;
}