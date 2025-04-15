#include <iostream>
using namespace std;

// Função que troca os valores usando ponteiros
void troca_de_valores(int *a, int *b) {
    int aux;// Variável auxiliar
    aux = *a; // aux recebe o valor apontado por 'a'
    *a = *b;  // O valor apontado por 'a' recebe o valor apontado por 'b'
    *b = aux; // O valor apontado por 'b' recebe o valor de 'aux'

    cout << "Dentro da troca:" << endl;
    cout << "Enderecos: A: " << a << " B: " << b << endl; // Imprime os endereços
    cout << "Valores: A: " << *a << " B: " << *b << endl; // Imprime os valores
}

int main() {
    int x, y; // Variáveis para armazenar os valores

    // Entrada dos valores
    cout << "Digite o primeiro numero: ";
    cin >> x;
    cout << "Digite o segundo numero: ";
    cin >> y;

    cout << "Antes da troca:" << endl;
    cout << "Valores: A: " << x << " B: " << y << endl;
    cout << "Enderecos: A: " << &x << " B: " << &y << endl; // Imprime os endereços

    troca_de_valores(&x, &y);

    cout << "Depois da troca:" << endl;
    cout << "Valores: A: " << x << " B: " << y << endl;
	cout << "Enderecos: A: " << &x << " B: " << &y << endl;
	
    return 0;
}
