#include "../Fonctions/montrer_deck.c"
#include "../Fonctions/verif_deck.c"

void phase_3(int k)
{ // a voir quel parametre prend la fonction

    // -> montrer ici le deck avec la fonction montrer_deck()
    bool atta_jouer = false; // set up variable bool atta_jouer = False pour verif si une carte attaque a été utilisé (False si pas encore, True si utilisé)

    do
    { // boucle do while pour jouer tant que bool jouer_carte == True

        bool jouer_carte = false;

        int option = 0;

        // -> proposer l'aret de son tour avec option 1
        printf("Si ne voulez pas ou plus jouer de carte, entrez 1")
        if (atta_jouer == false)
        {
            // carte perma
            for (int i = 0; i < 7; i++)
            {
                if ()
            }
            if (verif_deck_perma(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte perma avec option 2
                printf("Si vous voulez jouer une carte permanente, entrez 2")
            }
            if (verif_deck_act(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte action avec option 3
                printf("Si vous voulez jouer une carte d'action, entrez 3")
            }
            if (verif_deck_atta(joueurs, k) == true)
            {
                //-> Proposer option jouer une carte attaque avec option 4
                printf("Si vous voulez jouer une carte d'attaque, entrez 4")
            }
            printf("Quelle action souhaitez vous faire ? ")
                scanf("%d", &option);
        }
        else
        {
            if (verif_deck_perma(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte perma avec option 2
            }
            if (verif_deck_act(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte act avec option 3
            }
        }

        if (option == 1)
        {
            jouer_carte = false;
        }
        else if (option == 2)
        {
            //-> lister ses carte perma et demander laquelle il veut jouer ->carte_a_jouer + proposition de retour en arriere
        }
        else if (option == 3)
        {
            //-> lister ses carte action et demander laquelle il veut jouer->carte_a_jouer + proposition de retour en arrière
        }
        else if (option == 4)
        {
            if (attaque_jouer == false)
            {
                // -> lister ses cartes actions et demander laquelle il veut jouer->carte_a_jouer + proposition de retour en arrière
                // si pas de retour en arrière :
                atta_jouer = false;
            }
            else
            {
                printf("Vous avez déja joué une carte attaque, vous ne pouvez le faire qu'une fois par tour")
            }
        }
        //->action de la carte "carte_a_jouer"

    } while (jouer_carte == true);
}
