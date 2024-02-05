// Fonction Attaque
#include <stdio.h>

int diff_attaque(int joueur_a, int joueur_b)
{ // j_a e j_b prennent e parametre le numero du joueur
    int temp = 0;
    int temp2 = 0;
    int cas = 0;
    if (nb_joueur == 3){
        return 1;
    }
    else{

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
        printf("%d", temp2);
        return temp2;
    }
}