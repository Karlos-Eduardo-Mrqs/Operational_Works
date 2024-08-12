#include<stdio.h>

int main(void) {
    char nome[100]; // Array para armazenar o nome
    printf("Qual é o seu nome?: ");
    scanf("%s", nome); // Use %s para ler uma string
    printf("Prazer %s\n", nome); // Use %s para imprimir uma string
    return 0;
}