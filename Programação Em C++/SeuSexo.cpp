#include <stdio.h>

int main() {
    char sexo;
    printf("Qual é o seu sexo?: ");
    scanf("%c", &sexo);
    if (sexo == 'M') {
        printf("Olá meu caro Senhor\n");
    } else if (sexo == 'F') {
        printf("Olá minha cara Senhora\n");
    } else {
        printf("Olá meu caro COLORIDINHO\n");
    }
    
    return 0;
}
