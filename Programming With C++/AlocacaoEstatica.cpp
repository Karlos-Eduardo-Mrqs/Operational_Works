#include <iostream>
#include <cstdlib>  // Inclui a declaração de system()

static int a = 0;  // Variável global, alocação estática

void incrementa(void) {
    int b = 0;        // Variável local automática (stack)
    static int c = 0; // Variável local estática (segmento de dados)

    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    a++; // Incrementa a variável global
    b++; // Incrementa a variável local automática
    c++; // Incrementa a variável local estática
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        incrementa();
    }
    system("pause"); // Pausa o console (Windows)
    return 0;
}