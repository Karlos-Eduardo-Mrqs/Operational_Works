#include <stdio.h>

int main() {
    int i;
    double altura[10];
    double soma = 0.0; // Inicializa a variável soma
    
    // Loop para ler as alturas do usuário e somá-las
    for (i = 0; i < 10; i++) {
        printf("Digite a altura %d: ", i + 1);
        scanf("%lf", &altura[i]);
        soma = soma + altura[i]; // Soma as alturas enquanto são lidas
    }
    
    // Imprime as alturas lidas
    printf("\nAlturas lidas:\n");
    for (i = 0; i < 10; i++) {
        printf("Altura %d: %.2lf\n", i + 1, altura[i]);
    }
    
    // Imprime a soma das alturas
    printf("Soma das alturas: %.2lf\n", soma);
    
    return 0;
}
