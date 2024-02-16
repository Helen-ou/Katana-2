// Va demander le nombre de joueur et vérifier le résultat
#include <stdio.h>

int question()
{
    int question_nombre = 0;
    printf("Combien de joueurs jouent ? ");
    scanf("%d", &question_nombre);
    return question_nombre;
}

int nb_joueurs()
{
    int nombre;
    while (1)
    {
        nombre = question();
        if ((nombre > 2) && (nombre < 8))
        {
            break;
        }
        else
        {
            printf("Le nombre de joueurs n'est pas valide !\n");
        }
    }
    return nombre;
}