#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

No* topo = nullptr; // Topo da pilha

void push(int valor) {
    No* novo_no = new No{valor, topo}; // Aloca memória e conecta ao topo
    topo = novo_no;                   // Atualiza o topo
    cout << "Inserido na pilha: " << valor << endl;
}

void pop() {
    if (!topo) {
        cout << "Erro: Pilha vazia!" << endl;
        return;
    }
    No* temp = topo;                  // Guarda o nó a ser removido
    topo = topo->prox;                // Atualiza o topo
    cout << "Removido da pilha: " << temp->valor << endl;
    delete temp;                      // Libera memória
}

void exibirPilha() {
    if (!topo) {
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "Pilha: ";
    No* temp = topo;
    while (temp) {
        cout << temp->valor << " ";
        temp = temp->prox;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    exibirPilha();

    pop();
    exibirPilha();

    pop();
    exibirPilha();

    pop();
    exibirPilha();

    pop(); // Tentativa de remover de uma pilha vazia
    return 0;
}