#include <stdio.h>

int main() {
    int tableau[5] = {5};
    printf("%d", sizeof(tableau));
    tableau[1] = 3;
    printf("  %d", sizeof(tableau));
    printf("%d", tableau[3]);
    return 0;

}