#include <stdio.h>

int main(void) {
    int a, b, soma;
    printf("Digite dois números: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    soma = a + b;
    printf("%d + %d = %d\n", a, b, soma);
    return 0;
}