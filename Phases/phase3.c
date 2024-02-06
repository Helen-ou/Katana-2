#include "../Fonctions/montrer_deck.c"
#include "../Fonctions/verif_deck.c"


void phase_3(){// a voir quel parametre prend la fonction

    // -> montrer ici le deck avec la fonction montrer_deck()

    bool atta_jouer = False;    // set up variable bool atta_jouer = False pour verif si une carte attaque a été utilisé (False si pas encore, True si utilisé)


    do{    //boucle do while pour jouer tant que bool jouer_carte == True

       bool jouer_carte = True;

        int option = 0;

        // -> proposer l'aret de son tour avec option 1
        if(atta_jouer == False){
            if(verif_deck_perma == True){
                // -> Proposer option jouer une carte perma avec option 2
            }
            if(verif_deck_act == True){
                // -> Proposer option jouer une carte action avec option 3
            }
            if(verif_deck_perma == True){
                //-> Proposer option jouer une carte attaque avec option 4
            }   
        }
        else{
            if(verif_deck_perma == True){
                // -> Proposer option jouer une carte perma avec option 2
            }
            if(verif_deck_act == True){
                // -> Proposer option jouer une carte act avec option 3
            }
        }
        

        if(option == 1){
            jouer_carte = False;
        }
        else if(option == 2){
            //-> lister ses carte perma et demander laquelle il veut jouer ->carte_a_jouer + proposition de retour en arriere
        }
        else if(option == 3){
            //-> lister ses carte action et demander laquelle il veut jouer->carte_a_jouer + proposition de retour en arrière
        }
        else if(option == 4){
            if(attaque_jouer == False){
                // -> lister ses cartes actions et demander laquelle il veut jouer->carte_a_jouer + proposition de retour en arrière
                // si pas de retour en arrière :
                atta_jouer = False;
            }
            else{printf("Vous avez déja jouer un carte attaque, vous ne pouvez le faire qu'un fois par tour")}
                    }
        //->action de la carte "carte_a_jouer"


    }while(jouer_carte == True);
// -> déclancher la phase 4   
}





