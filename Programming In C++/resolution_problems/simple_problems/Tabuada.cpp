#include <cstdio>

int main() {
    int cont = 0, i, num = 0;
    char continuar = 'N'; 
    while (continuar != 'S') {
        printf("\nDigite um numero: ");
        scanf("%d", &num);
        cont = cont + 1;
        printf("A tabuada de %d", num);
        for (i = 1; i <= 10; i++) {
            printf("\n%d X %d = %d", num, i, num * i);
        }
        printf("\nDeseja parar [S/N] ? ");
        scanf(" %c", &continuar); 
    }
    printf("\nVoce pediu %d tabuada(s)",cont);
	return 0;
}
