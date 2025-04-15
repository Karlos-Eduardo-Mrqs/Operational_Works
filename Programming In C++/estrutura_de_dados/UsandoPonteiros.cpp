#include <cstdio>  
#include <iostream> // Para usar std::cout
int main() {
    int v_num = 10; // v_num é a variável que será apontada pelo ponteiro
    int *ptr;       // Declaração de variável ponteiro
    ptr = &v_num; // Atribuindo o endereço da variável v_num ao ponteiro
    // Usando printf para exibir informações
    std::printf("Utilizando ponteiros\n\n");
    std::printf("Conteúdo da variável v_num: %d\n", v_num);
    std::printf("Endereço da variável v_num: %p\n", (void*)&v_num);
    std::printf("Conteúdo da variável ponteiro ptr: %p\n", (void*)ptr);
    // Alternativa usando std::cout
    std::cout << "Utilizando ponteiros\n\n";
    std::cout << "Conteúdo da variável v_num: " << v_num << "\n";
    std::cout << "Endereço da variável v_num: " << &v_num << "\n";
    std::cout << "Conteúdo da variável ponteiro ptr: " << ptr << "\n";
    return 0;
}