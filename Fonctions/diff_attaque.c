// Fonction attaque
#include <stdio.h>

int diff_attaque(int joueur_a, int joueur_b, int nb_joueur)//joueur_a est le joueur qui attaque et joueur_b est le joueur qui reçoie
{ // j_a e j_b prennent e parametre le numero du joueur ( si 7 joueurs, les num vont de 1 a 7 et non de 0 a 6, donc num a modif avec un +1 si jamais)
    int temp = 0;
    int temp2 = 0;
    int cas = 0;
    if (nb_joueur == 3){
        return 1;
    }
    else{
//initialisation de la difficulté sans prise en compte de la vie des joueurs
        if (joueur_a > joueur_b)
        {
            temp = joueur_b - joueur_b;
        }
        else
        {
            temp = joueur_b - joueur_a;
        }

        if (temp > nb_joueur - temp)
        {
            temp2 = nb_joueur - temp;
            cas = 1;
        }
        else
        {
            temp2 = temp;
            cas = 2;
        }

// difficulté d'attaque en prenant en compte la vie des joueurs
        if(cas==1){
            for(compt = joueur_a + 1 ; compt<joueur_b ; compt++){
                if(true){//remplacer true par l'équivalent en c de "vie joueur(compt)==0"
                    temp2 = temp2-1;
                }
            }

        }
        else{
            for(compt = joueur_b + 1 ; compt<nb_joueur ; compt++){
                if(true){//remplacer true par l'équivalent en c de "vie joueur(compt)==0"
                    temp2 = temp2-1;
                }
            }
            for(compt = 0 + 1 ; compt<joueur_a ; compt++){
                if(true){//remplacer true par l'équivalent en c de "vie joueur(compt)==0"
                    temp2 = temp2-1;
                }
            }


    }






        printf("%d", temp2);
        return temp2;
    }
}