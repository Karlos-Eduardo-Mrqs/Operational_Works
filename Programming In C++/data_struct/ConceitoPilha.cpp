#include <iostream>
#include <vector>

const int maximo_da_pilha = 100; // Tamanho máximo da pilha
std::vector<int> pilha;          // Vetor para armazenar os elementos da pilha
int topo = -1;                   // Variável para controlar o topo da pilha

// Função para empilhar um elemento
bool push(int elemento) {
    if (topo >= maximo_da_pilha - 1) { // Verifica se a pilha está cheia
        std::cout << "Erro: a pilha esta cheia\n";
        return false;
    }
    topo++;                        // Incrementa o topo
    pilha.push_back(elemento);     // Adiciona o elemento ao vetor
    std::cout << "Elemento " << elemento << " inserido na pilha.\n";
    return true;
}

// Função para desempilhar um elemento
bool pop() {
    if (topo < 0) {                // Verifica se a pilha está vazia
        std::cout << "Erro: a pilha esta vazia\n";
        return false;
    }
    int elemento_removido = pilha.back(); // Obtém o elemento do topo
    pilha.pop_back();              // Remove o último elemento do vetor
    topo--;                        // Decrementa o topo
    std::cout << "Elemento " << elemento_removido << " removido da pilha.\n";
    return true;
}

// Função para consultar o topo da pilha
void peek() {
    if (topo < 0) {                // Verifica se a pilha está vazia
        std::cout << "A pilha esta vazia\n";
        return;
    }
    std::cout << "Topo da pilha: " << pilha[topo] << "\n";
}

int main() {
    push(20);
    push(35);
    push(15);

    peek(); // Exibe o topo da pilha

    pop();  // Remove o topo da pilha
    peek(); // Exibe o novo topo da pilha

    pop();  // Remove o topo da pilha
    pop();  // Remove o topo da pilha

    pop();  // Tentativa de remover de uma pilha vazia

    return 0;
}