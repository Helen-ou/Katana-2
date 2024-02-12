#include <stdio.h>

#include "../Fonctions/defaussecarteid.c"
#include "../Fonctions/verif_deck.c"
#include "../Fonctions/Attaque/Attaque.c"
#include "../Fonctions/verif_carte.c"
#include "../Effetcartes/ceremonieduthe.c"
#include "../Effetcartes/crideguerre.c"
#include "../Effetcartes/daimyo.c"
#include "../Effetcartes/diversion.c"
#include "../Effetcartes/geisha.c"
#include "../Effetcartes/jujitsu.c"
#include "../Effetcartes/meditation.c"

void phase_3(Joueurs *joueurs, int k, int nb_joueurs) // k est le joueur actif
{                                                     // a voir quel parametre prend la fonction
    // -> montrer ici le deck avec la fonction montrer_deck()

    afficherCartes(joueurs, k);

    bool atta_jouer = false; // set up variable bool atta_jouer = False pour verif si une carte attaque a été utilisé (False si pas encore, True si utilisé)
    bool jouer_carte = false;
    char carte[25];
    int option;
    do
    { // boucle do while pour jouer tant que bool jouer_carte == True

        option = 0;

        // -> proposer l'aret de son tour avec option 1
        printf("Si ne voulez pas ou plus jouer de carte, entrez 1\n");
        if (atta_jouer == false)
        {
            if (verif_deck_perma(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte perma avec option 2
                printf("Si vous voulez jouer une carte permanente, entrez 2\n");
            }
            if (verif_deck_act(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte action avec option 3
                printf("Si vous voulez jouer une carte d'action, entrez 3\n");
            }
            if (verif_deck_atta(joueurs, k) == true)
            {
                printf("Si vous voulez jouer une carte d'attaque, entrez 4\n");
            }
            printf("Quelle action souhaitez vous faire ? \n");
            scanf("%d", &option);
        }
        else
        {

            // bool CarteConcentration = Concentration(joueurs, k);
            // if (CarteConcentration) {
            // printf("Si vous voulez joruer rejouer une carte attaque, entrez 1\n");
            //  }
            if (verif_deck_perma(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte perma avec option 2
                printf("Si vous voulez jouer une carte permanente, entrez 2\n");
            }
            if (verif_deck_act(joueurs, k) == true)
            {
                // -> Proposer option jouer une carte act avec option 3
            }
            printf("Quelle action souhaitez vous faire ? \n");
            scanf("%d", &option);
        }

        if (option == 1)
        {
            jouer_carte = false;
        }
        else if (option == 2)
        {
            //-> lister ses carte perma et demander laquelle il veut jouer ->carte_a_jouer + proposition de retour en arriere
            afficherCartesPerma(joueurs, k);
            printf("Entrez le nom de la carte que vous voulez jouer :\n");
            printf("Note: Veillez à entrer exactement le nom de la carte : CodeDuBushido - AttaqueRapide - Armure - Concentration\n");
            scanf("%s", &carte);

            int id_carte;
            for (int i = 21; i < 24; i++)
            {
                if (strcmp(carte, deck_noms[i]) == 0)
                {
                    id_carte = i;
                }
            }
        }
        else if (option == 3)
        {
            //-> lister ses carte action et demander laquelle il veut jouer->carte_a_jouer + proposition de retour en arrière
            afficherCartesActions(joueurs, k);
            while (1)
            {
                printf("Entrez le nom de la carte que vous voulez jouer :\n");
                printf("Note: Veillez à entrer exactement le nom de la carte : CrideGuerre - Daimyo - Diversion - Geisha - Meditation - Jujitsu - CeremonieDuThe - STOP\n");
                char carte[25];
                scanf("%s", &carte);
                if (verif_carte(joueurs, k, carte) == 1 || strcmp(carte, "STOP") == 0) // Vérifie que le joueur à bien la carte dans son deck
                {
                    break;
                }
                else
                {
                    printf("Le nom de la carte est invalide, veuillez réessayer ou écrire STOP\n");
                    continue;
                }
            }

            if (strcmp(carte, "CriDeGuerre") == 0) // Vérifie si la carte que souhaite jouer le joueur r
            {
                // CriDeGuerre(Joueurs *joueurs, nb_joueurs);
            }
            else if (strcmp(carte, "Daimyo") == 0)
            {
                // Daimyo();
            }
            else if (strcmp(carte, "Diversion") == 0)
            {
                // Diversion();
            }
            else if (strcmp(carte, "Geisha") == 0)
            {
                // Geisha();
            }
            else if (strcmp(carte, "Meditation") == 0)
            {
                // Meditation();
            }
            else if (strcmp(carte, "Jujitsu") == 0)
            {
                // JuJitsu();
            }
            else if (strcmp(carte, "CeremonieDuThe") == 0)
            {
                // CeremonieDuThe(Joueurs *joueurs, nb_joueurs, k, Deck *deck);
            }
        }
        else if (option == 4)
        {
            if (atta_jouer == false)
            {
                // -> lister ses cartes actions et demander laquelle il veut jouer->carte_a_jouer + proposition de retour en arrière
                afficherCartesAttaques(joueurs, k);
                printf("Entrez le nom de la carte que vous voulez jouer :\n");
                char carte[25];
                scanf("%s", &carte);

                int id_carte;
                for (int i = 0; i < 13; i++)
                {
                    if (strcmp(carte, deck_noms[i]) == 0)
                    {
                        id_carte = i;
                    }
                }
                int preci_carte = deck[id_carte][2];
                int degat_carte = deck[id_carte][3];

                printf("Voici les joueurs que vous pouvez attaquez : \n");
                for (int j = 0; j < nb_joueurs; j++)
                {
                    if (joueurs[k].vies != 0 && diff_attaque(joueurs, j, k, nb_joueurs) <= preci_carte && k != j)
                    {
                        printf("Tu peux attaquer le joueur %s numero %d\n", joueurs[j].nom, j);
                    }
                }
                printf("Parmis eux, lequel voulez-vous attaquer ? (entrez le numero)\n");
                int j_visé;
                scanf("%d", &j_visé);
                int pers[2] = {k, j_visé};
                attaque(joueurs, preci_carte, degat_carte, nb_joueurs, pers);
                // si pas de retour en arrière :
                atta_jouer = false;
            }
            else
            {
                printf("Vous avez déja joué une carte attaque, vous ne pouvez le faire qu'une fois par tour\n");
            }
        }
    } while (jouer_carte == true);
}