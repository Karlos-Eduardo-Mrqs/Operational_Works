#include <stdio.h>

int main() {
    FILE *arquivo; // Declara um ponteiro para o arquivo

    // Abre o arquivo em modo de escrita ("w" - write)
    arquivo = fopen("exemplo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escreve no arquivo
    fprintf(arquivo, "Olá, mundo!\n");
    fprintf(arquivo, "Este é um exemplo de escrita em arquivo.\n");

    // Fecha o arquivo
    fclose(arquivo);

    printf("Dados escritos no arquivo com sucesso.\n");
    return 0;
}