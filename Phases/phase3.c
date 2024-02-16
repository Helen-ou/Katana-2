// Code qui gère la phase 3, phase de jeu des joueurs.
#include <stdio.h>

#include "../Fonctions/Attaque/echanger_carte.c"
#include "../Effetcartes/armure.c"
#include "../Effetcartes/attaque_rapide.c"
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
#include "../Effetcartes/codedubushido.c"

void phase_3(Joueurs *joueurs, int k, int nb_joueurs) // K correspond au joueur actif
{

    bool atta_jouer = false; // Met en place la variable bool atta_jouer = false qui vérifie si une carte d'attaque à déjà été utilisée
    bool jouer_carte = true;
    char carte[25];
    int option;
    int compteur_attaque = 0;
    do
    { // Boucle do while pour jouer tant que bool jouer_carte == true

        afficherCartes(joueurs, k); // Affiche les cartes jouables du joueurs

        option = 0;

        // Propose l'arrêt de son tour avec l'option 1
        printf("\nSi vous ne voulez pas ou plus jouer de carte, entrez 1\n");
        if (atta_jouer == false)
        {
            if (verif_deck_perma(joueurs, k) == true)
            {
                // Propose l'option jouer une carte permanante avec l'option 2
                printf("Si vous voulez jouer une carte permanente, entrez 2\n");
            }
            else
            {
                printf("Vous n'avez pas de carte permanentes dans votre deck !\n");
            }
            if (verif_deck_act(joueurs, k) == true)
            {
                // Propose l'option jouer une carte action avec l'option 3
                printf("Si vous voulez jouer une carte d'action, entrez 3\n");
            }
            else
            {
                printf("Vous n'avez pas de carte actions dans votre deck !\n");
            }
            if (verif_deck_atta(joueurs, k) == true)
            {
                printf("Si vous voulez jouer une carte d'attaque, entrez 4\n");
            }
            else
            {
                printf("Vous n'avez pas de carte attaque dans votre deck !\n");
            }
            printf("Quelle action souhaitez vous faire ? \n");
            scanf("%d", &option);
            printf("\n");
        }
        else
        {

            if (verif_deck_perma(joueurs, k) == true)
            {
                // Propose option jouer une carte permanante avec l'option 2
                printf("Si vous voulez jouer une carte permanente, entrez 2\n");
            }
            else
            {
                printf("Vous n'avez pas de carte permanentes dans votre deck !\n");
            }
            if (verif_deck_act(joueurs, k) == true)
            {
                printf("Si vous voulez jouer une carte action, entrez 3\n");
            }
            else
            {
                printf("Vous n'avez pas de carte actions dans votre deck !\n");
            }
            printf("Vous ne pouvez plus jouer de carte action \n");
            printf("Quelle action souhaitez vous faire ? \n");
            scanf("%d", &option);
        }

        if (option == 1)
        {
            jouer_carte = false;
        }
        else if (option == 2)
        {
            // Liste les carte permanantes et demande laquelle doit être jouée
            afficherCartesPerma(joueurs, k);
            printf("Entrez le nom de la carte que vous voulez jouer :\n");
            printf("Note: Veillez à entrer exactement le nom de la carte : CodeDuBushido - AttaqueRapide - Armure - Concentration\n");
            scanf("%s", &carte);

            if (strcmp(carte, "Armure") == 0)
            {
                joueurs[k].armure += 1;
                defausserCarte(joueurs, k, 23);
            }

            if (strcmp(carte, "AttaqueRapide") == 0)
            {
                joueurs[k].attaque_rapide += 1;
                defausserCarte(joueurs, k, 21);
            }

            if (strcmp(carte, "Concentration") == 0)
            {
                joueurs[k].concentration += 1;
                defausserCarte(joueurs, k, 24);
            }

            if (strcmp(carte, "CodeDuBushido") == 0)
            {
                CodeDuBushido(joueurs, nb_joueurs, k);
                defausserCarte(joueurs, k, 22);
            }
        }
        else if (option == 3)
        {
            // Liste les carte action et demande laquelle jouer
            afficherCartesActions(joueurs, k);
            char carte[25];
            while (1)
            {

                printf("Entrez le nom de la carte que vous voulez jouer :\n");
                printf("Note: Veillez à entrer exactement le nom de la carte : CrideGuerre - Daimyo - Diversion - Geisha - Meditation - Jujitsu - CeremonieDuThe - STOP\n");
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
            printf("Voici la valeur de carte : %s\n", carte);
            if (strcmp(carte, "CriDeGuerre") == 0)
            {
                CriDeGuerre(joueurs, nb_joueurs, k);
            }
            else if (strcmp(carte, "Daimyo") == 0)
            {
                Daimyo(joueurs, k, deck, nb_joueurs);
            }
            else if (strcmp(carte, "Diversion") == 0)
            {
                Diversion(joueurs, nb_joueurs, k);
            }
            else if (strcmp(carte, "Geisha") == 0)
            {
                Geisha(joueurs, nb_joueurs, k);
            }
            else if (strcmp(carte, "Meditation") == 0)
            {
                Meditation(joueurs, nb_joueurs, k);
            }
            else if (strcmp(carte, "Jujitsu") == 0)
            {
                JuJitsu(joueurs, nb_joueurs, k, deck);
            }
            else if (strcmp(carte, "CeremonieDuThe") == 0)
            {
                CeremonieDuThe(joueurs, nb_joueurs, k, deck);
            }
        }
        else if (option == 4)
        {
            if (atta_jouer == false)
            {
                // Liste les cartes attaque et demande laquelle jouer
                afficherCartesAttaques(joueurs, k);
                printf("Entrez le nom de la carte que vous voulez jouer :\n");
                char carte[25];
                scanf("%s", &carte);

                int id_carte;
                for (int i = 0; i < 14; i++)
                {
                    if (strcmp(carte, deck_noms[i]) == 0)
                    {
                        id_carte = i;
                    }
                }
                int preci_carte = deck[id_carte][2];
                int degat_carte = deck[id_carte][3];

                // Code de gestion de l'attaque
                for (int j = 0; j < nb_joueurs; j++)
                {
                    if (joueurs[j].vies > 0 && diff_attaque(joueurs, k, j, nb_joueurs) <= preci_carte && k != j)
                    {
                        printf("Tu peux attaquer le joueur %s numero %d.\n", joueurs[j].nom, j);
                    }
                }
                printf("Parmi eux, lequel voulez-vous attaquer ? (entrez le numero)\n");
                int j_visé;
                scanf("%d", &j_visé);
                int pers[2] = {k, j_visé};
                int atta_annule = attaque(joueurs, preci_carte, degat_carte, nb_joueurs, pers);

                if (atta_annule == 0)
                {
                    if (joueurs[k].concentration == 0)
                    {
                        atta_jouer = true;
                    }
                    else
                    {
                        compteur_attaque += 1;
                        if (compteur_attaque < joueurs[k].concentration)
                        {
                            atta_jouer = true;
                        }
                    }
                }
            }
            else
            {
                printf("Vous avez déja joué une carte attaque, vous ne pouvez le faire qu'une fois par tour\n");
            }
        }
    } while (jouer_carte == true);
}
