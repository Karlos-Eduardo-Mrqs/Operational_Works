#include <cstdio>

int main() {
    int i = 0; // Inicialize a variável para evitar comportamento indefinido
    do {
        printf("%d\n", i); // Imprima o valor da variável, não o seu endereço
        i++; // Atualize o valor de i para evitar um loop infinito
    } while (i > 10); // Condição corrigida para continuar o loop enquanto i for menor que 10
    return 0;
}
