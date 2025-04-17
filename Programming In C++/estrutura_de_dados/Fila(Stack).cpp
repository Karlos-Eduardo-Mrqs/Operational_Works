#include <iostream>
using namespace std;

// Variáveis globais para representar a fila
const int MAX_TAMANHO = 5; // Tamanho máximo da fila
int fila[MAX_TAMANHO];     // Array para armazenar os elementos
int frente = 0, tras = 0;            // Índice do elemento na frente e o que está proximo espaço vazio da fila 

bool estaVazia() { // Função para verificar se a fila está vazia
    return frente == tras;
}

bool estaCheia() { // Função para verificar se a fila está cheia
    return tras == MAX_TAMANHO;
}

void enqueue(int valor) { // Função para inserir um elemento na fila (enqueue)
    if (estaCheia()) {
        cout << "Erro: A fila está cheia!" << endl;
        return;
    }
    fila[tras] = valor; // Insere o valor no final da fila
    tras++;             // Incrementa o índice de trás
    cout << "Elemento " << valor << " inserido na fila." << endl;
}

int dequeue() { // Função para remover um elemento da fila (dequeue)
    if (estaVazia()) {
        cout << "Erro: A fila está vazia!" << endl;
        return -1; // Retorna -1 como indicador de erro
    }
    int valor = fila[frente]; // Armazena o valor da frente
    frente++;                 // Incrementa o índice da frente
    cout << "Elemento " << valor << " removido da fila." << endl;
    return valor;
}

void mostrarFila() { // Função para mostrar todos os elementos da fila
    if (estaVazia()) {
        cout << "A fila está vazia." << endl;
        return;
    }
    cout << "Fila: ";
    for (int i = frente; i < tras; i++) {
        cout << fila[i] << " ";
    }
    cout << endl;
}

int main() { // Função principal
    enqueue(10);// Insere elementos na fila
    enqueue(20);
    mostrarFila();

    dequeue();// Remove elementos da fila
    mostrarFila();

    // Insere mais elementos
    enqueue(40);
    enqueue(50);
    enqueue(60); // Tentativa de inserir quando a fila está cheia
    mostrarFila();

    return 0;
}