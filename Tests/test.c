#include <stdio.h>

void test() {
    printf("c'est un test");
}

int main() {
    int arr[5];
    arr[sizeof(arr) / sizeof(arr[0] - 1)] = 1;
    printf("%d", arr[1]);
return 0;
}