#include <stdio.h>

typedef struct {
    int id;
    char nom[20];
    int portee;
    int degats;
} Arme;

int main() {
    // 13 pour 13 armes
    Arme *armes = malloc(13 * sizeof(Arme));
    {0, "Nodachi", 3, 3},
    {1, "Nagayari", 4, 2},
    {2, "Tanegashima", 5, 1},
    {3, "Daikyu", 5, 3},
    {4, "Katana", 2, 3},
    {5, "Kanabo", 3, 2},
    {6, "Wakizashi", 1, 3},
    {7, "Naginata", 4, 1},
    {8, "Bo", 1, 4},
    {9, "Kusarigama", 2, 2},
    {10, "Shuriken", 2, 1},
    {11, "Bokken", 1, 1},
    {12, "Kiseru", 1, 2}
}
