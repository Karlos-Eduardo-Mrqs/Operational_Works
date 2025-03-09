#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória
    int* array = (int*) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return 1;
    }

    // Preenchendo o array
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // Imprimindo o array
    printf("Array alocado dinamicamente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberando a memória
    free(array);

    return 0;
}