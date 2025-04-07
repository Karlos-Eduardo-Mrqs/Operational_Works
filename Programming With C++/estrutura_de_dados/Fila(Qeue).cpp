#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

No* inicioFila = nullptr; // Início da fila
No* fimFila = nullptr;    // Fim da fila

void enqueue(int valor) {
    No* novo_no = new No{valor, nullptr}; // Aloca memória para o novo nó
    if (!inicioFila) {
        inicioFila = novo_no;            // Se a fila estiver vazia, o novo nó é o início
        fimFila = novo_no;               // E também o fim
    } else {
        fimFila->prox = novo_no;         // Conecta o novo nó ao final
        fimFila = novo_no;               // Atualiza o fim
    }
    cout << "Inserido na fila: " << valor << endl;
}

void dequeue() {
    if (!inicioFila) {
        cout << "Erro: Fila vazia!" << endl;
        return;
    }
    No* temp = inicioFila;               // Guarda o nó a ser removido
    inicioFila = inicioFila->prox;       // Atualiza o início
    cout << "Removido da fila: " << temp->valor << endl;
    delete temp;                         // Libera memória
    if (!inicioFila) fimFila = nullptr;  // Se a fila ficar vazia, ajusta o fim
}

void exibirFila() {
    if (!inicioFila) {
        cout << "Fila vazia!" << endl;
        return;
    }
    cout << "Fila: ";
    No* temp = inicioFila;
    while (temp) {
        cout << temp->valor << " ";
        temp = temp->prox;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    exibirFila();

    dequeue();
    exibirFila();

    dequeue();
    exibirFila();

    dequeue();
    exibirFila();

    dequeue(); // Tentativa de remover de uma fila vazia
    return 0;
}