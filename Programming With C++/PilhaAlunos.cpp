#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar dados de um aluno
struct aluno {
    int v_nmat;      // Número da matrícula
    float v_nota[3]; // Notas
    float v_media;   // Média
};

int main() {
    struct aluno Felipe; // Declara uma variável do tipo struct

    // Preenche os dados do aluno
    Felipe.v_nmat = 120;
    Felipe.v_nota[0] = 8.5;
    Felipe.v_nota[1] = 7.2;
    Felipe.v_nota[2] = 5.4;

    // Calcula a média
    Felipe.v_media = (Felipe.v_nota[0] + Felipe.v_nota[1] + Felipe.v_nota[2]) / 3.0;

    // Exibe os resultados
    printf("Matricula: %d\n", Felipe.v_nmat);
    printf("Media: %.2f\n", Felipe.v_media);

    // Substitui system("pause") por uma alternativa mais portátil
    printf("Pressione Enter para continuar...\n");
    getchar(); // Aguarda o usuário pressionar Enter

    return 0;
}