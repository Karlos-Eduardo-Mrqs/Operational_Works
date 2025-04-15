#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

No* inicio = nullptr; // Início da lista

void inserir(int valor) {
    No* novo_no = new No{valor, nullptr}; // Aloca memória para o novo nó
    if (!inicio) {
        inicio = novo_no;                 // Se a lista estiver vazia, o novo nó é o início
    } else {
        No* temp = inicio;
        while (temp->prox) temp = temp->prox; // Encontra o último nó
        temp->prox = novo_no;                // Conecta o novo nó ao final
    }
    cout << "Inserido na lista: " << valor << endl;
}

void remover() {
    if (!inicio) {
        cout << "Erro: Lista vazia!" << endl;
        return;
    }
    No* temp = inicio;                     // Guarda o nó a ser removido
    inicio = inicio->prox;                 // Atualiza o início
    cout << "Removido da lista: " << temp->valor << endl;
    delete temp;                           // Libera memória
}

void exibirLista() {
    if (!inicio) {
        cout << "Lista vazia!" << endl;
        return;
    }
    cout << "Lista: ";
    No* temp = inicio;
    while (temp) {
        cout << temp->valor << " ";
        temp = temp->prox;
    }
    cout << endl;
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    exibirLista();

    remover();
    exibirLista();

    remover();
    exibirLista();

    remover();
    exibirLista();

    remover(); // Tentativa de remover de uma lista vazia
    return 0;
}